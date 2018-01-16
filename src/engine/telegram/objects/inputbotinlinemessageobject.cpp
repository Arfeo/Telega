// This file generated by libqtelegram-code-generator.
// You can download it from: https://github.com/Aseman-Land/libqtelegram-code-generator
// DO NOT EDIT THIS FILE BY HAND -- YOUR CHANGES WILL BE OVERWRITTEN

#include "inputbotinlinemessageobject.h"

InputBotInlineMessageObject::InputBotInlineMessageObject(const InputBotInlineMessage &core, QObject *parent) :
    TelegramTypeQObject(parent),
    m_geoPoint(0),
    m_replyMarkup(0),
    m_core(core)
{
    m_geoPoint = new InputGeoPointObject(m_core.geoPoint(), this);
    connect(m_geoPoint.data(), SIGNAL(coreChanged()), this, SLOT(coreGeoPointChanged()));
    m_replyMarkup = new ReplyMarkupObject(m_core.replyMarkup(), this);
    connect(m_replyMarkup.data(), SIGNAL(coreChanged()), this, SLOT(coreReplyMarkupChanged()));
}

InputBotInlineMessageObject::InputBotInlineMessageObject(QObject *parent) :
    TelegramTypeQObject(parent),
    m_geoPoint(0),
    m_replyMarkup(0),
    m_core()
{
    m_geoPoint = new InputGeoPointObject(m_core.geoPoint(), this);
    connect(m_geoPoint.data(), SIGNAL(coreChanged()), this, SLOT(coreGeoPointChanged()));
    m_replyMarkup = new ReplyMarkupObject(m_core.replyMarkup(), this);
    connect(m_replyMarkup.data(), SIGNAL(coreChanged()), this, SLOT(coreReplyMarkupChanged()));
}

InputBotInlineMessageObject::~InputBotInlineMessageObject() {
}

void InputBotInlineMessageObject::setAddress(const QString &address) {
    if(m_core.address() == address) return;
    m_core.setAddress(address);
    Q_EMIT addressChanged();
    Q_EMIT coreChanged();
}

QString InputBotInlineMessageObject::address() const {
    return m_core.address();
}

void InputBotInlineMessageObject::setCaption(const QString &caption) {
    if(m_core.caption() == caption) return;
    m_core.setCaption(caption);
    Q_EMIT captionChanged();
    Q_EMIT coreChanged();
}

QString InputBotInlineMessageObject::caption() const {
    return m_core.caption();
}

void InputBotInlineMessageObject::setEntities(const QList<MessageEntity> &entities) {
    if(m_core.entities() == entities) return;
    m_core.setEntities(entities);
    Q_EMIT entitiesChanged();
    Q_EMIT coreChanged();
}

QList<MessageEntity> InputBotInlineMessageObject::entities() const {
    return m_core.entities();
}

void InputBotInlineMessageObject::setFirstName(const QString &firstName) {
    if(m_core.firstName() == firstName) return;
    m_core.setFirstName(firstName);
    Q_EMIT firstNameChanged();
    Q_EMIT coreChanged();
}

QString InputBotInlineMessageObject::firstName() const {
    return m_core.firstName();
}

void InputBotInlineMessageObject::setFlags(qint32 flags) {
    if(m_core.flags() == flags) return;
    m_core.setFlags(flags);
    Q_EMIT flagsChanged();
    Q_EMIT coreChanged();
}

qint32 InputBotInlineMessageObject::flags() const {
    return m_core.flags();
}

void InputBotInlineMessageObject::setGeoPoint(InputGeoPointObject* geoPoint) {
    if(m_geoPoint == geoPoint) return;
    if(m_geoPoint) delete m_geoPoint;
    m_geoPoint = geoPoint;
    if(m_geoPoint) {
        m_geoPoint->setParent(this);
        m_core.setGeoPoint(m_geoPoint->core());
        connect(m_geoPoint.data(), SIGNAL(coreChanged()), this, SLOT(coreGeoPointChanged()));
    }
    Q_EMIT geoPointChanged();
    Q_EMIT coreChanged();
}

InputGeoPointObject*  InputBotInlineMessageObject::geoPoint() const {
    return m_geoPoint;
}

void InputBotInlineMessageObject::setLastName(const QString &lastName) {
    if(m_core.lastName() == lastName) return;
    m_core.setLastName(lastName);
    Q_EMIT lastNameChanged();
    Q_EMIT coreChanged();
}

QString InputBotInlineMessageObject::lastName() const {
    return m_core.lastName();
}

void InputBotInlineMessageObject::setMessage(const QString &message) {
    if(m_core.message() == message) return;
    m_core.setMessage(message);
    Q_EMIT messageChanged();
    Q_EMIT coreChanged();
}

QString InputBotInlineMessageObject::message() const {
    return m_core.message();
}

void InputBotInlineMessageObject::setNoWebpage(bool noWebpage) {
    if(m_core.noWebpage() == noWebpage) return;
    m_core.setNoWebpage(noWebpage);
    Q_EMIT noWebpageChanged();
    Q_EMIT coreChanged();
}

bool InputBotInlineMessageObject::noWebpage() const {
    return m_core.noWebpage();
}

void InputBotInlineMessageObject::setPhoneNumber(const QString &phoneNumber) {
    if(m_core.phoneNumber() == phoneNumber) return;
    m_core.setPhoneNumber(phoneNumber);
    Q_EMIT phoneNumberChanged();
    Q_EMIT coreChanged();
}

QString InputBotInlineMessageObject::phoneNumber() const {
    return m_core.phoneNumber();
}

void InputBotInlineMessageObject::setProvider(const QString &provider) {
    if(m_core.provider() == provider) return;
    m_core.setProvider(provider);
    Q_EMIT providerChanged();
    Q_EMIT coreChanged();
}

