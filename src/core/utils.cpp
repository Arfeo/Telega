/*
 * Copyright 2013 Vitaly Valtman
 * Copyright 2014 Canonical Ltd.
 * Authors:
 *      Roberto Mier
 *      Tiago Herrmann
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; version 3.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#include "utils.h"
#include <openssl/rand.h>
#include <openssl/pem.h>
#include <openssl/err.h>
#include <sys/utsname.h>
#include <zlib.h>
#include <QDebug>
#include <QEventLoop>
#include <QProcess>
#include <QStringList>
#include <bb/device/HardwareInfo>
using namespace bb::device;

Utils::Utils(QObject *parent) :
    QObject(parent)
{
    // ..
}

qint32 Utils::randomBytes(void *buffer, qint32 count) {
    qint32 returnValue = RAND_bytes ((uchar *)buffer, count);
    if (returnValue < 0) {
        returnValue = RAND_pseudo_bytes ((uchar *)buffer, count);
    }
    return returnValue;
}

qint32 Utils::serializeBignum(BIGNUM *b, char *buffer, qint32 maxlen) {
    qint32 itslen = BN_num_bytes (b);
    qint32 reqlen;
    if (itslen < 254) {
        reqlen = itslen + 1;
    } else {
        reqlen = itslen + 4;
    }
    qint32 newlen = (reqlen + 3) & -4;
    qint32 pad = newlen - reqlen;
    reqlen = newlen;
    if (reqlen > maxlen) {
        return -reqlen;
    }
    if (itslen < 254) {
        *buffer++ = itslen;
    } else {
        *(qint32 *)buffer = (itslen << 8) + 0xfe;
        buffer += 4;
    }
    qint32 l = BN_bn2bin (b, (uchar *)buffer);
    Q_ASSERT (l == itslen);
    buffer += l;
    while (pad --> 0) {
        *buffer++ = 0;
    }
    return reqlen;
}

double Utils::getUTime(qint32 clockId) {
    struct timespec T;
    qint32 success = clock_gettime(clockId, &T);
    Q_UNUSED(success);
    Q_ASSERT(success == 0);
    double res = T.tv_sec + (double) T.tv_nsec * 1e-9;
    return res;
}

quint64 Utils::gcd(quint64 a, quint64 b) {
  return b ? gcd (b, a % b) : a;
}

qint32 Utils::check_g (uchar p[256], BIGNUM *g) {
    static uchar s[256];
    memset (s, 0, 256);
    Q_ASSERT(BN_num_bytes (g) <= 256);
    BN_bn2bin (g, s);
    qint32 ok = 0;
    qint32 i;
    for (i = 0; i < 64; i++) {
        if (s[i]) {
            ok = 1;
            break;
        }
    }
    if (!ok) { return -1; }
    ok = 0;
    for (i = 0; i < 64; i++) {
        if (s[255 - i]) {
            ok = 1;
            break;
        }
    }
    if (!ok) { return -1; }
    ok = 0;
    for (i = 0; i < 64; i++) {
        if (s[i] < p[i]) {
            ok = 1;
            break;
        } else if (s[i] > p[i]) {
//            qDebug() << i << "=" << (qint32)s[i] << (qint32)p[i];
            return -1;
        }
    }
    if (!ok) { return -1; }
    return 0;
}

qint32 Utils::check_g_bn (BIGNUM *p, BIGNUM *g) {
    static uchar s[256];
    memset (s, 0, 256);
    Q_ASSERT(BN_num_bytes (p) <= 256);
    BN_bn2bin (p, s);
    return check_g (s, g);
}

void Utils::ensurePtr(void *p) {
    if (p == NULL) {
        qFatal("Out of memory");
        exit (1);
    }
}

void Utils::ensure (qint32 r) {
  if (!r) {
    ERR_print_errors_fp (stderr);
    Q_ASSERT(0);
  }
}

void Utils::freeSecure(void *ptr, qint32 size) {
    if (!ptr) return;
    memset (ptr, 0, size);
    free (ptr);
}

RSA *Utils::rsaLoadPublicKey() {
    RSA *pubKey = NULL;
    QString publicKeyName = ":/tg.pub";
    QFile file(publicKeyName);

    if(!file.exists()) {
        qDebug() << "Public key file" << publicKeyName << "doesn't exist";
        return NULL;
    }
    if(!file.open(QFile::ReadOnly)) {
        qDebug() << "Couldn't open public key file" << publicKeyName;
        return NULL;
    }

    QByteArray fileData = file.readAll();
    BIO *bufio = BIO_new_mem_buf((void*)fileData.data(), fileData.length());
    pubKey = PEM_read_bio_RSAPublicKey (bufio, NULL, NULL, NULL);

    BUF_MEM *bptr;
    BIO_get_mem_ptr(bufio, &bptr);
    BIO_set_close(bufio, BIO_NOCLOSE); /* So BIO_free() leaves BUF_MEM alone */
    BIO_free(bufio);

    if (pubKey == NULL) {
        qDebug() << "PEM_read_RSAPublicKey returns NULL";
        return NULL;
    }
    qDebug() << "public key" << publicKeyName << "loaded successfully";
    return pubKey;
}

