// This file generated by libqtelegram-code-generator.
// You can download it from: https://github.com/Aseman-Land/libqtelegram-code-generator
// DO NOT EDIT THIS FILE BY HAND -- YOUR CHANGES WILL BE OVERWRITTEN

#include "shippingoption.h"
#include "core/inboundpkt.h"
#include "core/outboundpkt.h"
#include "../coretypes.h"

#include <QDataStream>

ShippingOption::ShippingOption(ShippingOptionClassType classType, InboundPkt *in) :
    m_classType(classType)
{
    if(in) fetch(in);
}

ShippingOption::ShippingOption(InboundPkt *in) :
    m_classType(typeShippingOption)
{
    fetch(in);
}

ShippingOption::ShippingOption(const ShippingOption &another) :
    TelegramTypeObject(),
    m_classType(typeShippingOption)
{
    operator=(another);
}

ShippingOption::ShippingOption(const Null &null) :
    TelegramTypeObject(null),
    m_classType(typeShippingOption)
{
}

ShippingOption::~ShippingOption() {

}

void ShippingOption::setId(const QString &id) {
    m_id = id;
}

QString ShippingOption::id() const {
    return m_id;
}

void ShippingOption::setPrices(const QList<LabeledPrice> &prices) {
    m_prices = prices;
}

QList<LabeledPrice> ShippingOption::prices() const {
    return m_prices;
}

void ShippingOption::setTitle(const QString &title) {
    m_title = title;
}

QString ShippingOption::title() const {
    return m_title;
}

bool ShippingOption::operator ==(const ShippingOption &b) const {
    return m_classType == b.m_classType &&
           m_id == b.m_id &&
           m_prices == b.m_prices &&
           m_title == b.m_title;
}

ShippingOption &ShippingOption::operator =(const ShippingOption &b) {
    m_classType = b.m_classType;
    m_id = b.m_id;
    m_prices = b.m_prices;
    m_title = b.m_title;
    setNull(b.isNull());
    return *this;
}

void ShippingOption::setClassType(ShippingOption::ShippingOptionClassType classType) {
    m_classType = classType;
}

ShippingOption::ShippingOptionClassType ShippingOption::classType() const {
    return m_classType;
}

bool ShippingOption::fetch(InboundPkt *in) {
    LQTG_FETCH_LOG;
    int x = in->fetchInt();
    switch(x) {
    case typeShippingOption: {
        m_id = in->fetchQString();
        m_title = in->fetchQString();
        if(in->fetchInt() != (qint32)CoreTypes::typeVector) return false;
        qint32 m_prices_length = in->fetchInt();
        m_prices.clear();
        for (qint32 i = 0; i < m_prices_length; i++) {
            LabeledPrice type;
            type.fetch(in);
            m_prices.append(type);
        }
        m_classType = static_cast<ShippingOptionClassType>(x);
        return true;
    }
        break;

    default:
        LQTG_FETCH_ASSERT;
        return false;
    }
}

bool ShippingOption::push(OutboundPkt *out) const {
    out->appendInt(m_classType);
    switch(m_classType) {
    case typeShippingOption: {
        out->appendQString(m_id);
        out->appendQString(m_title);
        out->appendInt(CoreTypes::typeVector);
        out->appendInt(m_prices.count());
        for (qint32 i = 0; i < m_prices.count(); i++) {
            m_prices[i].push(out);
        }
        return true;
    }
        break;

    default:
        return false;
    }
}

QMap<QString, QVariant> ShippingOption::toMap() const {
    QMap<QString, QVariant> result;
    switch(static_cast<int>(m_classType)) {
    case typeShippingOption: {
        result["classType"] = "ShippingOption::typeShippingOption";
        if( !m_id.isEmpty() ) result["id"] = QVariant::fromValue<QString>(m_id);
        if( !m_title.isEmpty() ) result["title"] = QVariant::fromValue<QString>(m_title);
        QList<QVariant> _prices;
        //for(const LabeledPrice &m__type: m_prices)
        for(int i = 0; i < m_prices.size(); ++i) {
            const LabeledPrice &m__type = m_prices[i];
            if( !m__type.isNull() ) _prices << m__type.toMap();
        }
        result["prices"] = _prices;
        return result;
    }
        break;

    default:
        return result;
    }
}

ShippingOption ShippingOption::fromMap(const QMap<QString, QVariant> &map) {
    ShippingOption result;
    if(map.value("classType").toString() == "ShippingOption::typeShippingOption") {
        result.setClassType(typeShippingOption);
        QVariant _id_var = map.value("id");
        if( !_id_var.isNull() ) {
            _id_var.convert( QVariant::nameToType("QString") );
            result.setId( _id_var.value<QString>() );
        }

        QVariant _title_var = map.value("title");
        if( !_title_var.isNull() ) {
            _title_var.convert( QVariant::nameToType("QString") );
            result.setTitle( _title_var.value<QString>() );
        }

        QList<QVariant> map_prices = map["prices"].toList();
        QList<LabeledPrice> _prices;
        //for(const QVariant &var: map_prices)
        for(int i = 0; i < map_prices.size(); ++i) {
            const QVariant &var = map_prices[i];
            _prices << LabeledPrice::fromMap(var.toMap());
        }
        result.setPrices(_prices);
        return result;
    }
    return result;
}

ShippingOption ShippingOption::fromJson(const QString &json) {
    return ShippingOption::fromMap(QJsonDocument::fromJson(json.toUtf8()).toVariant().toMap());
}

QByteArray ShippingOption::getHash(QCryptographicHash::Algorithm alg) const {
    QByteArray data;
    QDataStream str(&data, QIODevice::WriteOnly);
    str << *this;
    return QCryptographicHash::hash(data, alg);
}

QDataStream &operator<<(QDataStream &stream, const ShippingOption &item) {
    stream << static_cast<uint>(item.classType());
    switch(item.classType()) {
    case ShippingOption::typeShippingOption:
        stream << item.id();
        stream << item.title();
        stream << item.prices();
        break;
    }
    return stream;
}

QDataStream &operator>>(QDataStream &stream, ShippingOption &item) {
    uint type = 0;
    stream >> type;
    item.setClassType(static_cast<ShippingOption::ShippingOptionClassType>(type));
    switch(type) {
    case ShippingOption::typeShippingOption: {
        QString m_id;
        stream >> m_id;
        item.setId(m_id);
        QString m_title;
        stream >> m_title;
        item.setTitle(m_title);
        QList<LabeledPrice> m_prices;
        stream >> m_prices;
        item.setPrices(m_prices);
    }
        break;
    }
    return stream;
}

/*QDebug operator<<(QDebug debug,  const ShippingOption &item) {
    QDebugStateSaver saver(debug);
    Q_UNUSED(saver)
    debug.nospace() << "Telegram.ShippingOption(";
    switch(item.classType()) {
    case ShippingOption::typeShippingOption:
        debug.nospace() << "classType: typeShippingOption";
        debug.nospace() << ", id: " << item.id();
        debug.nospace() << ", title: " << item.title();
        debug.nospace() << ", prices: " << item.prices();
        break;
    }
    debug.nospace() << ")";
    return debug;
}
*/