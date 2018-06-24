//
// Created by XFC on 2018/6/24.
//

#ifndef SNAIL_LOGCONTEXT_H
#define SNAIL_LOGCONTEXT_H

#include <list>
#include <functional>
#include <sstream>
#include <vector>

enum Loglevel {
    Debug = 0,
    Trace,
    Warn,
    Error
};

class LogContext {
public:
    static LogContext* instance();
public:
    void addHandle(const std::function<void(const std::string &msg)> &func, bool enableCache);
    void flush(const std::string &msg);

private:
    LogContext():m_cache(0), m_currCacheSize(0){}
    ~LogContext() = default;

private:
    std::list<std::function<void(const std::string &msg)>> m_noCacheFunc;
    std::list<std::function<void(const std::string &msg)>> m_cacheFunc;
    std::vector<std::string> m_cache;
    int m_maxCacheSize;
    int m_currCacheSize;
};

 class Log {
 public:
     static void setLoglevel(Loglevel level);
     static void addHandle(const std::function<void(const std::string &msg)> &func, bool enableCache);

 public:
     Log() = default;
     ~Log();

 public:
    Log& operator << (Loglevel level);
     Log& operator << (int value);
     Log& operator << (const char *pChar);
 private:
     static Loglevel m_logLevel;

 private:
     std::ostringstream m_oStream;
     Loglevel m_currentLogLevel;
 };

#define Debug() (Log() << Loglevel::Debug <<__TIME__ << __FILE__ << __LINE__)

#endif //SNAIL_LOGCONTEXT_H