#include "EventControl.h"
#include <iostream>

EventControl::EventControl(const std::string& nameIn)
    : name(nameIn) {}

void EventControl::issueNotice(const Notice& notice) {
    std::cout << "\n=== " << name << " ISSUES NOTICE ===\n"
              << notice.message
              << " | area=" << notice.location
              << " | value=" << notice.value << "\n";
    notify(notice);
}

const std::string& EventControl::getName() const {
    return name;
}
