// This file generated by libqtelegram-code-generator.
// You can download it from: https://github.com/Aseman-Land/libqtelegram-code-generator
// DO NOT EDIT THIS FILE BY HAND -- YOUR CHANGES WILL BE OVERWRITTEN

#include "chatfull.h"
#include "core/inboundpkt.h"
#include "core/outboundpkt.h"
#include "../coretypes.h"

#include <QDataStream>

ChatFull::ChatFull(ChatFullClassType classType, InboundPkt *in) :
    m_adminsCount(0),
    m_bannedCount(0),
    m_flags(0),
    m_id(0),
    m_kickedCount(0),
    m_migratedFromChatId(0),
    m_migratedFromMaxId(0),
    m_participantsCount(0),
    m_pinnedMsgId(0),
    m_readInboxMaxId(0),
    m_readOutboxMaxId(0),
    m_unreadCount(0),
    m_classType(classType)
{
    if(in) fetch(in);
}

ChatFull::ChatFull(InboundPkt *in) :
    m_adminsCount(0),
    m_bannedCount(0),
    m_flags(0),
    m_id(0),
    m_kickedCount(0),
    m_migratedFromChatId(0),
    m_migratedFromMaxId(0),
    m_participantsCount(0),
    m_pinnedMsgId(0),
    m_readInboxMaxId(0),
    m_readOutboxMaxId(0),
    m_unreadCount(0),
    m_classType(typeChatFull)
{
    fetch(in);
}

ChatFull::ChatFull(const ChatFull &another) :
    TelegramTypeObject(),
    m_adminsCount(0),
    m_bannedCount(0),
    m_flags(0),
    m_id(0),
    m_kickedCount(0),
    m_migratedFromChatId(0),
    m_migratedFromMaxId(0),
    m_participantsCount(0),
    m_pinnedMsgId(0),
    m_readInboxMaxId(0),
    m_readOutboxMaxId(0),
    m_unreadCount(0),
    m_classType(typeChatFull)
{
    operator=(another);
}

ChatFull::ChatFull(const Null &null) :
    TelegramTypeObject(null),
    m_adminsCount(0),
    m_bannedCount(0),
    m_flags(0),
    m_id(0),
    m_kickedCount(0),
    m_migratedFromChatId(0),
    m_migratedFromMaxId(0),
    m_participantsCount(0),
    m_pinnedMsgId(0),
    m_readInboxMaxId(0),
    m_readOutboxMaxId(0),
    m_unreadCount(0),
    m_classType(typeChatFull)
{
}

ChatFull::~ChatFull() {

}

void ChatFull::setAbout(const QString &about) {
    m_about = about;
}

QString ChatFull::about() const {
    return m_about;
}

void ChatFull::setAdminsCount(qint32 adminsCount) {
    if(adminsCount) m_flags = (m_flags | (1<<1));
    else m_flags = (m_flags & ~(1<<1));
    m_adminsCount = adminsCount;
}

qint32 ChatFull::adminsCount() const {
    return m_adminsCount;
}

void ChatFull::setBannedCount(qint32 bannedCount) {
    if(bannedCount) m_flags = (m_flags | (1<<2));
    else m_flags = (m_flags & ~(1<<2));
    m_bannedCount = bannedCount;
}

qint32 ChatFull::bannedCount() const {
    return m_bannedCount;
}

void ChatFull::setBotInfo(const QList<BotInfo> &botInfo) {
    m_botInfo = botInfo;
}

QList<BotInfo> ChatFull::botInfo() const {
    return m_botInfo;
}

void ChatFull::setCanSetUsername(bool canSetUsername) {
    if(canSetUsername) m_flags = (m_flags | (1<<6));
    else m_flags = (m_flags & ~(1<<6));
}

bool ChatFull::canSetUsername() const {
    return (m_flags & 1<<6);
}

void ChatFull::setCanViewParticipants(bool canViewParticipants) {
    if(canViewParticipants) m_flags = (m_flags | (1<<3));
    else m_flags = (m_flags & ~(1<<3));
}

bool ChatFull::canViewParticipants() const {
    return (m_flags & 1<<3);
}

void ChatFull::setChatPhoto(const Photo &chatPhoto) {
    m_chatPhoto = chatPhoto;
}

Photo ChatFull::chatPhoto() const {
    return m_chatPhoto;
}

