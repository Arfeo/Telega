// This file generated by libqtelegram-code-generator.
// You can download it from: https://github.com/Aseman-Land/libqtelegram-code-generator
// DO NOT EDIT THIS FILE BY HAND -- YOUR CHANGES WILL BE OVERWRITTEN

#include "dialog.h"
#include "core/inboundpkt.h"
#include "core/outboundpkt.h"
#include "../coretypes.h"

#include <QDataStream>

Dialog::Dialog(DialogClassType classType, InboundPkt *in) :
    m_flags(0),
    m_pts(0),
    m_readInboxMaxId(0),
    m_readOutboxMaxId(0),
    m_topMessage(0),
    m_unreadCount(0),
    m_classType(classType)
{
    if(in) fetch(in);
}

Dialog::Dialog(InboundPkt *in) :
    m_flags(0),
    m_pts(0),
    m_readInboxMaxId(0),
    m_readOutboxMaxId(0),
    m_topMessage(0),
    m_unreadCount(0),
    m_classType(typeDialog)
{
    fetch(in);
}

Dialog::Dialog(const Dialog &another) :
    TelegramTypeObject(),
    m_flags(0),
    m_pts(0),
    m_readInboxMaxId(0),
    m_readOutboxMaxId(0),
    m_topMessage(0),
    m_unreadCount(0),
    m_classType(typeDialog)
{
    operator=(another);
}

Dialog::Dialog(const Null &null) :
    TelegramTypeObject(null),
    m_flags(0),
    m_pts(0),
    m_readInboxMaxId(0),
    m_readOutboxMaxId(0),
    m_topMessage(0),
    m_unreadCount(0),
    m_classType(typeDialog)
{
}

Dialog::~Dialog() {

}

void Dialog::setDraft(const DraftMessage &draft) {
    if(!draft.isNull()) m_flags = (m_flags | (1<<1));
    else m_flags = (m_flags & ~(1<<1));
    m_draft = draft;
}

DraftMessage Dialog::draft() const {
    return m_draft;
}

void Dialog::setFlags(qint32 flags) {
    m_flags = flags;
}

qint32 Dialog::flags() const {
    return m_flags;
}

void Dialog::setNotifySettings(const PeerNotifySettings &notifySettings) {
    m_notifySettings = notifySettings;
}

PeerNotifySettings Dialog::notifySettings() const {
    return m_notifySettings;
}

void Dialog::setPeer(const Peer &peer) {
    m_peer = peer;
}

Peer Dialog::peer() const {
    return m_peer;
}

void Dialog::setPinned(bool pinned) {
    if(pinned) m_flags = (m_flags | (1<<2));
    else m_flags = (m_flags & ~(1<<2));
}

bool Dialog::pinned() const {
    return (m_flags & 1<<2);
}

void Dialog::setPts(qint32 pts) {
    if(pts) m_flags = (m_flags | (1<<0));
    else m_flags = (m_flags & ~(1<<0));
    m_pts = pts;
}

qint32 Dialog::pts() const {
    return m_pts;
}

void Dialog::setReadInboxMaxId(qint32 readInboxMaxId) {
    m_readInboxMaxId = readInboxMaxId;
}

qint32 Dialog::readInboxMaxId() const {
    return m_readInboxMaxId;
}

void Dialog::setReadOutboxMaxId(qint32 readOutboxMaxId) {
    m_readOutboxMaxId = readOutboxMaxId;
}

qint32 Dialog::readOutboxMaxId() const {
    return m_readOutboxMaxId;
}

void Dialog::setTopMessage(qint32 topMessage) {
    m_topMessage = topMessage;
}

qint32 Dialog::topMessage() const {
    return m_topMessage;
}

void Dialog::setUnreadCount(qint32 unreadCount) {
    m_unreadCount = unreadCount;
}

qint32 Dialog::unreadCount() const {
    return m_unreadCount;
}

bool Dialog::operator ==(const Dialog &b) const {
    return m_classType == b.m_classType &&
           m_draft == b.m_draft &&
           m_flags == b.m_flags &&
           m_notifySettings == b.m_notifySettings &&
           m_peer == b.m_peer &&
           m_pts == b.m_pts &&
           m_readInboxMaxId == b.m_readInboxMaxId &&
           m_readOutboxMaxId == b.m_readOutboxMaxId &&
           m_topMessage == b.m_topMessage &&
           m_unreadCount == b.m_unreadCount;
}

