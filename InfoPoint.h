/*u25571878: Kelly Rademeyer
u25044215: Hannah diedrick
u25038967: Shelby bodenstein
*/
/**
 * @brief Concrete Leaf representing a Lentedag information or display point.
 */
class InfoPoint : public EventUnit {
public:

    /**
     * @brief Construct an information point.
     *
     * @param name Human-readable name of the information point.
     */
    explicit InfoPoint(const std::string& name);

    /**
     * @brief Virtual destructor.
     */
    virtual ~InfoPoint() {}

    /**
     * @brief Update the information display using the received Notice.
     *
     * @param notice Notice containing the message to display.
     */
    virtual void update(const Notice& notice);

    /**
     * @brief Report the current information-point status and display message.
     */
    virtual void reportStatus() const;

private:

    /**
     * @brief Message currently displayed to festival attendees.
     */
    std::string displayMessage;
};
