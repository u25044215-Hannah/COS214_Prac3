/*u25571878: Kelly Rademeyer
u25044215: Hannah diedrick
u25038967: Shelby bodenstein
*/
/**
 * @brief Concrete Leaf controlling attendee entry and exit at Lentedag.
 *
 */
class EntranceGate : public EventUnit {
public:

    /**
     * @brief Construct an entrance gate.
     *
     * @param name Human-readable gate name.
     */
    explicit EntranceGate(const std::string& name);

    /**
     * @brief Virtual destructor.
     */
    virtual ~EntranceGate() {}

    /**
     * @brief Respond to a festival Notice by changing admission behaviour.
     *
     * @param notice Notice pushed to this gate.
     */
    virtual void update(const Notice& notice);

private:

    /**
     * @brief true when the gate is currently admitting new attendees.
     */
    bool admitting;
};
