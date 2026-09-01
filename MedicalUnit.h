/*u25571878: Kelly Rademeyer
u25044215: Hannah diedrick
u25038967: Shelby bodenstein
*/

/**
 * @brief Concrete Leaf representing a Lentedag medical response unit.
 */
class MedicalUnit : public EventUnit {
public:

    /**
     * @brief Construct a medical unit.
     *
     * @param name Human-readable medical-unit name.
     */
    explicit MedicalUnit(const std::string& name);

    /**
     * @brief Virtual destructor.
     */
    virtual ~MedicalUnit() {}

    /**
     * @brief Respond to a festival Notice.
     *
     * @param notice Notice pushed to this medical unit.
     */
    virtual void update(const Notice& notice);

private:

    /**
     * @brief true while the medical unit is operating in emergency mode.
     */
    bool emergencyMode;
};