void ChatFull::setExportedInvite(const ExportedChatInvite &exportedInvite) {
    m_exportedInvite = exportedInvite;
}

ExportedChatInvite ChatFull::exportedInvite() const {
    return m_exportedInvite;
}

void ChatFull::setFlags(qint32 flags) {
    m_flags = flags;
}

qint32 ChatFull::flags() const {
    return m_flags;
}

void ChatFull::setId(qint32 id) {
    m_id = id;
}

qint32 ChatFull::id() const {
    return m_id;
}

void ChatFull::setKickedCount(qint32 kickedCount) {
    if(kickedCount) m_flags = (m_flags | (1<<2));
    else m_flags = (m_flags & ~(1<<2));
    m_kickedCount = kickedCount;
}

qint32 ChatFull::kickedCount() const {
    return m_kickedCount;
}

void ChatFull::setMigratedFromChatId(qint32 migratedFromChatId) {
    if(migratedFromChatId) m_flags = (m_flags | (1<<4));
    else m_flags = (m_flags & ~(1<<4));
    m_migratedFromChatId = migratedFromChatId;
}

qint32 ChatFull::migratedFromChatId() const {
    return m_migratedFromChatId;
}

void ChatFull::setMigratedFromMaxId(qint32 migratedFromMaxId) {
    if(migratedFromMaxId) m_flags = (m_flags | (1<<4));
    else m_flags = (m_flags & ~(1<<4));
    m_migratedFromMaxId = migratedFromMaxId;
}

qint32 ChatFull::migratedFromMaxId() const {
    return m_migratedFromMaxId;
}

void ChatFull::setNotifySettings(const PeerNotifySettings &notifySettings) {
    m_notifySettings = notifySettings;
}

PeerNotifySettings ChatFull::notifySettings() const {
    return m_notifySettings;
}

void ChatFull::setParticipants(const ChatParticipants &participants) {
    m_participants = participants;
}

ChatParticipants ChatFull::participants() const {
    return m_participants;
}

void ChatFull::setParticipantsCount(qint32 participantsCount) {
    if(participantsCount) m_flags = (m_flags | (1<<0));
    else m_flags = (m_flags & ~(1<<0));
    m_participantsCount = participantsCount;
}

qint32 ChatFull::participantsCount() const {
    return m_participantsCount;
}

void ChatFull::setPinnedMsgId(qint32 pinnedMsgId) {
    if(pinnedMsgId) m_flags = (m_flags | (1<<5));
    else m_flags = (m_flags & ~(1<<5));
    m_pinnedMsgId = pinnedMsgId;
}

qint32 ChatFull::pinnedMsgId() const {
    return m_pinnedMsgId;
}

void ChatFull::setReadInboxMaxId(qint32 readInboxMaxId) {
    m_readInboxMaxId = readInboxMaxId;
}

qint32 ChatFull::readInboxMaxId() const {
    return m_readInboxMaxId;
}

void ChatFull::setReadOutboxMaxId(qint32 readOutboxMaxId) {
    m_readOutboxMaxId = readOutboxMaxId;
}

qint32 ChatFull::readOutboxMaxId() const {
    return m_readOutboxMaxId;
}

void ChatFull::setUnreadCount(qint32 unreadCount) {
    m_unreadCount = unreadCount;
}

qint32 ChatFull::unreadCount() const {
    return m_unreadCount;
}

bool ChatFull::operator ==(const ChatFull &b) const {
    return m_classType == b.m_classType &&
           m_about == b.m_about &&
           m_adminsCount == b.m_adminsCount &&
           m_bannedCount == b.m_bannedCount &&
           m_botInfo == b.m_botInfo &&
           m_chatPhoto == b.m_chatPhoto &&
           m_exportedInvite == b.m_exportedInvite &&
           m_flags == b.m_flags &&
           m_id == b.m_id &&
           m_kickedCount == b.m_kickedCount &&
           m_migratedFromChatId == b.m_migratedFromChatId &&
           m_migratedFromMaxId == b.m_migratedFromMaxId &&
           m_notifySettings == b.m_notifySettings &&
           m_participants == b.m_participants &&
           m_participantsCount == b.m_participantsCount &&
           m_pinnedMsgId == b.m_pinnedMsgId &&
           m_readInboxMaxId == b.m_readInboxMaxId &&
           m_readOutboxMaxId == b.m_readOutboxMaxId &&
           m_unreadCount == b.m_unreadCount;
}

