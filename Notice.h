/*u25571878: Kelly Rademeyer
u25044215: Hannah diedrick
u25038967: Shelby bodenstein
*/
#ifndef NOTICE_H
#define NOTICE_H

#include <string>

enum class NoticeType {
    OPEN,
    CLOSE,
    SCHEDULE_CHANGE,
    CAPACITY_ALERT,
    WEATHER_ALERT,
    PAUSE,
    RESUME,
    EVACUATE,
    HYDRATION_ALERT,
    CROWD_SURGE,
    CLEANUP_REQUEST
};


struct Notice {
    NoticeType type;
    std::string message;
    std::string source;
    std::string location;
    int value;

    Notice(NoticeType typeIn,
        const std::string& messageIn,
        const std::string& sourceIn,
        const std::string& locationIn,
        int valueIn = 0)
    : type(typeIn),
        message(messageIn),
        source(sourceIn),
        location(locationIn),
        value(valueIn) {}
};

#endif
