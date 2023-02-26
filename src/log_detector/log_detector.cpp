#include <string>
#include "log_detector/log_detector.h"
#include "log_detector/log_event.h"


IEvent* LogDetector::detect(const IContext<std::string ,std::string>& context) const
{
    return new NullEvent();
};
