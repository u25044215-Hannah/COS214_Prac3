/*u25571878: Kelly Rademeyer
u25044215: Hannah diedrick
u25038967: Shelby bodenstein
*/
#include "InfoPoint.h"
#include <iostream>

InfoPoint::InfoPoint(const std::string& nameIn): EventUnit(nameIn, 0), displayMessage("Welcome to Lentedag") {
    openState = true;
}

void InfoPoint::update(const Notice& notice) {
    displayMessage = notice.message;
    std::cout << "[Info] " << name << " displays: " << displayMessage << "\n";
}

void InfoPoint::reportStatus() const {
    std::cout << name << " | INFO | "<< (openState ? "Open" : "Closed")<< " | display=\"" << displayMessage << "\"\n";
}
