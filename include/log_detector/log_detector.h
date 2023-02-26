#ifndef LOGDECTOR_H
#define LOGDECTOR_H

#include <Poco/AutoPtr.h>
#include "core_interface/detector.h"
#include "log_event.h"

class LogDetector : IDetector<std::string,std::string> {
public:
    IEvent* detect(const IContext<std::string,std::string>& context) const override;
};

#endif