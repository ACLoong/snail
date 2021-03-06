//
// Created by XFC on 2018/6/24.
//

#ifndef SNAIL_LOGCONTEXT_H
#define SNAIL_LOGCONTEXT_H

#include <list>
#include <functional>
#include <sstream>
#include <iostream>
#include <vector>
#include <map>
#include <thread>

namespace snail {
        using LogHandler = std::function<void(const std::string &msg)>;
        class LogContext {
        public:
            LogContext() : cache_(), currCacheSize_(0), maxCacheSize_(0) {}
            virtual ~LogContext() = default;

        public:
            void addHandler(const LogHandler &handler, bool enableCache);
            void flush(const std::string &msg);
            void setCacheSize(int size);

        private:
            std::list<LogHandler> noCacheFunc_;
            std::list<LogHandler> cacheFunc_;
            std::string cache_;
            int maxCacheSize_;
            int currCacheSize_;
        };

        class Log {
        public:
            enum Loglevel {
                Debug = 0,
                Trace,
                Warn,
                Error
            };
        public:
            static void setLoglevel(Log::Loglevel level);
            static void addHandler(const LogHandler &handler, bool enableCache);
            static void setCacheSize(int size);
            static void setLogContext(LogContext *context);
            const static std::vector<std::string> LogLevelStr;

        public:
            Log() = default;
            ~Log();

        public:
            Log &operator<<(Loglevel level);

            Log &operator<<(int value);

            Log &operator<<(const char *pChar);

        private:
            static Loglevel logLevel_;
            static LogContext *context_;

        private:
            std::ostringstream oStream_;
            Loglevel currentLogLevel_;
        };
}
#define Debug() (snail::Log() << snail::Log::Debug <<__TIME__ << __FILE__ << __LINE__)
#define Trace() (snail::Log() << snail::Log::Trace <<__TIME__ << __FILE__ << __LINE__)
#define Warn()  (snail::Log() << snail::Log:Warn <<__TIME__ << __FILE__ << __LINE__)
#define Error() (snail::Log() << snail::Log::Error <<__TIME__ << __FILE__ << __LINE__)


#endif //SNAIL_LOGCONTEXT_H
