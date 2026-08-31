#ifndef SUBJECT_H
#define SUBJECT_H

#include <vector>
#include "Observer.h"

/**
 * @brief GoF Subject abstraction storing non-owning observer pointers.
 *
 * Subject never deletes observers. Ownership belongs to the Composite tree.
 * Notification iterates over a snapshot so registration changes affect the
 * next notification cycle rather than invalidating the current iteration.
 */
class Subject {
public:
    virtual ~Subject();

    /**
     * @brief Register an observer.
     * @param observer Non-owning observer pointer. Must not be nullptr.
     * @return true if registered; false for nullptr or duplicate registration.
     */
    virtual bool attach(Observer* observer);

    /**
     * @brief Deregister an observer.
     * @param observer Observer pointer to remove.
     * @return true if removed; false if it was not registered.
     */
    virtual bool detach(Observer* observer);

    /**
     * @brief Push a notice to all observers registered at the start of the cycle.
     * @param notice Notice to push.
     */
    virtual void notify(const Notice& notice);

    /**
     * @brief Number of currently registered observers.
     * @return Registration count.
     */
    std::size_t observerCount() const;

protected:
    std::vector<Observer*> observers;
};

#endif
