#ifndef EVENT_COMPONENT_H
#define EVENT_COMPONENT_H

#include <string>
#include "Observer.h"

/**
 * @brief Composite Component abstraction and Observer participant.
 *
 * Every event component in this design can receive notices. EventGroup adds
 * Subject behaviour so a group can relay a notice to interested descendants.
 */
class EventComponent : public Observer {
public:
    virtual ~EventComponent() {}

    /** @brief Open this component. */
    virtual void open() = 0;

    /** @brief Close this component. */
    virtual void close() = 0;

    /** @brief Report status to standard output. */
    virtual void reportStatus() const = 0;

    /**
     * @brief Return attendee capacity represented by this component.
     * @return Capacity. Operational units with no attendee capacity return 0.
     */
    virtual int getCapacity() const = 0;

    /**
     * @brief Return the component name.
     * @return Human-readable name.
     */
    virtual const std::string& getName() const = 0;
};

#endif
