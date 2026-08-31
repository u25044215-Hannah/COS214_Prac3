#ifndef NOTICE_H
#define NOTICE_H

#include <string>

/**
 * @brief Types of notices that can move through the Lentedag Observer network.
 */
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

/**
 * @brief Value object containing the information pushed to observers.
 */
struct Notice {
    NoticeType type;
    std::string message;
    std::string source;
    std::string location;
    int value;

    /**
     * @brief Construct a notice.
     * @param typeIn Notice type.
     * @param messageIn Human-readable detail.
     * @param sourceIn Source that issued the notice.
     * @param locationIn Area affected by the notice.
     * @param valueIn Optional numeric value such as attendance or delay minutes.
     */
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
