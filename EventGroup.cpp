
/*u25571878: Kelly Rademeyer
u25044215: Hannah diedrick
u25038967: Shelby bodenstein
*/
#include "EventGroup.h"
#include <algorithm>
#include <iostream>

EventGroup::EventGroup(const std::string& nameIn): name(nameIn), openState(false) {}

EventGroup::~EventGroup() {
    // empty vector of pointers
    observers.clear();

    // delete all children (composite tree)
    for (std::size_t iCount = 0; iCount < children.size(); ++iCount) {
        delete children[iCount];
    }
    children.clear();

    std::cout << "[destroy group] " << name << "\n";
}

bool EventGroup::addChild(EventComponent* child) {
    if (child == 0) {
        return false;
    }

    if (std::find(children.begin(), children.end(), child) !=children.end()) {
        return false;
    }
    children.push_back(child);
    return true;
}

EventComponent* EventGroup::removeChild(EventComponent* child) {
    std::vector<EventComponent*>::iterator it = std::find(children.begin(), children.end(), child);

    if (it ==children.end()) {
        return 0;
    }

    EventComponent* released = *it;
    children.erase(it);
    return released;
}

bool EventGroup::transferChild(EventComponent* child, EventGroup* destination) {
    //reject null pointers and self-transfer
    if (child== 0 ||destination ==0 || destination ==this) {
        return false;
    }

    detach(child);

    EventComponent* released= removeChild(child);
    if (released ==0) {
        return false;
    }


    if (!destination->addChild(released)) {
        addChild(released);
        attach(released);
        return false;

    }

    
    destination->attach(released);
    return true;
}

void EventGroup::open() {
    openState = true;
    std::cout << "[open group] " << name << "\n";

    for (std::size_t iCount = 0; iCount < children.size(); ++iCount) {
        children[iCount]->open();
    }
}

void EventGroup::close() {
    openState = false;
    std::cout << "[close group] " << name << "\n";

    for (std::size_t iCount = 0; iCount < children.size(); ++iCount) {
        children[iCount]->close();
    }
}

void EventGroup::reportStatus() const {
    std::cout << "\n[group status] " << name<< " | " << (openState ? "open" : "closed")<< " | aggregate capacity=" << getCapacity()<< " | children=" << children.size() << "\n";

    for (std::size_t iCount = 0; iCount < children.size(); ++iCount) {
        children[iCount]->reportStatus();
    }
}

int EventGroup::getCapacity() const {
    int total =0;
    for (std::size_t iCount= 0; iCount < children.size(); ++iCount) {
        total += children[iCount]->getCapacity();
    }
    return total;
}

const std::string& EventGroup::getName() const {
    return name;
}

void EventGroup::update(const Notice& notice) {
    std::cout << "[group received] " << name<< " <- " << notice.message << "\n";

    if (notice.type == NoticeType::OPEN) {
        openState= true;
    } else if (notice.type ==NoticeType::CLOSE ||notice.type == NoticeType::EVACUATE) {
        openState =false;
    }
    notify(notice);
}

std::size_t EventGroup::childCount() const {
    return children.size();
}
