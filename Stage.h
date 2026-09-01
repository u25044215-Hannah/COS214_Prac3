/*u25571878: Kelly Rademeyer
u25044215: Hannah diedrick
u25038967: Shelby bodenstein
*/
#ifndef STAGE_H
#define STAGE_H

#include "EventUnit.h"

//inherits from Eventunit (which inherits EventComponent)
//stage is an observer (adds it's own state)
class Stage : public EventUnit {
public:
    Stage(const std::string& name, int capacity, bool outdoor = true);
    virtual ~Stage() {}

    //overrides EventComponent's update()
    virtual void update(const Notice& notice);

    virtual void reportStatus() const;

    void setAttendance(int attendance);
    int getAttendance() const;

    bool atCapacityThreshold(double fraction) const;

private:
    bool outdoor;
    bool paused;
    int attendance;
    std::string scheduleMessage;
};

#endif
