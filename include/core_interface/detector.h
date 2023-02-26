#ifndef IDETECTOR_H
#define IDETECTOR_H

#include "context.h"

template<typename K, typename V>
class IDetector {
public:
    virtual bool detect(const IContext<K,V>& context) const = 0; 
};

#endif