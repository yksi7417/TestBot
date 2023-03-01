#ifndef LOGDECTOR_H
#define LOGDECTOR_H

#include <memory>

#include "core_interface/detector.h"
#include "log_event.h"
#include "log_context.h"

class LogDetector : IDetector<LogEvent, LogContext> {
public:
    LogDetector(const char* configFile);
    LogEvent detect(const LogContext& context) const override;
private:
    class Impl;
    std::unique_ptr<Impl> impl; 
};

#endif