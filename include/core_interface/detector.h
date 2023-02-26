#ifndef IDETECTOR_H
#define IDETECTOR_H

#include <Poco/AutoPtr.h>
#include "context.h"
#include "event.h"

template<typename K, typename V>
class IDetector {
public:
    virtual IEvent* detect(const IContext<K,V>& context) const = 0; 
};

#endif