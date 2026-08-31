#ifndef OBSERVER_H
#define OBSERVER_H

#include "Notice.h"

/**
 * @brief GoF Observer participant for objects that receive Lentedag notices.
 */
class Observer {
public:
    virtual ~Observer() {}

    /**
     * @brief Receive a pushed notice from a Subject.
     * @param notice Notice state pushed by the Subject.
     */
    virtual void update(const Notice& notice) = 0;
};

#endif
