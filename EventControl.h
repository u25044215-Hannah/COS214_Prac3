#ifndef EVENT_CONTROL_H
#define EVENT_CONTROL_H

#include <string>
#include "Subject.h"

/**
 * @brief Concrete Subject representing Lentedag central festival control.
 */
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