ChatFull &ChatFull::operator =(const ChatFull &b) {
    m_classType = b.m_classType;
    m_about = b.m_about;
    m_adminsCount = b.m_adminsCount;
    m_bannedCount = b.m_bannedCount;
    m_botInfo = b.m_botInfo;
    m_chatPhoto = b.m_chatPhoto;
    m_exportedInvite = b.m_exportedInvite;
    m_flags = b.m_flags;
    m_id = b.m_id;
    m_kickedCount = b.m_kickedCount;
    m_migratedFromChatId = b.m_migratedFromChatId;
    m_migratedFromMaxId = b.m_migratedFromMaxId;
    m_notifySettings = b.m_notifySettings;
    m_participants = b.m_participants;
    m_participantsCount = b.m_participantsCount;
    m_pinnedMsgId = b.m_pinnedMsgId;
    m_readInboxMaxId = b.m_readInboxMaxId;
    m_readOutboxMaxId = b.m_readOutboxMaxId;
    m_unreadCount = b.m_unreadCount;
    setNull(b.isNull());
    return *this;
}

void ChatFull::setClassType(ChatFull::ChatFullClassType classType) {
    m_classType = classType;
}

ChatFull::ChatFullClassType ChatFull::classType() const {
    return m_classType;
}

bool ChatFull::fetch(InboundPkt *in) {
    LQTG_FETCH_LOG;
    int x = in->fetchInt();
    switch(x) {
    case typeChatFull: {
        m_id = in->fetchInt();
        m_participants.fetch(in);
        m_chatPhoto.fetch(in);
        m_notifySettings.fetch(in);
        m_exportedInvite.fetch(in);
        if(in->fetchInt() != (qint32)CoreTypes::typeVector) return false;
        qint32 m_botInfo_length = in->fetchInt();
        m_botInfo.clear();
        for (qint32 i = 0; i < m_botInfo_length; i++) {
            BotInfo type;
            type.fetch(in);
            m_botInfo.append(type);
        }
        m_classType = static_cast<ChatFullClassType>(x);
        return true;
    }
        break;

    case typeChannelFull: {
        m_flags = in->fetchInt();
        m_id = in->fetchInt();
        m_about = in->fetchQString();
        if(m_flags & 1<<0) {
            m_participantsCount = in->fetchInt();
        }
        if(m_flags & 1<<1) {
            m_adminsCount = in->fetchInt();
        }
        if(m_flags & 1<<2) {
            m_kickedCount = in->fetchInt();
        }
        if(m_flags & 1<<2) {
            m_bannedCount = in->fetchInt();
        }
        m_readInboxMaxId = in->fetchInt();
        m_readOutboxMaxId = in->fetchInt();
        m_unreadCount = in->fetchInt();
        m_chatPhoto.fetch(in);
        m_notifySettings.fetch(in);
        m_exportedInvite.fetch(in);
        if(in->fetchInt() != (qint32)CoreTypes::typeVector) return false;
        qint32 m_botInfo_length = in->fetchInt();
        m_botInfo.clear();
        for (qint32 i = 0; i < m_botInfo_length; i++) {
            BotInfo type;
            type.fetch(in);
            m_botInfo.append(type);
        }
        if(m_flags & 1<<4) {
            m_migratedFromChatId = in->fetchInt();
        }
        if(m_flags & 1<<4) {
            m_migratedFromMaxId = in->fetchInt();
        }
        if(m_flags & 1<<5) {
            m_pinnedMsgId = in->fetchInt();
        }
        m_classType = static_cast<ChatFullClassType>(x);
        return true;
    }
        break;

    default:
        LQTG_FETCH_ASSERT;
        return false;
    }
}

