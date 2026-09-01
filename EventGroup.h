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


class EventGroup : public EventComponent, public Subject {
public:
    explicit EventGroup(const std::string& name);
    virtual ~EventGroup();

    bool addChild(EventComponent* child);

    EventComponent* removeChild(EventComponent* child);
    bool transferChild(EventComponent* child, EventGroup* destination);

    virtual void open();
    virtual void close();
    virtual void reportStatus() const;
    virtual int getCapacity() const;
    virtual const std::string& getName() const;
    virtual void update(const Notice& notice);

    std::size_t childCount() const;

private:
    std::string name;
    bool openState;
    std::vector<EventComponent*> children;
};

#endif
