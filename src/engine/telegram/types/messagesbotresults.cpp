// This file generated by libqtelegram-code-generator.
// You can download it from: https://github.com/Aseman-Land/libqtelegram-code-generator
// DO NOT EDIT THIS FILE BY HAND -- YOUR CHANGES WILL BE OVERWRITTEN

#include "messagesbotresults.h"
#include "core/inboundpkt.h"
#include "core/outboundpkt.h"
#include "../coretypes.h"

#include <QDataStream>

MessagesBotResults::MessagesBotResults(MessagesBotResultsClassType classType, InboundPkt *in) :
    m_cacheTime(0),
    m_flags(0),
    m_queryId(0),
    m_classType(classType)
{
    if(in) fetch(in);
}

MessagesBotResults::MessagesBotResults(InboundPkt *in) :
    m_cacheTime(0),
    m_flags(0),
    m_queryId(0),
    m_classType(typeMessagesBotResults)
{
    fetch(in);
}

MessagesBotResults::MessagesBotResults(const MessagesBotResults &another) :
    TelegramTypeObject(),
    m_cacheTime(0),
    m_flags(0),
    m_queryId(0),
    m_classType(typeMessagesBotResults)
{
    operator=(another);
}

MessagesBotResults::MessagesBotResults(const Null &null) :
    TelegramTypeObject(null),
    m_cacheTime(0),
    m_flags(0),
    m_queryId(0),
    m_classType(typeMessagesBotResults)
{
}

MessagesBotResults::~MessagesBotResults() {

}

void MessagesBotResults::setCacheTime(qint32 cacheTime) {
    m_cacheTime = cacheTime;
}

qint32 MessagesBotResults::cacheTime() const {
    return m_cacheTime;
}

void MessagesBotResults::setFlags(qint32 flags) {
    m_flags = flags;
}

qint32 MessagesBotResults::flags() const {
    return m_flags;
}

void MessagesBotResults::setGallery(bool gallery) {
    if(gallery) m_flags = (m_flags | (1<<0));
    else m_flags = (m_flags & ~(1<<0));
}

bool MessagesBotResults::gallery() const {
    return (m_flags & 1<<0);
}

void MessagesBotResults::setNextOffset(const QString &nextOffset) {
    if(!nextOffset.isNull()) m_flags = (m_flags | (1<<1));
    else m_flags = (m_flags & ~(1<<1));
    m_nextOffset = nextOffset;
}

QString MessagesBotResults::nextOffset() const {
    return m_nextOffset;
}

void MessagesBotResults::setQueryId(qint64 queryId) {
    m_queryId = queryId;
}

qint64 MessagesBotResults::queryId() const {
    return m_queryId;
}

void MessagesBotResults::setResults(const QList<BotInlineResult> &results) {
    m_results = results;
}

QList<BotInlineResult> MessagesBotResults::results() const {
    return m_results;
}

void MessagesBotResults::setSwitchPm(const InlineBotSwitchPM &switchPm) {
    if(!switchPm.isNull()) m_flags = (m_flags | (1<<2));
    else m_flags = (m_flags & ~(1<<2));
    m_switchPm = switchPm;
}

InlineBotSwitchPM MessagesBotResults::switchPm() const {
    return m_switchPm;
}

bool MessagesBotResults::operator ==(const MessagesBotResults &b) const {
    return m_classType == b.m_classType &&
           m_cacheTime == b.m_cacheTime &&
           m_flags == b.m_flags &&
           m_nextOffset == b.m_nextOffset &&
           m_queryId == b.m_queryId &&
           m_results == b.m_results &&
           m_switchPm == b.m_switchPm;
}

MessagesBotResults &MessagesBotResults::operator =(const MessagesBotResults &b) {
    m_classType = b.m_classType;
    m_cacheTime = b.m_cacheTime;
    m_flags = b.m_flags;
    m_nextOffset = b.m_nextOffset;
    m_queryId = b.m_queryId;
    m_results = b.m_results;
    m_switchPm = b.m_switchPm;
    setNull(b.isNull());
    return *this;
}