bool ChatFull::push(OutboundPkt *out) const {
    out->appendInt(m_classType);
    switch(m_classType) {
    case typeChatFull: {
        out->appendInt(m_id);
        m_participants.push(out);
        m_chatPhoto.push(out);
        m_notifySettings.push(out);
        m_exportedInvite.push(out);
        out->appendInt(CoreTypes::typeVector);
        out->appendInt(m_botInfo.count());
        for (qint32 i = 0; i < m_botInfo.count(); i++) {
            m_botInfo[i].push(out);
        }
        return true;
    }
        break;

    case typeChannelFull: {
        out->appendInt(m_flags);
        out->appendInt(m_id);
        out->appendQString(m_about);
        if(m_flags & 1<<0) {
            out->appendInt(m_participantsCount);
        }
        if(m_flags & 1<<1) {
            out->appendInt(m_adminsCount);
        }
        if(m_flags & 1<<2) {
            out->appendInt(m_kickedCount);
        }
        if(m_flags & 1<<2) {
            out->appendInt(m_bannedCount);
        }
        out->appendInt(m_readInboxMaxId);
        out->appendInt(m_readOutboxMaxId);
        out->appendInt(m_unreadCount);
        m_chatPhoto.push(out);
        m_notifySettings.push(out);
        m_exportedInvite.push(out);
        out->appendInt(CoreTypes::typeVector);
        out->appendInt(m_botInfo.count());
        for (qint32 i = 0; i < m_botInfo.count(); i++) {
            m_botInfo[i].push(out);
        }
        if(m_flags & 1<<4) {
            out->appendInt(m_migratedFromChatId);
        }
        if(m_flags & 1<<4) {
            out->appendInt(m_migratedFromMaxId);
        }
        if(m_flags & 1<<5) {
            out->appendInt(m_pinnedMsgId);
        }
        return true;
    }
        break;

    default:
        return false;
    }
}

QMap<QString, QVariant> ChatFull::toMap() const {
    QMap<QString, QVariant> result;
    switch(static_cast<int>(m_classType)) {
    case typeChatFull: {
        result["classType"] = "ChatFull::typeChatFull";
        if( id() ) result["id"] = QString::number(id());
        if( !m_participants.isNull() ) result["participants"] = m_participants.toMap();
        if( !m_chatPhoto.isNull() ) result["chatPhoto"] = m_chatPhoto.toMap();
        if( !m_notifySettings.isNull() ) result["notifySettings"] = m_notifySettings.toMap();
        if( !m_exportedInvite.isNull() ) result["exportedInvite"] = m_exportedInvite.toMap();
        QList<QVariant> _botInfo;
        for(const BotInfo &m__type: m_botInfo)
            if( !m__type.isNull() ) _botInfo << m__type.toMap();
        result["botInfo"] = _botInfo;
        return result;
    }
        break;

    case typeChannelFull: {
        result["classType"] = "ChatFull::typeChannelFull";
        if( canViewParticipants() ) result["canViewParticipants"] = QString::number(canViewParticipants());
        if( canSetUsername() ) result["canSetUsername"] = QString::number(canSetUsername());
        if( id() ) result["id"] = QString::number(id());
        if( !m_about.isEmpty() ) result["about"] = QVariant::fromValue<QString>(m_about);
        if( participantsCount() ) result["participantsCount"] = QString::number(participantsCount());
        if( adminsCount() ) result["adminsCount"] = QString::number(adminsCount());
        if( kickedCount() ) result["kickedCount"] = QString::number(kickedCount());
        if( bannedCount() ) result["bannedCount"] = QString::number(bannedCount());
        if( readInboxMaxId() ) result["readInboxMaxId"] = QString::number(readInboxMaxId());
        if( readOutboxMaxId() ) result["readOutboxMaxId"] = QString::number(readOutboxMaxId());
        if( unreadCount() ) result["unreadCount"] = QString::number(unreadCount());
        if( !m_chatPhoto.isNull() ) result["chatPhoto"] = m_chatPhoto.toMap();
        if( !m_notifySettings.isNull() ) result["notifySettings"] = m_notifySettings.toMap();
        if( !m_exportedInvite.isNull() ) result["exportedInvite"] = m_exportedInvite.toMap();
        QList<QVariant> _botInfo;
        for(const BotInfo &m__type: m_botInfo)
            if( !m__type.isNull() ) _botInfo << m__type.toMap();
        result["botInfo"] = _botInfo;
        if( migratedFromChatId() ) result["migratedFromChatId"] = QString::number(migratedFromChatId());
        if( migratedFromMaxId() ) result["migratedFromMaxId"] = QString::number(migratedFromMaxId());
        if( pinnedMsgId() ) result["pinnedMsgId"] = QString::number(pinnedMsgId());
        return result;
    }
        break;

    default:
        return result;
    }
}

