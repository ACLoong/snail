//
// Created by XFC on 2018/6/24.
//

#include "Log.h"

namespace snail {
        void LogContext::setCacheSize(int size) {
            maxCacheSize_ = size;
            cache_.resize(size);
        }

        void LogContext::addHandler(const LogHandler &handler, bool enableCache){
            if (enableCache) {
                cacheFunc_.push_back(handler);
            } else {
                noCacheFunc_.push_back(handler);
            }
        }

        void LogContext::flush(const std::string &msg) {
            for (auto &func : noCacheFunc_) {
                func(msg);
            }
            if (!cacheFunc_.empty()) {
                currCacheSize_ += msg.size();
            }
            if (currCacheSize_ >= maxCacheSize_) {
                for (auto &func : cacheFunc_) {
                    func(cache_ + msg);
                }
                currCacheSize_ = 0;
                cache_.clear();
            } else {
                cache_.append(msg);
            }
        }

        Log::Loglevel Log::logLevel_ = Loglevel::Debug;
        LogContext* Log::context_ = nullptr;
        const std::vector<std::string> Log::LogLevelStr   = {"[DEBUG]", "[TRACE]", "[WARN]", "[ERROR]"};

        Log::~Log() {
            if (currentLogLevel_ >= logLevel_) {
                context_->flush(oStream_.str());
            }
        }
        void Log::setLogContext(LogContext *context) {
            context_ = context;
        }
        void Log::setLoglevel(Loglevel level) {
            logLevel_ = level;
        }

        void Log::setCacheSize(int size) {
            context_->setCacheSize(size);
        }

        void Log::addHandler(const LogHandler &handler, bool enableCache) {
            context_->addHandler(handler, enableCache);
        }

        Log& Log::operator << (const int value) {
            oStream_ << "[" << value << "]";
            return *this;
        }

        Log& Log::operator << (const char *pChar) {
            oStream_ << "[" << pChar << "]";
            return *this;
        }

        Log& Log::operator << (Loglevel level) {
            oStream_ << LogLevelStr.at(level);
            return *this;
        }
}

