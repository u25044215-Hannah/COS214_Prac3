#include "EventUnit.h"
#include <iostream>

EventUnit::EventUnit(const std::string& nameIn, int capacityIn): name(nameIn), openState(false), capacity(capacityIn) {}

void EventUnit::open() {
    openState = true;
    std::cout << "[open] " << name << "\n";
}

void EventUnit::close() {
    openState = false;
    std::cout << "[close] " << name << "\n";
}

void EventUnit::reportStatus() const {
    std::cout << name << " | " << (openState ? "open" : "closed") << " | capacity=" << capacity << "\n";
}

int EventUnit::getCapacity() const {
    return capacity;
}

const std::string& EventUnit::getName() const {
    return name;
}

bool EventUnit::isOpen() const {
    return openState;
}
