#ifndef LOGDECTOR_H
#define LOGDECTOR_H

#include "core_interface/detector.h"

class LogDetector : IDetector<std::string,std::string> {
    public:
    bool detect(const IContext<std::string,std::string>& context) const;
};

#endif