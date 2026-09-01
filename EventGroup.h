/*u25571878: Kelly Rademeyer
u25044215: Hannah diedrick
u25038967: Shelby bodenstein
*/
#ifndef EVENT_GROUP_H
#define EVENT_GROUP_H

#include <vector>
#include "EventComponent.h"
#include "Subject.h"
//both an observer (someone else's registered list) and a subject(maintain own oberver list)

/**
 * @brief Composite participant representing a Lentedag area or grouping.
 *
 * EventGroup owns its child EventComponent pointers. It is also an Observer,
 * receiving notices from above, and a Subject, relaying notices to registered
 * observers below. Ownership and observation remain separate relationships:
 * addChild() does not automatically attach().
 */
class EventGroup : public EventComponent, public Subject {
public:
    explicit EventGroup(const std::string& name);
    virtual ~EventGroup();

    /**
     * @brief Add a child and take ownership.
     * @param child Heap-allocated component. Must not already be owned elsewhere.
     * @return true if ownership was accepted.
     */
    bool addChild(EventComponent* child);

    /**
     * @brief Remove a child without deleting it and relinquish ownership.
     * @param child Child to remove.
     * @return Removed pointer, or nullptr if not found. Caller owns returned object.
     */
    EventComponent* removeChild(EventComponent* child);

    /**
     * @brief Transfer a child to another EventGroup.
     *
     * This operation updates both Composite ownership and direct Observer
     * registration. If the child was observing this group, it is detached before
     * the ownership move and attached to the destination afterwards.
     *
     * @param child Child to move.
     * @param destination New owning group.
     * @return true on success.
     */
    bool transferChild(EventComponent* child, EventGroup* destination);

    virtual void open();
    virtual void close();
    virtual void reportStatus() const;
    virtual int getCapacity() const;
    virtual const std::string& getName() const;
    virtual void update(const Notice& notice);

    /**
     * @brief Number of directly owned children.
     * @return Child count.
     */
    std::size_t childCount() const;

private:
    std::string name;
    bool openState;
    std::vector<EventComponent*> children;
};

#endif
