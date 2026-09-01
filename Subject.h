/*u25571878: Kelly Rademeyer
u25044215: Hannah diedrick
u25038967: Shelby bodenstein
*/
/**
 * @brief Abstract Subject participant in the Lentedag Observer collaboration.
 *
 * Subject maintains a collection of non-owning Observer pointers. Observers
 * may register and deregister at runtime using attach() and detach().
 */
//used by anthing that keeps a list of observers and can notify them of changes
class Subject {
public:

    /**
     * @brief Destroy the Subject.
     *
     * Registered Observer pointers are non-owning and are therefore not
     * deleted by the Subject.
     */
    virtual ~Subject();

    /**
     * @brief Register an Observer to receive future notices.
     *
     * The supplied pointer is stored as a non-owning reference. The Observer
     * must remain valid while it is registered with this Subject.
     *
     * @param observer Non-owning pointer to the Observer to register.
     * @return true if registration succeeds; false if observer is nullptr
     * or already registered.
     */
    virtual bool attach(Observer* observer);

    /**
     * @brief Deregister an Observer from this Subject.
     *
     * Deregistration removes only the non-owning reference. The Observer
     * object itself is not deleted.
     *
     * @param observer Pointer to the Observer to deregister.
     * @return true if the Observer was registered and removed; false if it
     * was not registered.
     */
    virtual bool detach(Observer* observer);

    /**
     * @brief Push a festival notice to currently registered Observers.
     *
     * Notification is performed using a snapshot of the registration list.
     * Registration changes made during the current notification cycle affect
     * the next cycle rather than the current one.
     *
     * @param notice Notice to push to registered Observers.
     */
    virtual void notify(const Notice& notice);

    /**
     * @brief Return the number of currently registered Observers.
     *
     * @return Number of Observer pointers currently stored by the Subject.
     */
    std::size_t observerCount() const;

protected:

    /**
     * @brief Non-owning references to registered Observers.
     *
     * The Subject never deletes these pointers.
     */
    std::vector<Observer*> observers;
};