ChatFull ChatFull::fromMap(const QMap<QString, QVariant> &map) {
    ChatFull result;
    if(map.value("classType").toString() == "ChatFull::typeChatFull") {
        result.setClassType(typeChatFull);
        QVariant _id_var = map.value("id");
        if( !_id_var.isNull() ) {
            _id_var.convert( QVariant::nameToType("qint32") );
            result.setId( _id_var.value<qint32>() );
        }

        QVariant _participants_var = map.value("participants");
        if( !_participants_var.isNull() )
            result.setParticipants( ChatParticipants::fromMap(_participants_var.toMap()) );

        QVariant _chatPhoto_var = map.value("chatPhoto");
        if( !_chatPhoto_var.isNull() )
            result.setChatPhoto( Photo::fromMap(_chatPhoto_var.toMap()) );

        QVariant _notifySettings_var = map.value("notifySettings");
        if( !_notifySettings_var.isNull() )
            result.setNotifySettings( PeerNotifySettings::fromMap(_notifySettings_var.toMap()) );

        QVariant _exportedInvite_var = map.value("exportedInvite");
        if( !_exportedInvite_var.isNull() )
            result.setExportedInvite( ExportedChatInvite::fromMap(_exportedInvite_var.toMap()) );

        QList<QVariant> map_botInfo = map["botInfo"].toList();
        QList<BotInfo> _botInfo;
        for(const QVariant &var: map_botInfo)
            _botInfo << BotInfo::fromMap(var.toMap());
        result.setBotInfo(_botInfo);
        return result;
    }
    if(map.value("classType").toString() == "ChatFull::typeChannelFull") {
        result.setClassType(typeChannelFull);
        QVariant _canViewParticipants_var = map.value("canViewParticipants");
        if( !_canViewParticipants_var.isNull() ) {
            _canViewParticipants_var.convert( QVariant::nameToType("bool") );
            result.setCanViewParticipants( _canViewParticipants_var.value<bool>() );
        }

        QVariant _canSetUsername_var = map.value("canSetUsername");
        if( !_canSetUsername_var.isNull() ) {
            _canSetUsername_var.convert( QVariant::nameToType("bool") );
            result.setCanSetUsername( _canSetUsername_var.value<bool>() );
        }

        QVariant _id_var = map.value("id");
        if( !_id_var.isNull() ) {
            _id_var.convert( QVariant::nameToType("qint32") );
            result.setId( _id_var.value<qint32>() );
        }

        QVariant _about_var = map.value("about");
        if( !_about_var.isNull() ) {
            _about_var.convert( QVariant::nameToType("QString") );
            result.setAbout( _about_var.value<QString>() );
        }

        QVariant _participantsCount_var = map.value("participantsCount");
        if( !_participantsCount_var.isNull() ) {
            _participantsCount_var.convert( QVariant::nameToType("qint32") );
            result.setParticipantsCount( _participantsCount_var.value<qint32>() );
        }

        QVariant _adminsCount_var = map.value("adminsCount");
        if( !_adminsCount_var.isNull() ) {
            _adminsCount_var.convert( QVariant::nameToType("qint32") );
            result.setAdminsCount( _adminsCount_var.value<qint32>() );
        }

        QVariant _kickedCount_var = map.value("kickedCount");
        if( !_kickedCount_var.isNull() ) {
            _kickedCount_var.convert( QVariant::nameToType("qint32") );
            result.setKickedCount( _kickedCount_var.value<qint32>() );
        }

        QVariant _bannedCount_var = map.value("bannedCount");
        if( !_bannedCount_var.isNull() ) {
            _bannedCount_var.convert( QVariant::nameToType("qint32") );
            result.setBannedCount( _bannedCount_var.value<qint32>() );
        }

        QVariant _readInboxMaxId_var = map.value("readInboxMaxId");
        if( !_readInboxMaxId_var.isNull() ) {
            _readInboxMaxId_var.convert( QVariant::nameToType("qint32") );
            result.setReadInboxMaxId( _readInboxMaxId_var.value<qint32>() );
        }

        QVariant _readOutboxMaxId_var = map.value("readOutboxMaxId");
        if( !_readOutboxMaxId_var.isNull() ) {
            _readOutboxMaxId_var.convert( QVariant::nameToType("qint32") );
            result.setReadOutboxMaxId( _readOutboxMaxId_var.value<qint32>() );
        }

        QVariant _unreadCount_var = map.value("unreadCount");
        if( !_unreadCount_var.isNull() ) {
            _unreadCount_var.convert( QVariant::nameToType("qint32") );
            result.setUnreadCount( _unreadCount_var.value<qint32>() );
        }

        QVariant _chatPhoto_var = map.value("chatPhoto");
        if( !_chatPhoto_var.isNull() )
            result.setChatPhoto( Photo::fromMap(_chatPhoto_var.toMap()) );

        QVariant _notifySettings_var = map.value("notifySettings");
        if( !_notifySettings_var.isNull() )
            result.setNotifySettings( PeerNotifySettings::fromMap(_notifySettings_var.toMap()) );

        QVariant _exportedInvite_var = map.value("exportedInvite");
        if( !_exportedInvite_var.isNull() )
            result.setExportedInvite( ExportedChatInvite::fromMap(_exportedInvite_var.toMap()) );

        QList<QVariant> map_botInfo = map["botInfo"].toList();
        QList<BotInfo> _botInfo;
        for(const QVariant &var: map_botInfo)
            _botInfo << BotInfo::fromMap(var.toMap());
        result.setBotInfo(_botInfo);
        QVariant _migratedFromChatId_var = map.value("migratedFromChatId");
        if( !_migratedFromChatId_var.isNull() ) {
            _migratedFromChatId_var.convert( QVariant::nameToType("qint32") );
            result.setMigratedFromChatId( _migratedFromChatId_var.value<qint32>() );
        }

        QVariant _migratedFromMaxId_var = map.value("migratedFromMaxId");
        if( !_migratedFromMaxId_var.isNull() ) {
            _migratedFromMaxId_var.convert( QVariant::nameToType("qint32") );
            result.setMigratedFromMaxId( _migratedFromMaxId_var.value<qint32>() );
        }

        QVariant _pinnedMsgId_var = map.value("pinnedMsgId");
        if( !_pinnedMsgId_var.isNull() ) {
            _pinnedMsgId_var.convert( QVariant::nameToType("qint32") );
            result.setPinnedMsgId( _pinnedMsgId_var.value<qint32>() );
        }

        return result;
    }
    return result;
}

