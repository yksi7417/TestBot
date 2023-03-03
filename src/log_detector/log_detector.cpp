#include <string>
#include "log_detector/log_detector.h"
#include "log_detector/log_event.h"

class LogDetector::Impl{ 
public:
};

LogDetector::LogDetector(const char* configFile) : impl(new LogDetector::Impl) {
}

LogEvent LogDetector::detect(const LogContext& context) const
{
    return LogEvent();
};
