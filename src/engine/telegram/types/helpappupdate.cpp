// This file generated by libqtelegram-code-generator.
// You can download it from: https://github.com/Aseman-Land/libqtelegram-code-generator
// DO NOT EDIT THIS FILE BY HAND -- YOUR CHANGES WILL BE OVERWRITTEN

#include "helpappupdate.h"
#include "core/inboundpkt.h"
#include "core/outboundpkt.h"
#include "../coretypes.h"

#include <QDataStream>

HelpAppUpdate::HelpAppUpdate(HelpAppUpdateClassType classType, InboundPkt *in) :
    m_critical(false),
    m_id(0),
    m_classType(classType)
{
    if(in) fetch(in);
}

HelpAppUpdate::HelpAppUpdate(InboundPkt *in) :
    m_critical(false),
    m_id(0),
    m_classType(typeHelpAppUpdate)
{
    fetch(in);
}

HelpAppUpdate::HelpAppUpdate(const HelpAppUpdate &another) :
    TelegramTypeObject(),
    m_critical(false),
    m_id(0),
    m_classType(typeHelpAppUpdate)
{
    operator=(another);
}

HelpAppUpdate::HelpAppUpdate(const Null &null) :
    TelegramTypeObject(null),
    m_critical(false),
    m_id(0),
    m_classType(typeHelpAppUpdate)
{
}

HelpAppUpdate::~HelpAppUpdate() {

}

void HelpAppUpdate::setCritical(bool critical) {
    m_critical = critical;
}

bool HelpAppUpdate::critical() const {
    return m_critical;
}

void HelpAppUpdate::setId(qint32 id) {
    m_id = id;
}

qint32 HelpAppUpdate::id() const {
    return m_id;
}

void HelpAppUpdate::setText(const QString &text) {
    m_text = text;
}

QString HelpAppUpdate::text() const {
    return m_text;
}

void HelpAppUpdate::setUrl(const QString &url) {
    m_url = url;
}

QString HelpAppUpdate::url() const {
    return m_url;
}

bool HelpAppUpdate::operator ==(const HelpAppUpdate &b) const {
    return m_classType == b.m_classType &&
           m_critical == b.m_critical &&
           m_id == b.m_id &&
           m_text == b.m_text &&
           m_url == b.m_url;
}

HelpAppUpdate &HelpAppUpdate::operator =(const HelpAppUpdate &b) {
    m_classType = b.m_classType;
    m_critical = b.m_critical;
    m_id = b.m_id;
    m_text = b.m_text;
    m_url = b.m_url;
    setNull(b.isNull());
    return *this;
}

void HelpAppUpdate::setClassType(HelpAppUpdate::HelpAppUpdateClassType classType) {
    m_classType = classType;
}

HelpAppUpdate::HelpAppUpdateClassType HelpAppUpdate::classType() const {
    return m_classType;
}

bool HelpAppUpdate::fetch(InboundPkt *in) {
    LQTG_FETCH_LOG;
    int x = in->fetchInt();
    switch(x) {
    case typeHelpAppUpdate: {
        m_id = in->fetchInt();
        m_critical = in->fetchBool();
        m_url = in->fetchQString();
        m_text = in->fetchQString();
        m_classType = static_cast<HelpAppUpdateClassType>(x);
        return true;
    }
        break;

    case typeHelpNoAppUpdate: {
        m_classType = static_cast<HelpAppUpdateClassType>(x);
        return true;
    }
        break;

    default:
        LQTG_FETCH_ASSERT;
        return false;
    }
}

bool HelpAppUpdate::push(OutboundPkt *out) const {
    out->appendInt(m_classType);
    switch(m_classType) {
    case typeHelpAppUpdate: {
        out->appendInt(m_id);
        out->appendBool(m_critical);
        out->appendQString(m_url);
        out->appendQString(m_text);
        return true;
    }
        break;

    case typeHelpNoAppUpdate: {
        return true;
    }
        break;

    default:
        return false;
    }
}

