//
// Created by XFC on 2018/6/24.
//

#include "Log.h"

namespace snail {
    namespace log{

        void LogContext::setCacheSize(int size) {
            m_maxCacheSize_ = size;
            m_cache_.resize(size);
        }

        void LogContext::addHandler(const LogHandler &handler, bool enableCache){
            if (enableCache) {
                m_cacheFunc_.push_back(handler);
            } else {
                m_noCacheFunc_.push_back(handler);
            }
        }

        void LogContext::flush(const std::string &msg) {
            for (auto &func : m_noCacheFunc_) {
                func(msg);
            }
            if (!m_cacheFunc_.empty()) {
                m_currCacheSize_ += msg.size();
            }
            if (m_currCacheSize_ >= m_maxCacheSize_) {
                for (auto &func : m_cacheFunc_) {
                    func(m_cache_ + msg);
                }
                m_currCacheSize_ = 0;
                m_cache_.clear();
            } else {
                m_cache_.append(msg);
            }
        }

        Loglevel Log::m_logLevel = Loglevel::Debug;
        LogContext* Log::m_context = nullptr;
        const std::vector<std::string> Log::LogLevelStr   = {"[DEBUG]", "[TRACE]", "[WARN]", "[ERROR]"};

        Log::~Log() {
            if (m_currentLogLevel_ >= m_logLevel) {
                m_context->flush(m_oStream_.str());
            }
        }
        void Log::setLogContext(LogContext *context) {
            m_context = context;
        }
        void Log::setLoglevel(Loglevel level) {
            m_logLevel = level;
        }

        void Log::setCacheSize(int size) {
            m_context->setCacheSize(size);
        }

        void Log::addHandle(const LogHandler &handler, bool enableCache) {
            m_context->addHandler(handler, enableCache);
        }

        Log& Log::operator << (const int value) {
            m_oStream_ << "[" << value << "]";
            return *this;
        }

        Log& Log::operator << (const char *pChar) {
            m_oStream_ << "[" << pChar << "]";
            return *this;
        }

        Log& Log::operator << (Loglevel level) {
            m_oStream_ << LogLevelStr.at(level);
            return *this;
        }
    }
}

