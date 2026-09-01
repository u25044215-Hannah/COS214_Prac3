/*u25571878: Kelly Rademeyer
u25044215: Hannah diedrick
u25038967: Shelby bodenstein
*/

#ifndef MEDICAL_UNIT_H
#define MEDICAL_UNIT_H

#include "EventUnit.h"

class MedicalUnit : public EventUnit {
public:
    explicit MedicalUnit(const std::string& name);
    virtual ~MedicalUnit() {}
    virtual void update(const Notice& notice);

private:
    bool emergencyMode;
};

#endif