QMap<QString, QVariant> HelpAppUpdate::toMap() const {
    QMap<QString, QVariant> result;
    switch(static_cast<int>(m_classType)) {
    case typeHelpAppUpdate: {
        result["classType"] = "HelpAppUpdate::typeHelpAppUpdate";
        if( id() ) result["id"] = QString::number(id());
        if( critical() ) result["critical"] = QString::number(critical());
        if( !m_url.isEmpty() ) result["url"] = QVariant::fromValue<QString>(m_url);
        if( !m_text.isEmpty() ) result["text"] = QVariant::fromValue<QString>(m_text);
        return result;
    }
        break;

    case typeHelpNoAppUpdate: {
        result["classType"] = "HelpAppUpdate::typeHelpNoAppUpdate";
        return result;
    }
        break;

    default:
        return result;
    }
}

HelpAppUpdate HelpAppUpdate::fromMap(const QMap<QString, QVariant> &map) {
    HelpAppUpdate result;
    if(map.value("classType").toString() == "HelpAppUpdate::typeHelpAppUpdate") {
        result.setClassType(typeHelpAppUpdate);
        QVariant _id_var = map.value("id");
        if( !_id_var.isNull() ) {
            _id_var.convert( QVariant::nameToType("qint32") );
            result.setId( _id_var.value<qint32>() );
        }

        QVariant _critical_var = map.value("critical");
        if( !_critical_var.isNull() ) {
            _critical_var.convert( QVariant::nameToType("bool") );
            result.setCritical( _critical_var.value<bool>() );
        }

        QVariant _url_var = map.value("url");
        if( !_url_var.isNull() ) {
            _url_var.convert( QVariant::nameToType("QString") );
            result.setUrl( _url_var.value<QString>() );
        }

        QVariant _text_var = map.value("text");
        if( !_text_var.isNull() ) {
            _text_var.convert( QVariant::nameToType("QString") );
            result.setText( _text_var.value<QString>() );
        }

        return result;
    }
    if(map.value("classType").toString() == "HelpAppUpdate::typeHelpNoAppUpdate") {
        result.setClassType(typeHelpNoAppUpdate);
        return result;
    }
    return result;
}

HelpAppUpdate HelpAppUpdate::fromJson(const QString &json) {
    return HelpAppUpdate::fromMap(QJsonDocument::fromJson(json.toUtf8()).toVariant().toMap());
}

QByteArray HelpAppUpdate::getHash(QCryptographicHash::Algorithm alg) const {
    QByteArray data;
    QDataStream str(&data, QIODevice::WriteOnly);
    str << *this;
    return QCryptographicHash::hash(data, alg);
}

QDataStream &operator<<(QDataStream &stream, const HelpAppUpdate &item) {
    stream << static_cast<uint>(item.classType());
    switch(item.classType()) {
    case HelpAppUpdate::typeHelpAppUpdate:
        stream << item.id();
        stream << item.critical();
        stream << item.url();
        stream << item.text();
        break;
    case HelpAppUpdate::typeHelpNoAppUpdate:

        break;
    }
    return stream;
}

QDataStream &operator>>(QDataStream &stream, HelpAppUpdate &item) {
    uint type = 0;
    stream >> type;
    item.setClassType(static_cast<HelpAppUpdate::HelpAppUpdateClassType>(type));
    switch(type) {
    case HelpAppUpdate::typeHelpAppUpdate: {
        qint32 m_id;
        stream >> m_id;
        item.setId(m_id);
        bool m_critical;
        stream >> m_critical;
        item.setCritical(m_critical);
        QString m_url;
        stream >> m_url;
        item.setUrl(m_url);
        QString m_text;
        stream >> m_text;
        item.setText(m_text);
    }
        break;
    case HelpAppUpdate::typeHelpNoAppUpdate: {

    }
        break;
    }
    return stream;
}

/*QDebug operator<<(QDebug debug,  const HelpAppUpdate &item) {
    QDebugStateSaver saver(debug);
    Q_UNUSED(saver)
    debug.nospace() << "Telegram.HelpAppUpdate(";
    switch(item.classType()) {
    case HelpAppUpdate::typeHelpAppUpdate:
        debug.nospace() << "classType: typeHelpAppUpdate";
        debug.nospace() << ", id: " << item.id();
        debug.nospace() << ", critical: " << item.critical();
        debug.nospace() << ", url: " << item.url();
        debug.nospace() << ", text: " << item.text();
        break;
    case HelpAppUpdate::typeHelpNoAppUpdate:
        debug.nospace() << "classType: typeHelpNoAppUpdate";
        break;
    }
    debug.nospace() << ")";
    return debug;
}
*/
