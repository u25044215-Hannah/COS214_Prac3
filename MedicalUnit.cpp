#include "MedicalUnit.h"
#include <iostream>

MedicalUnit::MedicalUnit(const std::string& nameIn): EventUnit(nameIn, 0), emergencyMode(false) {
    openState = true;
}

void MedicalUnit::update(const Notice& notice) {
    switch (notice.type) {
        case NoticeType::EVACUATE:
        case NoticeType::WEATHER_ALERT:
        case NoticeType::CROWD_SURGE:
            emergencyMode = true;
            openState = true;
            std::cout << "[Medical] " << name<< " stays active and enters emergency response mode.\n";
            break;
        case NoticeType::HYDRATION_ALERT:
            emergencyMode = true;
            std::cout << "[Medical] " << name << " prepares heat and dehydration support.\n";
            break;
        case NoticeType::RESUME:
            emergencyMode = false;
            std::cout << "[Medical] " << name<< " returns to normal medical standby.\n";
            break;
        default:
            std::cout << "[Medical] " << name<< " remains available while recording: " << notice.message << "\n";
            break;
    }
}