ChatFull ChatFull::fromJson(const QString &json) {
    return ChatFull::fromMap(QJsonDocument::fromJson(json.toUtf8()).toVariant().toMap());
}

QByteArray ChatFull::getHash(QCryptographicHash::Algorithm alg) const {
    QByteArray data;
    QDataStream str(&data, QIODevice::WriteOnly);
    str << *this;
    return QCryptographicHash::hash(data, alg);
}

QDataStream &operator<<(QDataStream &stream, const ChatFull &item) {
    stream << static_cast<uint>(item.classType());
    switch(item.classType()) {
    case ChatFull::typeChatFull:
        stream << item.id();
        stream << item.participants();
        stream << item.chatPhoto();
        stream << item.notifySettings();
        stream << item.exportedInvite();
        stream << item.botInfo();
        break;
    case ChatFull::typeChannelFull:
        stream << item.flags();
        stream << item.id();
        stream << item.about();
        stream << item.participantsCount();
        stream << item.adminsCount();
        stream << item.kickedCount();
        stream << item.bannedCount();
        stream << item.readInboxMaxId();
        stream << item.readOutboxMaxId();
        stream << item.unreadCount();
        stream << item.chatPhoto();
        stream << item.notifySettings();
        stream << item.exportedInvite();
        stream << item.botInfo();
        stream << item.migratedFromChatId();
        stream << item.migratedFromMaxId();
        stream << item.pinnedMsgId();
        break;
    }
    return stream;
}

