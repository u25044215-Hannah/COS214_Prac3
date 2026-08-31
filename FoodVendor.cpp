#include "FoodVendor.h"
#include <iostream>

FoodVendor::FoodVendor(const std::string& nameIn): EventUnit(nameIn, 40) {}

void FoodVendor::update(const Notice& notice) {
    switch (notice.type) {
        case NoticeType::OPEN:
            open();
            break;
        case NoticeType::CLOSE:
        case NoticeType::EVACUATE:
            close();
            std::cout << "[food] " << name << " secures cooking equipment and stops service.\n";
            break;
        case NoticeType::WEATHER_ALERT:
            std::cout << "[food] " << name << " secures outdoor equipment and continues only if safe.\n";
            break;
        case NoticeType::CAPACITY_ALERT:
        case NoticeType::CROWD_SURGE:
            std::cout << "[food] " << name << " keeps queues inside marked vendor lanes.\n";
            break;
        case NoticeType::HYDRATION_ALERT:
            std::cout << "[food] " << name<< " highlights high-water food options.\n";
            break;
        default:
            std::cout << "[food] " << name << " records notice: " << notice.message << "\n";
            break;
    }
}
