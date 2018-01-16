// This file generated by libqtelegram-code-generator.
// You can download it from: https://github.com/Aseman-Land/libqtelegram-code-generator
// DO NOT EDIT THIS FILE BY HAND -- YOUR CHANGES WILL BE OVERWRITTEN

#include "inputdocument.h"
#include "core/inboundpkt.h"
#include "core/outboundpkt.h"
#include "../coretypes.h"

#include <QDataStream>

InputDocument::InputDocument(InputDocumentClassType classType, InboundPkt *in) :
    m_accessHash(0),
    m_id(0),
    m_classType(classType)
{
    if(in) fetch(in);
}

InputDocument::InputDocument(InboundPkt *in) :
    m_accessHash(0),
    m_id(0),
    m_classType(typeInputDocumentEmpty)
{
    fetch(in);
}

InputDocument::InputDocument(const InputDocument &another) :
    TelegramTypeObject(),
    m_accessHash(0),
    m_id(0),
    m_classType(typeInputDocumentEmpty)
{
    operator=(another);
}

InputDocument::InputDocument(const Null &null) :
    TelegramTypeObject(null),
    m_accessHash(0),
    m_id(0),
    m_classType(typeInputDocumentEmpty)
{
}

InputDocument::~InputDocument() {

}

void InputDocument::setAccessHash(qint64 accessHash) {
    m_accessHash = accessHash;
}

qint64 InputDocument::accessHash() const {
    return m_accessHash;
}

void InputDocument::setId(qint64 id) {
    m_id = id;
}

qint64 InputDocument::id() const {
    return m_id;
}

bool InputDocument::operator ==(const InputDocument &b) const {
    return m_classType == b.m_classType &&
           m_accessHash == b.m_accessHash &&
           m_id == b.m_id;
}

InputDocument &InputDocument::operator =(const InputDocument &b) {
    m_classType = b.m_classType;
    m_accessHash = b.m_accessHash;
    m_id = b.m_id;
    setNull(b.isNull());
    return *this;
}

void InputDocument::setClassType(InputDocument::InputDocumentClassType classType) {
    m_classType = classType;
}

InputDocument::InputDocumentClassType InputDocument::classType() const {
    return m_classType;
}

bool InputDocument::fetch(InboundPkt *in) {
    LQTG_FETCH_LOG;
    int x = in->fetchInt();
    switch(x) {
    case typeInputDocumentEmpty: {
        m_classType = static_cast<InputDocumentClassType>(x);
        return true;
    }
        break;

    case typeInputDocument: {
        m_id = in->fetchLong();
        m_accessHash = in->fetchLong();
        m_classType = static_cast<InputDocumentClassType>(x);
        return true;
    }
        break;

    default:
        LQTG_FETCH_ASSERT;
        return false;
    }
}

bool InputDocument::push(OutboundPkt *out) const {
    out->appendInt(m_classType);
    switch(m_classType) {
    case typeInputDocumentEmpty: {
        return true;
    }
        break;

    case typeInputDocument: {
        out->appendLong(m_id);
        out->appendLong(m_accessHash);
        return true;
    }
        break;

    default:
        return false;
    }
}

QMap<QString, QVariant> InputDocument::toMap() const {
    QMap<QString, QVariant> result;
    switch(static_cast<int>(m_classType)) {
    case typeInputDocumentEmpty: {
        result["classType"] = "InputDocument::typeInputDocumentEmpty";
        return result;
    }
        break;

    case typeInputDocument: {
        result["classType"] = "InputDocument::typeInputDocument";
        if( id() ) result["id"] = QString::number(id());
        if( accessHash() ) result["accessHash"] = QString::number(accessHash());
        return result;
    }
        break;

    default:
        return result;
    }
}

InputDocument InputDocument::fromMap(const QMap<QString, QVariant> &map) {
    InputDocument result;
    if(map.value("classType").toString() == "InputDocument::typeInputDocumentEmpty") {
        result.setClassType(typeInputDocumentEmpty);
        return result;
    }
    if(map.value("classType").toString() == "InputDocument::typeInputDocument") {
        result.setClassType(typeInputDocument);
        QVariant _id_var = map.value("id");
        if( !_id_var.isNull() ) {
            _id_var.convert( QVariant::nameToType("qint64") );
            result.setId( _id_var.value<qint64>() );
        }

        QVariant _accessHash_var = map.value("accessHash");
        if( !_accessHash_var.isNull() ) {
            _accessHash_var.convert( QVariant::nameToType("qint64") );
            result.setAccessHash( _accessHash_var.value<qint64>() );
        }

        return result;
    }
    return result;
}

InputDocument InputDocument::fromJson(const QString &json) {
    return InputDocument::fromMap(QJsonDocument::fromJson(json.toUtf8()).toVariant().toMap());
}

QByteArray InputDocument::getHash(QCryptographicHash::Algorithm alg) const {
    QByteArray data;
    QDataStream str(&data, QIODevice::WriteOnly);
    str << *this;
    return QCryptographicHash::hash(data, alg);
}

QDataStream &operator<<(QDataStream &stream, const InputDocument &item) {
    stream << static_cast<uint>(item.classType());
    switch(item.classType()) {
    case InputDocument::typeInputDocumentEmpty:

        break;
    case InputDocument::typeInputDocument:
        stream << item.id();
        stream << item.accessHash();
        break;
    }
    return stream;
}

QDataStream &operator>>(QDataStream &stream, InputDocument &item) {
    uint type = 0;
    stream >> type;
    item.setClassType(static_cast<InputDocument::InputDocumentClassType>(type));
    switch(type) {
    case InputDocument::typeInputDocumentEmpty: {

    }
        break;
    case InputDocument::typeInputDocument: {
        qint64 m_id;
        stream >> m_id;
        item.setId(m_id);
        qint64 m_access_hash;
        stream >> m_access_hash;
        item.setAccessHash(m_access_hash);
    }
        break;
    }
    return stream;
}

/*QDebug operator<<(QDebug debug,  const InputDocument &item) {
    QDebugStateSaver saver(debug);
    Q_UNUSED(saver)
    debug.nospace() << "Telegram.InputDocument(";
    switch(item.classType()) {
    case InputDocument::typeInputDocumentEmpty:
        debug.nospace() << "classType: typeInputDocumentEmpty";
        break;
    case InputDocument::typeInputDocument:
        debug.nospace() << "classType: typeInputDocument";
        debug.nospace() << ", id: " << item.id();
        debug.nospace() << ", accessHash: " << item.accessHash();
        break;
    }
    debug.nospace() << ")";
    return debug;
}
*/