void MessagesBotResults::setClassType(MessagesBotResults::MessagesBotResultsClassType classType) {
    m_classType = classType;
}

MessagesBotResults::MessagesBotResultsClassType MessagesBotResults::classType() const {
    return m_classType;
}

bool MessagesBotResults::fetch(InboundPkt *in) {
    LQTG_FETCH_LOG;
    int x = in->fetchInt();
    switch(x) {
    case typeMessagesBotResults: {
        m_flags = in->fetchInt();
        m_queryId = in->fetchLong();
        if(m_flags & 1<<1) {
            m_nextOffset = in->fetchQString();
        }
        if(m_flags & 1<<2) {
            m_switchPm.fetch(in);
        }
        if(in->fetchInt() != (qint32)CoreTypes::typeVector) return false;
        qint32 m_results_length = in->fetchInt();
        m_results.clear();
        for (qint32 i = 0; i < m_results_length; i++) {
            BotInlineResult type;
            type.fetch(in);
            m_results.append(type);
        }
        m_cacheTime = in->fetchInt();
        m_classType = static_cast<MessagesBotResultsClassType>(x);
        return true;
    }
        break;

    default:
        LQTG_FETCH_ASSERT;
        return false;
    }
}

bool MessagesBotResults::push(OutboundPkt *out) const {
    out->appendInt(m_classType);
    switch(m_classType) {
    case typeMessagesBotResults: {
        out->appendInt(m_flags);
        out->appendLong(m_queryId);
        if(m_flags & 1<<1) {
            out->appendQString(m_nextOffset);
        }
        if(m_flags & 1<<2) {
            m_switchPm.push(out);
        }
        out->appendInt(CoreTypes::typeVector);
        out->appendInt(m_results.count());
        for (qint32 i = 0; i < m_results.count(); i++) {
            m_results[i].push(out);
        }
        out->appendInt(m_cacheTime);
        return true;
    }
        break;

    default:
        return false;
    }
}

QMap<QString, QVariant> MessagesBotResults::toMap() const {
    QMap<QString, QVariant> result;
    switch(static_cast<int>(m_classType)) {
    case typeMessagesBotResults: {
        result["classType"] = "MessagesBotResults::typeMessagesBotResults";
        if( gallery() ) result["gallery"] = QString::number(gallery());
        if( queryId() ) result["queryId"] = QString::number(queryId());
        if( !m_nextOffset.isEmpty() ) result["nextOffset"] = QVariant::fromValue<QString>(m_nextOffset);
        if( !m_switchPm.isNull() ) result["switchPm"] = m_switchPm.toMap();
        QList<QVariant> _results;
        //for(const BotInlineResult &m__type: m_results)
        for(int i = 0; i < m_results.size(); ++i) {
            const BotInlineResult &m__type = m_results[i];
            if( !m__type.isNull() ) _results << m__type.toMap();
        }
        result["results"] = _results;
        if( cacheTime() ) result["cacheTime"] = QString::number(cacheTime());
        return result;
    }
        break;

    default:
        return result;
    }
}

