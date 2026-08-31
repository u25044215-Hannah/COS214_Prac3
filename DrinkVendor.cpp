
/*u25571878: Kelly Rademeyer
u25044215: Hannah diedrick
u25038967: Shelby bodenstein
*/#include "DrinkVendor.h"
#include <iostream>

DrinkVendor::DrinkVendor(const std::string& nameIn)
    : EventUnit(nameIn, 35), waterPriority(false) {}

void DrinkVendor::update(const Notice& notice) {
    switch (notice.type) {
        case NoticeType::OPEN:
            open();
            break;
        case NoticeType::CLOSE:
        case NoticeType::EVACUATE:
            close();
            std::cout << "[Drink] " << name
                    << " stops service and secures the serving area.\n";
            break;
        case NoticeType::HYDRATION_ALERT:
            waterPriority = true;
            std::cout << "[Drink] " << name
                    << " switches to water-priority service.\n";
            break;
        case NoticeType::RESUME:
            waterPriority = false;
            std::cout << "[Drink] " << name
                    << " returns to normal beverage service.\n";
            break;
        case NoticeType::CAPACITY_ALERT:
        case NoticeType::CROWD_SURGE:
            std::cout << "[Drink] " << name
                    << " shortens the queue footprint and keeps access lanes open.\n";
            break;
        default:
            std::cout << "[Drink] " << name
                    << " records notice: " << notice.message << "\n";
            break;
    }
}
