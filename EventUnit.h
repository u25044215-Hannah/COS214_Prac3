/*u25571878: Kelly Rademeyer
u25044215: Hannah diedrick
u25038967: Shelby bodenstein
*/
#ifndef EVENT_UNIT_H
#define EVENT_UNIT_H

#include "EventComponent.h"

//inherits from eventComponent (inherits Observer)
class EventUnit : public EventComponent {
public:
    EventUnit(const std::string& name, int capacity);
    virtual ~EventUnit() {}

    virtual void open();
    virtual void close();
    virtual void reportStatus() const;
    virtual int getCapacity() const;
    virtual const std::string& getName() const;

    bool isOpen() const;

protected:
    std::string name;
    bool openState;
    int capacity;
};

#endif
