/*u25571878: Kelly Rademeyer
u25044215: Hannah diedrick
u25038967: Shelby bodenstein
*/
#ifndef EVENT_CONTROL_H
#define EVENT_CONTROL_H

#include <string>
#include "Subject.h"

class EventControl : public Subject {
public:
    explicit EventControl(const std::string& name);
    virtual ~EventControl() {}

    /**
     * @brief Issue a notice to all top-level registered observers.
     * @param notice Notice to push.
     */
    void issueNotice(const Notice& notice);

    /**
     * @brief Return control-centre name.
     * @return Name string.
     */
    const std::string& getName() const;

private:
    std::string name;
};

#endif
