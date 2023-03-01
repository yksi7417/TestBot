#ifndef IDETECTOR_H
#define IDETECTOR_H

#include "event.h"

template<typename T, typename CTX>
class IDetector {
public:
    virtual T detect(const CTX& context) const = 0; 
};

#endif