MessagesBotResults MessagesBotResults::fromMap(const QMap<QString, QVariant> &map) {
    MessagesBotResults result;
    if(map.value("classType").toString() == "MessagesBotResults::typeMessagesBotResults") {
        result.setClassType(typeMessagesBotResults);
        QVariant _gallery_var = map.value("gallery");
        if( !_gallery_var.isNull() ) {
            _gallery_var.convert( QVariant::nameToType("bool") );
            result.setGallery( _gallery_var.value<bool>() );
        }

        QVariant _queryId_var = map.value("queryId");
        if( !_queryId_var.isNull() ) {
            _queryId_var.convert( QVariant::nameToType("qint64") );
            result.setQueryId( _queryId_var.value<qint64>() );
        }

        QVariant _nextOffset_var = map.value("nextOffset");
        if( !_nextOffset_var.isNull() ) {
            _nextOffset_var.convert( QVariant::nameToType("QString") );
            result.setNextOffset( _nextOffset_var.value<QString>() );
        }

        QVariant _switchPm_var = map.value("switchPm");
        if( !_switchPm_var.isNull() )
            result.setSwitchPm( InlineBotSwitchPM::fromMap(_switchPm_var.toMap()) );

        QList<QVariant> map_results = map["results"].toList();
        QList<BotInlineResult> _results;
        //for(const QVariant &var: map_results)
        for(int i = 0; i < map_results.size(); ++i) {
            const QVariant &var = map_results[i];
            _results << BotInlineResult::fromMap(var.toMap());
        }
        result.setResults(_results);
        QVariant _cacheTime_var = map.value("cacheTime");
        if( !_cacheTime_var.isNull() ) {
            _cacheTime_var.convert( QVariant::nameToType("qint32") );
            result.setCacheTime( _cacheTime_var.value<qint32>() );
        }

        return result;
    }
    return result;
}

MessagesBotResults MessagesBotResults::fromJson(const QString &json) {
    return MessagesBotResults::fromMap(QJsonDocument::fromJson(json.toUtf8()).toVariant().toMap());
}

QByteArray MessagesBotResults::getHash(QCryptographicHash::Algorithm alg) const {
    QByteArray data;
    QDataStream str(&data, QIODevice::WriteOnly);
    str << *this;
    return QCryptographicHash::hash(data, alg);
}

QDataStream &operator<<(QDataStream &stream, const MessagesBotResults &item) {
    stream << static_cast<uint>(item.classType());
    switch(item.classType()) {
    case MessagesBotResults::typeMessagesBotResults:
        stream << item.flags();
        stream << item.queryId();
        stream << item.nextOffset();
        stream << item.switchPm();
        stream << item.results();
        stream << item.cacheTime();
        break;
    }
    return stream;
}

QDataStream &operator>>(QDataStream &stream, MessagesBotResults &item) {
    uint type = 0;
    stream >> type;
    item.setClassType(static_cast<MessagesBotResults::MessagesBotResultsClassType>(type));
    switch(type) {
    case MessagesBotResults::typeMessagesBotResults: {
        qint32 m_flags;
        stream >> m_flags;
        item.setFlags(m_flags);
        qint64 m_query_id;
        stream >> m_query_id;
        item.setQueryId(m_query_id);
        QString m_next_offset;
        stream >> m_next_offset;
        item.setNextOffset(m_next_offset);
        InlineBotSwitchPM m_switch_pm;
        stream >> m_switch_pm;
        item.setSwitchPm(m_switch_pm);
        QList<BotInlineResult> m_results;
        stream >> m_results;
        item.setResults(m_results);
        qint32 m_cache_time;
        stream >> m_cache_time;
        item.setCacheTime(m_cache_time);
    }
        break;
    }
    return stream;
}

/*QDebug operator<<(QDebug debug,  const MessagesBotResults &item) {
    QDebugStateSaver saver(debug);
    Q_UNUSED(saver)
    debug.nospace() << "Telegram.MessagesBotResults(";
    switch(item.classType()) {
    case MessagesBotResults::typeMessagesBotResults:
        debug.nospace() << "classType: typeMessagesBotResults";
        debug.nospace() << ", flags: " << item.flags();
        debug.nospace() << ", queryId: " << item.queryId();
        debug.nospace() << ", nextOffset: " << item.nextOffset();
        debug.nospace() << ", switchPm: " << item.switchPm();
        debug.nospace() << ", results: " << item.results();
        debug.nospace() << ", cacheTime: " << item.cacheTime();
        break;
    }
    debug.nospace() << ")";
    return debug;
}
*/