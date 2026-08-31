/*u25571878: Kelly Rademeyer
u25044215: Hannah diedrick
u25038967: Shelby bodenstein
*/
#ifndef EVENT_COMPONENT_H
#define EVENT_COMPONENT_H

#include <string>
#include "Observer.h"

class EventComponent : public Observer {
public:
    virtual ~EventComponent() {}

    virtual void open() = 0;

    virtual void close() = 0;

    virtual void reportStatus() const = 0;

    virtual int getCapacity() const = 0;

    virtual const std::string& getName() const = 0;
};

#endif
