#ifndef GEARUP_H
#define GEARUP_H
#include "Equipment.h"

// Gear up is meant to hold tabales for each possible equipment impacting level combination for attack and str rolls and weapon speed
// The reason for this seperate table from Equipment class is because passing the large and very filled Equipment object everytime
// an exp/hr calculation was performed was causing the program to run very slow, this is an idea to possibly speed the program up
class GearUp
{
public:
    // int pointer tables are tables of bonuses depending on relevant variables such as att,str,def, equipment selection, potion selection
    int* attBonusTable = nullptr;
    int* strBonusTable = nullptr;
    float* speedTable;
    int* attPotBoost;
    int* strPotBoost;

    // prayer boosts are a single value that is found during equipment settings, currently only 1 prayer for entirety of training is supported
    float attPrayerBoost;
    float strPrayerboost;

    // opponent information is found during equipment settings and these values are set to those
    int oppDefLevel;
    int oppDefBonus;
    int oppHpLevel;

    // functions to transfer information found in equipment settings to this object
    // this was done because passing an equipment object was very slow so only the essential information found
    // in the equipment object is stored here, where this object will be passed around and used frequently
    void fillTableRolls(Equipment gear);
    void fillPotionBoosts(Equipment gear);
    void fillPrayerBoosts(Equipment gear);
    void fillOppInfo(Equipment gear);
};

#endif