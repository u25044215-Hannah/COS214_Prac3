/*u25571878: Kelly Rademeyer
u25044215: Hannah diedrick
u25038967: Shelby bodenstein
*/
#ifndef NOTICE_H
#define NOTICE_H

#include <string>

/**
 * @brief Types of notices distributed through the Lentedag Observer network.
 *
 * These notice types represent operational changes, capacity changes,
 * safety-related changes and Lentedag-specific festival events.
 */
enum class NoticeType {

    /**
     * @brief Opens an event area or operational unit.
     */
    OPEN,

    /**
     * @brief Closes an event area or operational unit.
     */
    CLOSE,

    /**
     * @brief Indicates that the festival schedule has changed.
     */
    SCHEDULE_CHANGE,

    /**
     * @brief Warns that an area is approaching or has reached capacity.
     */
    CAPACITY_ALERT,

    /**
     * @brief Warns observers about unsafe weather conditions.
     */
    WEATHER_ALERT,

    /**
     * @brief Temporarily pauses an affected operation or performance.
     */
    PAUSE,

    /**
     * @brief Resumes previously paused festival operations.
     */
    RESUME,

    /**
     * @brief Instructs affected areas to begin evacuation procedures.
     */
    EVACUATE,

    /**
     * @brief Lentedag-specific notice requesting increased hydration support.
     */
    HYDRATION_ALERT,

    /**
     * @brief Warns observers of dangerous crowd density or movement.
     */
    CROWD_SURGE,

    /**
     * @brief Requests a cleaning response in a festival area.
     */
    CLEANUP_REQUEST
};


/**
 * @brief Represents a notice pushed through the Lentedag Observer system.
 *
 * Notice acts as a value object that packages the information required by
 * observers when something changes during the festival.
 *
 * Lentedag uses the Push model of the Observer pattern. Instead of requiring
 * observers to query the Subject for changed state, the relevant information
 * is placed inside a Notice object and passed directly to update().
 */
struct Notice {

    /**
     * @brief Type or category of the notice.
     */
    NoticeType type;

    /**
     * @brief Human-readable description of the notice.
     */
    std::string message;

    /**
     * @brief Name of the object or control centre that issued the notice.
     */
    std::string source;

    /**
     * @brief Festival area affected by the notice.
     */
    std::string location;

    /**
     * @brief Optional numeric value associated with the notice.
     *
     * This can represent values such as current attendance,
     * temperature or schedule delay in minutes.
     */
    int value;

    /**
     * @brief Constructs a Notice object.
     *
     * @param typeIn Type of festival notice.
     * @param messageIn Human-readable description of the notice.
     * @param sourceIn Name of the source issuing the notice.
     * @param locationIn Festival area affected by the notice.
     * @param valueIn Optional numeric value associated with the notice.
     * Defaults to 0.
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
          value(valueIn) {
    }
};

#endif