QString InputBotInlineMessageObject::provider() const {
    return m_core.provider();
}

void InputBotInlineMessageObject::setReplyMarkup(ReplyMarkupObject* replyMarkup) {
    if(m_replyMarkup == replyMarkup) return;
    if(m_replyMarkup) delete m_replyMarkup;
    m_replyMarkup = replyMarkup;
    if(m_replyMarkup) {
        m_replyMarkup->setParent(this);
        m_core.setReplyMarkup(m_replyMarkup->core());
        connect(m_replyMarkup.data(), SIGNAL(coreChanged()), this, SLOT(coreReplyMarkupChanged()));
    }
    Q_EMIT replyMarkupChanged();
    Q_EMIT coreChanged();
}

ReplyMarkupObject*  InputBotInlineMessageObject::replyMarkup() const {
    return m_replyMarkup;
}

void InputBotInlineMessageObject::setTitle(const QString &title) {
    if(m_core.title() == title) return;
    m_core.setTitle(title);
    Q_EMIT titleChanged();
    Q_EMIT coreChanged();
}

QString InputBotInlineMessageObject::title() const {
    return m_core.title();
}

void InputBotInlineMessageObject::setVenueId(const QString &venueId) {
    if(m_core.venueId() == venueId) return;
    m_core.setVenueId(venueId);
    Q_EMIT venueIdChanged();
    Q_EMIT coreChanged();
}

QString InputBotInlineMessageObject::venueId() const {
    return m_core.venueId();
}

InputBotInlineMessageObject &InputBotInlineMessageObject::operator =(const InputBotInlineMessage &b) {
    if(m_core == b) return *this;
    m_core = b;
    m_geoPoint->setCore(b.geoPoint());
    m_replyMarkup->setCore(b.replyMarkup());

    Q_EMIT addressChanged();
    Q_EMIT captionChanged();
    Q_EMIT entitiesChanged();
    Q_EMIT firstNameChanged();
    Q_EMIT flagsChanged();
    Q_EMIT geoPointChanged();
    Q_EMIT lastNameChanged();
    Q_EMIT messageChanged();
    Q_EMIT noWebpageChanged();
    Q_EMIT phoneNumberChanged();
    Q_EMIT providerChanged();
    Q_EMIT replyMarkupChanged();
    Q_EMIT titleChanged();
    Q_EMIT venueIdChanged();
    Q_EMIT coreChanged();
    return *this;
}

bool InputBotInlineMessageObject::operator ==(const InputBotInlineMessage &b) const {
    return m_core == b;
}

void InputBotInlineMessageObject::setClassType(quint32 classType) {
    InputBotInlineMessage::InputBotInlineMessageClassType result;
    switch(classType) {
    case TypeInputBotInlineMessageMediaAuto:
        result = InputBotInlineMessage::typeInputBotInlineMessageMediaAuto;
        break;
    case TypeInputBotInlineMessageText:
        result = InputBotInlineMessage::typeInputBotInlineMessageText;
        break;
    case TypeInputBotInlineMessageMediaGeo:
        result = InputBotInlineMessage::typeInputBotInlineMessageMediaGeo;
        break;
    case TypeInputBotInlineMessageMediaVenue:
        result = InputBotInlineMessage::typeInputBotInlineMessageMediaVenue;
        break;
    case TypeInputBotInlineMessageMediaContact:
        result = InputBotInlineMessage::typeInputBotInlineMessageMediaContact;
        break;
    case TypeInputBotInlineMessageGame:
        result = InputBotInlineMessage::typeInputBotInlineMessageGame;
        break;
    default:
        result = InputBotInlineMessage::typeInputBotInlineMessageMediaAuto;
        break;
    }

    if(m_core.classType() == result) return;
    m_core.setClassType(result);
    Q_EMIT classTypeChanged();
    Q_EMIT coreChanged();
}

quint32 InputBotInlineMessageObject::classType() const {
    int result;
    switch(static_cast<qint64>(m_core.classType())) {
    case InputBotInlineMessage::typeInputBotInlineMessageMediaAuto:
        result = TypeInputBotInlineMessageMediaAuto;
        break;
    case InputBotInlineMessage::typeInputBotInlineMessageText:
        result = TypeInputBotInlineMessageText;
        break;
    case InputBotInlineMessage::typeInputBotInlineMessageMediaGeo:
        result = TypeInputBotInlineMessageMediaGeo;
        break;
    case InputBotInlineMessage::typeInputBotInlineMessageMediaVenue:
        result = TypeInputBotInlineMessageMediaVenue;
        break;
    case InputBotInlineMessage::typeInputBotInlineMessageMediaContact:
        result = TypeInputBotInlineMessageMediaContact;
        break;
    case InputBotInlineMessage::typeInputBotInlineMessageGame:
        result = TypeInputBotInlineMessageGame;
        break;
    default:
        result = TypeInputBotInlineMessageMediaAuto;
        break;
    }

    return result;
}

void InputBotInlineMessageObject::setCore(const InputBotInlineMessage &core) {
    operator =(core);
}

InputBotInlineMessage InputBotInlineMessageObject::core() const {
    return m_core;
}

void InputBotInlineMessageObject::coreGeoPointChanged() {
    if(m_core.geoPoint() == m_geoPoint->core()) return;
    m_core.setGeoPoint(m_geoPoint->core());
    Q_EMIT geoPointChanged();
    Q_EMIT coreChanged();
}

void InputBotInlineMessageObject::coreReplyMarkupChanged() {
    if(m_core.replyMarkup() == m_replyMarkup->core()) return;
    m_core.setReplyMarkup(m_replyMarkup->core());
    Q_EMIT replyMarkupChanged();
    Q_EMIT coreChanged();
}

