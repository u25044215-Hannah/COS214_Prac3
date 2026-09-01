/*u25571878: Kelly Rademeyer
u25044215: Hannah diedrick
u25038967: Shelby bodenstein
*/
#ifndef INFO_POINT_H
#define INFO_POINT_H

#include "EventUnit.h"

class InfoPoint : public EventUnit {
public:
    explicit InfoPoint(const std::string& name);
    virtual ~InfoPoint() {}
    virtual void update(const Notice& notice);
    virtual void reportStatus() const;

private:
    std::string displayMessage;
};

#endif
