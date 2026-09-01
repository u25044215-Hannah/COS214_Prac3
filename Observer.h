/*u25571878: Kelly Rademeyer
u25044215: Hannah diedrick
u25038967: Shelby bodenstein
*/
/**
 * @brief Abstract Observer participant in the Lentedag notification system.
 *
 * Observer defines the interface that all objects interested in festival
 * notices must implement. Subjects notify registered observers by calling
 * update() and pushing a Notice object to them.
 */

//used by anything that can be told something changed
//anything with an update(const Notice&) method.
class Observer {
public:

    /**
     * @brief Virtual destructor for safe polymorphic destruction.
     */
    virtual ~Observer() {}

    /**
     * @brief Receive a notice pushed by a Subject.
     *
     * Concrete observers implement this operation to perform behaviour appropriate to the received notice.
     * @param notice Festival notice containing the type, message, source, location and optional numeric value.
     */
    virtual void update(const Notice& notice) = 0;
};
