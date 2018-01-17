// This file generated by libqtelegram-code-generator.
// You can download it from: https://github.com/Aseman-Land/libqtelegram-code-generator
// DO NOT EDIT THIS FILE BY HAND -- YOUR CHANGES WILL BE OVERWRITTEN

#include "uploadgetfile.h"
#include "../coretypes.h"

UploadGetFile::UploadGetFile(UploadGetFileClassType classType) :
    m_downloaded(0),
    m_mtime(0),
    m_partId(0),
    m_total(0),
    m_classType(classType)
{
}

UploadGetFile::UploadGetFile(const Null &null) :
    TelegramCustomTypeObject(null),
    m_downloaded(0),
    m_mtime(0),
    m_partId(0),
    m_total(0),
    m_classType(typeUploadGetFileEmpty)
{
}

UploadGetFile::~UploadGetFile() {
}

void UploadGetFile::setBytes(const QByteArray &bytes) {
    m_bytes = bytes;
}

QByteArray UploadGetFile::bytes() const {
    return m_bytes;
}

void UploadGetFile::setDownloaded(qint32 downloaded) {
    m_downloaded = downloaded;
}

qint32 UploadGetFile::downloaded() const {
    return m_downloaded;
}

void UploadGetFile::setMtime(qint32 mtime) {
    m_mtime = mtime;
}

qint32 UploadGetFile::mtime() const {
    return m_mtime;
}

void UploadGetFile::setPartId(qint32 partId) {
    m_partId = partId;
}

qint32 UploadGetFile::partId() const {
    return m_partId;
}

void UploadGetFile::setTotal(qint32 total) {
    m_total = total;
}

qint32 UploadGetFile::total() const {
    return m_total;
}

void UploadGetFile::setType(const StorageFileType &type) {
    m_type = type;
}

StorageFileType UploadGetFile::type() const {
    return m_type;
}

bool UploadGetFile::operator ==(const UploadGetFile &b) const {
    return m_classType == b.m_classType &&
           m_bytes == b.m_bytes &&
           m_downloaded == b.m_downloaded &&
           m_mtime == b.m_mtime &&
           m_partId == b.m_partId &&
           m_total == b.m_total &&
           m_type == b.m_type;
}

void UploadGetFile::setClassType(UploadGetFile::UploadGetFileClassType classType) {
    m_classType = classType;
}

UploadGetFile::UploadGetFileClassType UploadGetFile::classType() const {
    return m_classType;
}
