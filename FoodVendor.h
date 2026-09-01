/*u25571878: Kelly Rademeyer
u25044215: Hannah diedrick
u25038967: Shelby bodenstein
*/
#ifndef FOOD_VENDOR_H
#define FOOD_VENDOR_H

#include "EventUnit.h"

class FoodVendor : public EventUnit {
public:
    explicit FoodVendor(const std::string& name);
    virtual ~FoodVendor() {}
    virtual void update(const Notice& notice);
};

#endif
