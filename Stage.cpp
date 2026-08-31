/*u25571878: Kelly Rademeyer
u25044215: Hannah diedrick
u25038967: Shelby bodenstein
*/
#include "Stage.h"
#include <iostream>

Stage::Stage(const std::string& nameIn, int capacityIn, bool outdoorIn)
    : EventUnit(nameIn, capacityIn),
    outdoor(outdoorIn),
    paused(false),
    attendance(0),
    scheduleMessage("On schedule") {}

void Stage::update(const Notice& notice) {
    switch (notice.type) {
        case NoticeType::OPEN:
            open();
            break;
        case NoticeType::CLOSE:
            close();
            break;
        case NoticeType::SCHEDULE_CHANGE:
            scheduleMessage = notice.message;
            std::cout << "[Stage] " << name<< " updates running order: " << notice.message << "\n";
            break;
        case NoticeType::CAPACITY_ALERT:
        case NoticeType::CROWD_SURGE:
            std::cout << "[Stage] " << name<< " pauses further audience entry and protects performance area.\n";
            break;
        case NoticeType::WEATHER_ALERT:
            if (outdoor) {
                paused = true;
                std::cout << "[Stage] " << name << " pauses performance because it is outdoors.\n";
            } else {
                std::cout << "[Stage] " << name<< " continues because it is sheltered.\n";
            }
            break;
        case NoticeType::PAUSE:
            paused = true;
            std::cout << "[Stage] " << name << " pauses the performance.\n";
            break;
        case NoticeType::RESUME:
            paused = false;
            std::cout << "[Stage] " << name << " resumes the performance.\n";
            break;
        case NoticeType::EVACUATE:
            paused = true;
            close();
            std::cout << "[Stage] " << name << " stops sound and begins audience evacuation.\n";
            break;
        case NoticeType::HYDRATION_ALERT:
            std::cout << "[Stage] " << name<< " displays a hydration reminder between acts.\n";
            break;
        case NoticeType::CLEANUP_REQUEST:
            std::cout << "[Stage] " << name<< " keeps a service lane clear for the cleaning response.\n";
            break;
    }
}

void Stage::reportStatus() const {
    std::cout << name<< " | Stage | " << (openState ? "Open" : "Closed")<< " | paused=" << (paused ? "yes" : "no")<< " | attendance=" << attendance << "/" << capacity << " | " << scheduleMessage << "\n";
}

void Stage::setAttendance(int attendanceIn) {
    if (attendanceIn < 0) 
    {
        attendanceIn = 0;
    }
    if (attendanceIn > capacity) 
    {
        attendanceIn = capacity;
    }
    attendance = attendanceIn;
}

int Stage::getAttendance() const {
    return attendance;
}

bool Stage::atCapacityThreshold(double fraction) const {
    return capacity > 0 && attendance >= static_cast<int>(capacity * fraction);
}
