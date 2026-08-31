/*u25571878: Kelly Rademeyer
u25044215: Hannah diedrick
u25038967: Shelby bodenstein
*/
#include "CleaningTeam.h"
#include <iostream>

CleaningTeam::CleaningTeam(const std::string& nameIn): EventUnit(nameIn, 0) {
    openState = true;
}

void CleaningTeam::update(const Notice& notice) 
{
    if (notice.type == NoticeType::CLEANUP_REQUEST) 
    {
        std::cout << "[cleaning] "<< name<< " responds to cleanup at "<< notice.location << ".\n";
    } 
    else if (notice.type == NoticeType::EVACUATE) 
    {
        std::cout <<"[cleaning] " << name << " clears access routes and leaves the danger area.\n";
    } 
    else 
    {
        std::cout << "[cleaning] " << name<< " acknowledges: "<< notice.message << "\n";
    }
}
