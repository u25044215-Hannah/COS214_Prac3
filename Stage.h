/*u25571878: Kelly Rademeyer
u25044215: Hannah diedrick
u25038967: Shelby bodenstein
*/
/**
 * @brief Concrete Leaf representing one of Lentedag's five music stages.
 * It tracks its own capacity, attendance,
 * performance status and schedule information and responds differently to
 * safety, capacity, weather and operational notices.
 */
//inherits from Eventunit (which inherits EventComponent)
//stage is an observer (adds it's own state)
class Stage : public EventUnit {
public:

    /**
     * @brief Construct a Lentedag stage.
     *
     * @param name Name of the stage.
     * @param capacity Maximum attendee capacity of the stage.
     * @param outdoor true if the stage is exposed to outdoor weather;
     * false if it is sheltered.
     */
    Stage(const std::string& name, int capacity, bool outdoor = true);

    /**
     * @brief Virtual destructor.
     */
    virtual ~Stage() {}

    /**
     * @brief Respond to a festival Notice.
     *
     * Behaviour depends on the notice type. For example, a Stage may pause
     * during a weather alert, protect audience entry during a capacity alert,
     * update its running order after a schedule change, or resume after a
     * clearance notice.
     *
     * @param notice Notice pushed to this stage.
     */
//overrides EventComponent's update()
    virtual void update(const Notice& notice);

    /**
     * @brief Report detailed stage status.
     *
     * The report includes open/closed state, pause state, attendance,
     * capacity and current schedule information.
     */
//overrides EventComponent's reportStatus()
    virtual void reportStatus() const;

    /**
     * @brief Set the current stage attendance.
     *
     * Values below zero are restricted to zero and values above stage
     * capacity are restricted to the maximum capacity.
     *
     * @param attendance Current number of attendees at the stage.
     */
    void setAttendance(int attendance);

    /**
     * @brief Return the current stage attendance.
     *
     * @return Number of attendees currently recorded at the stage.
     */
    int getAttendance() const;

    /**
     * @brief Test whether attendance has reached a capacity threshold.
     *
     * For example, a fraction of 0.90 represents a 90 percent threshold.
     *
     * @param fraction Fraction of total capacity used as the threshold.
     * @return true if attendance is at or above the requested threshold;
     * false otherwise.
     */
    bool atCapacityThreshold(double fraction) const;

private:

    /** @brief true if the stage is exposed to outdoor weather conditions. */
    bool outdoor;

    /** @brief true while performances at this stage are temporarily paused. */
    bool paused;

    /** @brief Current attendee count at the stage. */
    int attendance;

    /** @brief Current schedule or running-order message for the stage. */
    std::string scheduleMessage;
};
