// This file generated by libqtelegram-code-generator.
// You can download it from: https://github.com/Aseman-Land/libqtelegram-code-generator
// DO NOT EDIT THIS FILE BY HAND -- YOUR CHANGES WILL BE OVERWRITTEN

#include "phoneconnection.h"
#include "core/inboundpkt.h"
#include "core/outboundpkt.h"
#include "../coretypes.h"

#include <QDataStream>

PhoneConnection::PhoneConnection(PhoneConnectionClassType classType, InboundPkt *in) :
    m_id(0),
    m_port(0),
    m_classType(classType)
{
    if(in) fetch(in);
}

PhoneConnection::PhoneConnection(InboundPkt *in) :
    m_id(0),
    m_port(0),
    m_classType(typePhoneConnection)
{
    fetch(in);
}

PhoneConnection::PhoneConnection(const PhoneConnection &another) :
    TelegramTypeObject(),
    m_id(0),
    m_port(0),
    m_classType(typePhoneConnection)
{
    operator=(another);
}

PhoneConnection::PhoneConnection(const Null &null) :
    TelegramTypeObject(null),
    m_id(0),
    m_port(0),
    m_classType(typePhoneConnection)
{
}

PhoneConnection::~PhoneConnection() {

}

void PhoneConnection::setId(qint64 id) {
    m_id = id;
}

qint64 PhoneConnection::id() const {
    return m_id;
}

void PhoneConnection::setIp(const QString &ip) {
    m_ip = ip;
}

QString PhoneConnection::ip() const {
    return m_ip;
}

void PhoneConnection::setIpv6(const QString &ipv6) {
    m_ipv6 = ipv6;
}

QString PhoneConnection::ipv6() const {
    return m_ipv6;
}

void PhoneConnection::setPeerTag(const QByteArray &peerTag) {
    m_peerTag = peerTag;
}

QByteArray PhoneConnection::peerTag() const {
    return m_peerTag;
}

void PhoneConnection::setPort(qint32 port) {
    m_port = port;
}

qint32 PhoneConnection::port() const {
    return m_port;
}

bool PhoneConnection::operator ==(const PhoneConnection &b) const {
    return m_classType == b.m_classType &&
           m_id == b.m_id &&
           m_ip == b.m_ip &&
           m_ipv6 == b.m_ipv6 &&
           m_peerTag == b.m_peerTag &&
           m_port == b.m_port;
}

PhoneConnection &PhoneConnection::operator =(const PhoneConnection &b) {
    m_classType = b.m_classType;
    m_id = b.m_id;
    m_ip = b.m_ip;
    m_ipv6 = b.m_ipv6;
    m_peerTag = b.m_peerTag;
    m_port = b.m_port;
    setNull(b.isNull());
    return *this;
}

void PhoneConnection::setClassType(PhoneConnection::PhoneConnectionClassType classType) {
    m_classType = classType;
}

PhoneConnection::PhoneConnectionClassType PhoneConnection::classType() const {
    return m_classType;
}

bool PhoneConnection::fetch(InboundPkt *in) {
    LQTG_FETCH_LOG;
    int x = in->fetchInt();
    switch(x) {
    case typePhoneConnection: {
        m_id = in->fetchLong();
        m_ip = in->fetchQString();
        m_ipv6 = in->fetchQString();
        m_port = in->fetchInt();
        m_peerTag = in->fetchBytes();
        m_classType = static_cast<PhoneConnectionClassType>(x);
        return true;
    }
        break;

    default:
        LQTG_FETCH_ASSERT;
        return false;
    }
}

bool PhoneConnection::push(OutboundPkt *out) const {
    out->appendInt(m_classType);
    switch(m_classType) {
    case typePhoneConnection: {
        out->appendLong(m_id);
        out->appendQString(m_ip);
        out->appendQString(m_ipv6);
        out->appendInt(m_port);
        out->appendBytes(m_peerTag);
        return true;
    }
        break;

    default:
        return false;
    }
}

