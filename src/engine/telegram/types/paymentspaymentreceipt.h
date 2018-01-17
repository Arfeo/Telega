// This file generated by libqtelegram-code-generator.
// You can download it from: https://github.com/Aseman-Land/libqtelegram-code-generator
// DO NOT EDIT THIS FILE BY HAND -- YOUR CHANGES WILL BE OVERWRITTEN

#ifndef LQTG_TYPE_PAYMENTSPAYMENTRECEIPT
#define LQTG_TYPE_PAYMENTSPAYMENTRECEIPT

#include "telegramtypeobject.h"

#include <QMetaType>
#include <QVariant>
#include "../coretypes.h"

#include <QDataStream>

#include <QtGlobal>
#include <QString>
#include "paymentrequestedinfo.h"
#include "invoice.h"
#include "shippingoption.h"
#include <QList>
#include "user.h"

class LIBQTELEGRAMSHARED_EXPORT PaymentsPaymentReceipt : public TelegramTypeObject
{
public:
    enum PaymentsPaymentReceiptClassType {
        typePaymentsPaymentReceipt = 0x500911e1
    };

    PaymentsPaymentReceipt(PaymentsPaymentReceiptClassType classType = typePaymentsPaymentReceipt, InboundPkt *in = 0);
    PaymentsPaymentReceipt(InboundPkt *in);
    PaymentsPaymentReceipt(const Null&);
    PaymentsPaymentReceipt(const PaymentsPaymentReceipt &another);
    virtual ~PaymentsPaymentReceipt();

    void setBotId(qint32 botId);
    qint32 botId() const;

    void setCredentialsTitle(const QString &credentialsTitle);
    QString credentialsTitle() const;

    void setCurrency(const QString &currency);
    QString currency() const;

    void setDate(qint32 date);
    qint32 date() const;

    void setFlags(qint32 flags);
    qint32 flags() const;

    void setInfo(const PaymentRequestedInfo &info);
    PaymentRequestedInfo info() const;

    void setInvoice(const Invoice &invoice);
    Invoice invoice() const;

    void setProviderId(qint32 providerId);
    qint32 providerId() const;

    void setShipping(const ShippingOption &shipping);
    ShippingOption shipping() const;

    void setTotalAmount(qint64 totalAmount);
    qint64 totalAmount() const;

    void setUsers(const QList<User> &users);
    QList<User> users() const;

    void setClassType(PaymentsPaymentReceiptClassType classType);
    PaymentsPaymentReceiptClassType classType() const;

    bool fetch(InboundPkt *in);
    bool push(OutboundPkt *out) const;

    QMap<QString, QVariant> toMap() const;
    static PaymentsPaymentReceipt fromMap(const QMap<QString, QVariant> &map);
    static PaymentsPaymentReceipt fromJson(const QString &json);

    bool operator ==(const PaymentsPaymentReceipt &b) const;
    PaymentsPaymentReceipt &operator =(const PaymentsPaymentReceipt &b);

    bool operator==(bool stt) const { return isNull() != stt; }
    bool operator!=(bool stt) const { return !operator ==(stt); }

    QByteArray getHash(QCryptographicHash::Algorithm alg = QCryptographicHash::Md5) const;

private:
    qint32 m_botId;
    QString m_credentialsTitle;
    QString m_currency;
    qint32 m_date;
    qint32 m_flags;
    PaymentRequestedInfo m_info;
    Invoice m_invoice;
    qint32 m_providerId;
    ShippingOption m_shipping;
    qint64 m_totalAmount;
    QList<User> m_users;
    PaymentsPaymentReceiptClassType m_classType;
};

Q_DECLARE_METATYPE(PaymentsPaymentReceipt)

QDataStream LIBQTELEGRAMSHARED_EXPORT &operator<<(QDataStream &stream, const PaymentsPaymentReceipt &item);
QDataStream LIBQTELEGRAMSHARED_EXPORT &operator>>(QDataStream &stream, PaymentsPaymentReceipt &item);

QDebug LIBQTELEGRAMSHARED_EXPORT operator<<(QDebug debug,  const PaymentsPaymentReceipt &item);

#endif // LQTG_TYPE_PAYMENTSPAYMENTRECEIPT