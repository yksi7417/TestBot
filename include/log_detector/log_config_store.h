#ifndef LOG_CONFIG_PARSER_H
#define LOG_CONFIG_PARSER_H

#include <memory>
#include <iostream>
#include <fstream>
#include <unordered_map>
#include "csv.h"

class LogConfig {
public:
    LogConfig(int eventId_, const std::string& event_, const std::string& regex_) : 
        eventId(eventId_), 
        event(event_),
        regex(regex_) {}

private:
    int eventId;    // can I use unsigned int instead?
    std::string event; 
    std::string regex; 
};


class LogConfigStore {
public:
    LogConfigStore(const char* filename) {
        data = std::make_shared<std::unordered_map<std::string, LogConfig>>();
        io::CSVReader<3> csv(filename);
        csv.read_header(io::ignore_extra_column, "EventId", "Event", "RegexPattern"); 
        int eventId; 
        std::string event, regex;
        while (csv.read_row(eventId, event, regex)) {
            data->insert(std::make_pair(event, LogConfig(eventId, event, regex)));  // TODO:  can I use emplace instead? 
        }
    }
    auto getConfig() const { return data; }
private:    
    std::shared_ptr<std::unordered_map<std::string, LogConfig>> data;
};



#endif 