QDataStream &operator>>(QDataStream &stream, ChatFull &item) {
    uint type = 0;
    stream >> type;
    item.setClassType(static_cast<ChatFull::ChatFullClassType>(type));
    switch(type) {
    case ChatFull::typeChatFull: {
        qint32 m_id;
        stream >> m_id;
        item.setId(m_id);
        ChatParticipants m_participants;
        stream >> m_participants;
        item.setParticipants(m_participants);
        Photo m_chat_photo;
        stream >> m_chat_photo;
        item.setChatPhoto(m_chat_photo);
        PeerNotifySettings m_notify_settings;
        stream >> m_notify_settings;
        item.setNotifySettings(m_notify_settings);
        ExportedChatInvite m_exported_invite;
        stream >> m_exported_invite;
        item.setExportedInvite(m_exported_invite);
        QList<BotInfo> m_bot_info;
        stream >> m_bot_info;
        item.setBotInfo(m_bot_info);
    }
        break;
    case ChatFull::typeChannelFull: {
        qint32 m_flags;
        stream >> m_flags;
        item.setFlags(m_flags);
        qint32 m_id;
        stream >> m_id;
        item.setId(m_id);
        QString m_about;
        stream >> m_about;
        item.setAbout(m_about);
        qint32 m_participants_count;
        stream >> m_participants_count;
        item.setParticipantsCount(m_participants_count);
        qint32 m_admins_count;
        stream >> m_admins_count;
        item.setAdminsCount(m_admins_count);
        qint32 m_kicked_count;
        stream >> m_kicked_count;
        item.setKickedCount(m_kicked_count);
        qint32 m_banned_count;
        stream >> m_banned_count;
        item.setBannedCount(m_banned_count);
        qint32 m_read_inbox_max_id;
        stream >> m_read_inbox_max_id;
        item.setReadInboxMaxId(m_read_inbox_max_id);
        qint32 m_read_outbox_max_id;
        stream >> m_read_outbox_max_id;
        item.setReadOutboxMaxId(m_read_outbox_max_id);
        qint32 m_unread_count;
        stream >> m_unread_count;
        item.setUnreadCount(m_unread_count);
        Photo m_chat_photo;
        stream >> m_chat_photo;
        item.setChatPhoto(m_chat_photo);
        PeerNotifySettings m_notify_settings;
        stream >> m_notify_settings;
        item.setNotifySettings(m_notify_settings);
        ExportedChatInvite m_exported_invite;
        stream >> m_exported_invite;
        item.setExportedInvite(m_exported_invite);
        QList<BotInfo> m_bot_info;
        stream >> m_bot_info;
        item.setBotInfo(m_bot_info);
        qint32 m_migrated_from_chat_id;
        stream >> m_migrated_from_chat_id;
        item.setMigratedFromChatId(m_migrated_from_chat_id);
        qint32 m_migrated_from_max_id;
        stream >> m_migrated_from_max_id;
        item.setMigratedFromMaxId(m_migrated_from_max_id);
        qint32 m_pinned_msg_id;
        stream >> m_pinned_msg_id;
        item.setPinnedMsgId(m_pinned_msg_id);
    }
        break;
    }
    return stream;
}

/*QDebug operator<<(QDebug debug,  const ChatFull &item) {
    QDebugStateSaver saver(debug);
    Q_UNUSED(saver)
    debug.nospace() << "Telegram.ChatFull(";
    switch(item.classType()) {
    case ChatFull::typeChatFull:
        debug.nospace() << "classType: typeChatFull";
        debug.nospace() << ", id: " << item.id();
        debug.nospace() << ", participants: " << item.participants();
        debug.nospace() << ", chatPhoto: " << item.chatPhoto();
        debug.nospace() << ", notifySettings: " << item.notifySettings();
        debug.nospace() << ", exportedInvite: " << item.exportedInvite();
        debug.nospace() << ", botInfo: " << item.botInfo();
        break;
    case ChatFull::typeChannelFull:
        debug.nospace() << "classType: typeChannelFull";
        debug.nospace() << ", flags: " << item.flags();
        debug.nospace() << ", id: " << item.id();
        debug.nospace() << ", about: " << item.about();
        debug.nospace() << ", participantsCount: " << item.participantsCount();
        debug.nospace() << ", adminsCount: " << item.adminsCount();
        debug.nospace() << ", kickedCount: " << item.kickedCount();
        debug.nospace() << ", bannedCount: " << item.bannedCount();
        debug.nospace() << ", readInboxMaxId: " << item.readInboxMaxId();
        debug.nospace() << ", readOutboxMaxId: " << item.readOutboxMaxId();
        debug.nospace() << ", unreadCount: " << item.unreadCount();
        debug.nospace() << ", chatPhoto: " << item.chatPhoto();
        debug.nospace() << ", notifySettings: " << item.notifySettings();
        debug.nospace() << ", exportedInvite: " << item.exportedInvite();
        debug.nospace() << ", botInfo: " << item.botInfo();
        debug.nospace() << ", migratedFromChatId: " << item.migratedFromChatId();
        debug.nospace() << ", migratedFromMaxId: " << item.migratedFromMaxId();
        debug.nospace() << ", pinnedMsgId: " << item.pinnedMsgId();
        break;
    }
    debug.nospace() << ")";
    return debug;
}
*/
