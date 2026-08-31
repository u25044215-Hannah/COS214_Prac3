/*u25571878: Kelly Rademeyer
u25044215: Hannah diedrick
u25038967: Shelby bodenstein
*/
#ifndef CLEANING_TEAM_H
#define CLEANING_TEAM_H

#include "EventUnit.h"

class CleaningTeam : public EventUnit {
public:
    explicit CleaningTeam(const std::string& name);
    virtual ~CleaningTeam() {}
    virtual void update(const Notice& notice);
};

#endif
