#ifndef ILOGEVENT_H
#define ILOGEVENT_H

#include <string>
#include "core_interface/event.h"

// Design consideration - uint32_t is 32 bits integer, holding 0 - 4,294,967,295
// That means max number of log event is ~4.2billion
// max number of line is ~4.2billion

// 4 bytes is nice w/ cache alignment  

class LogEvent: IEvent{
public:

    virtual uint32_t getEventId() {
        return event_type_id; 
    }

private:
    uint32_t event_type_id; 
    uint32_t timestamp_yyyymmdd_utc;
    uint32_t timestamp_hhmmssSSS_utc;
    uint32_t line_number; 
};

#endif