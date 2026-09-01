#include <iostream>
#include "EventControl.h"
#include "EventGroup.h"
#include "Stage.h"
#include "FoodVendor.h"
#include "DrinkVendor.h"
#include "SecurityPost.h"
#include "MedicalUnit.h"
#include "EntranceGate.h"
#include "InfoPoint.h"
#include "CleaningTeam.h"

int main() {
    EventControl control("Lentedag Control");

    // Root Composite.
    EventGroup* lentedag = new EventGroup("Lentedag Spring Music Festival");

    // Level 1 groups.
    EventGroup* musicPrecinct = new EventGroup("Music Precinct");
    EventGroup* marketPrecinct = new EventGroup("Spring Market Precinct");
    EventGroup* supportPrecinct = new EventGroup("Festival Support Precinct");

    lentedag->addChild(musicPrecinct);
    lentedag->addChild(marketPrecinct);
    lentedag->addChild(supportPrecinct);

    // Level 2 groups.
    EventGroup* centralDistrict = new EventGroup("Central Stage District");
    EventGroup* gardenDistrict = new EventGroup("Garden Stage District");
    musicPrecinct->addChild(centralDistrict);
    musicPrecinct->addChild(gardenDistrict);

    EventGroup* foodVillage = new EventGroup("Food Village");
    marketPrecinct->addChild(foodVillage);

    EventGroup* wellnessZone = new EventGroup("Wellness and Information Zone");
    supportPrecinct->addChild(wellnessZone);

    // Level 3 groups under the stage districts.
    EventGroup* jacarandaArea = new EventGroup("Jacaranda Stage Area");
    EventGroup* blossomArea = new EventGroup("Blossom Stage Area");
    EventGroup* sunflowerArea = new EventGroup("Sunflower Stage Area");
    EventGroup* duskArea = new EventGroup("Dusk Stage Area");
    EventGroup* springGardenArea = new EventGroup("Spring Garden Stage Area");

    centralDistrict->addChild(jacarandaArea);
    centralDistrict->addChild(blossomArea);
    gardenDistrict->addChild(sunflowerArea);
    gardenDistrict->addChild(duskArea);
    gardenDistrict->addChild(springGardenArea);

    EventGroup* vendorRow = new EventGroup("Vendor Row");
    foodVillage->addChild(vendorRow);

    EventGroup* medicalHub = new EventGroup("Medical and Information Hub");
    wellnessZone->addChild(medicalHub);

    // Concrete leaves (5+ distinct leaf TYPES).
    Stage* jacarandaStage = new Stage("Jacaranda Main Stage", 5000, true);
    Stage* blossomStage = new Stage("Blossom Stage", 3000, true);
    Stage* sunflowerStage = new Stage("Sunflower Stage", 2200, true);
    Stage* duskStage = new Stage("Dusk Stage", 1800, true);
    Stage* springGardenStage = new Stage("Spring Garden Stage", 1200, true);

    EntranceGate* mainGate = new EntranceGate("Jacaranda Crowd Gate");
    SecurityPost* mainSecurity = new SecurityPost("Jacaranda Security Post");
    DrinkVendor* stageWater = new DrinkVendor("Spring Water Bar");

    FoodVendor* foodVendor = new FoodVendor("Bloom Bites");
    DrinkVendor* drinkVendor = new DrinkVendor("Petal Drinks");
    CleaningTeam* cleaningTeam = new CleaningTeam("Spring Clean Team");

    MedicalUnit* medical = new MedicalUnit("First Aid Team");
    InfoPoint* info = new InfoPoint("Lentedag Info Point");

    jacarandaArea->addChild(jacarandaStage);
    jacarandaArea->addChild(mainGate);
    jacarandaArea->addChild(mainSecurity);
    jacarandaArea->addChild(stageWater);

    blossomArea->addChild(blossomStage);
    sunflowerArea->addChild(sunflowerStage);
    duskArea->addChild(duskStage);
    springGardenArea->addChild(springGardenStage);

    vendorRow->addChild(foodVendor);
    vendorRow->addChild(drinkVendor);
    vendorRow->addChild(cleaningTeam);

    medicalHub->addChild(medical);
    medicalHub->addChild(info);

    // Observer registrations are deliberately separate from ownership.
    control.attach(lentedag);

    lentedag->attach(musicPrecinct);
    lentedag->attach(marketPrecinct);
    lentedag->attach(supportPrecinct);

    musicPrecinct->attach(centralDistrict);
    musicPrecinct->attach(gardenDistrict);

    centralDistrict->attach(jacarandaArea);
    centralDistrict->attach(blossomArea);

    gardenDistrict->attach(sunflowerArea);
    gardenDistrict->attach(duskArea);
    gardenDistrict->attach(springGardenArea);

    marketPrecinct->attach(foodVillage);
    foodVillage->attach(vendorRow);

    supportPrecinct->attach(wellnessZone);
    wellnessZone->attach(medicalHub);

    jacarandaArea->attach(jacarandaStage);
    jacarandaArea->attach(mainGate);
    jacarandaArea->attach(mainSecurity);
    jacarandaArea->attach(stageWater);

    blossomArea->attach(blossomStage);
    sunflowerArea->attach(sunflowerStage);
    duskArea->attach(duskStage);
    springGardenArea->attach(springGardenStage);

    vendorRow->attach(foodVendor);
    vendorRow->attach(drinkVendor);
    vendorRow->attach(cleaningTeam);

    medicalHub->attach(medical);
    medicalHub->attach(info);

    std::cout << "\n===== BUILD COMPLETE =====\n";
    std::cout << "Lentedag aggregate capacity: "
              << lentedag->getCapacity() << "\n";

    // Composite recursive operation.
    lentedag->open();

    // Notice 1: schedule change.
    control.issueNotice(
        Notice(NoticeType::SCHEDULE_CHANGE,
               "Jacaranda headline set delayed by 20 minutes.",
               "Lentedag Control",
               "Jacaranda Stage Area",
               20));

    // Notice 2: capacity condition + crowd response.
    jacarandaStage->setAttendance(4700);
    if (jacarandaStage->atCapacityThreshold(0.90)) {
        control.issueNotice(
            Notice(NoticeType::CAPACITY_ALERT,
                   "Jacaranda Stage has reached the 90% crowd threshold.",
                   "Lentedag Control",
                   "Jacaranda Stage Area",
                   jacarandaStage->getAttendance()));
    }

    // Notice 3: original Lentedag hydration feature.
    control.issueNotice(
        Notice(NoticeType::HYDRATION_ALERT,
               "High afternoon temperature: prioritise water and hydration messaging.",
               "Lentedag Control",
               "Festival-wide",
               34));

    // Runtime reorganisation: move cleaning team from Vendor Row to Jacaranda.
    std::cout << "\n===== RUNTIME REORGANISATION =====\n";
    if (vendorRow->transferChild(cleaningTeam, jacarandaArea)) {
        std::cout << "Spring Clean Team transferred to Jacaranda Stage Area.\n";
    }

    // Registration change demonstration: Info Point temporarily leaves notices.
    std::cout << "\n===== REGISTRATION CHANGE =====\n";
    bool detached = medicalHub->detach(info);
    std::cout << "Info Point detached from Medical Hub: "
              << (detached ? "yes" : "no") << "\n";

    control.issueNotice(
        Notice(NoticeType::CLEANUP_REQUEST,
               "Large post-performance cleanup required near Jacaranda.",
               "Lentedag Control",
               "Jacaranda Stage Area"));

    // Re-register Info Point for later notices.
    medicalHub->attach(info);

    // Weather safety + recovery.
    control.issueNotice(
        Notice(NoticeType::WEATHER_ALERT,
               "Lightning detected near the festival: pause exposed performances.",
               "Lentedag Control",
               "Festival-wide"));

    control.issueNotice(
        Notice(NoticeType::RESUME,
               "Weather clearance received: normal operations may resume.",
               "Lentedag Control",
               "Festival-wide"));

    // Composite traversal/report.
    std::cout << "\n===== FINAL STATUS TRAVERSAL =====\n";
    lentedag->reportStatus();

    // Prevent EventControl from retaining a non-owning pointer to deleted root.
    control.detach(lentedag);

    std::cout << "\n===== CLEAN SHUTDOWN =====\n";
    delete lentedag;
    lentedag = 0;

    return 0;
}