Dialog &Dialog::operator =(const Dialog &b) {
    m_classType = b.m_classType;
    m_draft = b.m_draft;
    m_flags = b.m_flags;
    m_notifySettings = b.m_notifySettings;
    m_peer = b.m_peer;
    m_pts = b.m_pts;
    m_readInboxMaxId = b.m_readInboxMaxId;
    m_readOutboxMaxId = b.m_readOutboxMaxId;
    m_topMessage = b.m_topMessage;
    m_unreadCount = b.m_unreadCount;
    setNull(b.isNull());
    return *this;
}

void Dialog::setClassType(Dialog::DialogClassType classType) {
    m_classType = classType;
}

Dialog::DialogClassType Dialog::classType() const {
    return m_classType;
}

bool Dialog::fetch(InboundPkt *in) {
    LQTG_FETCH_LOG;
    int x = in->fetchInt();
    switch(x) {
    case typeDialog: {
        m_flags = in->fetchInt();
        m_peer.fetch(in);
        m_topMessage = in->fetchInt();
        m_readInboxMaxId = in->fetchInt();
        m_readOutboxMaxId = in->fetchInt();
        m_unreadCount = in->fetchInt();
        m_notifySettings.fetch(in);
        if(m_flags & 1<<0) {
            m_pts = in->fetchInt();
        }
        if(m_flags & 1<<1) {
            m_draft.fetch(in);
        }
        m_classType = static_cast<DialogClassType>(x);
        return true;
    }
        break;

    default:
        LQTG_FETCH_ASSERT;
        return false;
    }
}

bool Dialog::push(OutboundPkt *out) const {
    out->appendInt(m_classType);
    switch(m_classType) {
    case typeDialog: {
        out->appendInt(m_flags);
        m_peer.push(out);
        out->appendInt(m_topMessage);
        out->appendInt(m_readInboxMaxId);
        out->appendInt(m_readOutboxMaxId);
        out->appendInt(m_unreadCount);
        m_notifySettings.push(out);
        if(m_flags & 1<<0) {
            out->appendInt(m_pts);
        }
        if(m_flags & 1<<1) {
            m_draft.push(out);
        }
        return true;
    }
        break;

    default:
        return false;
    }
}

QMap<QString, QVariant> Dialog::toMap() const {
    QMap<QString, QVariant> result;
    switch(static_cast<int>(m_classType)) {
    case typeDialog: {
        result["classType"] = "Dialog::typeDialog";
        if( pinned() ) result["pinned"] = QString::number(pinned());
        if( !m_peer.isNull() ) result["peer"] = m_peer.toMap();
        if( topMessage() ) result["topMessage"] = QString::number(topMessage());
        if( readInboxMaxId() ) result["readInboxMaxId"] = QString::number(readInboxMaxId());
        if( readOutboxMaxId() ) result["readOutboxMaxId"] = QString::number(readOutboxMaxId());
        if( unreadCount() ) result["unreadCount"] = QString::number(unreadCount());
        if( !m_notifySettings.isNull() ) result["notifySettings"] = m_notifySettings.toMap();
        if( pts() ) result["pts"] = QString::number(pts());
        if( !m_draft.isNull() ) result["draft"] = m_draft.toMap();
        return result;
    }
        break;

    default:
        return result;
    }
}

