#include "GearUp.h"

// fillTable rolls is meant to load this GearUp object with the att,str, and speed table info from an Equipment object
// The tables are filled out in Equipment settings() and depend on att, str, def levels, and equipment selection
void GearUp::fillTableRolls(Equipment gear) {
    this->attBonusTable = gear.attBonusTable;
    this->strBonusTable = gear.strBonusTable;
    this->speedTable = gear.speedTable;
}

// Fill attack and strength boosts by selected potions and att/str levels
void GearUp::fillPotionBoosts(Equipment gear) {
    this->attPotBoost = new int[100];
    this->strPotBoost = new int[100];
    for (int i = 1; i <= 99; i++) {
        attPotBoost[i] = gear.getAttPotionBoost(i);
        strPotBoost[i] = gear.getStrPotionBoost(i);
    }
}

// Set this objects prayer boosts to those found in equipment settings
void GearUp::fillPrayerBoosts(Equipment gear) {
    this->attPrayerBoost = gear.getAttPrayerBoost();
    this->strPrayerboost = gear.getStrPrayerBoost();
}

// Set this objects opp info to that found in equipment settings
void GearUp::fillOppInfo(Equipment gear) {
    this->oppDefLevel = gear.getOppDefLvl();
    this->oppDefBonus = gear.getOppDefBonus();
    this->oppHpLevel = gear.getOppHpLvl();
}