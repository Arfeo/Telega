// This file generated by libqtelegram-code-generator.
// You can download it from: https://github.com/Aseman-Land/libqtelegram-code-generator
// DO NOT EDIT THIS FILE BY HAND -- YOUR CHANGES WILL BE OVERWRITTEN

#ifndef LQTG_TYPE_INPUTPHONECALL
#define LQTG_TYPE_INPUTPHONECALL

#include "telegramtypeobject.h"

#include <QMetaType>
#include <QVariant>
#include "../coretypes.h"

#include <QDataStream>

#include <QtGlobal>

class LIBQTELEGRAMSHARED_EXPORT InputPhoneCall : public TelegramTypeObject
{
public:
    enum InputPhoneCallClassType {
        typeInputPhoneCall = 0x1e36fded
    };

    InputPhoneCall(InputPhoneCallClassType classType = typeInputPhoneCall, InboundPkt *in = 0);
    InputPhoneCall(InboundPkt *in);
    InputPhoneCall(const Null&);
    InputPhoneCall(const InputPhoneCall &another);
    virtual ~InputPhoneCall();

    void setAccessHash(qint64 accessHash);
    qint64 accessHash() const;

    void setId(qint64 id);
    qint64 id() const;

    void setClassType(InputPhoneCallClassType classType);
    InputPhoneCallClassType classType() const;

    bool fetch(InboundPkt *in);
    bool push(OutboundPkt *out) const;

    QMap<QString, QVariant> toMap() const;
    static InputPhoneCall fromMap(const QMap<QString, QVariant> &map);
    static InputPhoneCall fromJson(const QString &json);

    bool operator ==(const InputPhoneCall &b) const;
    InputPhoneCall &operator =(const InputPhoneCall &b);

    bool operator==(bool stt) const { return isNull() != stt; }
    bool operator!=(bool stt) const { return !operator ==(stt); }

    QByteArray getHash(QCryptographicHash::Algorithm alg = QCryptographicHash::Md5) const;

private:
    qint64 m_accessHash;
    qint64 m_id;
    InputPhoneCallClassType m_classType;
};

Q_DECLARE_METATYPE(InputPhoneCall)

QDataStream LIBQTELEGRAMSHARED_EXPORT &operator<<(QDataStream &stream, const InputPhoneCall &item);
QDataStream LIBQTELEGRAMSHARED_EXPORT &operator>>(QDataStream &stream, InputPhoneCall &item);

QDebug LIBQTELEGRAMSHARED_EXPORT operator<<(QDebug debug,  const InputPhoneCall &item);

#endif // LQTG_TYPE_INPUTPHONECALL