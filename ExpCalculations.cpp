#include "ExpCalculations.h"
#include <algorithm>

int ExpCalculations::expLeft(int end) {
    if (end > 99 || end < 1)
        std::cout << "Value Range Error: Exp to level tried for a level greater than 99 or less than 1.\n";
    else
        return ExpTable[end - 1];
}

double ExpCalculations::expHr(int att, int str, int def, int stance, Equipment player) { //Stance{ 1 : attack, 2 : strength, 3 : defence }, standard +8 stance boost, +11 with stance boost
    int attBonus = player.getAttBonus(att, str, def);
    int strBonus = player.getStrBonus(att, str, def);
    int attPotionBoost = player.getAttPotionBoost(att);
    float strPotionBoost = player.getStrPotionBoost(str);
    float attPrayerBoost = player.getAttPrayerBoost();
    float strPrayerBoost = player.getStrPrayerBoost();
    float attackSpeed = player.getSpeed(att, str, def); // Seconds per attack, EX: 4 tic = 2.4 seconds. -> 4 * 0.6 = 2.4
    int oppDefBonus = player.getOppDefBonus();
    int oppDefLvl = player.getOppDefLvl();
    float oppHpLvl = player.getOppHpLvl();
    int attStance = 8, strStance = 8, defStance = 8;
    if (stance == 1)
        attStance = 11;
    else if (stance == 2)
        strStance = 11;
    else if (stance == 3)
        defStance = 11;

    float attRoll = ((att * attPotionBoost * attPrayerBoost) + attStance)* (64 + attBonus);                          //Effective lvl * (64 + att bonus)   SOURCE BITTERKOEKJE DPS SHEET
    float strRoll = floor(0.5 + (((str * strPotionBoost * strPrayerBoost) + strStance) * (64 + strBonus) / 640));    //0.5 + (Effective level * ((64 + str bonus) / 640))
    float oppDefRoll = (9 + oppDefLvl) * (64 + oppDefBonus);                                                         //(9 + def lvl) * (64 + def bonus)
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
