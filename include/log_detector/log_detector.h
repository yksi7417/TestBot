#ifndef LOGDECTOR_H
#define LOGDECTOR_H

#include "core_interface/detector.h"
#include "log_event.h"
#include "log_context.h"

class LogDetector : IDetector<LogEvent, LogContext> {
public:
    LogEvent detect(const LogContext& context) const override;
};

#endif