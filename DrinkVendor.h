/*u25571878: Kelly Rademeyer
u25044215: Hannah diedrick
u25038967: Shelby bodenstein
*/
#ifndef DRINK_VENDOR_H
#define DRINK_VENDOR_H

#include "EventUnit.h"


class DrinkVendor : public EventUnit {
public:
    explicit DrinkVendor(const std::string& name);
    virtual ~DrinkVendor() {}
    virtual void update(const Notice& notice);

private:
    bool waterPriority;
};

#endif
