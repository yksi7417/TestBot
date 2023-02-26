#ifndef IEVENT_H
#define IEVENT_H

class IEvent {
public:
    virtual uint32_t getEventId() = 0;
};

#endif