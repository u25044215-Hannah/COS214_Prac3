/*u25571878: Kelly Rademeyer
u25044215: Hannah diedrick
u25038967: Shelby bodenstein
*/
/**
 * @brief Concrete Leaf representing a mobile Lentedag cleaning team.
 */
class CleaningTeam : public EventUnit {
public:

    /**
     * @brief Construct a cleaning team.
     *
     * @param name Human-readable cleaning-team name.
     */
    explicit CleaningTeam(const std::string& name);

    /**
     * @brief Virtual destructor.
     */
    virtual ~CleaningTeam() {}

    /**
     * @brief Respond to a festival Notice.
     *
     * Cleanup notices cause the team to respond to the specified location,
     * while safety notices may cause it to clear access routes.
     *
     * @param notice Notice pushed to this cleaning team.
     */
    virtual void update(const Notice& notice);
};