Dialog Dialog::fromMap(const QMap<QString, QVariant> &map) {
    Dialog result;
    if(map.value("classType").toString() == "Dialog::typeDialog") {
        result.setClassType(typeDialog);
        QVariant _pinned_var = map.value("pinned");
        if( !_pinned_var.isNull() ) {
            _pinned_var.convert( QVariant::nameToType("bool") );
            result.setPinned( _pinned_var.value<bool>() );
        }

        QVariant _peer_var = map.value("peer");
        if( !_peer_var.isNull() )
            result.setPeer( Peer::fromMap(_peer_var.toMap()) );

        QVariant _topMessage_var = map.value("topMessage");
        if( !_topMessage_var.isNull() ) {
            _topMessage_var.convert( QVariant::nameToType("qint32") );
            result.setTopMessage( _topMessage_var.value<qint32>() );
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

        QVariant _notifySettings_var = map.value("notifySettings");
        if( !_notifySettings_var.isNull() )
            result.setNotifySettings( PeerNotifySettings::fromMap(_notifySettings_var.toMap()) );

        QVariant _pts_var = map.value("pts");
        if( !_pts_var.isNull() ) {
            _pts_var.convert( QVariant::nameToType("qint32") );
            result.setPts( _pts_var.value<qint32>() );
        }

        QVariant _draft_var = map.value("draft");
        if( !_draft_var.isNull() )
            result.setDraft( DraftMessage::fromMap(_draft_var.toMap()) );

        return result;
    }
    return result;
}

Dialog Dialog::fromJson(const QString &json) {
    return Dialog::fromMap(QJsonDocument::fromJson(json.toUtf8()).toVariant().toMap());
}

QByteArray Dialog::getHash(QCryptographicHash::Algorithm alg) const {
    QByteArray data;
    QDataStream str(&data, QIODevice::WriteOnly);
    str << *this;
    return QCryptographicHash::hash(data, alg);
}

QDataStream &operator<<(QDataStream &stream, const Dialog &item) {
    stream << static_cast<uint>(item.classType());
    switch(item.classType()) {
    case Dialog::typeDialog:
        stream << item.flags();
        stream << item.peer();
        stream << item.topMessage();
        stream << item.readInboxMaxId();
        stream << item.readOutboxMaxId();
        stream << item.unreadCount();
        stream << item.notifySettings();
        stream << item.pts();
        stream << item.draft();
        break;
    }
    return stream;
}

QDataStream &operator>>(QDataStream &stream, Dialog &item) {
    uint type = 0;
    stream >> type;
    item.setClassType(static_cast<Dialog::DialogClassType>(type));
    switch(type) {
    case Dialog::typeDialog: {
        qint32 m_flags;
        stream >> m_flags;
        item.setFlags(m_flags);
        Peer m_peer;
        stream >> m_peer;
        item.setPeer(m_peer);
        qint32 m_top_message;
        stream >> m_top_message;
        item.setTopMessage(m_top_message);
        qint32 m_read_inbox_max_id;
        stream >> m_read_inbox_max_id;
        item.setReadInboxMaxId(m_read_inbox_max_id);
        qint32 m_read_outbox_max_id;
        stream >> m_read_outbox_max_id;
        item.setReadOutboxMaxId(m_read_outbox_max_id);
        qint32 m_unread_count;
        stream >> m_unread_count;
        item.setUnreadCount(m_unread_count);
        PeerNotifySettings m_notify_settings;
        stream >> m_notify_settings;
        item.setNotifySettings(m_notify_settings);
        qint32 m_pts;
        stream >> m_pts;
        item.setPts(m_pts);
        DraftMessage m_draft;
        stream >> m_draft;
        item.setDraft(m_draft);
    }
        break;
    }
    return stream;
}

/*QDebug operator<<(QDebug debug,  const Dialog &item) {
    QDebugStateSaver saver(debug);
    Q_UNUSED(saver)
    debug.nospace() << "Telegram.Dialog(";
    switch(item.classType()) {
    case Dialog::typeDialog:
        debug.nospace() << "classType: typeDialog";
        debug.nospace() << ", flags: " << item.flags();
        debug.nospace() << ", peer: " << item.peer();
        debug.nospace() << ", topMessage: " << item.topMessage();
        debug.nospace() << ", readInboxMaxId: " << item.readInboxMaxId();
        debug.nospace() << ", readOutboxMaxId: " << item.readOutboxMaxId();
        debug.nospace() << ", unreadCount: " << item.unreadCount();
        debug.nospace() << ", notifySettings: " << item.notifySettings();
        debug.nospace() << ", pts: " << item.pts();
        debug.nospace() << ", draft: " << item.draft();
        break;
    }
    debug.nospace() << ")";
    return debug;
}
*/
