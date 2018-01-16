// This file generated by libqtelegram-code-generator.
// You can download it from: https://github.com/Aseman-Land/libqtelegram-code-generator
// DO NOT EDIT THIS FILE BY HAND -- YOUR CHANGES WILL BE OVERWRITTEN

#include "contact.h"
#include "core/inboundpkt.h"
#include "core/outboundpkt.h"
#include "../coretypes.h"

#include <QDataStream>

Contact::Contact(ContactClassType classType, InboundPkt *in) :
    m_mutual(false),
    m_userId(0),
    m_classType(classType)
{
    if(in) fetch(in);
}

Contact::Contact(InboundPkt *in) :
    m_mutual(false),
    m_userId(0),
    m_classType(typeContact)
{
    fetch(in);
}

Contact::Contact(const Contact &another) :
    TelegramTypeObject(),
    m_mutual(false),
    m_userId(0),
    m_classType(typeContact)
{
    operator=(another);
}

Contact::Contact(const Null &null) :
    TelegramTypeObject(null),
    m_mutual(false),
    m_userId(0),
    m_classType(typeContact)
{
}

Contact::~Contact() {

}

void Contact::setMutual(bool mutual) {
    m_mutual = mutual;
}

bool Contact::mutual() const {
    return m_mutual;
}

void Contact::setUserId(qint32 userId) {
    m_userId = userId;
}

qint32 Contact::userId() const {
    return m_userId;
}

bool Contact::operator ==(const Contact &b) const {
    return m_classType == b.m_classType &&
           m_mutual == b.m_mutual &&
           m_userId == b.m_userId;
}

Contact &Contact::operator =(const Contact &b) {
    m_classType = b.m_classType;
    m_mutual = b.m_mutual;
    m_userId = b.m_userId;
    setNull(b.isNull());
    return *this;
}

void Contact::setClassType(Contact::ContactClassType classType) {
    m_classType = classType;
}

Contact::ContactClassType Contact::classType() const {
    return m_classType;
}

bool Contact::fetch(InboundPkt *in) {
    LQTG_FETCH_LOG;
    int x = in->fetchInt();
    switch(x) {
    case typeContact: {
        m_userId = in->fetchInt();
        m_mutual = in->fetchBool();
        m_classType = static_cast<ContactClassType>(x);
        return true;
    }
        break;

    default:
        LQTG_FETCH_ASSERT;
        return false;
    }
}

bool Contact::push(OutboundPkt *out) const {
    out->appendInt(m_classType);
    switch(m_classType) {
    case typeContact: {
        out->appendInt(m_userId);
        out->appendBool(m_mutual);
        return true;
    }
        break;

    default:
        return false;
    }
}

QMap<QString, QVariant> Contact::toMap() const {
    QMap<QString, QVariant> result;
    switch(static_cast<int>(m_classType)) {
    case typeContact: {
        result["classType"] = "Contact::typeContact";
        if( userId() ) result["userId"] = QString::number(userId());
        if( mutual() ) result["mutual"] = QString::number(mutual());
        return result;
    }
        break;

    default:
        return result;
    }
}

Contact Contact::fromMap(const QMap<QString, QVariant> &map) {
    Contact result;
    if(map.value("classType").toString() == "Contact::typeContact") {
        result.setClassType(typeContact);
        QVariant _userId_var = map.value("userId");
        if( !_userId_var.isNull() ) {
            _userId_var.convert( QVariant::nameToType("qint32") );
            result.setUserId( _userId_var.value<qint32>() );
        }

        QVariant _mutual_var = map.value("mutual");
        if( !_mutual_var.isNull() ) {
            _mutual_var.convert( QVariant::nameToType("bool") );
            result.setMutual( _mutual_var.value<bool>() );
        }

        return result;
    }
    return result;
}

Contact Contact::fromJson(const QString &json) {
    return Contact::fromMap(QJsonDocument::fromJson(json.toUtf8()).toVariant().toMap());
}

QByteArray Contact::getHash(QCryptographicHash::Algorithm alg) const {
    QByteArray data;
    QDataStream str(&data, QIODevice::WriteOnly);
    str << *this;
    return QCryptographicHash::hash(data, alg);
}

QDataStream &operator<<(QDataStream &stream, const Contact &item) {
    stream << static_cast<uint>(item.classType());
    switch(item.classType()) {
    case Contact::typeContact:
        stream << item.userId();
        stream << item.mutual();
        break;
    }
    return stream;
}

QDataStream &operator>>(QDataStream &stream, Contact &item) {
    uint type = 0;
    stream >> type;
    item.setClassType(static_cast<Contact::ContactClassType>(type));
    switch(type) {
    case Contact::typeContact: {
        qint32 m_user_id;
        stream >> m_user_id;
        item.setUserId(m_user_id);
        bool m_mutual;
        stream >> m_mutual;
        item.setMutual(m_mutual);
    }
        break;
    }
    return stream;
}

/*QDebug operator<<(QDebug debug,  const Contact &item) {
    QDebugStateSaver saver(debug);
    Q_UNUSED(saver)
    debug.nospace() << "Telegram.Contact(";
    switch(item.classType()) {
    case Contact::typeContact:
        debug.nospace() << "classType: typeContact";
        debug.nospace() << ", userId: " << item.userId();
        debug.nospace() << ", mutual: " << item.mutual();
        break;
    }
    debug.nospace() << ")";
    return debug;
}
*/
