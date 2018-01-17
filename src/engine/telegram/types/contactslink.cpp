// This file generated by libqtelegram-code-generator.
// You can download it from: https://github.com/Aseman-Land/libqtelegram-code-generator
// DO NOT EDIT THIS FILE BY HAND -- YOUR CHANGES WILL BE OVERWRITTEN

#include "contactslink.h"
#include "core/inboundpkt.h"
#include "core/outboundpkt.h"
#include "../coretypes.h"

#include <QDataStream>

ContactsLink::ContactsLink(ContactsLinkClassType classType, InboundPkt *in) :
    m_classType(classType)
{
    if(in) fetch(in);
}

ContactsLink::ContactsLink(InboundPkt *in) :
    m_classType(typeContactsLink)
{
    fetch(in);
}

ContactsLink::ContactsLink(const ContactsLink &another) :
    TelegramTypeObject(),
    m_classType(typeContactsLink)
{
    operator=(another);
}

ContactsLink::ContactsLink(const Null &null) :
    TelegramTypeObject(null),
    m_classType(typeContactsLink)
{
}

ContactsLink::~ContactsLink() {

}

void ContactsLink::setForeignLink(const ContactLink &foreignLink) {
    m_foreignLink = foreignLink;
}

ContactLink ContactsLink::foreignLink() const {
    return m_foreignLink;
}

void ContactsLink::setMyLink(const ContactLink &myLink) {
    m_myLink = myLink;
}

ContactLink ContactsLink::myLink() const {
    return m_myLink;
}

void ContactsLink::setUser(const User &user) {
    m_user = user;
}

User ContactsLink::user() const {
    return m_user;
}

bool ContactsLink::operator ==(const ContactsLink &b) const {
    return m_classType == b.m_classType &&
           m_foreignLink == b.m_foreignLink &&
           m_myLink == b.m_myLink &&
           m_user == b.m_user;
}

ContactsLink &ContactsLink::operator =(const ContactsLink &b) {
    m_classType = b.m_classType;
    m_foreignLink = b.m_foreignLink;
    m_myLink = b.m_myLink;
    m_user = b.m_user;
    setNull(b.isNull());
    return *this;
}

void ContactsLink::setClassType(ContactsLink::ContactsLinkClassType classType) {
    m_classType = classType;
}

ContactsLink::ContactsLinkClassType ContactsLink::classType() const {
    return m_classType;
}

bool ContactsLink::fetch(InboundPkt *in) {
    LQTG_FETCH_LOG;
    int x = in->fetchInt();
    switch(x) {
    case typeContactsLink: {
        m_myLink.fetch(in);
        m_foreignLink.fetch(in);
        m_user.fetch(in);
        m_classType = static_cast<ContactsLinkClassType>(x);
        return true;
    }
        break;

    default:
        LQTG_FETCH_ASSERT;
        return false;
    }
}

bool ContactsLink::push(OutboundPkt *out) const {
    out->appendInt(m_classType);
    switch(m_classType) {
    case typeContactsLink: {
        m_myLink.push(out);
        m_foreignLink.push(out);
        m_user.push(out);
        return true;
    }
        break;

    default:
        return false;
    }
}

QMap<QString, QVariant> ContactsLink::toMap() const {
    QMap<QString, QVariant> result;
    switch(static_cast<int>(m_classType)) {
    case typeContactsLink: {
        result["classType"] = "ContactsLink::typeContactsLink";
        if( !m_myLink.isNull() ) result["myLink"] = m_myLink.toMap();
        if( !m_foreignLink.isNull() ) result["foreignLink"] = m_foreignLink.toMap();
        if( !m_user.isNull() ) result["user"] = m_user.toMap();
        return result;
    }
        break;

    default:
        return result;
    }
}

ContactsLink ContactsLink::fromMap(const QMap<QString, QVariant> &map) {
    ContactsLink result;
    if(map.value("classType").toString() == "ContactsLink::typeContactsLink") {
        result.setClassType(typeContactsLink);
        QVariant _myLink_var = map.value("myLink");
        if( !_myLink_var.isNull() )
            result.setMyLink( ContactLink::fromMap(_myLink_var.toMap()) );

        QVariant _foreignLink_var = map.value("foreignLink");
        if( !_foreignLink_var.isNull() )
            result.setForeignLink( ContactLink::fromMap(_foreignLink_var.toMap()) );

        QVariant _user_var = map.value("user");
        if( !_user_var.isNull() )
            result.setUser( User::fromMap(_user_var.toMap()) );

        return result;
    }
    return result;
}

ContactsLink ContactsLink::fromJson(const QString &json) {
    return ContactsLink::fromMap(QJsonDocument::fromJson(json.toUtf8()).toVariant().toMap());
}

QByteArray ContactsLink::getHash(QCryptographicHash::Algorithm alg) const {
    QByteArray data;
    QDataStream str(&data, QIODevice::WriteOnly);
    str << *this;
    return QCryptographicHash::hash(data, alg);
}

QDataStream &operator<<(QDataStream &stream, const ContactsLink &item) {
    stream << static_cast<uint>(item.classType());
    switch(item.classType()) {
    case ContactsLink::typeContactsLink:
        stream << item.myLink();
        stream << item.foreignLink();
        stream << item.user();
        break;
    }
    return stream;
}

QDataStream &operator>>(QDataStream &stream, ContactsLink &item) {
    uint type = 0;
    stream >> type;
    item.setClassType(static_cast<ContactsLink::ContactsLinkClassType>(type));
    switch(type) {
    case ContactsLink::typeContactsLink: {
        ContactLink m_my_link;
        stream >> m_my_link;
        item.setMyLink(m_my_link);
        ContactLink m_foreign_link;
        stream >> m_foreign_link;
        item.setForeignLink(m_foreign_link);
        User m_user;
        stream >> m_user;
        item.setUser(m_user);
    }
        break;
    }
    return stream;
}

/*QDebug operator<<(QDebug debug,  const ContactsLink &item) {
    QDebugStateSaver saver(debug);
    Q_UNUSED(saver)
    debug.nospace() << "Telegram.ContactsLink(";
    switch(item.classType()) {
    case ContactsLink::typeContactsLink:
        debug.nospace() << "classType: typeContactsLink";
        debug.nospace() << ", myLink: " << item.myLink();
        debug.nospace() << ", foreignLink: " << item.foreignLink();
        debug.nospace() << ", user: " << item.user();
        break;
    }
    debug.nospace() << ")";
    return debug;
}
*/