
/*u25571878: Kelly Rademeyer
u25044215: Hannah diedrick
u25038967: Shelby bodenstein
*/
#include "EventGroup.h"
#include <algorithm>
#include <iostream>

EventGroup::EventGroup(const std::string& nameIn)
    : name(nameIn), openState(false) {}

EventGroup::~EventGroup() {
    // Registrations are non-owning. Clear them before owned descendants die.
    observers.clear();

    for (std::size_t i = 0; i < children.size(); ++i) {
        delete children[i];
    }
    children.clear();

    std::cout << "[DESTROY GROUP] " << name << "\n";
}

bool EventGroup::addChild(EventComponent* child) {
    if (child == 0) {
        return false;
    }

    if (std::find(children.begin(), children.end(), child) != children.end()) {
        return false;
    }

    children.push_back(child);
    return true;
}

EventComponent* EventGroup::removeChild(EventComponent* child) {
    std::vector<EventComponent*>::iterator it =
        std::find(children.begin(), children.end(), child);

    if (it == children.end()) {
        return 0;
    }

    EventComponent* released = *it;
    children.erase(it);
    return released;
}

bool EventGroup::transferChild(EventComponent* child, EventGroup* destination) {
    if (child == 0 || destination == 0 || destination == this) {
        return false;
    }

    // Observer registration and Composite ownership are intentionally separate.
    // We update both here because a transfer changes both collaborations.
    detach(child);

    EventComponent* released = removeChild(child);
    if (released == 0) {
        return false;
    }

    if (!destination->addChild(released)) {
        // Roll back ownership if destination unexpectedly rejects it.
        addChild(released);
        attach(released);
        return false;
    }

    destination->attach(released);
    return true;
}

void EventGroup::open() {
    openState = true;
    std::cout << "[OPEN GROUP] " << name << "\n";

    for (std::size_t i = 0; i < children.size(); ++i) {
        children[i]->open();
    }
}

void EventGroup::close() {
    openState = false;
    std::cout << "[CLOSE GROUP] " << name << "\n";

    for (std::size_t i = 0; i < children.size(); ++i) {
        children[i]->close();
    }
}

void EventGroup::reportStatus() const {
    std::cout << "\n[GROUP STATUS] " << name
              << " | " << (openState ? "OPEN" : "CLOSED")
              << " | aggregate capacity=" << getCapacity()
              << " | children=" << children.size() << "\n";

    for (std::size_t i = 0; i < children.size(); ++i) {
        children[i]->reportStatus();
    }
}

int EventGroup::getCapacity() const {
    int total = 0;
    for (std::size_t i = 0; i < children.size(); ++i) {
        total += children[i]->getCapacity();
    }
    return total;
}

const std::string& EventGroup::getName() const {
    return name;
}

void EventGroup::update(const Notice& notice) {
    std::cout << "[GROUP RECEIVED] " << name
              << " <- " << notice.message << "\n";

    if (notice.type == NoticeType::OPEN) {
        openState = true;
    } else if (notice.type == NoticeType::CLOSE ||
               notice.type == NoticeType::EVACUATE) {
        openState = false;
    }

    // Cascade to observers registered with this group.
    notify(notice);
}

std::size_t EventGroup::childCount() const {
    return children.size();
}
