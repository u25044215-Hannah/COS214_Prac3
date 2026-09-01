/*u25571878: Kelly Rademeyer
u25044215: Hannah diedrick
u25038967: Shelby bodenstein
*/
#include "EntranceGate.h"
#include <iostream>

EntranceGate::EntranceGate(const std::string& nameIn)
    : EventUnit(nameIn, 0), admitting(false) {}

void EntranceGate::update(const Notice& notice) {
    switch (notice.type) {
        case NoticeType::OPEN:
            openState = true;
            admitting = true;
            std::cout << "[Gate] " << name << " begins admitting attendees.\n";
            break;
        case NoticeType::CAPACITY_ALERT:
        case NoticeType::CROWD_SURGE:
            admitting = false;
            std::cout << "[Gate] " << name
                << " pauses new entry but remains available for exit.\n";
            break;
        case NoticeType::EVACUATE:
            admitting = false;
            openState = true;
            std::cout << "[Gate] " << name
                << " switches to exit-only evacuation flow.\n";
            break;
        case NoticeType::CLOSE:
            close();
            admitting = false;
            break;
        case NoticeType::RESUME:
            openState = true;
            admitting = true;
            std::cout << "[Gate] " << name << " resumes normal admission.\n";
            break;
        default:
            std::cout << "[Gate] " << name
                << " records notice: " << notice.message << "\n";
            break;
    }
}
