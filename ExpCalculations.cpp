#include "ExpCalculations.h"
#include <algorithm>

int ExpCalculations::expLeft(int end) {
    if (end > 99 || end < 1)
        std::cout << "Value Range Error: Exp to level tried for a level greater than 99 or less than 1.\n";
    else
        return ExpTable[end - 1];
}

//Stance{ 1 : attack, 2 : strength, 3 : defence }, standard +8 stance boost, +11 with stance boost
double ExpCalculations::expHr(int startAtt, int startStr, int startDef, int checkAtt, int checkStr, int checkDef, int endAtt, int endStr, int endDef, int stance, GearUp gearUp) {
    int tableIndex = ExpCalculations::findLocation(startAtt, startStr, startDef, checkAtt, checkStr, checkDef, endAtt, endStr, endDef);
    int attBonus = gearUp.attBonusTable[tableIndex];
    int strBonus = gearUp.strBonusTable[tableIndex];
    int attPotionBoost = gearUp.attPotBoost[checkAtt];
    float strPotionBoost = gearUp.strPotBoost[checkStr];
    float attPrayerBoost = gearUp.attPrayerBoost;
    float strPrayerBoost = gearUp.strPrayerboost;
    float attackSpeed = gearUp.speedTable[tableIndex]; // Seconds per attack, EX: 4 tic = 2.4 seconds. -> 4 * 0.6 = 2.4
    int oppDefBonus = gearUp.oppDefBonus;
    int oppDefLvl = gearUp.oppDefLevel;
    float oppHpLvl = gearUp.oppHpLevel;
    int attStance = 8, strStance = 8, defStance = 8;
    if (stance == 1)
        attStance = 11;
    else if (stance == 2)
        strStance = 11;
    else if (stance == 3)
        defStance = 11;

    float attRoll = (((checkAtt + attPotionBoost) * attPrayerBoost) + attStance)* (64 + attBonus);                             //Effective lvl * (64 + att bonus)   SOURCE BITTERKOEKJE DPS SHEET
    float strRoll = floor(0.5 + ((((checkStr + strPotionBoost) * strPrayerBoost) + strStance) * (64 + strBonus) / 640));     //0.5 + (Effective level * ((64 + str bonus) / 640))
    float oppDefRoll = (9 + oppDefLvl) * (64 + oppDefBonus);                                                                        //(9 + def lvl) * (64 + def bonus)
    float accuracy;

    // Formula for accuracy changes depending on whether the max attacking roll or the max defending roll is higher
    if (attRoll > oppDefRoll) {
        accuracy = 1 - ((oppDefRoll + 2) / (2 * (attRoll + 1)));
    }
    else {
        accuracy = attRoll / (2 * (oppDefRoll + 1));
    }

    // Avg dmg overkill: accuracy * min(max hit, opp hp) * (min(max hit, opp hp)) * (((opp hp + max hit + 1)/(opp hp * (max hit + 1) * 2 )) - (2 / (opp hp * (max hit + 1) * 6 )) * ( 2 * min(max hit, opp hp) + 1 ))
    // Overkill Dps: Avg dmg overkill / attack speed(seconds/attack)
    float avgDmgOvekill = accuracy * std::min(strRoll, oppHpLvl) * (std::min(strRoll, oppHpLvl)) * 
                         (((oppHpLvl + strRoll + 1) / (oppHpLvl * (strRoll + 1) * 2)) - (2 / (oppHpLvl * (strRoll + 1) * 6)) * (2 * std::min(strRoll, oppHpLvl) + 1));
    
    float overkillDps = avgDmgOvekill / attackSpeed;

    //std::cout << "Debug: Stance:" << stance << " Stats:" << att << " " << str << " " << def << " Exp/hr:" << 4 * overkillDps * 3600 << '\n';

    return (4 * overkillDps * 3600); // 4 exp per damage, 3600 seconds per hour, return exp/hr
}

int ExpCalculations::findLocation(int startAtt, int startStr, int startDef, int checkAtt, int checkStr, int checkDef, int endAtt, int endStr, int endDef) {
    // Third digit strength refers to att in (att, str, def) in a location object, the strength is the number of
    // combinations of str and def that must be gone through before att will be raised by 1
    // Uses absolute start and end points
    int thirdDigitStrength = ((endStr - startStr) * (endDef - (startDef - 1))) + (endDef - (startDef - 1));

    // Second digit strength refers to str in (att, str, def) in a location object, the strength is the number of
    // combinations of def that must be gone through before str will be raised by 1
    // Uses absolute start and end points
    int secondDigitStrength = (endDef - (startDef - 1));

    // the ranges are the number of values between the starting and ending, ending included
    // def includes the starting value whereas the others do not, so the def formula includes a -1
    // Uses absolute start and desired endpoint
    int attRange = checkAtt - startAtt;
    int strRange = checkStr - startStr;
    int defRange = checkDef - (startDef - 1);

    return (attRange * thirdDigitStrength) + (strRange * secondDigitStrength) + (defRange);
}
