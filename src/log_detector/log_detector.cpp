#include <string>
#include <Poco/Util/MapConfiguration.h>
#include <Poco/Util/IniFileConfiguration.h>
#include "log_detector/log_detector.h"
#include "log_detector/log_event.h"

using Poco::Util::MapConfiguration;
using Poco::Util::IniFileConfiguration;

class LogDetector::Impl{ 
public:
};

LogDetector::LogDetector(const char* configFile) : impl(new LogDetector::Impl) {
    // impl->config = std::make_unique<MapConfiguration>(configFile);
}

LogEvent LogDetector::detect(const LogContext& context) const
{
    return LogEvent();
};
