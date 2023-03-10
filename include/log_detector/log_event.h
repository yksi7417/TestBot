#ifndef ILOGEVENT_H
#define ILOGEVENT_H

#include <string>
#include "core_interface/event.h"

// Design consideration - uint32_t is 32 bits integer, holding 0 - 4,294,967,295
// That means max number of log event is ~4.2billion
// max number of line is ~4.2billion

// 4 bytes is nice w/ cache alignment  
// modern 64bit CPU hs 16 registers - 4 bytes can fit onto the register nicely. 

class LogEvent: IEvent{
public:
    LogEvent() : event_type_id(0), timestamp_HHMMSSsss_utc(0), line_number(0) {}

    LogEvent(uint32_t event_type_id_, 
            uint32_t timestamp_HHMMSSsss_utc_,
            uint32_t line_number_) : 
            event_type_id(event_type_id_), 
            timestamp_HHMMSSsss_utc(timestamp_HHMMSSsss_utc_), 
            line_number(line_number_) 
        {
        }

    virtual uint32_t getEventId() 
    {
        return event_type_id; 
    }

    uint32_t getTimestamp_HHMMSSsss_utc()
    {
        return timestamp_HHMMSSsss_utc;
    }

    uint32_t getLineNumber()
    {
        return line_number;
    }

private:
    uint32_t event_type_id; 
    uint32_t timestamp_HHMMSSsss_utc;
    uint32_t line_number; 
};

#endif