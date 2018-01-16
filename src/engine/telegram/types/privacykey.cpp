// This file generated by libqtelegram-code-generator.
// You can download it from: https://github.com/Aseman-Land/libqtelegram-code-generator
// DO NOT EDIT THIS FILE BY HAND -- YOUR CHANGES WILL BE OVERWRITTEN

#include "privacykey.h"
#include "core/inboundpkt.h"
#include "core/outboundpkt.h"
#include "../coretypes.h"

#include <QDataStream>

PrivacyKey::PrivacyKey(PrivacyKeyClassType classType, InboundPkt *in) :
    m_classType(classType)
{
    if(in) fetch(in);
}

PrivacyKey::PrivacyKey(InboundPkt *in) :
    m_classType(typePrivacyKeyStatusTimestamp)
{
    fetch(in);
}

PrivacyKey::PrivacyKey(const PrivacyKey &another) :
    TelegramTypeObject(),
    m_classType(typePrivacyKeyStatusTimestamp)
{
    operator=(another);
}

PrivacyKey::PrivacyKey(const Null &null) :
    TelegramTypeObject(null),
    m_classType(typePrivacyKeyStatusTimestamp)
{
}

PrivacyKey::~PrivacyKey() {

}

bool PrivacyKey::operator ==(const PrivacyKey &b) const {
    return m_classType == b.m_classType;
}

PrivacyKey &PrivacyKey::operator =(const PrivacyKey &b) {
    m_classType = b.m_classType;
    setNull(b.isNull());
    return *this;
}

void PrivacyKey::setClassType(PrivacyKey::PrivacyKeyClassType classType) {
    m_classType = classType;
}

PrivacyKey::PrivacyKeyClassType PrivacyKey::classType() const {
    return m_classType;
}

bool PrivacyKey::fetch(InboundPkt *in) {
    LQTG_FETCH_LOG;
    int x = in->fetchInt();
    switch(x) {
    case typePrivacyKeyStatusTimestamp: {
        m_classType = static_cast<PrivacyKeyClassType>(x);
        return true;
    }
        break;

    case typePrivacyKeyChatInvite: {
        m_classType = static_cast<PrivacyKeyClassType>(x);
        return true;
    }
        break;

    case typePrivacyKeyPhoneCall: {
        m_classType = static_cast<PrivacyKeyClassType>(x);
        return true;
    }
        break;

    default:
        LQTG_FETCH_ASSERT;
        return false;
    }
}

bool PrivacyKey::push(OutboundPkt *out) const {
    out->appendInt(m_classType);
    switch(m_classType) {
    case typePrivacyKeyStatusTimestamp: {
        return true;
    }
        break;

    case typePrivacyKeyChatInvite: {
        return true;
    }
        break;

    case typePrivacyKeyPhoneCall: {
        return true;
    }
        break;

    default:
        return false;
    }
}

QMap<QString, QVariant> PrivacyKey::toMap() const {
    QMap<QString, QVariant> result;
    switch(static_cast<int>(m_classType)) {
    case typePrivacyKeyStatusTimestamp: {
        result["classType"] = "PrivacyKey::typePrivacyKeyStatusTimestamp";
        return result;
    }
        break;

    case typePrivacyKeyChatInvite: {
        result["classType"] = "PrivacyKey::typePrivacyKeyChatInvite";
        return result;
    }
        break;

    case typePrivacyKeyPhoneCall: {
        result["classType"] = "PrivacyKey::typePrivacyKeyPhoneCall";
        return result;
    }
        break;

    default:
        return result;
    }
}

PrivacyKey PrivacyKey::fromMap(const QMap<QString, QVariant> &map) {
    PrivacyKey result;
    if(map.value("classType").toString() == "PrivacyKey::typePrivacyKeyStatusTimestamp") {
        result.setClassType(typePrivacyKeyStatusTimestamp);
        return result;
    }
    if(map.value("classType").toString() == "PrivacyKey::typePrivacyKeyChatInvite") {
        result.setClassType(typePrivacyKeyChatInvite);
        return result;
    }
    if(map.value("classType").toString() == "PrivacyKey::typePrivacyKeyPhoneCall") {
        result.setClassType(typePrivacyKeyPhoneCall);
        return result;
    }
    return result;
}

PrivacyKey PrivacyKey::fromJson(const QString &json) {
    return PrivacyKey::fromMap(QJsonDocument::fromJson(json.toUtf8()).toVariant().toMap());
}

QByteArray PrivacyKey::getHash(QCryptographicHash::Algorithm alg) const {
    QByteArray data;
    QDataStream str(&data, QIODevice::WriteOnly);
    str << *this;
    return QCryptographicHash::hash(data, alg);
}

QDataStream &operator<<(QDataStream &stream, const PrivacyKey &item) {
    stream << static_cast<uint>(item.classType());
    switch(item.classType()) {
    case PrivacyKey::typePrivacyKeyStatusTimestamp:

        break;
    case PrivacyKey::typePrivacyKeyChatInvite:

        break;
    case PrivacyKey::typePrivacyKeyPhoneCall:

        break;
    }
    return stream;
}

QDataStream &operator>>(QDataStream &stream, PrivacyKey &item) {
    uint type = 0;
    stream >> type;
    item.setClassType(static_cast<PrivacyKey::PrivacyKeyClassType>(type));
    switch(type) {
    case PrivacyKey::typePrivacyKeyStatusTimestamp: {

    }
        break;
    case PrivacyKey::typePrivacyKeyChatInvite: {

    }
        break;
    case PrivacyKey::typePrivacyKeyPhoneCall: {

    }
        break;
    }
    return stream;
}

/*QDebug operator<<(QDebug debug,  const PrivacyKey &item) {
    QDebugStateSaver saver(debug);
    Q_UNUSED(saver)
    debug.nospace() << "Telegram.PrivacyKey(";
    switch(item.classType()) {
    case PrivacyKey::typePrivacyKeyStatusTimestamp:
        debug.nospace() << "classType: typePrivacyKeyStatusTimestamp";
        break;
    case PrivacyKey::typePrivacyKeyChatInvite:
        debug.nospace() << "classType: typePrivacyKeyChatInvite";
        break;
    case PrivacyKey::typePrivacyKeyPhoneCall:
        debug.nospace() << "classType: typePrivacyKeyPhoneCall";
        break;
    }
    debug.nospace() << ")";
    return debug;
}
*/
