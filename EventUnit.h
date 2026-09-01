/*u25571878: Kelly Rademeyer
u25044215: Hannah diedrick
u25038967: Shelby bodenstein
*/
/**
 * @brief Abstract base class for individual Lentedag operational units.
 *
 * EventUnit provides state and common behaviour shared by concrete Composite
 * Leaves such as Stage, FoodVendor, DrinkVendor, MedicalUnit and SecurityPost.

 */
class EventUnit : public EventComponent {
public:

    /**
     * @brief Construct an event unit.
     *
     * New units are initially closed unless a concrete subclass changes the
     * state during its own construction.
     *
     * @param name Human-readable name of the unit.
     * @param capacity Attendee capacity associated with the unit.
     */
    EventUnit(const std::string& name, int capacity);

    /**
     * @brief Virtual destructor for safe polymorphic destruction.
     */
    virtual ~EventUnit() {}

    /**
     * @brief Mark this unit as open.
     */
    virtual void open();

    /**
     * @brief Mark this unit as closed.
     */
    virtual void close();

    /**
     * @brief Print the current operational status of the unit.
     */
    virtual void reportStatus() const;

    /**
     * @brief Return the attendee capacity of this unit.
     *
     * @return Capacity assigned to the unit.
     */
    virtual int getCapacity() const;

    /**
     * @brief Return the unit name.
     *
     * @return Constant reference to the unit name.
     */
    virtual const std::string& getName() const;

    /**
     * @brief Determine whether this unit is currently open.
     *
     * @return true if the unit is open; false otherwise.
     */
    bool isOpen() const;

protected:

    /** @brief Human-readable name of this event unit. */
    std::string name;

    /** @brief true when the unit is currently operational/open. */
    bool openState;

    /** @brief Attendee capacity associated with the unit. */
    int capacity;
};
