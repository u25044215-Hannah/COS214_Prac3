/*u25571878: Kelly Rademeyer
u25044215: Hannah diedrick
u25038967: Shelby bodenstein
*/
/**
 * @brief Abstract Component participant in the Lentedag Composite pattern.
 *
 * EventComponent defines the common interface used to treat individual
 * festival units and groups uniformly. It also inherits from Observer so
 * every component may receive festival notices.
 */
class EventComponent : public Observer {
public:

    /**
     * @brief Virtual destructor for safe polymorphic destruction.
     *
     * EventComponent objects are commonly accessed through base-class
     * pointers, so the destructor must be virtual.
     */
    virtual ~EventComponent() {}

    /**
     * @brief Open this event component.
     *
     * Concrete leaves open themselves, while Composite groups apply this
     * operation recursively to their owned children.
     */
    virtual void open() = 0;

    /**
     * @brief Close this event component.
     *
     * Concrete leaves close themselves, while Composite groups apply this
     * operation recursively to their owned children.
     */
    virtual void close() = 0;

    /**
     * @brief Report the current status of this component.
     *
     * Composite groups may recursively report the status of their descendants.
     */
    virtual void reportStatus() const = 0;

    /**
     * @brief Return the attendee capacity represented by this component.
     *
     * Composite groups return an aggregate capacity calculated from their
     * children. Operational units without attendee capacity return zero.
     *
     * @return Capacity represented by the component.
     */
    virtual int getCapacity() const = 0;

    /**
     * @brief Return the name of this component.
     *
     * @return Constant reference to the human-readable component name.
     */
    virtual const std::string& getName() const = 0;
};