qint64 Utils::computeRSAFingerprint(RSA *key) {
    static char tempbuff[4096];
    static uchar sha[20];
    Q_ASSERT(key->n && key->e);
    qint32 l1 = serializeBignum (key->n, tempbuff, 4096);
    Q_ASSERT(l1 > 0);
    qint32 l2 = serializeBignum (key->e, tempbuff + l1, 4096 - l1);
    Q_ASSERT(l2 > 0 && l1 + l2 <= 4096);
    SHA1 ((uchar *)tempbuff, l1 + l2, sha);
    return *(qint64 *)(sha + 12);
}

void *Utils::talloc(size_t size) {
#ifdef DEBUG
  total_allocated_bytes += size;
  void *p = malloc (size + RES_PRE + RES_AFTER);
  ensurePtr (p);
  *(qint32 *)p = size ^ 0xbedabeda;
  *(qint32 *)(p + 4) = size;
  *(qint32 *)(p + RES_PRE + size) = size ^ 0x7bed7bed;
  *(qint32 *)(p + RES_AFTER + 4 + size) = usedBlocks;
  blocks[usedBlocks ++] = p;
  return p + 8;
#else
  void *p = malloc (size);
  ensurePtr (p);
  return p;
#endif
}

qint32 Utils::tinflate(void *input, qint32 ilen, void *output, qint32 olen) {
    z_stream strm;
    memset(&strm, 0, sizeof (strm));
    qint32 inflateResult = inflateInit2(&strm, 16 + MAX_WBITS);
    Q_UNUSED(inflateResult);
    Q_ASSERT(inflateResult == Z_OK);
    strm.avail_in = ilen;
    strm.next_in = (Bytef *)input;
    strm.avail_out = olen ;
    strm.next_out = (Bytef *)output;
    qint32 err = inflate (&strm, Z_FINISH), totalOut = 0;
    if (err == Z_OK || err == Z_STREAM_END) {
        totalOut = (qint32) strm.total_out;
    }
    inflateEnd (&strm);
    return totalOut;
}

QString Utils::toHex(qint32 x) {
    return "0x" + QString::number(static_cast<quint32>(x), 16);
}

QString Utils::toHex(void *buffer, qint32 size) {
    QByteArray array((char *)buffer, size);
    QByteArray hexArray = array.toHex();
    QString sb;
    qint32 count = 0;
    for (qint32 i = 0; i < hexArray.length(); i += 2) {
        count++;
        sb.append(QString(hexArray.at(i)).toUpper());
        sb.append(QString(hexArray.at(i+1)).toUpper());
        if (count == 8) {
            sb.append("\n");
            count = 0;
        } else if (count == 4) {
            sb.append("\t");
        } else {
            sb.append(" ");
        }
    }
    return sb;
}

BIGNUM *Utils::padBytesAndGetBignum(const QByteArray &gAOrB) {
    // padding of B (gAOrB) to have exactly 256 bytes
    uchar paddedGAOrB[256];
    qint32 length = gAOrB.length();
    // check that size of
    uchar *rawGAOrB = (uchar *)gAOrB.data();
    if (length < 256) {
      memcpy (paddedGAOrB + 256 - length, rawGAOrB, length);
    } else {
      memcpy (paddedGAOrB, rawGAOrB + (length - 256), 256);
    }

    BIGNUM *bigNumGAOrB = BN_bin2bn(paddedGAOrB, 256, 0);
    return bigNumGAOrB;
}

BIGNUM *Utils::bytesToBignum(const QByteArray &bytes) {
    uchar *data = (uchar *)bytes.data();
    qint32 length = bytes.length();
    BIGNUM *bignum = BN_bin2bn(data, length, 0);
    return bignum;
}

QByteArray Utils::bignumToBytes(BIGNUM *bignum) {
    qint32 length = BN_num_bytes(bignum);
    uchar data[length];
    BN_bn2bin(bignum, data);
    return QByteArray((char *)data, length);
}

qint64 Utils::getKeyFingerprint(uchar *sharedKey) {
    uchar shaBuffer[20];
    SHA1(sharedKey, 256, shaBuffer);
    qint64 keyFingerprint = *(qint64 *)(shaBuffer + 12);
    return keyFingerprint;
}

QString Utils::getDeviceModel() {
//    mHardwareInfo = new ;
//    HardwareInfo info;

//   qDebug()<< "the device name  is ::\n" << info.deviceName()<< "imei number \n" << info.imei()<<"the model name "<<info.modelName();

    return QString("Expert");
}

QString Utils::getSystemVersion() {

    return QString("BB10");
}

QString Utils::getAppVersion() {
    return TELEGA_VERSION;
}

QString Utils::parsePhoneNumberDigits(const QString &phoneNumber) {
    // Only allowing + and [0..9] chars
    QString filteredChars;

    if (phoneNumber.length() > 0) {

        for (int i = 0; i < phoneNumber.length(); i++) {
            const QChar c = phoneNumber.at(i);
            if (c.isDigit() || c == '+') {
                filteredChars.append(c);
            }
        }
    }

    return filteredChars;
}
