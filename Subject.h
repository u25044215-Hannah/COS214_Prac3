/*u25571878: Kelly Rademeyer
u25044215: Hannah diedrick
u25038967: Shelby bodenstein
*/
#ifndef SUBJECT_H
#define SUBJECT_H

#include <vector>
#include "Observer.h"

class Subject {
public:
    virtual ~Subject();

    virtual bool attach(Observer* observer);
    virtual bool detach(Observer* observer);
    virtual void notify(const Notice& notice);
    std::size_t observerCount() const;

protected:
    std::vector<Observer*> observers;
};

#endif
