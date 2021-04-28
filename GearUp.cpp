#include "GearUp.h"

void GearUp::fillTableRolls(Equipment gear) {
    this->attRollTable = gear.attBonusTable;
    this->strRollTable = gear.strBonusTable;
    this->speedTable = gear.speedTable;
}

void GearUp::fillPotionBoosts(Equipment gear) {
    this->attPotBoost = new int[100];
    this->strPotBoost = new int[100];
    for (int i = 1; i <= 99; i++) {
        attPotBoost[i] = gear.getAttPotionBoost(i);
        strPotBoost[i] = gear.getStrPotionBoost(i);
    }
}

void GearUp::fillPrayerBoosts(Equipment gear) {
    this->attPrayerBoost = gear.getAttPrayerBoost();
    this->strPrayerboost = gear.getStrPrayerBoost();
}

void GearUp::fillOppInfo(Equipment gear) {
    this->oppDefLevel = gear.getOppDefLvl();
    this->oppDefBonus = gear.getOppDefBonus();
    this->oppHpLevel = gear.getOppHpLvl();
}

