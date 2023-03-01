#include <string>
#include "log_detector/log_detector.h"
#include "log_detector/log_event.h"

LogEvent LogDetector::detect(const LogContext& context) const
{
    return LogEvent();
};
