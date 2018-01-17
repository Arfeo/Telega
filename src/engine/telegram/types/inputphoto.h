// This file generated by libqtelegram-code-generator.
// You can download it from: https://github.com/Aseman-Land/libqtelegram-code-generator
// DO NOT EDIT THIS FILE BY HAND -- YOUR CHANGES WILL BE OVERWRITTEN

#ifndef LQTG_TYPE_INPUTPHOTO
#define LQTG_TYPE_INPUTPHOTO

#include "telegramtypeobject.h"

#include <QMetaType>
#include <QVariant>
#include "../coretypes.h"

#include <QDataStream>

#include <QtGlobal>

class LIBQTELEGRAMSHARED_EXPORT InputPhoto : public TelegramTypeObject
{
public:
    enum InputPhotoClassType {
        typeInputPhotoEmpty = 0x1cd7bf0d,
        typeInputPhoto = 0xfb95c6c4
    };

    InputPhoto(InputPhotoClassType classType = typeInputPhotoEmpty, InboundPkt *in = 0);
    InputPhoto(InboundPkt *in);
    InputPhoto(const Null&);
    InputPhoto(const InputPhoto &another);
    virtual ~InputPhoto();

    void setAccessHash(qint64 accessHash);
    qint64 accessHash() const;

    void setId(qint64 id);
    qint64 id() const;

    void setClassType(InputPhotoClassType classType);
    InputPhotoClassType classType() const;

    bool fetch(InboundPkt *in);
    bool push(OutboundPkt *out) const;

    QMap<QString, QVariant> toMap() const;
    static InputPhoto fromMap(const QMap<QString, QVariant> &map);
    static InputPhoto fromJson(const QString &json);

    bool operator ==(const InputPhoto &b) const;
    InputPhoto &operator =(const InputPhoto &b);

    bool operator==(bool stt) const { return isNull() != stt; }
    bool operator!=(bool stt) const { return !operator ==(stt); }

    QByteArray getHash(QCryptographicHash::Algorithm alg = QCryptographicHash::Md5) const;

private:
    qint64 m_accessHash;
    qint64 m_id;
    InputPhotoClassType m_classType;
};

Q_DECLARE_METATYPE(InputPhoto)

QDataStream LIBQTELEGRAMSHARED_EXPORT &operator<<(QDataStream &stream, const InputPhoto &item);
QDataStream LIBQTELEGRAMSHARED_EXPORT &operator>>(QDataStream &stream, InputPhoto &item);

QDebug LIBQTELEGRAMSHARED_EXPORT operator<<(QDebug debug,  const InputPhoto &item);

#endif // LQTG_TYPE_INPUTPHOTO