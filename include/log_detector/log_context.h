#ifndef ILOGCONTEXT_H
#define ILOGCONTEXT_H

#include <memory>


class LogContext{
public:
    LogContext(const char* filename_);
    void loadFile();

private:
    class LogContextImpl; 
    std::unique_ptr<LogContextImpl> impl; 

public:
    LogContext(const LogContext&) = delete;
    LogContext& operator=(const LogContext&) = delete;
    LogContext(LogContext&&) = delete;
    LogContext& operator=(LogContext&&) = delete;
};

#endif