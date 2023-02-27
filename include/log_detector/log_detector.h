#ifndef LOGDECTOR_H
#define LOGDECTOR_H

#include "core_interface/detector.h"
#include "log_event.h"

class LogDetector : IDetector<LogEvent, std::string, std::string> {
public:
    LogEvent detect(const IContext<std::string,std::string>& context) const override;
};

#endif