QMap<QString, QVariant> PhoneConnection::toMap() const {
    QMap<QString, QVariant> result;
    switch(static_cast<int>(m_classType)) {
    case typePhoneConnection: {
        result["classType"] = "PhoneConnection::typePhoneConnection";
        if( id() ) result["id"] = QString::number(id());
        if( !m_ip.isEmpty() ) result["ip"] = QVariant::fromValue<QString>(m_ip);
        if( !m_ipv6.isEmpty() ) result["ipv6"] = QVariant::fromValue<QString>(m_ipv6);
        if( port() ) result["port"] = QString::number(port());
        if( !m_peerTag.isEmpty() ) result["peerTag"] = QVariant::fromValue<QByteArray>(m_peerTag);
        return result;
    }
        break;

    default:
        return result;
    }
}

PhoneConnection PhoneConnection::fromMap(const QMap<QString, QVariant> &map) {
    PhoneConnection result;
    if(map.value("classType").toString() == "PhoneConnection::typePhoneConnection") {
        result.setClassType(typePhoneConnection);
        QVariant _id_var = map.value("id");
        if( !_id_var.isNull() ) {
            _id_var.convert( QVariant::nameToType("qint64") );
            result.setId( _id_var.value<qint64>() );
        }

        QVariant _ip_var = map.value("ip");
        if( !_ip_var.isNull() ) {
            _ip_var.convert( QVariant::nameToType("QString") );
            result.setIp( _ip_var.value<QString>() );
        }

        QVariant _ipv6_var = map.value("ipv6");
        if( !_ipv6_var.isNull() ) {
            _ipv6_var.convert( QVariant::nameToType("QString") );
            result.setIpv6( _ipv6_var.value<QString>() );
        }

        QVariant _port_var = map.value("port");
        if( !_port_var.isNull() ) {
            _port_var.convert( QVariant::nameToType("qint32") );
            result.setPort( _port_var.value<qint32>() );
        }

        QVariant _peerTag_var = map.value("peerTag");
        if( !_peerTag_var.isNull() ) {
            _peerTag_var.convert( QVariant::nameToType("QByteArray") );
            result.setPeerTag( _peerTag_var.value<QByteArray>() );
        }

        return result;
    }
    return result;
}

PhoneConnection PhoneConnection::fromJson(const QString &json) {
    return PhoneConnection::fromMap(QJsonDocument::fromJson(json.toUtf8()).toVariant().toMap());
}

QByteArray PhoneConnection::getHash(QCryptographicHash::Algorithm alg) const {
    QByteArray data;
    QDataStream str(&data, QIODevice::WriteOnly);
    str << *this;
    return QCryptographicHash::hash(data, alg);
}

QDataStream &operator<<(QDataStream &stream, const PhoneConnection &item) {
    stream << static_cast<uint>(item.classType());
    switch(item.classType()) {
    case PhoneConnection::typePhoneConnection:
        stream << item.id();
        stream << item.ip();
        stream << item.ipv6();
        stream << item.port();
        stream << item.peerTag();
        break;
    }
    return stream;
}

QDataStream &operator>>(QDataStream &stream, PhoneConnection &item) {
    uint type = 0;
    stream >> type;
    item.setClassType(static_cast<PhoneConnection::PhoneConnectionClassType>(type));
    switch(type) {
    case PhoneConnection::typePhoneConnection: {
        qint64 m_id;
        stream >> m_id;
        item.setId(m_id);
        QString m_ip;
        stream >> m_ip;
        item.setIp(m_ip);
        QString m_ipv6;
        stream >> m_ipv6;
        item.setIpv6(m_ipv6);
        qint32 m_port;
        stream >> m_port;
        item.setPort(m_port);
        QByteArray m_peer_tag;
        stream >> m_peer_tag;
        item.setPeerTag(m_peer_tag);
    }
        break;
    }
    return stream;
}

/*QDebug operator<<(QDebug debug,  const PhoneConnection &item) {
    QDebugStateSaver saver(debug);
    Q_UNUSED(saver)
    debug.nospace() << "Telegram.PhoneConnection(";
    switch(item.classType()) {
    case PhoneConnection::typePhoneConnection:
        debug.nospace() << "classType: typePhoneConnection";
        debug.nospace() << ", id: " << item.id();
        debug.nospace() << ", ip: " << item.ip();
        debug.nospace() << ", ipv6: " << item.ipv6();
        debug.nospace() << ", port: " << item.port();
        debug.nospace() << ", peerTag: " << item.peerTag();
        break;
    }
    debug.nospace() << ")";
    return debug;
}
*/
