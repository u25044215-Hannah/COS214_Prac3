/*u25571878: Kelly Rademeyer
u25044215: Hannah diedrick
u25038967: Shelby bodenstein
*/
#ifndef ENTRANCE_GATE_H
#define ENTRANCE_GATE_H

#include "EventUnit.h"

class EntranceGate : public EventUnit {
public:
    explicit EntranceGate(const std::string& name);
    virtual ~EntranceGate() {}
    virtual void update(const Notice& notice);

private:
    bool admitting;
};

#endif
