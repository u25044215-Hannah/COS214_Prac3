/*u25571878: Kelly Rademeyer
u25044215: Hannah diedrick
u25038967: Shelby bodenstein
*/
#ifndef OBSERVER_H
#define OBSERVER_H

#include "Notice.h"


class Observer {
public:
    virtual ~Observer() {}

    virtual void update(const Notice& notice) = 0;
};

#endif
