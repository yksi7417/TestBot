#ifndef IDETECTOR_H
#define IDETECTOR_H

#include "context.h"
#include "event.h"

template<typename T, typename K, typename V>
class IDetector {
public:
    virtual T detect(const IContext<K,V>& context) const = 0; 
};

#endif