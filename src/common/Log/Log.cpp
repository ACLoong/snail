//
// Created by XFC on 2018/6/24.
//

#include "Log.h"

char logLevelStr[][8] = {"[DEBUG]", "[TRACE]", "[WARN]", "[ERROR]"};

LogContext* LogContext::instance() {
    static LogContext _context;
    return &_context;
}

void LogContext::setCacheSize(int size) {
    m_maxCacheSize = size;
    m_cache.resize(size);
}

void LogContext::addHandle(const std::function<void(const std::string &msg)> &func, bool enableCache){
    if (enableCache) {
        m_cacheFunc.push_back(func);
    } else {
        m_noCacheFunc.push_back(func);
    }
}

void LogContext::flush(const std::string &msg) {
    for (auto &func : m_noCacheFunc) {
        func(msg);
    }
    if (!m_cacheFunc.empty()) {
        m_currCacheSize += msg.size();
    }
    if (m_currCacheSize >= m_maxCacheSize) {
            for (auto &func : m_cacheFunc) {
                func(m_cache + msg);
            }
        m_currCacheSize = 0;
        m_cache.clear();
    } else {
        m_cache.append(msg);
    }
}

Loglevel Log::m_logLevel = Loglevel::Debug;

Log::~Log() {
    if (m_currentLogLevel >= m_logLevel) {
        LogContext::instance()->flush(m_oStream.str());
    }
}

void Log::setLoglevel(Loglevel level) {
    m_logLevel = level;
}

void Log::setCacheSize(int size) {
    LogContext::instance()->setCacheSize(size);
}

void Log::addHandle(const std::function<void(const std::string &msg)> &func, bool enableCache) {
    LogContext::instance()->addHandle(func, enableCache);
}

Log& Log::operator << (const int value) {
    m_oStream << "[" << value << "]";
    return *this;
}

Log& Log::operator << (const char *pChar) {
    m_oStream << "[" << pChar << "]";
    return *this;
}

Log& Log::operator << (Loglevel level) {
    m_oStream << logLevelStr[level];
    return *this;
}

