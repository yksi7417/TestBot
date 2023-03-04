#include <string>
#include "log_detector/log_detector.h"
#include "log_detector/log_event.h"
#include "log_detector/log_config_store.h"

class LogDetector::Impl{ 
public:
    Impl(const char* configFile) : logConfigStore(configFile) {}
    LogConfigStore logConfigStore; 

};

LogDetector::LogDetector(const char* configFile)  {
    impl = std::make_unique<Impl>(configFile);
}

LogEvent LogDetector::detect(const LogContext& context) const
{
    LogConfigStore& store = (impl->logConfigStore); 
    std::unordered_map<std::string, LogConfig>& configMap = *store.getConfig(); 
    for (const auto& [key, value] : configMap) {
        std::cout << value.getEvent() << " " << value.getRegex() << "\n";
    }
    return LogEvent();
};
