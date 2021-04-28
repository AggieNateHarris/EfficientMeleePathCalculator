#ifndef GEARUP_H
#define GEARUP_H
#include "Equipment.h"

// Gear up is meant to hold tabales for each possible equipment impacting level combination for attack and str rolls and weapon speed
// The reason for this seperate table from Equipment class is because passing the large and very filled Equipment object everytime
// an exp/hr calculation was performed was causing the program to run very slow, this is an idea to possibly speed the program up
class GearUp
{
public:
    // int pointer tables are made up of all the different equipment unlock stat combinations: (<40, <40, <10), (<40, <40, 10), (<40, <40, 20), ..., def 30, 40, 42, 50, 60, 65, 70, 75
    int* attRollTable;                                              // The tables for each will be ordered in the following manner
    int* strRollTable;                                              // Index 0-10: (<40, <40, <10), ..., (<40, <40, >=75)
    float* speedTable;                                              // Index 11-21: (<40, 59-40, <10), ..., (<40, 59-40, >=75)
    int* attPotBoost;                                             // Index 22-32: (<40, >=60, <10), ..., (<40, 59-40, >=75)
    int* strPotBoost;                                             // Index 33-43: (40, <40, <10), ..., (40, <40, >=75)
    float attPrayerBoost;                                           // Index 44-65: " ^ " 59-40 str, 60+ str
    float strPrayerboost;                                           // Index 66-99: " " 50 att combinations
    int oppDefLevel;                                                // Index 100-198: " " 60, 70, 75 att combinations
    int oppDefBonus;
    int oppHpLevel;

    void fillTableRolls(Equipment gear);
    void fillPotionBoosts(Equipment gear);
    void fillPrayerBoosts(Equipment gear);
    void fillOppInfo(Equipment gear);
};

#endif