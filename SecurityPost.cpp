/*u25571878: Kelly Rademeyer
u25044215: Hannah diedrick
u25038967: Shelby bodenstein
*/
#include "SecurityPost.h"
#include <iostream>

SecurityPost::SecurityPost(const std::string& nameIn)
    : EventUnit(nameIn, 0), exitMode(false) {}

void SecurityPost::update(const Notice& notice) {
    switch (notice.type) {
        case NoticeType::EVACUATE:
            exitMode = true;
            openState = true;
            std::cout << "[security] " << name<< " opens evacuation routes and directs the crowd outward.\n";
            break;
        case NoticeType::CAPACITY_ALERT:
        case NoticeType::CROWD_SURGE:
            std::cout << "[security] " << name<< " creates a one-way crowd route and redirects arrivals.\n";
            break;
        case NoticeType::WEATHER_ALERT:
            std::cout << "[security] " << name<< " remains operational and protects restricted areas.\n";
            break;
        case NoticeType::RESUME:
            exitMode = false;
            std::cout << "[security] " << name<< " returns to normal crowd-control mode.\n";
            break;
        default:
            std::cout << "[security] " << name<< " acknowledges: " << notice.message << "\n";
            break;
    }
}
