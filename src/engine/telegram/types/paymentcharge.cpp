// This file generated by libqtelegram-code-generator.
// You can download it from: https://github.com/Aseman-Land/libqtelegram-code-generator
// DO NOT EDIT THIS FILE BY HAND -- YOUR CHANGES WILL BE OVERWRITTEN

#include "paymentcharge.h"
#include "core/inboundpkt.h"
#include "core/outboundpkt.h"
#include "../coretypes.h"

#include <QDataStream>

PaymentCharge::PaymentCharge(PaymentChargeClassType classType, InboundPkt *in) :
    m_classType(classType)
{
    if(in) fetch(in);
}

PaymentCharge::PaymentCharge(InboundPkt *in) :
    m_classType(typePaymentCharge)
{
    fetch(in);
}

PaymentCharge::PaymentCharge(const PaymentCharge &another) :
    TelegramTypeObject(),
    m_classType(typePaymentCharge)
{
    operator=(another);
}

PaymentCharge::PaymentCharge(const Null &null) :
    TelegramTypeObject(null),
    m_classType(typePaymentCharge)
{
}

PaymentCharge::~PaymentCharge() {

}

void PaymentCharge::setId(const QString &id) {
    m_id = id;
}

QString PaymentCharge::id() const {
    return m_id;
}

void PaymentCharge::setProviderChargeId(const QString &providerChargeId) {
    m_providerChargeId = providerChargeId;
}

QString PaymentCharge::providerChargeId() const {
    return m_providerChargeId;
}

bool PaymentCharge::operator ==(const PaymentCharge &b) const {
    return m_classType == b.m_classType &&
           m_id == b.m_id &&
           m_providerChargeId == b.m_providerChargeId;
}

PaymentCharge &PaymentCharge::operator =(const PaymentCharge &b) {
    m_classType = b.m_classType;
    m_id = b.m_id;
    m_providerChargeId = b.m_providerChargeId;
    setNull(b.isNull());
    return *this;
}

void PaymentCharge::setClassType(PaymentCharge::PaymentChargeClassType classType) {
    m_classType = classType;
}

PaymentCharge::PaymentChargeClassType PaymentCharge::classType() const {
    return m_classType;
}

bool PaymentCharge::fetch(InboundPkt *in) {
    LQTG_FETCH_LOG;
    int x = in->fetchInt();
    switch(x) {
    case typePaymentCharge: {
        m_id = in->fetchQString();
        m_providerChargeId = in->fetchQString();
        m_classType = static_cast<PaymentChargeClassType>(x);
        return true;
    }
        break;

    default:
        LQTG_FETCH_ASSERT;
        return false;
    }
}

bool PaymentCharge::push(OutboundPkt *out) const {
    out->appendInt(m_classType);
    switch(m_classType) {
    case typePaymentCharge: {
        out->appendQString(m_id);
        out->appendQString(m_providerChargeId);
        return true;
    }
        break;

    default:
        return false;
    }
}

QMap<QString, QVariant> PaymentCharge::toMap() const {
    QMap<QString, QVariant> result;
    switch(static_cast<int>(m_classType)) {
    case typePaymentCharge: {
        result["classType"] = "PaymentCharge::typePaymentCharge";
        if( !m_id.isEmpty() ) result["id"] = QVariant::fromValue<QString>(m_id);
        if( !m_providerChargeId.isEmpty() ) result["providerChargeId"] = QVariant::fromValue<QString>(m_providerChargeId);
        return result;
    }
        break;

    default:
        return result;
    }
}

PaymentCharge PaymentCharge::fromMap(const QMap<QString, QVariant> &map) {
    PaymentCharge result;
    if(map.value("classType").toString() == "PaymentCharge::typePaymentCharge") {
        result.setClassType(typePaymentCharge);
        QVariant _id_var = map.value("id");
        if( !_id_var.isNull() ) {
            _id_var.convert( QVariant::nameToType("QString") );
            result.setId( _id_var.value<QString>() );
        }

        QVariant _providerChargeId_var = map.value("providerChargeId");
        if( !_providerChargeId_var.isNull() ) {
            _providerChargeId_var.convert( QVariant::nameToType("QString") );
            result.setProviderChargeId( _providerChargeId_var.value<QString>() );
        }

        return result;
    }
    return result;
}

PaymentCharge PaymentCharge::fromJson(const QString &json) {
    return PaymentCharge::fromMap(QJsonDocument::fromJson(json.toUtf8()).toVariant().toMap());
}

QByteArray PaymentCharge::getHash(QCryptographicHash::Algorithm alg) const {
    QByteArray data;
    QDataStream str(&data, QIODevice::WriteOnly);
    str << *this;
    return QCryptographicHash::hash(data, alg);
}

QDataStream &operator<<(QDataStream &stream, const PaymentCharge &item) {
    stream << static_cast<uint>(item.classType());
    switch(item.classType()) {
    case PaymentCharge::typePaymentCharge:
        stream << item.id();
        stream << item.providerChargeId();
        break;
    }
    return stream;
}

QDataStream &operator>>(QDataStream &stream, PaymentCharge &item) {
    uint type = 0;
    stream >> type;
    item.setClassType(static_cast<PaymentCharge::PaymentChargeClassType>(type));
    switch(type) {
    case PaymentCharge::typePaymentCharge: {
        QString m_id;
        stream >> m_id;
        item.setId(m_id);
        QString m_provider_charge_id;
        stream >> m_provider_charge_id;
        item.setProviderChargeId(m_provider_charge_id);
    }
        break;
    }
    return stream;
}

/*QDebug operator<<(QDebug debug,  const PaymentCharge &item) {
    QDebugStateSaver saver(debug);
    Q_UNUSED(saver)
    debug.nospace() << "Telegram.PaymentCharge(";
    switch(item.classType()) {
    case PaymentCharge::typePaymentCharge:
        debug.nospace() << "classType: typePaymentCharge";
        debug.nospace() << ", id: " << item.id();
        debug.nospace() << ", providerChargeId: " << item.providerChargeId();
        break;
    }
    debug.nospace() << ")";
    return debug;
}
*/