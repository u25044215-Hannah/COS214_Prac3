/*u25571878: Kelly Rademeyer
u25044215: Hannah diedrick
u25038967: Shelby bodenstein
*/
#ifndef SECURITY_POST_H
#define SECURITY_POST_H

#include "EventUnit.h"

class SecurityPost : public EventUnit {
public:
    explicit SecurityPost(const std::string& name);
    virtual ~SecurityPost() {}
    virtual void update(const Notice& notice);

private:
    bool exitMode;
};

#endif
