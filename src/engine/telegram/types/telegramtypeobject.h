// This file generated by libqtelegram-code-generator.
// You can download it from: https://github.com/Aseman-Land/libqtelegram-code-generator
// DO NOT EDIT THIS FILE BY HAND -- YOUR CHANGES WILL BE OVERWRITTEN

#ifndef TELEGRAMTYPEOBJECT_H
#define TELEGRAMTYPEOBJECT_H

#define LQTG_FETCH_ASSERT setError(true)
#define LQTG_PUSH_ASSERT setError(true)

#ifndef LQTG_ENABLE_LOG
#define LQTG_FETCH_LOG
#define LQTG_PUSH_LOG
#else
#include <QDebug>
#define LQTG_FETCH_LOG qDebug() << this << __PRETTY_FUNCTION__;
#define LQTG_PUSH_LOG qDebug() << this << __PRETTY_FUNCTION__;
#endif

#include <QCryptographicHash>
#include <QVariant>
#include "libs/QJsonDocument.h"

#include "libqtelegram_global.h"

class InboundPkt;
class OutboundPkt;
class LIBQTELEGRAMSHARED_EXPORT TelegramTypeObject
{
public:
    struct Null { };
    static const Null null;

    TelegramTypeObject();
    TelegramTypeObject(const Null&);
    ~TelegramTypeObject();

    virtual bool fetch(InboundPkt *in) = 0;
    virtual bool push(OutboundPkt *out) const = 0;
    virtual QByteArray getHash(QCryptographicHash::Algorithm alg) const = 0;

    bool error() const { return mError; }
    bool isNull() const { return mNull; }
    bool operator==(bool stt) { return mNull != stt; }
    bool operator!=(bool stt) { return !operator ==(stt); }

    virtual QMap<QString, QVariant> toMap() const = 0;
    QString toJson(QJsonDocument::JsonFormat format = QJsonDocument::Indented) const {
        return QJsonDocument::fromVariant( toMap() ).toJson(format);
    }

    static qint64 constructedCount() {
        return mConstructedCount;
    }

protected:
    void setError(bool stt) { mError = stt; }
    void setNull(bool stt) { mNull = stt; }

private:
    bool mError;
    bool mNull;
    static qint64 mConstructedCount;
};

#endif // TELEGRAMTYPEOBJECT_H