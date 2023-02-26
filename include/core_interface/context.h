#ifndef ICONTEXT_H
#define ICONTEXT_H

template<typename K, typename V>
class IContext {
public:
    virtual V get(K key) = 0;
};

#endif