#include "Equipment.h"
#include <iostream>

// This bonus getter is making exp/hr calcs take way too long, need to come up with a solution to speed it up
// Plan to fix right now: calculate all individual attack bonus and strength bonus while doing the settings
// Have gearup copy those values over to itself and pass a gearup object instead of an equipment object
// make sure to get gearup any other values that it will need(potion and prayer boosts), opponent rolls

std::string Equipment::getWeapon(int att, int str, int def) {
    std::string weapon;
    if (att < 40 && str < 40)
        weapon = this->weapon1Att;
    else if (att < 40 && str >= 40 && str < 60)
        weapon = this->weapon1Att40Str;
    else if (att < 40 && str >= 60)
        weapon = this->weapon1Att60Str;
    else if (att >= 40 && att < 50)
        weapon = this->weapon40Att;
    else if (att >= 50 && att < 60)
        weapon = this->weapon50Att;
    else if (att >= 60 && att < 70)
        weapon = this->weapon60Att;
    else if (att >= 70 && att < 75)
        weapon = this->weapon70Att;
    else if (att >= 75)
        weapon = this->weapon75Att;
    return weapon;
}

std::string Equipment::getHelm(int att, int str, int def) {
    std::string helm;
    if (def < 45)
        helm = this->head30Def;
    else if (def < 55)
        helm = this->head45Def;
    else if (def < 60)
        helm = this->head55Def;
    else if (def < 70)
        helm = this->head60Def;
    else if (def < 75)
        helm = this->head70Def;
    else if (def >= 75)
        helm = this->head75Def;
    return helm;
}

std::string Equipment::getCape(int att, int str, int def) {
    std::string cape;
    if (def < 40)
        cape = this->cape1Def;
    else if (def < 70)
        cape = this->cape40Def;
    else if (def >= 70)
        cape = this->cape70Def;
    return cape;
}

std::string Equipment::getNecklace(int att, int str, int def) {
    std::string necklace;
    if (def < 40)
        necklace = this->necklace1Def;
    else if (def < 70)
        necklace = this->necklace40Def;
    else if (def >= 70)
        necklace = this->necklace70Def;
    return necklace;
}

std::string Equipment::getTorso(int att, int str, int def) {
    std::string torso;
    if (def < 40)
        torso = this->torso30Def;
    else if (def < 60)
        torso = this->torso40Def;
    else if (def < 65)
        torso = this->torso60Def;
    else if (def >= 65)
        torso = this->torso65Def;
    return torso;
}

std::string Equipment::getShield(int att, int str, int def) {
    std::string shield;
    if (def < 10)
        shield = this->shield10Def;
    else if (def < 20)
        shield = this->shield10Def;
    else if (def < 30)
        shield = this->shield20Def;
    else if (def < 40)
        shield = this->shield30Def;
    else if (def < 60)
        shield = this->shield40Def;
    else if (def < 70)
        shield = this->shield60Def;
    else if (def < 75 && att >= 70)
        shield = this->shield70Def70Att;
    else if (def >= 75 && att >= 70)
        shield = this->shield75Def70Att;
    else if (def >= 75)
        shield = this->shield75Def;
    return shield;
}

std::string Equipment::getLegs(int att, int str, int def) {
    std::string legs;
    if (def < 30)
        legs = this->legs1Def;
    else if (def < 60)
        legs = this->legs30Def;
    else if (def < 65)
        legs = this->legs60Def;
    else if (def >= 65)
        legs = this->legs65Def;
    return legs;
}

std::string Equipment::getGloves(int att, int str, int def) {
    std::string gloves;
    if (def < 32)
        gloves = this->gloves1Def;
    else if (def < 42)
        gloves = this->gloves32Def;
    else if (def < 80)
        gloves = this->gloves42Def;
    else if (def >= 80 && att >= 80)
        gloves = this->gloves80Def80Att;
    return gloves;
}

std::string Equipment::getBoots(int att, int str, int def) {
    std::string boots;
    if (def < 50)
        boots = this->boot1Def;
    else if (def < 60)
        boots = this->boot50Def;
    else if (def < 75)
        boots = this->boot60Def;
    else if (def >= 75)
        boots = this->boot75Def;
    return boots;
}

std::string Equipment::getRing(int att, int str, int def) {
    std::string ring;
    if (def < 50)
        ring = this->ring1Def;
    else if (def >= 50)
        ring = this->ring50Def;
    return ring;
}

int Equipment::getAttBonus(int att, int str, int def) {
    int attBonus = 0;
    attBonus += equipmentAtt[getWeapon(att, str, def)];
    attBonus += equipmentAtt[getHelm(att, str, def)];
    attBonus += equipmentAtt[getCape(att, str, def)];
    attBonus += equipmentAtt[getNecklace(att, str, def)];
    attBonus += equipmentAtt[getTorso(att, str, def)];
    attBonus += equipmentAtt[getShield(att, str, def)];
    attBonus += equipmentAtt[getLegs(att, str, def)];
    attBonus += equipmentAtt[getGloves(att, str, def)];
    attBonus += equipmentAtt[getBoots(att, str, def)];
    attBonus += equipmentAtt[getRing(att, str, def)];
    return attBonus;
}

int Equipment::getStrBonus(int att, int str, int def) {
    int strBonus = 0;
    strBonus += equipmentStr[getWeapon(att, str, def)];
    strBonus += equipmentStr[getHelm(att, str, def)];
    strBonus += equipmentStr[getCape(att, str, def)];
    strBonus += equipmentStr[getNecklace(att, str, def)];
    strBonus += equipmentStr[getTorso(att, str, def)];
    strBonus += equipmentStr[getShield(att, str, def)];
    strBonus += equipmentStr[getLegs(att, str, def)];
    strBonus += equipmentStr[getGloves(att, str, def)];
    strBonus += equipmentStr[getBoots(att, str, def)];
    strBonus += equipmentStr[getRing(att, str, def)];
    return strBonus;
}

int Equipment::getAttPotionBoost(int att) {
    if (this->attPotion == "NOTHING")
        return 1;
    else if (this->attPotion == "REGULARATT")
        return 3 + (1.1 * att);
    else if (this->attPotion == "SUPERATT")
        return 5 + (1.15 * att);
}

int Equipment::getStrPotionBoost(int str) {
    if (this->strPotion == "NOTHING")
        return 1;
    else if (this->strPotion == "REGULARSTR")
        return 3 + (1.1 * str);
    else if (this->strPotion == "SUPERSTR")
        return 5 + (1.15 * str);
}

float Equipment::getAttPrayerBoost() {
    return this->prayerAttBoost[this->attPrayer];
}

float Equipment::getStrPrayerBoost() {
    return this->prayerStrBoost[this->strPrayer];
}

float Equipment::getSpeed(int att, int str, int def) {            // Seconds per attack, EX: 4 tic = 2.4 seconds. -> 4 * 0.6 = 2.4
    return this->equipmentSpeed[getWeapon(att, str, def)];
}

int Equipment::getOppDefBonus() {
    return this->opponentDefBonus[this->opponent];
}

int Equipment::getOppDefLvl() {
    return this->opponentDefLvl[this->opponent];
}
int Equipment::getOppHpLvl() {
    return this->opponentHp[this->opponent];
}

void Equipment::settings(int startAtt, int startStr, int startDef, int endAtt, int endStr, int endDef) {
    std::cout << "Welcome to equipment set up!\n";
    std::cout << "We'll start with weapon selection!\n";

    bool helmAssigned = 0, capeAssigned = 0, necklaceAssigned = 0, torsoAssigned = 0, shieldAssigned = 0;
    bool legAssigned = 0, gloveAssigned = 0, bootAssigned = 0, ringAssigned = 0;

    // Choice is the variable that will hold your choice for each of the following questions
    int choice = 0;

    // During the time that you are lower than or equal to 30 att and str, these are the weapon options, choose 1
    if (startAtt < 40 && startStr < 40) {

        // While loop to block choice into possible choices
        while (choice > 3 || choice < 1) {
            std::cout << "For when attack < 40 AND str < 40, please enter the number next to your weapon of choice.\n";
            std::cout << "1. Event Rpg\n";
            std::cout << "2. Nothing\n";
            std::cout << "3. Exit\n";
            std::cin >> choice;

            // If you choose RPG, set this bracket and all above brackets to RPG, higher brackets will be changed later if at all
            if (choice == 1) {
                this->weapon1Att = "RPG";
                this->weapon1Att40Str = "RPG";
                this->weapon1Att60Str = "RPG";
                this->weapon40Att = "RPG";
                this->weapon50Att = "RPG";
                this->weapon60Att = "RPG";
                this->weapon70Att = "RPG";
                this->weapon75Att = "RPG";
            }

            // If you choose nothing, set this bracket and all above brackets to nothing, higher brackets will be changed later if at all
            else if (choice == 2) {
                this->weapon1Att = "NOTHING";
                this->weapon1Att40Str = "NOTHING";
                this->weapon1Att60Str = "NOTHING";
                this->weapon40Att = "NOTHING";
                this->weapon50Att = "NOTHING";
                this->weapon60Att = "NOTHING";
                this->weapon70Att = "NOTHING";
                this->weapon75Att = "NOTHING";
            }

            // If you choose exit, exit from program
            else if (choice == 3)
                exit(0);
        }
        choice = 0;
    }

    // When attack is less than 40 but str can be above 40, rune warhammer is a new option
    if (startAtt < 40 && endStr >= 40) {
        while (choice < 1 || choice > 4) {
            std::cout << "For when attack < 30 AND str >= 40, please enter the number next to your weapon of choice.\n";
            std::cout << "1. Rune warhammer\n";
            std::cout << "2. RPG\n";
            std::cout << "3. Nothing\n";
            std::cout << "3. Exit\n";
            std::cin >> choice;

            // Set choice for all the higher brackets, those will be updated later if at all
            if (choice == 1) {
                this->weapon1Att40Str = "RUNEWARHAMMER";
                this->weapon1Att60Str = "RUNEWARHAMMER";
            }

            if (choice == 2) {
                this->weapon1Att40Str = "RPG";
                this->weapon1Att60Str = "RPG";
            }

            if (choice == 3) {
                this->weapon1Att40Str = "NOTHING";
                this->weapon1Att60Str = "NOTHING";
            }

            // If you choose exit, exit from program
            else if (choice == 4)
                exit(0);
        }
        choice = 0;
    }

    // When attack is less than 40 but str can be above 60, dragon warhammer and obby maul are unlocked
    if (startAtt < 40 && endStr >= 60) {
        while (choice < 1 || choice > 6) {
            std::cout << "For when attack < 40 AND str >= 60, please enter the number next to your weapon of choice.\n";
            std::cout << "1. Dragon warhammer\n";
            std::cout << "2. Obby maul with berserker necklace\n";
            std::cout << "3. Rune warhammer\n";
            std::cout << "4. RPG\n";
            std::cout << "5. Nothing\n";
            std::cout << "6. Exit\n";
            std::cin >> choice;

            // Set this bracket and all above brackets to the same thing, they will be changed later if at all
            if (choice == 1) {
                this->weapon1Att60Str = "DRAGONWARHAMMER";
            }

            if (choice == 2) {
                this->weapon1Att60Str = "OBBYMAUL";
            }

            if (choice == 3) {
                this->weapon1Att60Str = "RUNEWARHAMMER";
            }

            if (choice == 4) {
                this->weapon1Att60Str = "RPG";
            }

            if (choice == 5) {
                this->weapon1Att60Str = "NOTHING";
            }

            // If you choose exit, exit from program
            else if (choice == 6)
                exit(0);
        }
        choice = 0;
    }

    // When attack can be greater than 40
    if (startAtt < 50 && endAtt >= 40) {
        while (choice < 1 || choice > 7) {
            std::cout << "For when attack is 40 or greater, choose your weapon.\n";
            std::cout << "1. Brine sabre\n";
            std::cout << "2. Dragon warhammer(REQUIRES 60 STR)\n";
            std::cout << "3. Obby maul with berserker necklace(REQUIRES 60 STR)\n";
            std::cout << "4. Rune warhammer(REQUIRES 40 STR)\n";
            std::cout << "5. RPG\n";
            std::cout << "6. Nothing\n";
            std::cout << "7. Exit\n";
            std::cin >> choice;

            // Set this bracket and all above brackets to the same thing, they will be changed later if at all
            if (choice == 1) {
                this->weapon40Att = "BRINESABRE";
                this->weapon50Att = "BRINESABRE";
                this->weapon60Att = "BRINESABRE";
                this->weapon70Att = "BRINESABRE";
                this->weapon75Att = "BRINESABRE";
            }

            if (choice == 2) {
                this->weapon40Att = "DRAGONWARHAMMER";
                this->weapon50Att = "DRAGONWARHAMMER";
                this->weapon60Att = "DRAGONWARHAMMER";
                this->weapon70Att = "DRAGONWARHAMMER";
                this->weapon75Att = "DRAGONWARHAMMER";
            }

            if (choice == 3) {
                this->weapon40Att = "OBBYMAUL";
                this->weapon50Att = "OBBYMAUL";
                this->weapon60Att = "OBBYMAUL";
                this->weapon70Att = "OBBYMAUL";
                this->weapon75Att = "OBBYMAUL";
            }

            if (choice == 4) {
                this->weapon40Att = "RUNEWARHAMMER";
                this->weapon50Att = "RUNEWARHAMMER";
                this->weapon60Att = "RUNEWARHAMMER";
                this->weapon70Att = "RUNEWARHAMMER";
                this->weapon75Att = "RUNEWARHAMMER";
            }

            if (choice == 5) {
                this->weapon40Att = "RPG";
                this->weapon50Att = "RPG";
                this->weapon60Att = "RPG";
                this->weapon70Att = "RPG";
                this->weapon75Att = "RPG";
            }

            if (choice == 6) {
                this->weapon40Att = "NOTHING";
                this->weapon50Att = "NOTHING";
                this->weapon60Att = "NOTHING";
                this->weapon70Att = "NOTHING";
                this->weapon75Att = "NOTHING";
            }

            // If you choose exit, exit from program
            else if (choice == 7)
                exit(0);
        }
        choice = 0;
    }

    // When attack can be greater than 50 but starts below
    if (startAtt < 60 && endAtt >= 50) {
        while (choice < 1 || choice > 10) {
            std::cout << "For when attack is 50 or greater, choose your weapon.\n";
            std::cout << "1. Leaf bladed sword(REQUIRES 55 SLAYER)\n";
            std::cout << "2. Ancient staff(REQUIRES DESERT TREASURE)\n";
            std::cout << "3. Granite hammer(REQUIRES 50 STR)\n";
            std::cout << "4. Brine sabre\n";
            std::cout << "5. Dragon warhammer(REQUIRES 60 STR)\n";
            std::cout << "6. Obby maul with berserker necklace(REQUIRES 60 STR)\n";
            std::cout << "7. Rune warhammer(REQUIRES 40 STR)\n";
            std::cout << "8. RPG\n";
            std::cout << "9. Nothing\n";
            std::cout << "10. Exit\n";
            std::cin >> choice;

            // Set this bracket and all above brackets to the same thing, they will be changed later if at all
            if (choice == 1) {
                this->weapon50Att = "LEAFBLADEDSWORD";
                this->weapon60Att = "LEAFBLADEDSWORD";
                this->weapon70Att = "LEAFBLADEDSWORD";
                this->weapon75Att = "LEAFBLADEDSWORD";
            }

            if (choice == 2) {
                this->weapon50Att = "ANCIENTSTAFF";
                this->weapon60Att = "ANCIENTSTAFF";
                this->weapon70Att = "ANCIENTSTAFF";
                this->weapon75Att = "ANCIENTSTAFF";
            }

            if (choice == 3) {
                this->weapon50Att = "GRANITEHAMMER";
                this->weapon60Att = "GRANITEHAMMER";
                this->weapon70Att = "GRANITEHAMMER";
                this->weapon75Att = "GRANITEHAMMER";
            }

            if (choice == 4) {
                this->weapon50Att = "BRINESABRE";
                this->weapon60Att = "BRINESABRE";
                this->weapon70Att = "BRINESABRE";
                this->weapon75Att = "BRINESABRE";
            }

            if (choice == 5) {
                this->weapon50Att = "DRAGONWARHAMMER";
                this->weapon60Att = "DRAGONWARHAMMER";
                this->weapon70Att = "DRAGONWARHAMMER";
                this->weapon75Att = "DRAGONWARHAMMER";
            }

            if (choice == 6) {
                this->weapon50Att = "OBBYMAUL";
                this->weapon60Att = "OBBYMAUL";
                this->weapon70Att = "OBBYMAUL";
                this->weapon75Att = "OBBYMAUL";
            }

            if (choice == 7) {
                this->weapon50Att = "RUNEWARHAMMER";
                this->weapon60Att = "RUNEWARHAMMER";
                this->weapon70Att = "RUNEWARHAMMER";
                this->weapon75Att = "RUNEWARHAMMER";
            }

            if (choice == 8) {
                this->weapon50Att = "RPG";
                this->weapon60Att = "RPG";
                this->weapon70Att = "RPG";
                this->weapon75Att = "RPG";
            }

            if (choice == 9) {
                this->weapon50Att = "NOTHING";
                this->weapon60Att = "NOTHING";
                this->weapon70Att = "NOTHING";
                this->weapon75Att = "NOTHING";
            }

            // If you choose exit, exit from program
            else if (choice == 10)
                exit(0);
        }
        choice = 0;
    }

    // When attack can be greater than 60 but starts below
    if (startAtt < 70 && endAtt >= 60) {
        while (choice < 1 || choice > 12) {
            std::cout << "For when attack is 60 or greater, choose your weapon.\n";
            std::cout << "1. Dragon scimitar(REQUIRES MONKEY MADNESS)\n";
            std::cout << "2. Dragon sword\n";
            std::cout << "3. Leaf bladed sword(REQUIRES 55 SLAYER)\n";
            std::cout << "4. Ancient staff(REQUIRES DESERT TREASURE)\n";
            std::cout << "5. Granite hammer(REQUIRES 50 STR)\n";
            std::cout << "6. Brine sabre\n";
            std::cout << "7. Dragon warhammer(REQUIRES 60 STR)\n";
            std::cout << "8. Obby maul with berserker necklace(REQUIRES 60 STR)\n";
            std::cout << "9. Rune warhammer(REQUIRES 40 STR)\n";
            std::cout << "10. RPG\n";
            std::cout << "11. Nothing\n";
            std::cout << "12. Exit\n";
            std::cin >> choice;

            // Set this bracket and all above brackets to the same thing, they will be changed later if at all
            if (choice == 1) {
                this->weapon60Att = "DRAGONSCIMITAR";
                this->weapon70Att = "DRAGONSCIMITAR";
                this->weapon75Att = "DRAGONSCIMITAR";
            }

            if (choice == 2) {
                this->weapon60Att = "DRAGONSWORD";
                this->weapon70Att = "DRAGONSWORD";
                this->weapon75Att = "DRAGONSWORD";
            }

            if (choice == 3) {
                this->weapon60Att = "LEAFBLADEDSWORD";
                this->weapon70Att = "LEAFBLADEDSWORD";
                this->weapon75Att = "LEAFBLADEDSWORD";
            }

            if (choice == 4) {
                this->weapon60Att = "ANCIENTSTAFF";
                this->weapon70Att = "ANCIENTSTAFF";
                this->weapon75Att = "ANCIENTSTAFF";
            }

            if (choice == 5) {;
                this->weapon60Att = "GRANITEHAMMER";
                this->weapon70Att = "GRANITEHAMMER";
                this->weapon75Att = "GRANITEHAMMER";
            }

            if (choice == 6) {
                this->weapon60Att = "BRINESABRE";
                this->weapon70Att = "BRINESABRE";
                this->weapon75Att = "BRINESABRE";
            }

            if (choice == 7) {
                this->weapon60Att = "DRAGONWARHAMMER";
                this->weapon70Att = "DRAGONWARHAMMER";
                this->weapon75Att = "DRAGONWARHAMMER";
            }

            if (choice == 8) {
                this->weapon60Att = "OBBYMAUL";
                this->weapon70Att = "OBBYMAUL";
                this->weapon75Att = "OBBYMAUL";
            }

            if (choice == 9) {
                this->weapon60Att = "RUNEWARHAMMER";
                this->weapon70Att = "RUNEWARHAMMER";
                this->weapon75Att = "RUNEWARHAMMER";
            }

            if (choice == 10) {
                this->weapon60Att = "RPG";
                this->weapon70Att = "RPG";
                this->weapon75Att = "RPG";
            }

            if (choice == 11) {
                this->weapon60Att = "NOTHING";
                this->weapon70Att = "NOTHING";
                this->weapon75Att = "NOTHING";
            }

            // If you choose exit, exit from program
            else if (choice == 12)
                exit(0);
        }
        choice = 0;
    }

    // When attack can be greater than 70 but starts below
    if (startAtt < 75 && endAtt >= 70) {
        int choice2;
        while (choice < 1 || choice > 18) {
            std::cout << "For when attack is 70 or greater, choose your weapon.\n";
            std::cout << "1. Abyssal whip controlled(not working atm)\n";
            std::cout << "2. Abyssal whip(STRENGTH NOT ALLOWED)\n";
            std::cout << "3. Abyssal bludgeon(ATT AND DEF NOT ALLOWED)\n";
            std::cout << "4. Abyssal dagger\n";
            std::cout << "5. Saradomin sword\n";
            std::cout << "6. Sarachnis cudgel\n";
            std::cout << "7. Dragon scimitar(REQUIRES MONKEY MADNESS)\n";
            std::cout << "8. Dragon sword\n";
            std::cout << "9. Leaf bladed sword(REQUIRES 55 SLAYER)\n";
            std::cout << "10. Ancient staff(REQUIRES DESERT TREASURE)\n";
            std::cout << "11. Granite hammer(REQUIRES 50 STR)\n";
            std::cout << "12. Brine sabre\n";
            std::cout << "13. Dragon warhammer(REQUIRES 60 STR)\n";
            std::cout << "14. Obby maul with berserker necklace(REQUIRES 60 STR)\n";
            std::cout << "15. Rune warhammer(REQUIRES 40 STR)\n";
            std::cout << "16. RPG\n";
            std::cout << "17. Nothing\n";
            std::cout << "18. Exit\n";
            std::cin >> choice;

            // Whip att/def selected, need strength training weapon
            if (choice == 2) {
                while (choice2 > 17 || choice2 < 1) {
                    std::cout << "You selected a whip, you still need a strength training weapon for when attack is 70 or greater.\n";
                    std::cout << "1. Abyssal whip controlled(not working atm)\n";
                    std::cout << "2. Abyssal bludgeon(ATT AND DEF NOT ALLOWED)\n";
                    std::cout << "3. Abyssal dagger\n";
                    std::cout << "4. Saradomin sword\n";
                    std::cout << "5. Sarachnis cudgel\n";
                    std::cout << "6. Dragon scimitar(REQUIRES MONKEY MADNESS)\n";
                    std::cout << "7. Dragon sword\n";
                    std::cout << "8. Leaf bladed sword(REQUIRES 55 SLAYER)\n";
                    std::cout << "9. Ancient staff(REQUIRES DESERT TREASURE)\n";
                    std::cout << "10. Granite hammer(REQUIRES 50 STR)\n";
                    std::cout << "11. Brine sabre\n";
                    std::cout << "12. Dragon warhammer(REQUIRES 60 STR)\n";
                    std::cout << "13. Obby maul with berserker necklace(REQUIRES 60 STR)\n";
                    std::cout << "14. Rune warhammer(REQUIRES 40 STR)\n";
                    std::cout << "15. RPG\n";
                    std::cout << "16. Nothing\n";
                    std::cout << "17. Exit\n";
                    std::cin >> choice2;
                }
            }

            // Bludgeon selected, still need att/def training weapon
            if (choice == 3) {
                while (choice2 > 17 || choice2 < 1) {
                    std::cout << "For when attack is 70 or greater, choose your weapon.\n";
                    std::cout << "1. Abyssal whip controlled(not working atm)\n";
                    std::cout << "2. Abyssal whip(STRENGTH NOT ALLOWED)\n";
                    std::cout << "3. Abyssal dagger\n";
                    std::cout << "4. Saradomin sword\n";
                    std::cout << "5. Sarachnis cudgel\n";
                    std::cout << "6. Dragon scimitar(REQUIRES MONKEY MADNESS)\n";
                    std::cout << "7. Dragon sword\n";
                    std::cout << "8. Leaf bladed sword(REQUIRES 55 SLAYER)\n";
                    std::cout << "9. Ancient staff(REQUIRES DESERT TREASURE)\n";
                    std::cout << "10. Granite hammer(REQUIRES 50 STR)\n";
                    std::cout << "11. Brine sabre\n";
                    std::cout << "12. Dragon warhammer(REQUIRES 60 STR)\n";
                    std::cout << "13. Obby maul with berserker necklace(REQUIRES 60 STR)\n";
                    std::cout << "14. Rune warhammer(REQUIRES 40 STR)\n";
                    std::cout << "15. RPG\n";
                    std::cout << "16. Nothing\n";
                    std::cout << "17. Exit\n";
                    std::cin >> choice2;
                }
            }

            // Set this bracket and all above brackets to the same thing, they will be changed later if at all
            if (choice == 1) {
                this->weapon70Att = "ABYSSALWHIPCONTROLLED";
                this->weapon75Att = "ABYSSALWHIPCONTROLLED";
            }

            if (choice == 2) {
                this->secondaryWeapon70Att = "ABYSSALWHIP";
                this->weapon75Att = "ABYSSALWHIP";

                if (choice2 == 1) {
                    this->secondaryWeapon70Att = "ABYSSALWHIPCONTROLLED";
                    this->secondaryWeapon75Att = "ABYSSALWHIPCONTROLLED";
                }

                if (choice2 == 2) {
                    this->secondaryWeapon70Att = "ABYSSALBLUDGEON";
                    this->secondaryWeapon75Att = "ABYSSALBLUDGEON";
                }

                if (choice2 == 3) {
                    this->secondaryWeapon70Att = "ABYSSALDAGGER";
                    this->secondaryWeapon75Att = "ABYSSALDAGGER";
                }

                if (choice2 == 4) {
                    this->secondaryWeapon70Att = "SARADOMINSWORD";
                    this->secondaryWeapon75Att = "SARADOMINSWORD";
                }

                if (choice2 == 5) {
                    this->secondaryWeapon70Att = "SARACHNISCUDGEL";
                    this->secondaryWeapon75Att = "SARACHNISCUDGEL";
                }

                if (choice2 == 6) {
                    this->secondaryWeapon70Att = "DRAGONSCIMITAR";
                    this->secondaryWeapon75Att = "DRAGONSCIMITAR";
                }

                if (choice2 == 7) {
                    this->secondaryWeapon70Att = "DRAGONSWORD";
                    this->secondaryWeapon75Att = "DRAGONSWORD";
                }

                if (choice2 == 8) {
                    this->secondaryWeapon70Att = "LEAFBLADEDSWORD";
                    this->secondaryWeapon75Att = "LEAFBLADEDSWORD";
                }

                if (choice2 == 9) {
                    this->secondaryWeapon70Att = "ANCIENTSTAFF";
                    this->secondaryWeapon75Att = "ANCIENTSTAFF";
                }

                if (choice2 == 10) {
                    this->secondaryWeapon70Att = "GRANITEHAMMER";
                    this->secondaryWeapon75Att = "GRANITEHAMMER";
                }

                if (choice2 == 11) {
                    this->secondaryWeapon70Att = "BRINESABRE";
                    this->secondaryWeapon75Att = "BRINESABRE";
                }

                if (choice2 == 12) {
                    this->secondaryWeapon70Att = "DRAGONWARHAMMER";
                    this->secondaryWeapon75Att = "DRAGONWARHAMMER";
                }

                if (choice2 == 13) {
                    this->secondaryWeapon70Att = "OBBYMAUL";
                    this->secondaryWeapon75Att = "OBBYMAUL";
                }

                if (choice2 == 14) {
                    this->secondaryWeapon70Att = "RUNEWARHAMMER";
                    this->secondaryWeapon75Att = "RUNEWARHAMMER";
                }

                if (choice2 == 15) {
                    this->secondaryWeapon70Att = "RPG";
                    this->secondaryWeapon75Att = "RPG";
                }

                if (choice2 == 16) {
                    this->secondaryWeapon70Att = "NOTHING";
                    this->secondaryWeapon75Att = "NOTHING";
                }
            }

            if (choice == 3) {
                this->weapon70Att = "ABYSSALBLUDGEON";
                this->weapon75Att = "ABYSSALBLUDGEON";

                // Bludgeon selected, still need an att/def weapon
                if (choice2 == 1) {
                    this->secondaryWeapon70Att = "ABYSSALWHIPCONTROLLED";
                    this->secondaryWeapon75Att = "ABYSSALWHIPCONTROLLED";
                }

                if (choice2 == 2) {
                    this->secondaryWeapon70Att = "ABYSSALWHIP";
                    this->secondaryWeapon75Att = "ABYSSALWHIP";
                }

                if (choice2 == 3) {
                    this->secondaryWeapon70Att = "ABYSSALDAGGER";
                    this->secondaryWeapon75Att = "ABYSSALDAGGER";
                }

                if (choice2 == 4) {
                    this->secondaryWeapon70Att = "SARADOMINSWORD";
                    this->secondaryWeapon75Att = "SARADOMINSWORD";
                }

                if (choice2 == 5) {
                    this->secondaryWeapon70Att = "SARACHNISCUDGEL";
                    this->secondaryWeapon75Att = "SARACHNISCUDGEL";
                }

                if (choice2 == 6) {
                    this->secondaryWeapon70Att = "DRAGONSCIMITAR";
                    this->secondaryWeapon75Att = "DRAGONSCIMITAR";
                }

                if (choice2 == 7) {
                    this->secondaryWeapon70Att = "DRAGONSWORD";
                    this->secondaryWeapon75Att = "DRAGONSWORD";
                }

                if (choice2 == 8) {
                    this->secondaryWeapon70Att = "LEAFBLADEDSWORD";
                    this->secondaryWeapon75Att = "LEAFBLADEDSWORD";
                }

                if (choice2 == 9) {
                    this->secondaryWeapon70Att = "ANCIENTSTAFF";
                    this->secondaryWeapon75Att = "ANCIENTSTAFF";
                }

                if (choice2 == 10) {
                    this->secondaryWeapon70Att = "GRANITEHAMMER";
                    this->secondaryWeapon75Att = "GRANITEHAMMER";
                }

                if (choice2 == 11) {
                    this->secondaryWeapon70Att = "BRINESABRE";
                    this->secondaryWeapon75Att = "BRINESABRE";
                }

                if (choice2 == 12) {
                    this->secondaryWeapon70Att = "DRAGONWARHAMMER";
                    this->secondaryWeapon75Att = "DRAGONWARHAMMER";
                }

                if (choice2 == 13) {
                    this->secondaryWeapon70Att = "OBBYMAUL";
                    this->secondaryWeapon75Att = "OBBYMAUL";
                }

                if (choice2 == 14) {
                    this->secondaryWeapon70Att = "RUNEWARHAMMER";
                    this->secondaryWeapon75Att = "RUNEWARHAMMER";
                }

                if (choice2 == 15) {
                    this->secondaryWeapon70Att = "RPG";
                    this->secondaryWeapon75Att = "RPG";
                }

                if (choice2 == 16) {
                    this->secondaryWeapon70Att = "NOTHING";
                    this->secondaryWeapon75Att = "NOTHING";
                }
            }

            if (choice == 4) {
                this->weapon70Att = "ABYSSALDAGGER";
                this->weapon75Att = "ABYSSALDAGGER";
            }

            if (choice == 5) {
                this->weapon70Att = "SARADOMINSWORD";
                this->weapon75Att = "SARADOMINSWORD";
            }

            if (choice == 6) {
                this->weapon70Att = "SARACHNISCUDGEL";
                this->weapon75Att = "SARACHNISCUDGEL";
            }

            if (choice == 7) {
                this->weapon70Att = "DRAGONSCIMITAR";
                this->weapon75Att = "DRAGONSCIMITAR";
            }

            if (choice == 8) {
                this->weapon70Att = "DRAGONSWORD";
                this->weapon75Att = "DRAGONSWORD";
            }

            if (choice == 9) {
                this->weapon70Att = "LEAFBLADEDSWORD";
                this->weapon75Att = "LEAFBLADEDSWORD";
            }

            if (choice == 10) {
                this->weapon70Att = "ANCIENTSTAFF";
                this->weapon75Att = "ANCIENTSTAFF";
            }

            if (choice == 11) {
                this->weapon70Att = "GRANITEHAMMER";
                this->weapon75Att = "GRANITEHAMMER";
            }

            if (choice == 12) {
                this->weapon70Att = "BRINESABRE";
                this->weapon75Att = "BRINESABRE";
            }

            if (choice == 13) {
                this->weapon70Att = "DRAGONWARHAMMER";
                this->weapon75Att = "DRAGONWARHAMMER";
            }

            if (choice == 14) {
                this->weapon70Att = "OBBYMAUL";
                this->weapon75Att = "OBBYMAUL";
            }

            if (choice == 15) {
                this->weapon70Att = "RUNEWARHAMMER";
                this->weapon75Att = "RUNEWARHAMMER";
            }

            if (choice == 16) {
                this->weapon70Att = "RPG";
                this->weapon75Att = "RPG";
            }

            if (choice == 17) {
                this->weapon70Att = "NOTHING";
                this->weapon75Att = "NOTHING";
            }

            // If you choose exit, exit from program
            else if (choice == 18)
                exit(0);
        }
        choice = 0;
    }

    if (endAtt >= 75) {
        int choice2;
        while (choice < 1 || choice > 18) {
            std::cout << "For when attack is 75 or greater, choose your weapon.\n";
            std::cout << "1. Ghrazi rapier\n";
            std::cout << "2. Inquisitors mace\n";
            std::cout << "3. Blade of saeldor\n";
            std::cout << "4. Abyssal tentacle(STRENGTH NOT ALLOWED)\n";
            std::cout << "5. Blessed sara sword\n";
            std::cout << "6. Abyssal whip controlled\n";
            std::cout << "7. Abyssal whip(STRENGTH NOT ALLOWED)\n";
            std::cout << "8. Abyssal bludgeon(ATT AND DEF NOT ALLOWED)\n";
            std::cout << "9. Abyssal dagger\n";
            std::cout << "10. Saradomin sword\n";
            std::cout << "11. Sarachnis cudgel\n";
            std::cout << "12. Dragon scimitar(REQUIRES MONKEY MADNESS)\n";
            std::cout << "13. Dragon sword\n";
            std::cout << "14. Leaf bladed sword(REQUIRES 55 SLAYER)\n";
            std::cout << "15. Ancient staff(REQUIRES DESERT TREASURE)\n";
            std::cout << "16. Granite hammer(REQUIRES 50 STR)\n";
            std::cout << "17. Brine sabre\n";
            std::cout << "18. Dragon warhammer(REQUIRES 60 STR)\n";
            std::cout << "19. Obby maul with berserker necklace(REQUIRES 60 STR)\n";
            std::cout << "20. Rune warhammer(REQUIRES 40 STR)\n";
            std::cout << "21. RPG\n";
            std::cout << "22. Nothing\n";
            std::cout << "23. Exit\n";
            std::cin >> choice;

            // Whip att/def selected, need strength training weapon
            if (choice == 4 || choice == 7) {
                while (choice2 > 21 || choice2 < 1) {
                    std::cout << "You selected tentacle or whip, you still need a strength training weapon.\n";
                    std::cout << "1. Ghrazi rapier\n";
                    std::cout << "2. Inquisitors mace\n";
                    std::cout << "3. Blade of saeldor\n";
                    std::cout << "4. Blessed sara sword\n";
                    std::cout << "5. Abyssal whip controlled(not working atm)\n";
                    std::cout << "6. Abyssal bludgeon(ATT AND DEF NOT ALLOWED)\n";
                    std::cout << "7. Abyssal dagger\n";
                    std::cout << "8. Saradomin sword\n";
                    std::cout << "9. Sarachnis cudgel\n";
                    std::cout << "10. Dragon scimitar(REQUIRES MONKEY MADNESS)\n";
                    std::cout << "11. Dragon sword\n";
                    std::cout << "12. Leaf bladed sword(REQUIRES 55 SLAYER)\n";
                    std::cout << "13. Ancient staff(REQUIRES DESERT TREASURE)\n";
                    std::cout << "14. Granite hammer(REQUIRES 50 STR)\n";
                    std::cout << "15. Brine sabre\n";
                    std::cout << "16. Dragon warhammer(REQUIRES 60 STR)\n";
                    std::cout << "17. Obby maul with berserker necklace(REQUIRES 60 STR)\n";
                    std::cout << "18. Rune warhammer(REQUIRES 40 STR)\n";
                    std::cout << "19. RPG\n";
                    std::cout << "20. Nothing\n";
                    std::cout << "21. Exit\n";
                    std::cin >> choice2;
                }
            }

            // Bludgeon selected, still need att/def training weapon
            if (choice == 8) {
                while (choice2 > 22 || choice2 < 1) {
                    std::cout << "You selected bludgeon, you still need an att/def training weapon.\n";
                    std::cout << "1. Ghrazi rapier\n";
                    std::cout << "2. Inquisitors mace\n";
                    std::cout << "3. Blade of saeldor\n";
                    std::cout << "4. Abyssal tentacle(STRENGTH NOT ALLOWED)\n";
                    std::cout << "5. Blessed sara sword\n";
                    std::cout << "6. Abyssal whip controlled\n";
                    std::cout << "7. Abyssal whip(STRENGTH NOT ALLOWED)\n";
                    std::cout << "8. Abyssal dagger\n";
                    std::cout << "9. Saradomin sword\n";
                    std::cout << "10. Sarachnis cudgel\n";
                    std::cout << "11. Dragon scimitar(REQUIRES MONKEY MADNESS)\n";
                    std::cout << "12. Dragon sword\n";
                    std::cout << "13. Leaf bladed sword(REQUIRES 55 SLAYER)\n";
                    std::cout << "14. Ancient staff(REQUIRES DESERT TREASURE)\n";
                    std::cout << "15. Granite hammer(REQUIRES 50 STR)\n";
                    std::cout << "16. Brine sabre\n";
                    std::cout << "17. Dragon warhammer(REQUIRES 60 STR)\n";
                    std::cout << "18. Obby maul with berserker necklace(REQUIRES 60 STR)\n";
                    std::cout << "19. Rune warhammer(REQUIRES 40 STR)\n";
                    std::cout << "20. RPG\n";
                    std::cout << "21. Nothing\n";
                    std::cout << "22. Exit\n";
                    std::cin >> choice2;
                }
            }

            // Set this bracket and all above brackets to the same thing, they will be changed later if at all
            if (choice == 1) {
                this->weapon75Att = "GHRAZIRAPIER";
            }

            if (choice == 2) {
                this->weapon75Att = "INQUISITORSMACE";
            }

            if (choice == 3) {
                this->weapon75Att = "BLADEOFSAELDOR";
            }

            if (choice == 4) {
                this->weapon75Att = "ABYSSALTENTACLE";

                if (choice2 == 1) {
                    this->secondaryWeapon75Att = "GHRAZIRAPIER";
                }

                if (choice2 == 2) {
                    this->secondaryWeapon75Att = "INQUISITORSMACE";
                }

                if (choice2 == 3) {
                    this->secondaryWeapon75Att = "BLADEOFSAELDOR";
                }

                if (choice2 == 4) {
                    this->secondaryWeapon75Att = "BLESSEDSARASWORD";
                }

                if (choice2 == 5) {
                    this->secondaryWeapon75Att = "ABYSSALWHIPCONTROLLED";
                }

                if (choice2 == 6) {
                    this->secondaryWeapon75Att = "ABYSSALBLUDGEON";
                }

                if (choice2 == 7) {
                    this->secondaryWeapon75Att = "ABYSSALDAGGER";
                }

                if (choice2 == 8) {
                    this->secondaryWeapon75Att = "SARADOMINSWORD";
                }

                if (choice2 == 9) {
                    this->secondaryWeapon75Att = "SARACHNISCUDGEL";
                }

                if (choice2 == 10) {
                    this->secondaryWeapon75Att = "DRAGONSCIMITAR";
                }

                if (choice2 == 11) {
                    this->secondaryWeapon75Att = "DRAGONSWORD";
                }

                if (choice2 == 12) {
                    this->secondaryWeapon75Att = "LEAFBLADEDSWORD";
                }

                if (choice2 == 13) {
                    this->secondaryWeapon75Att = "ANCIENTSTAFF";
                }

                if (choice2 == 14) {
                    this->secondaryWeapon75Att = "GRANITEHAMMER";
                }

                if (choice2 == 15) {
                    this->secondaryWeapon75Att = "BRINESABRE";
                }

                if (choice2 == 16) {
                    this->secondaryWeapon75Att = "DRAGONWARHAMMER";
                }

                if (choice2 == 17) {
                    this->secondaryWeapon75Att = "OBBYMAUL";
                }

                if (choice2 == 18) {
                    this->secondaryWeapon75Att = "RUNEWARHAMMER";
                }

                if (choice2 == 19) {
                    this->secondaryWeapon75Att = "RPG";
                }

                if (choice2 == 20) {
                    this->secondaryWeapon75Att = "NOTHING";
                }
            }

            if (choice == 5) {
                this->weapon75Att = "BLESSEDSARASWORD";
            }

            if (choice == 6) {
                this->weapon75Att = "ABYSSALWHIPCONTROLLED";
            }

            if (choice == 7) {
                this->weapon75Att = "ABYSSALWHIP";

                if (choice2 == 1) {
                    this->secondaryWeapon75Att = "GHRAZIRAPIER";
                }

                if (choice2 == 2) {
                    this->secondaryWeapon75Att = "INQUISITORSMACE";
                }

                if (choice2 == 3) {
                    this->secondaryWeapon75Att = "BLADEOFSAELDOR";
                }

                if (choice2 == 4) {
                    this->secondaryWeapon75Att = "BLESSEDSARASWORD";
                }

                if (choice2 == 5) {
                    this->secondaryWeapon75Att = "ABYSSALWHIPCONTROLLED";
                }

                if (choice2 == 6) {
                    this->secondaryWeapon75Att = "ABYSSALBLUDGEON";
                }

                if (choice2 == 7) {
                    this->secondaryWeapon75Att = "ABYSSALDAGGER";
                }

                if (choice2 == 8) {
                    this->secondaryWeapon75Att = "SARADOMINSWORD";
                }

                if (choice2 == 9) {
                    this->secondaryWeapon75Att = "SARACHNISCUDGEL";
                }

                if (choice2 == 10) {
                    this->secondaryWeapon75Att = "DRAGONSCIMITAR";
                }

                if (choice2 == 11) {
                    this->secondaryWeapon75Att = "DRAGONSWORD";
                }

                if (choice2 == 12) {
                    this->secondaryWeapon75Att = "LEAFBLADEDSWORD";
                }

                if (choice2 == 13) {
                    this->secondaryWeapon75Att = "ANCIENTSTAFF";
                }

                if (choice2 == 14) {
                    this->secondaryWeapon75Att = "GRANITEHAMMER";
                }

                if (choice2 == 15) {
                    this->secondaryWeapon75Att = "BRINESABRE";
                }

                if (choice2 == 16) {
                    this->secondaryWeapon75Att = "DRAGONWARHAMMER";
                }

                if (choice2 == 17) {
                    this->secondaryWeapon75Att = "OBBYMAUL";
                }

                if (choice2 == 18) {
                    this->secondaryWeapon75Att = "RUNEWARHAMMER";
                }

                if (choice2 == 19) {
                    this->secondaryWeapon75Att = "RPG";
                }

                if (choice2 == 20) {
                    this->secondaryWeapon75Att = "NOTHING";
                }
            }

            if (choice == 8) {
                this->weapon75Att = "ABYSSALBLUDGEON";

                if (choice2 == 1) {
                    this->secondaryWeapon75Att = "GHRAZIRAPIER";
                }

                if (choice2 == 2) {
                    this->secondaryWeapon75Att = "INQUISITORSMACE";
                }

                if (choice2 == 3) {
                    this->secondaryWeapon75Att = "BLADEOFSAELDOR";
                }

                if (choice2 == 4) {
                    this->secondaryWeapon75Att = "ABYSSALTENTACLE";
                }

                if (choice2 == 5) {
                    this->secondaryWeapon75Att = "BLESSEDSARASWORD";
                }

                if (choice2 == 6) {
                    this->secondaryWeapon75Att = "ABYSSALWHIPCONTROLLED";
                }

                if (choice2 == 7) {
                    this->secondaryWeapon75Att = "ABYSSALWHIP";
                }

                if (choice2 == 8) {
                    this->secondaryWeapon75Att = "ABYSSALDAGGER";
                }

                if (choice2 == 9) {
                    this->secondaryWeapon75Att = "SARADOMINSWORD";
                }

                if (choice2 == 10) {
                    this->secondaryWeapon75Att = "SARACHNISCUDGEL";
                }

                if (choice2 == 11) {
                    this->secondaryWeapon75Att = "DRAGONSCIMITAR";
                }

                if (choice2 == 12) {
                    this->secondaryWeapon75Att = "DRAGONSWORD";
                }

                if (choice2 == 13) {
                    this->secondaryWeapon75Att = "LEAFBLADEDSWORD";
                }

                if (choice2 == 14) {
                    this->secondaryWeapon75Att = "ANCIENTSTAFF";
                }

                if (choice2 == 15) {
                    this->secondaryWeapon75Att = "GRANITEHAMMER";
                }

                if (choice2 == 16) {
                    this->secondaryWeapon75Att = "BRINESABRE";
                }

                if (choice2 == 17) {
                    this->secondaryWeapon75Att = "DRAGONWARHAMMER";
                }

                if (choice2 == 18) {
                    this->secondaryWeapon75Att = "OBBYMAUL";
                }

                if (choice2 == 19) {
                    this->secondaryWeapon75Att = "RUNEWARHAMMER";
                }

                if (choice2 == 20) {
                    this->secondaryWeapon75Att = "RPG";
                }

                if (choice2 == 21) {
                    this->secondaryWeapon75Att = "NOTHING";
                }
            }

            if (choice == 9) {
                this->weapon75Att = "ABYSSALDAGGER";
            }

            if (choice == 10) {
                this->weapon75Att = "SARADOMINSWORD";
            }

            if (choice == 11) {
                this->weapon75Att = "SARACHNISCUDGEL";
            }

            if (choice == 12) {
                this->weapon75Att = "DRAGONSCIMITAR";
            }

            if (choice == 13) {
                this->weapon75Att = "DRAGONSWORD";
            }

            if (choice == 14) {
                this->weapon75Att = "LEAFBLADEDSWORD";
            }

            if (choice == 15) {
                this->weapon75Att = "ANCIENTSTAFF";
            }

            if (choice == 16) {
                this->weapon75Att = "GRANITEHAMMER";
            }

            if (choice == 17) {
                this->weapon75Att = "BRINESABRE";
            }

            if (choice == 18) {
                this->weapon75Att = "DRAGONWARHAMMER";
            }

            if (choice == 19) {
                this->weapon75Att = "OBBYMAUL";
            }

            if (choice == 20) {
                this->weapon75Att = "RUNEWARHAMMER";
            }

            if (choice == 21) {
                this->weapon75Att = "RPG";
            }

            if (choice == 22) {
                this->weapon75Att = "NOTHING";
            }

            // If you choose exit, exit from program
            else if (choice == 23)
                exit(0);
        }
        choice = 0;
    }

    // During the time that you are lower than 10 def
    if (startDef < 10) {

        // While loop to block choice into possible choices cape
        while (choice > 4 || choice < 1) {
            std::cout << "For when def < 10, please enter the number next to the cape you will be using.\n";
            std::cout << "1. Fire cape\n";
            std::cout << "2. Infernal cape\n";
            std::cout << "3. Nothing\n";
            std::cout << "4. Exit\n";
            std::cin >> choice;

            // If you choose Firecape, set this bracket and all above brackets to RPG, higher brackets will be changed later if at all
            if (choice == 1) {
                this->cape1Def = "FIRECAPE";
                this->cape40Def = "FIRECAPE";
                this->cape70Def = "FIRECAPE";
            }

            // If you choose Infernal cape, set this bracket and all above brackets to infernal cape, higher brackets will be changed later if at all
            else if (choice == 2) {
                this->cape1Def = "INFERNALCAPE";
                this->cape40Def = "INFERNALCAPE";
                this->cape70Def = "INFERNALCAPE";
            }

            else if (choice == 3) {
                this->cape1Def = "NOTHING";
                this->cape40Def = "NOTHING";
                this->cape70Def = "NOTHING";
            }

            else if (choice == 4)
                exit(0);
        }
        choice = 0;

        // While loop to block choice into possible choices necklace
        while (choice > 8 || choice < 1) {
            std::cout << "For when def < 10, please enter the number next to the necklace you will be using.\n";
            std::cout << "1. Amulet of torture\n";
            std::cout << "2. Amulet of fury\n";
            std::cout << "3. Amulet of glory\n";
            std::cout << "4. Amulet of strength\n";
            std::cout << "5. Berserker necklace\n";
            std::cout << "6. Amulet of power\n";
            std::cout << "7. Nothing\n";
            std::cout << "8. Exit\n";
            std::cin >> choice;

            if (choice == 1) {
                this->necklace1Def = "AMMYTORTURE";          
                this->necklace40Def = "AMMYTORTURE";
                this->necklace70Def = "AMMYTORTURE";
            }

            else if (choice == 2) {
                this->necklace1Def = "AMMYFURY";
                this->necklace40Def = "AMMYFURY";
                this->necklace70Def = "AMMYFURY";
            }

            else if (choice == 3) {
                this->necklace1Def = "AMMYGLORY";
                this->necklace40Def = "AMMYGLORY";
                this->necklace70Def = "AMMYGLORY";
            }

            else if (choice == 4) {
                this->necklace1Def = "AMMYSTRENGTH";
                this->necklace40Def = "AMMYSTRENGTH";
                this->necklace70Def = "AMMYSTRENGTH";
            }

            else if (choice == 5) {
                this->necklace1Def = "BERSERKERNECKLACE";
                this->necklace40Def = "BERSERKERNECKLACE";
                this->necklace70Def = "BERSERKERNECKLACE";
            }

            else if (choice == 6) {
                this->necklace1Def = "AMMYPOWER";
                this->necklace40Def = "AMMYPOWER";
                this->necklace70Def = "AMMYPOWER";
            }

            else if (choice == 7) {
                this->necklace1Def = "NOTHING";
                this->necklace40Def = "NOTHING";
                this->necklace70Def = "NOTHING";
            }

            else if (choice == 8)
                exit(0);
        }
        choice = 0;

        // While loop to block choice into possible choices shield
        while (choice > 3 || choice < 1) {
            std::cout << "For when def < 10, please enter the number next to the shield you will be using.\n";
            std::cout << "1. Book of war\n";
            std::cout << "2. Nothing\n";
            std::cout << "3. Exit\n";
            std::cin >> choice;

            if (choice == 1) {
                this->shield1Def = "BOOKOFWAR";
                this->shield10Def = "BOOKOFWAR";
                this->shield20Def = "BOOKOFWAR";
                this->shield30Def = "BOOKOFWAR";
                this->shield40Def = "BOOKOFWAR";
                this->shield60Def = "BOOKOFWAR";
                this->shield70Def70Att = "BOOKOFWAR";
                this->shield75Def = "BOOKOFWAR";
            }

            else if (choice == 2) {
                this->shield1Def = "NOTHING";
                this->shield10Def = "NOTHING";
                this->shield20Def = "NOTHING";
                this->shield30Def = "NOTHING";
                this->shield40Def = "NOTHING";
                this->shield60Def = "NOTHING";
                this->shield70Def70Att = "NOTHING";
                this->shield75Def = "NOTHING";
            }

            else if (choice == 3) {
                exit(0);
            }
        }
        choice = 0;

        // While loop to block choice into possible choices leg slot
        while (choice > 3 || choice < 1) {
            std::cout << "For when def < 10, please enter the number next to the leg slot item you will be using.\n";
            std::cout << "1. Fremennik kilt\n";
            std::cout << "2. Nothing\n";
            std::cout << "3. Exit\n";
            std::cin >> choice;

            if (choice == 1) {
                this->legs1Def = "FREMMYKILT";
                this->legs30Def = "FREMMYKILT";
                this->legs60Def = "FREMMYKILT";
                this->legs65Def = "FREMMYKILT";
            }

            else if (choice == 2) {
                this->legs1Def = "NOTHING";
                this->legs30Def = "NOTHING";
                this->legs60Def = "NOTHING";
                this->legs65Def = "NOTHING";
            }

            else if (choice == 3) {
                exit(0);
            }
        }
        choice = 0;

        // While loop to block choice into possible choices gloves
        while (choice > 5 || choice < 1) {
            std::cout << "For when def < 10, please enter the number next to the gloves you will be using.\n";
            std::cout << "1. Regeneration bracelet\n";
            std::cout << "2. Combat bracelete\n";
            std::cout << "3. Mithril gloves\n";
            std::cout << "4. Nothing\n";
            std::cout << "5. Exit\n";
            std::cin >> choice;

            if (choice == 1) {
                this->gloves1Def = "REGENBRACE";
                this->gloves32Def = "REGENBRACE";
                this->gloves42Def = "REGENBRACE";
                this->gloves80Def80Att = "REGENBRACE";
            }

            if (choice == 2) {
                this->gloves1Def = "COMBATBRACE";
                this->gloves32Def = "COMBATBRACE";
                this->gloves42Def = "COMBATBRACE";
                this->gloves80Def80Att = "COMBATBRACE";
            }

            if (choice == 3) {
                this->gloves1Def = "MITHRILGLOVES";
                this->gloves32Def = "MITHRILGLOVES";
                this->gloves42Def = "MITHRILGLOVES";
                this->gloves80Def80Att = "MITHRILGLOVES";
            }

            else if (choice == 4) {
                this->gloves1Def = "NOTHING";
                this->gloves32Def = "NOTHING";
                this->gloves42Def = "NOTHING";
                this->gloves80Def80Att = "NOTHING";
            }

            else if (choice == 5) {
                exit(0);
            }
        }
        choice = 0;

        // While loop to block choice into possible choices boots
        while (choice > 4 || choice < 1) {
            std::cout << "For when def < 10, please enter the number next to the boots you will be using.\n";
            std::cout << "1. Spiked manacles\n";
            std::cout << "2. Climbing boots\n";
            std::cout << "3. Nothing\n";
            std::cout << "4. Exit\n";
            std::cin >> choice;

            if (choice == 1) {
                this->boot1Def = "SPIKEDMANACLES";
                this->boot50Def = "SPIKEDMANACLES";
                this->boot60Def = "SPIKEDMANACLES";
                this->boot75Def = "SPIKEDMANACLES";
            }

            if (choice == 2) {
                this->boot1Def = "CLIMBINGBOOTS";
                this->boot50Def = "CLIMBINGBOOTS";
                this->boot60Def = "CLIMBINGBOOTS";
                this->boot75Def = "CLIMBINGBOOTS";
            }

            else if (choice == 3) {
                this->boot1Def = "NOTHING";
                this->boot50Def = "NOTHING";
                this->boot60Def = "NOTHING";
                this->boot75Def = "NOTHING";
            }

            else if (choice == 4) {
                exit(0);
            }
        }
        choice = 0;

        // While loop to block choice into possible choices ring
        while (choice > 5 || choice < 1) {
            std::cout << "For when def < 10, please enter the number next to the ring you will be using.\n";
            std::cout << "1. Berserker ring(i)\n";
            std::cout << "2. Berserker ring\n";
            std::cout << "3. Brimstone ring\n";
            std::cout << "4. Nothing\n";
            std::cout << "5. Exit\n";
            std::cin >> choice;

            if (choice == 1) {
                this->ring1Def = "BERSERKERRINGI";
                this->ring50Def = "BERSERKERRINGI";
            }

            if (choice == 2) {
                this->ring1Def = "BERSERKERRING";
                this->ring50Def = "BERSERKERRING";
            }

            else if (choice == 3) {
                this->ring1Def = "BRIMSTONERING";
                this->ring50Def = "BRIMSTONERING";
            }

            else if (choice == 4) {
                this->ring1Def = "NOTHING";
                this->ring50Def = "NOTHING";
            }

            else if (choice == 5) {
                exit(0);
            }
        }
        choice = 0;
    }

    // During the time that you are greater than 10 def
    if (startDef < 20 && endDef >= 10) {
        // While loop to block choice into possible choices
        while (choice > 4 || choice < 1) {
            std::cout << "For when def is 10 or greater, please enter the number next to the shield you will be using.\n";
            std::cout << "1. Black defender\n";
            std::cout << "2. Book of war\n";
            std::cout << "3. Nothing\n";
            std::cout << "4. Exit\n";
            std::cin >> choice;

            if (choice == 1) {
                this->shield10Def = "BLACKDEFENDER";
                this->shield20Def = "BLACKDEFENDER";
                this->shield30Def = "BLACKDEFENDER";
                this->shield40Def = "BLACKDEFENDER";
                this->shield60Def = "BLACKDEFENDER";
                this->shield70Def70Att = "BLACKDEFENDER";
                this->shield75Def = "BLACKDEFENDER";
            }

            if (choice == 2) {
                this->shield10Def = "BOOKOFWAR";
                this->shield20Def = "BOOKOFWAR";
                this->shield30Def = "BOOKOFWAR";
                this->shield40Def = "BOOKOFWAR";
                this->shield60Def = "BOOKOFWAR";
                this->shield70Def70Att = "BOOKOFWAR";
                this->shield75Def = "BOOKOFWAR";
            }

            else if (choice == 3) {
                this->shield10Def = "NOTHING";
                this->shield20Def = "NOTHING";
                this->shield30Def = "NOTHING";
                this->shield40Def = "NOTHING";
                this->shield60Def = "NOTHING";
                this->shield70Def70Att = "NOTHING";
                this->shield75Def = "NOTHING";
            }

            else if (choice == 4) {
                exit(0);
            }
        }
        choice = 0;
    }

    if (startDef < 30 && endDef >= 20) {
        // While loop to block choice into possible choices
        while (choice > 5 || choice < 1) {
            std::cout << "For when def is 20 or greater, please enter the number next to the shield you will be using.\n";
            std::cout << "1. Mithril defender\n";
            std::cout << "2. Black defender\n";
            std::cout << "3. Book of war\n";
            std::cout << "4. Nothing\n";
            std::cout << "5. Exit\n";
            std::cin >> choice;

            if (choice == 1) {
                this->shield20Def = "MITHRILDEFENDER";
                this->shield30Def = "MITHRILDEFENDER";
                this->shield40Def = "MITHRILDEFENDER";
                this->shield60Def = "MITHRILDEFENDER";
                this->shield70Def70Att = "MITHRILDEFENDER";
                this->shield75Def = "MITHRILDEFENDER";
            }

            if (choice == 2) {
                this->shield20Def = "BLACKDEFENDER";
                this->shield30Def = "BLACKDEFENDER";
                this->shield40Def = "BLACKDEFENDER";
                this->shield60Def = "BLACKDEFENDER";
                this->shield70Def70Att = "BLACKDEFENDER";
                this->shield75Def = "BLACKDEFENDER";
            }

            if (choice == 3) {
                this->shield20Def = "BOOKOFWAR";
                this->shield30Def = "BOOKOFWAR";
                this->shield40Def = "BOOKOFWAR";
                this->shield60Def = "BOOKOFWAR";
                this->shield70Def70Att = "BOOKOFWAR";
                this->shield75Def = "BOOKOFWAR";
            }

            else if (choice == 4) {
                this->shield20Def = "NOTHING";
                this->shield30Def = "NOTHING";
                this->shield40Def = "NOTHING";
                this->shield60Def = "NOTHING";
                this->shield70Def70Att = "NOTHING";
                this->shield75Def = "NOTHING";
            }

            else if (choice == 5) {
                exit(0);
            }
        }
        choice = 0;
    }

    if (startDef < 40 && endDef >= 30) {
        // While loop to block choice into possible choices
        while (choice > 3 || choice < 1) {
            std::cout << "For when def is 30 or greater, please enter the number next to the helmet you will be using.\n";
            std::cout << "1. Inquisitors helm\n";
            std::cout << "2. Nothing\n";
            std::cout << "3. Exit\n";
            std::cin >> choice;

            if (choice == 1) {
                this->head30Def = "INQUISITORHELM";
                this->head45Def = "INQUISITORHELM";
                this->head55Def = "INQUISITORHELM";
                this->head60Def = "INQUISITORHELM";
                this->head70Def = "INQUISITORHELM";
                this->head75Def = "INQUISITORHELM";
            }

            else if (choice == 2) {
                this->head30Def = "NOTHING";
                this->head45Def = "NOTHING";
                this->head55Def = "NOTHING";
                this->head60Def = "NOTHING";
                this->head70Def = "NOTHING";
                this->head75Def = "NOTHING";
            }

            else if (choice == 3) {
                exit(0);
            }
        }
        choice = 0;

        while (choice > 6 || choice < 1) {
            std::cout << "For when def is 30 or greater, please enter the number next to the shield you will be using.\n";
            std::cout << "1. Adamant defender\n";
            std::cout << "2. Mithril defender\n";
            std::cout << "3. Black defender\n";
            std::cout << "4. Book of war\n";
            std::cout << "5. Nothing\n";
            std::cout << "6. Exit\n";
            std::cin >> choice;

            if (choice == 1) {
                this->shield30Def = "ADAMANTDEFENDER";
                this->shield40Def = "ADAMANTDEFENDER";
                this->shield60Def = "ADAMANTDEFENDER";
                this->shield70Def70Att = "ADAMANTDEFENDER";
                this->shield75Def = "ADAMANTDEFENDER";
            }

            if (choice == 2) {
                this->shield30Def = "MITHRILDEFENDER";
                this->shield40Def = "MITHRILDEFENDER";
                this->shield60Def = "MITHRILDEFENDER";
                this->shield70Def70Att = "MITHRILDEFENDER";
                this->shield75Def = "MITHRILDEFENDER";
            }

            if (choice == 3) {
                this->shield30Def = "BLACKDEFENDER";
                this->shield40Def = "BLACKDEFENDER";
                this->shield60Def = "BLACKDEFENDER";
                this->shield70Def70Att = "BLACKDEFENDER";
                this->shield75Def = "BLACKDEFENDER";
            }

            if (choice == 4) {
                this->shield30Def = "BOOKOFWAR";
                this->shield40Def = "BOOKOFWAR";
                this->shield60Def = "BOOKOFWAR";
                this->shield70Def70Att = "BOOKOFWAR";
                this->shield75Def = "BOOKOFWAR";
            }

            else if (choice == 5) {
                this->shield30Def = "NOTHING";
                this->shield40Def = "NOTHING";
                this->shield60Def = "NOTHING";
                this->shield70Def70Att = "NOTHING";
                this->shield75Def = "NOTHING";
            }

            else if (choice == 6) {
                exit(0);
            }
        }
        choice = 0;

        while (choice > 3 || choice < 1) {
            std::cout << "For when def is 30 or greater, please enter the number next to the platebody you will be using.\n";
            std::cout << "1. Inquisitors plate\n";
            std::cout << "2. Nothing\n";
            std::cout << "3. Exit\n";
            std::cin >> choice;

            if (choice == 1) {
                this->torso30Def = "INQUISITORSPLATE";
                this->torso40Def = "INQUISITORSPLATE";
                this->torso60Def = "INQUISITORSPLATE";
                this->torso65Def = "INQUISITORSPLATE";
            }

            else if (choice == 2) {
                this->torso30Def = "NOTHING";
                this->torso40Def = "NOTHING";
                this->torso60Def = "NOTHING";
                this->torso65Def = "NOTHING";
            }

            else if (choice == 3) {
                exit(0);
            }
        }
        choice = 0;

        while (choice > 3 || choice < 1) {
            std::cout << "For when def is 30 or greater, please enter the number next to the platelegs you will be using.\n";
            std::cout << "1. Inquisitors plateskirt\n";
            std::cout << "2. Nothing\n";
            std::cout << "3. Exit\n";
            std::cin >> choice;

            if (choice == 1) {
                this->legs30Def = "INQUISITORSLEGS";
                this->legs60Def = "INQUISITORSLEGS";
                this->legs65Def = "INQUISITORSLEGS";
            }

            else if (choice == 2) {
                this->legs30Def = "NOTHING";
                this->legs60Def = "NOTHING";
                this->legs65Def = "NOTHING";
            }

            else if (choice == 3) {
                exit(0);
            }
        }
        choice = 0;
    }

    if (startDef < 42 && endDef >= 40) {

        while (choice > 5 || choice < 1) {
            std::cout << "For when def is 40 or greater, please enter the number next to the cape you will be using.\n";
            std::cout << "1. Fire cape\n";
            std::cout << "2. Infernal cape\n";
            std::cout << "3. Mythical cape\n";
            std::cout << "4. Nothing\n";
            std::cout << "5. Exit\n";
            std::cin >> choice;

            // If you choose Firecape, set this bracket and all above brackets to RPG, higher brackets will be changed later if at all
            if (choice == 1) {
                this->cape40Def = "FIRECAPE";
                this->cape70Def = "FIRECAPE";
            }

            // If you choose Infernal cape, set this bracket and all above brackets to infernal cape, higher brackets will be changed later if at all
            else if (choice == 2) {
                this->cape40Def = "INFERNALCAPE";
                this->cape70Def = "INFERNALCAPE";
            }

            else if (choice == 3) {
                this->cape40Def = "MYTHCAPE";
                this->cape70Def = "MYTHCAPE";
            }

            else if (choice == 4) {
                this->cape40Def = "NOTHING";
                this->cape70Def = "NOTHING";
            }

            else if (choice == 5)
                exit(0);
        }
        choice = 0;

        // While loop to block choice into possible choices
        while (choice > 8 || choice < 1) {
            std::cout << "For when def 40 or greater, please enter the number next to the necklace you will be using.\n";
            std::cout << "1. Amulet of torture\n";
            std::cout << "2. Amulet of fury\n";
            std::cout << "3. Amulet of glory\n";
            std::cout << "4. Amulet of strength\n";
            std::cout << "5. Berserker necklace\n";
            std::cout << "6. Amulet of power\n";
            std::cout << "7. Nothing\n";
            std::cout << "8. Exit\n";
            std::cin >> choice;

            if (choice == 1) {
                this->necklace40Def = "AMMYTORTURE";
                this->necklace70Def = "AMMYTORTURE";
            }

            else if (choice == 2) {
                this->necklace40Def = "AMMYFURY";
                this->necklace70Def = "AMMYFURY";
            }

            else if (choice == 3) {
                this->necklace40Def = "AMMYGLORY";
                this->necklace70Def = "AMMYGLORY";
            }

            else if (choice == 4) {
                this->necklace40Def = "AMMYSTRENGTH";
                this->necklace70Def = "AMMYSTRENGTH";
            }

            else if (choice == 5) {
                this->necklace40Def = "BERSERKERNECKLACE";
                this->necklace70Def = "BERSERKERNECKLACE";
            }

            else if (choice == 6) {
                this->necklace40Def = "AMMYPOWER";
                this->necklace70Def = "AMMYPOWER";
            }

            else if (choice == 7) {
                this->necklace40Def = "NOTHING";
                this->necklace70Def = "NOTHING";
            }

            else if (choice == 8)
                exit(0);
        }
        choice = 0;

        while (choice > 4 || choice < 1) {
            std::cout << "For when def is 40 or greater, please enter the number next to the platebody you will be using.\n";
            std::cout << "1. Fighter torso\n";
            std::cout << "2. Inquisitors plate\n";
            std::cout << "3. Nothing\n";
            std::cout << "4. Exit\n";
            std::cin >> choice;

            if (choice == 1) {
                this->torso40Def = "FIGHTERTORSO";
                this->torso60Def = "FIGHTERTORSO";
                this->torso65Def = "FIGHTERTORSO";
            }

            if (choice == 2) {
                this->torso40Def = "INQUISITORSPLATE";
                this->torso60Def = "INQUISITORSPLATE";
                this->torso65Def = "INQUISITORSPLATE";
            }

            else if (choice == 3) {
                this->torso40Def = "NOTHING";
                this->torso60Def = "NOTHING";
                this->torso65Def = "NOTHING";
            }

            else if (choice == 4) {
                exit(0);
            }
        }
        choice = 0;

        while (choice > 6 || choice < 1) {
            std::cout << "For when def is 40 or greater, please enter the number next to the shield you will be using.\n";
            std::cout << "1. Rune defender\n";
            std::cout << "1. Adamant defender\n";
            std::cout << "2. Mithril defender\n";
            std::cout << "3. Black defender\n";
            std::cout << "4. Book of war\n";
            std::cout << "5. Nothing\n";
            std::cout << "6. Exit\n";
            std::cin >> choice;

            if (choice == 1) {
                this->shield40Def = "RUNEDEFENDER";
                this->shield60Def = "RUNEDEFENDER";
                this->shield70Def70Att = "RUNEDEFENDER";
                this->shield75Def = "RUNEDEFENDER";
            }

            if (choice == 1) {
                this->shield40Def = "ADAMANTDEFENDER";
                this->shield60Def = "ADAMANTDEFENDER";
                this->shield70Def70Att = "ADAMANTDEFENDER";
                this->shield75Def = "ADAMANTDEFENDER";
            }

            if (choice == 2) {
                this->shield40Def = "MITHRILDEFENDER";
                this->shield60Def = "MITHRILDEFENDER";
                this->shield70Def70Att = "MITHRILDEFENDER";
                this->shield75Def = "MITHRILDEFENDER";
            }

            if (choice == 3) {
                this->shield40Def = "BLACKDEFENDER";
                this->shield60Def = "BLACKDEFENDER";
                this->shield70Def70Att = "BLACKDEFENDER";
                this->shield75Def = "BLACKDEFENDER";
            }

            if (choice == 4) {
                this->shield40Def = "BOOKOFWAR";
                this->shield60Def = "BOOKOFWAR";
                this->shield70Def70Att = "BOOKOFWAR";
                this->shield75Def = "BOOKOFWAR";
            }

            else if (choice == 5) {
                this->shield40Def = "NOTHING";
                this->shield60Def = "NOTHING";
                this->shield70Def70Att = "NOTHING";
                this->shield75Def = "NOTHING";
            }

            else if (choice == 6) {
                exit(0);
            }
        }
        choice = 0;
    }

    if (startDef < 45 && endDef >= 42) {
        // While loop to block choice into possible choices gloves
        while (choice > 6 || choice < 1) {

            if (gloveAssigned == 0)
                gloveAssigned = 1;

            std::cout << "For when def is 40 or greater, please enter the number next to the gloves you will be using.\n";
            std::cout << "1. Barrow gloves\n";
            std::cout << "2. Regeneration bracelet\n";
            std::cout << "3. Combat bracelete\n";
            std::cout << "4. Mithril gloves\n";
            std::cout << "5. Nothing\n";
            std::cout << "6. Exit\n";
            std::cin >> choice;

            if (choice == 1) {
                this->gloves42Def = "BARROWGLOVES";
                this->gloves80Def80Att = "BARROWGLOVES";
            }

            if (choice == 1) {
                this->gloves42Def = "REGENBRACE";
                this->gloves80Def80Att = "REGENBRACE";
            }

            if (choice == 2) {
                this->gloves42Def = "COMBATBRACE";
                this->gloves80Def80Att = "COMBATBRACE";
            }

            if (choice == 3) {
                this->gloves42Def = "MITHRILGLOVES";
                this->gloves80Def80Att = "MITHRILGLOVES";
            }

            else if (choice == 4) {
                this->gloves42Def = "NOTHING";
                this->gloves80Def80Att = "NOTHING";
            }

            else if (choice == 5) {
                exit(0);
            }
        }
        choice = 0;
    }

    if (startDef < 50 && endDef >= 45) {
        // While loop to block choice into possible choices
        while (choice > 4 || choice < 1) {
            std::cout << "For when def is 45 or greater, please enter the number next to the helmet you will be using.\n";
            std::cout << "1. Berserker helm\n";
            std::cout << "2. Inquisitors helm\n";
            std::cout << "3. Nothing\n";
            std::cout << "4. Exit\n";
            std::cin >> choice;

            if (choice == 1) {
                this->head45Def = "BERSERKERHELM";
                this->head55Def = "BERSERKERHELM";
                this->head60Def = "BERSERKERHELM";
                this->head70Def = "BERSERKERHELM";
                this->head75Def = "BERSERKERHELM";
            }

            if (choice == 2) {
                this->head45Def = "INQUISITORHELM";
                this->head55Def = "INQUISITORHELM";
                this->head60Def = "INQUISITORHELM";
                this->head70Def = "INQUISITORHELM";
                this->head75Def = "INQUISITORHELM";
            }

            else if (choice == 3) {
                this->head45Def = "NOTHING";
                this->head55Def = "NOTHING";
                this->head60Def = "NOTHING";
                this->head70Def = "NOTHING";
                this->head75Def = "NOTHING";
            }

            else if (choice == 4) {
                exit(0);
            }
        }
        choice = 0;
    }

    if (startDef < 55 && endDef >= 50) {
        // While loop to block choice into possible choices boots
        while (choice > 5 || choice < 1) {
            std::cout << "For when def is 50 or greater, please enter the number next to the boots you will be using.\n";
            std::cout << "1. Granite boots\n";
            std::cout << "2. Spiked manacles\n";
            std::cout << "3. Climbing boots\n";
            std::cout << "4. Nothing\n";
            std::cout << "5. Exit\n";
            std::cin >> choice;

            if (choice == 1) {
                this->boot50Def = "GRANITEBOOTS";
                this->boot60Def = "GRANITEBOOTS";
                this->boot75Def = "GRANITEBOOTS";
            }

            if (choice == 2) {
                this->boot50Def = "SPIKEDMANACLES";
                this->boot60Def = "SPIKEDMANACLES";
                this->boot75Def = "SPIKEDMANACLES";
            }

            if (choice == 3) {
                this->boot50Def = "CLIMBINGBOOTS";
                this->boot60Def = "CLIMBINGBOOTS";
                this->boot75Def = "CLIMBINGBOOTS";
            }

            else if (choice == 4) {
                this->boot50Def = "NOTHING";
                this->boot60Def = "NOTHING";
                this->boot75Def = "NOTHING";
            }

            else if (choice == 5) {
                exit(0);
            }
        }
        choice = 0;
    }

    if (startDef < 60 && endDef >= 55) {
        // While loop to block choice into possible choices
        while (choice > 5 || choice < 1) {
            std::cout << "For when def is 55 or greater, please enter the number next to the helmet you will be using.\n";
            std::cout << "1. Nezzy helm\n";
            std::cout << "2. Berserker helm\n";
            std::cout << "3. Inquisitors helm\n";
            std::cout << "4. Nothing\n";
            std::cout << "5. Exit\n";
            std::cin >> choice;

            if (choice == 1) {
                this->head55Def = "NEZZYHELM";
                this->head60Def = "NEZZYHELM";
                this->head70Def = "NEZZYHELM";
                this->head75Def = "NEZZYHELM";
            }

            if (choice == 2) {
                this->head55Def = "BERSERKERHELM";
                this->head60Def = "BERSERKERHELM";
                this->head70Def = "BERSERKERHELM";
                this->head75Def = "BERSERKERHELM";
            }

            if (choice == 3) {
                this->head55Def = "INQUISITORHELM";
                this->head60Def = "INQUISITORHELM";
                this->head70Def = "INQUISITORHELM";
                this->head75Def = "INQUISITORHELM";
            }

            else if (choice == 4) {
                this->head55Def = "NOTHING";
                this->head60Def = "NOTHING";
                this->head70Def = "NOTHING";
                this->head75Def = "NOTHING";
            }

            else if (choice == 5) {
                exit(0);
            }
        }
        choice = 0;
    }

    if (startDef < 65 && endDef >= 60) {
        // While loop to block choice into possible choices
        while (choice > 6 || choice < 1) {
            std::cout << "For when def is 60 or greater, please enter the number next to the helmet you will be using.\n";
            std::cout << "1. Obsidian helm\n";
            std::cout << "2. Nezzy helm\n";
            std::cout << "3. Berserker helm\n";
            std::cout << "4. Inquisitors helm\n";
            std::cout << "5. Nothing\n";
            std::cout << "6. Exit\n";
            std::cin >> choice;

            if (choice == 1) {
                this->head60Def = "OBBYHELM";
                this->head70Def = "OBBYHELM";
                this->head75Def = "OBBYHELM";
            }

            if (choice == 2) {
                this->head60Def = "NEZZYHELM";
                this->head70Def = "NEZZYHELM";
                this->head75Def = "NEZZYHELM";
            }

            if (choice == 3) {
                this->head60Def = "BERSERKERHELM";
                this->head70Def = "BERSERKERHELM";
                this->head75Def = "BERSERKERHELM";
            }

            if (choice == 4) {
                this->head60Def = "INQUISITORHELM";
                this->head70Def = "INQUISITORHELM";
                this->head75Def = "INQUISITORHELM";
            }

            else if (choice == 5) {
                this->head60Def = "NOTHING";
                this->head70Def = "NOTHING";
                this->head75Def = "NOTHING";
            }

            else if (choice == 6) {
                exit(0);
            }
        }
        choice = 0;

        while (choice > 5 || choice < 1) {
            std::cout << "For when def is 60 or greater, please enter the number next to the platebody you will be using.\n";
            std::cout << "1. Obby plate\n";
            std::cout << "2. Fighter torso\n";
            std::cout << "3. Inquisitors plate\n";
            std::cout << "4. Nothing\n";
            std::cout << "5. Exit\n";
            std::cin >> choice;

            if (choice == 1) {
                this->torso60Def = "OBBYPLATE";
                this->torso65Def = "OBBYPLATE";
            }

            if (choice == 2) {
                this->torso60Def = "FIGHTERTORSO";
                this->torso65Def = "FIGHTERTORSO";
            }

            if (choice == 3) {
                this->torso60Def = "INQUISITORSPLATE";
                this->torso65Def = "INQUISITORSPLATE";
            }

            else if (choice == 4) {
                this->torso60Def = "NOTHING";
                this->torso65Def = "NOTHING";
            }

            else if (choice == 5) {
                exit(0);
            }
        }
        choice = 0;

        while (choice > 9 || choice < 1) {
            std::cout << "For when def is 60 or greater, please enter the number next to the shield you will be using.\n";
            std::cout << "1. Dragon defender\n";
            std::cout << "2. Obby shield\n";
            std::cout << "3. Rune defender\n";
            std::cout << "4. Adamant defender\n";
            std::cout << "5. Mithril defender\n";
            std::cout << "6. Black defender\n";
            std::cout << "7. Book of war\n";
            std::cout << "8. Nothing\n";
            std::cout << "9. Exit\n";
            std::cin >> choice;

            if (choice == 1) {
                this->shield60Def = "DRAGONDEFENDER";
                this->shield70Def70Att = "DRAGONDEFENDER";
                this->shield75Def = "DRAGONDEFENDER";
            }

            if (choice == 2) {
                this->shield60Def = "OBBYSHIELD";
                this->shield70Def70Att = "OBBYSHIELD";
                this->shield75Def = "OBBYSHIELD";
            }

            if (choice == 3) {
                this->shield60Def = "RUNEDEFENDER";
                this->shield70Def70Att = "RUNEDEFENDER";
                this->shield75Def = "RUNEDEFENDER";
            }

            if (choice == 4) {
                this->shield60Def = "ADAMANTDEFENDER";
                this->shield70Def70Att = "ADAMANTDEFENDER";
                this->shield75Def = "ADAMANTDEFENDER";
            }

            if (choice == 5) {
                this->shield60Def = "MITHRILDEFENDER";
                this->shield70Def70Att = "MITHRILDEFENDER";
                this->shield75Def = "MITHRILDEFENDER";
            }

            if (choice == 6) {
                this->shield60Def = "BLACKDEFENDER";
                this->shield70Def70Att = "BLACKDEFENDER";
                this->shield75Def = "BLACKDEFENDER";
            }

            if (choice == 7) {
                this->shield60Def = "BOOKOFWAR";
                this->shield70Def70Att = "BOOKOFWAR";
                this->shield75Def = "BOOKOFWAR";
            }

            else if (choice == 8) {
                this->shield60Def = "NOTHING";
                this->shield70Def70Att = "NOTHING";
                this->shield75Def = "NOTHING";
            }

            else if (choice == 9) {
                exit(0);
            }
        }
        choice = 0;

        while (choice > 4 || choice < 1) {
            std::cout << "For when def is 60 or greater, please enter the number next to the platelegs you will be using.\n";
            std::cout << "1. Obby legs\n";
            std::cout << "2. Inquisitors plateskirt\n";
            std::cout << "3. Nothing\n";
            std::cout << "4. Exit\n";
            std::cin >> choice;

            if (choice == 1) {
                this->legs60Def = "OBBYLEGS";
                this->legs65Def = "OBBYLEGS";
            }

            if (choice == 2) {
                this->legs60Def = "INQUISITORSLEGS";
                this->legs65Def = "INQUISITORSLEGS";
            }

            else if (choice == 3) {
                this->legs60Def = "NOTHING";
                this->legs65Def = "NOTHING";
            }

            else if (choice == 4) {
                exit(0);
            }
        }
        choice = 0;

        // While loop to block choice into possible choices boots
        while (choice > 6 || choice < 1) {
            std::cout << "For when def is 60 or greater, please enter the number next to the boots you will be using.\n";
            std::cout << "1. Dragon boots\n";
            std::cout << "2. Granite boots\n";
            std::cout << "3. Spiked manacles\n";
            std::cout << "4. Climbing boots\n";
            std::cout << "5. Nothing\n";
            std::cout << "6. Exit\n";
            std::cin >> choice;

            if (choice == 1) {
                this->boot60Def = "DRAGONBOOTS";
                this->boot75Def = "DRAGONBOOTS";
            }

            if (choice == 2) {
                this->boot60Def = "GRANITEBOOTS";
                this->boot75Def = "GRANITEBOOTS";
            }

            if (choice == 3) {
                this->boot60Def = "SPIKEDMANACLES";
                this->boot75Def = "SPIKEDMANACLES";
            }

            if (choice == 4) {
                this->boot60Def = "CLIMBINGBOOTS";
                this->boot75Def = "CLIMBINGBOOTS";
            }

            else if (choice == 5) {
                this->boot60Def = "NOTHING";
                this->boot75Def = "NOTHING";
            }

            else if (choice == 6) {
                exit(0);
            }
        }
        choice = 0;
    }

    if (startDef < 70 && endDef >= 65) {
        while (choice > 6 || choice < 1) {
            std::cout << "For when def is 65 or greater, please enter the number next to the platebody you will be using.\n";
            std::cout << "1. Bandos chestplate\n";
            std::cout << "2. Obby plate\n";
            std::cout << "3. Fighter torso\n";
            std::cout << "4. Inquisitors plate\n";
            std::cout << "5. Nothing\n";
            std::cout << "6. Exit\n";
            std::cin >> choice;

            if (choice == 1) {
                this->torso65Def = "BANDOSCHESTPLATE";
            }

            if (choice == 2) {
                this->torso65Def = "OBBYPLATE";
            }

            if (choice == 3) {

                this->torso65Def = "FIGHTERTORSO";
            }

            if (choice == 4) {
                this->torso65Def = "INQUISITORSPLATE";
            }

            else if (choice == 5) {
                this->torso65Def = "NOTHING";
            }

            else if (choice == 6) {
                exit(0);
            }
        }
        choice = 0;

        while (choice > 5 || choice < 1) {
            std::cout << "For when def is 65 or greater, please enter the number next to the platelegs you will be using.\n";
            std::cout << "1. Bandos tassy\n";
            std::cout << "2. Obby legs\n";
            std::cout << "3. Inquisitors plateskirt\n";
            std::cout << "4. Nothing\n";
            std::cout << "5. Exit\n";
            std::cin >> choice;

            if (choice == 1) {
                this->legs65Def = "BANDOSTASSY";
            }

            if (choice == 2) {
                this->legs65Def = "OBBYLEGS";
            }

            if (choice == 3) {

                this->legs65Def = "INQUISITORSLEGS";
            }

            else if (choice == 4) {
                this->legs65Def = "NOTHING";
            }

            else if (choice == 5) {
                exit(0);
            }
        }
        choice = 0;
    }

    if (startDef < 75 && endDef >= 70) {
        // While loop to block choice into possible choices
        while (choice > 7 || choice < 1) {
            std::cout << "For when def is 70 or greater, please enter the number next to the helmet you will be using.\n";
            std::cout << "1. Nezzy faceguard\n";
            std::cout << "2. Obby helm\n";
            std::cout << "3. Nezzy helm\n";
            std::cout << "4. Berserker helm\n";
            std::cout << "5. Inquisitors helm\n";
            std::cout << "6. Nothing\n";
            std::cout << "7. Exit\n";
            std::cin >> choice;

            if (choice == 1) {
                this->head70Def = "NEZZYFACEGUARD";
                this->head75Def = "NEZZYFACEGUARD";
            }

            if (choice == 2) {
                this->head70Def = "OBBYHELM";
                this->head75Def = "OBBYHELM";
            }

            if (choice == 3) {
                this->head70Def = "NEZZYHELM";
                this->head75Def = "NEZZYHELM";
            }

            if (choice == 4) {
                this->head70Def = "BERSERKERHELM";
                this->head75Def = "BERSERKERHELM";
            }

            if (choice == 5) {
                this->head70Def = "INQUISITORHELM";
                this->head75Def = "INQUISITORHELM";
            }

            else if (choice == 6) {
                this->head70Def = "NOTHING";
                this->head75Def = "NOTHING";
            }

            else if (choice == 7) {
                exit(0);
            }
        }
        choice = 0;

        while (choice > 5 || choice < 1) {
            std::cout << "For when def is 70 or greater, please enter the number next to the cape you will be using.\n";
            std::cout << "1. Fire cape\n";
            std::cout << "2. Infernal cape\n";
            std::cout << "3. Mythical cape\n";
            std::cout << "4. Nothing\n";
            std::cout << "5. Exit\n";
            std::cin >> choice;

            // If you choose Firecape, set this bracket and all above brackets to RPG, higher brackets will be changed later if at all
            if (choice == 1) {
                this->cape70Def = "FIRECAPE";
            }

            // If you choose Infernal cape, set this bracket and all above brackets to infernal cape, higher brackets will be changed later if at all
            else if (choice == 2) {
                this->cape70Def = "INFERNALCAPE";
            }

            else if (choice == 3) {
                this->cape70Def = "MYTHCAPE";
            }

            else if (choice == 4) {
                this->cape70Def = "NOTHING";
            }

            else if (choice == 5)
                exit(0);
        }
        choice = 0;

        // While loop to block choice into possible choices
        while (choice > 8 || choice < 1) {
            std::cout << "For when def 70 or greater, please enter the number next to the necklace you will be using.\n";
            std::cout << "1. Amulet of torture\n";
            std::cout << "2. Amulet of fury\n";
            std::cout << "3. Amulet of glory\n";
            std::cout << "4. Amulet of strength\n";
            std::cout << "5. Berserker necklace\n";
            std::cout << "6. Amulet of power\n";
            std::cout << "7. Nothing\n";
            std::cout << "8. Exit\n";
            std::cin >> choice;

            if (choice == 1) {
                this->necklace70Def = "AMMYTORTURE";
            }

            else if (choice == 2) {
                this->necklace70Def = "AMMYFURY";
            }

            else if (choice == 3) {
                this->necklace70Def = "AMMYGLORY";
            }

            else if (choice == 4) {
                this->necklace70Def = "AMMYSTRENGTH";
            }

            else if (choice == 5) {
                this->necklace70Def = "BERSERKERNECKLACE";
            }

            else if (choice == 6) {
                this->necklace70Def = "AMMYPOWER";
            }

            else if (choice == 7) {
                this->necklace70Def = "NOTHING";
            }

            else if (choice == 8)
                exit(0);
        }
        choice = 0;
    }

    if (startDef < 75 && endDef >= 70 && endAtt >= 70) {
        while (choice > 10 || choice < 1) {
            std::cout << "For when att and def are 70 or greater, please enter the number next to the shield you will be using.\n";
            std::cout << "1. Avernic defender\n";
            std::cout << "2. Dragon defender\n";
            std::cout << "3. Obby shield\n";
            std::cout << "4. Rune defender\n";
            std::cout << "5. Adamant defender\n";
            std::cout << "6. Mithril defender\n";
            std::cout << "7. Black defender\n";
            std::cout << "8. Book of war\n";
            std::cout << "9. Nothing\n";
            std::cout << "10. Exit\n";
            std::cin >> choice;

            if (choice == 1) {
                this->shield70Def70Att = "AVERNICDEFENDER";
                this->shield75Def70Att = "AVERNICDEFENDER";
            }

            if (choice == 2) {
                this->shield70Def70Att = "DRAGONDEFENDER";
                this->shield75Def70Att = "DRAGONDEFENDER";
            }

            if (choice == 3) {
                this->shield70Def70Att = "OBBYSHIELD";
                this->shield75Def70Att = "OBBYSHIELD";
            }

            if (choice == 4) {
                this->shield70Def70Att = "RUNEDEFENDER";
                this->shield75Def70Att = "RUNEDEFENDER";
            }

            if (choice == 5) {
                this->shield70Def70Att = "ADAMANTDEFENDER";
                this->shield75Def70Att = "ADAMANTDEFENDER";
            }

            if (choice == 6) {
                this->shield70Def70Att = "MITHRILDEFENDER";
                this->shield75Def70Att = "MITHRILDEFENDER";
            }

            if (choice == 7) {
                this->shield70Def70Att = "BLACKDEFENDER";
                this->shield75Def70Att = "BLACKDEFENDER";
            }

            if (choice == 8) {
                this->shield70Def70Att = "BOOKOFWAR";
                this->shield75Def70Att = "BOOKOFWAR";
            }

            else if (choice == 9) {
                this->shield70Def70Att = "NOTHING";
                this->shield75Def70Att = "NOTHING";
            }

            else if (choice == 10) {
                exit(0);
            }
        }
        choice = 0;
    }

    if (endDef >= 75) {
        // While loop to block choice into possible choices
        while (choice > 8 || choice < 1) {
            std::cout << "For when def is 75 or greater, please enter the number next to the helmet you will be using.\n";
            std::cout << "1. Serpentine helm\n";
            std::cout << "2. Nezzy faceguard\n";
            std::cout << "3. Obby helm\n";
            std::cout << "4. Nezzy helm\n";
            std::cout << "5. Berserker helm\n";
            std::cout << "6. Inquisitors helm\n";
            std::cout << "7. Nothing\n";
            std::cout << "8. Exit\n";
            std::cin >> choice;

            if (choice == 1) {
                this->head75Def = "SERPHELM";
            }

            if (choice == 2) {
                this->head75Def = "NEZZYFACEGUARD";
            }

            if (choice == 3) {
                this->head75Def = "OBBYHELM";
            }

            if (choice == 4) {
                this->head75Def = "NEZZYHELM";
            }

            if (choice == 5) {
                this->head75Def = "BERSERKERHELM";
            }

            if (choice == 6) {
                this->head75Def = "INQUISITORHELM";
            }

            else if (choice == 7) {
                this->head75Def = "NOTHING";
            }

            else if (choice == 8) {
                exit(0);
            }
        }
        choice = 0;

        while (choice > 10 || choice < 1) {
            std::cout << "For when def is 75 or greater and attack is <70, please enter the number next to the shield you will be using.\n";
            std::cout << "1. Dragonfire shield\n";
            std::cout << "2. Dragon defender\n";
            std::cout << "3. Obby shield\n";
            std::cout << "4. Rune defender\n";
            std::cout << "5. Adamant defender\n";
            std::cout << "6. Mithril defender\n";
            std::cout << "7. Black defender\n";
            std::cout << "8. Book of war\n";
            std::cout << "9. Nothing\n";
            std::cout << "10. Exit\n";
            std::cin >> choice;

            if (choice == 1) {
                this->shield75Def = "DRAGONFIRESHIELD";
            }

            if (choice == 2) {
                this->shield75Def = "DRAGONDEFENDER";
            }

            if (choice == 3) {
                this->shield75Def = "OBBYSHIELD";
            }

            if (choice == 4) {
                this->shield75Def = "RUNEDEFENDER";
            }

            if (choice == 5) {
                this->shield75Def = "ADAMANTDEFENDER";
            }

            if (choice == 6) {
                this->shield75Def = "MITHRILDEFENDER";
            }

            if (choice == 7) {
                this->shield75Def = "BLACKDEFENDER";
            }

            if (choice == 8) {
                this->shield75Def = "BOOKOFWAR";
            }

            else if (choice == 9) {
                this->shield75Def = "NOTHING";
            }

            else if (choice == 10) {
                exit(0);
            }
        }
        choice = 0;

        // While loop to block choice into possible choices boots
        while (choice > 7 || choice < 1) {
            std::cout << "For when def is 75 or greater, please enter the number next to the boots you will be using.\n";
            std::cout << "1. Primordial boots\n";
            std::cout << "2. Dragon boots\n";
            std::cout << "3. Granite boots\n";
            std::cout << "4. Spiked manacles\n";
            std::cout << "5. Climbing boots\n";
            std::cout << "6. Nothing\n";
            std::cout << "7. Exit\n";
            std::cin >> choice;

            if (choice == 1) {
                this->boot75Def = "PRIMORDIALBOOTS";
            }

            if (choice == 1) {
                this->boot75Def = "DRAGONBOOTS";
            }

            if (choice == 2) {
                this->boot75Def = "GRANITEBOOTS";
            }

            if (choice == 3) {
                this->boot75Def = "SPIKEDMANACLES";
            }

            if (choice == 4) {
                this->boot75Def = "CLIMBINGBOOTS";
            }

            else if (choice == 5) {
                this->boot75Def = "NOTHING";
            }

            else if (choice == 6) {
                exit(0);
            }
        }
        choice = 0;
    }

    if (endDef >= 80 && endAtt >= 80) {
        // While loop to block choice into possible choices gloves
        while (choice > 7 || choice < 1) {
            std::cout << "For when def and att are 80 or greater, please enter the number next to the gloves you will be using.\n";
            std::cout << "1. Ferocious gloves\n";
            std::cout << "2. Barrow gloves\n";
            std::cout << "3. Regeneration bracelet\n";
            std::cout << "4. Combat bracelete\n";
            std::cout << "5. Mithril gloves\n";
            std::cout << "6. Nothing\n";
            std::cout << "7. Exit\n";
            std::cin >> choice;

            if (choice == 1) {
                this->gloves80Def80Att = "FEROCIOUSGLOVES";
            }

            if (choice == 1) {
                this->gloves80Def80Att = "BARROWGLOVES";
            }

            if (choice == 1) {
                this->gloves80Def80Att = "REGENBRACE";
            }

            if (choice == 2) {
                this->gloves80Def80Att = "COMBATBRACE";
            }

            if (choice == 3) {
                this->gloves80Def80Att = "MITHRILGLOVES";
            }

            else if (choice == 4) {
                this->gloves80Def80Att = "NOTHING";
            }

            else if (choice == 5) {
                exit(0);
            }
        }
        choice = 0;
    }

    while (choice < 1 || choice > 4) {
        std::cout << "Enter the number next to the attack potion you will use.\n";
        std::cout << "1. Super attack\n";
        std::cout << "2. Attack potion\n";
        std::cout << "3. Nothing\n";
        std::cout << "4. Exit\n";
        std::cin >> choice;

        if (choice == 1)
            this->attPotion = "SUPERATT";
        else if (choice == 2)
            this->attPotion = "REGULARATT";
        else if (choice == 3)
            this->attPotion = "NOTHING";
        else if (choice == 4)
            exit(0);
    }
    choice = 0;

    while (choice < 1 || choice > 4) {
        std::cout << "Enter the number next to the strength potion you will use.\n";
        std::cout << "1. Super strength\n";
        std::cout << "2. Strength potion\n";
        std::cout << "3. Nothing\n";
        std::cout << "4. Exit\n";
        std::cin >> choice;

        if (choice == 1)
            this->strPotion = "SUPERSTR";
        else if (choice == 2)
            this->strPotion = "REGULARSTR";
        else if (choice == 3)
            this->strPotion = "NOTHING";
        else if (choice == 4)
            exit(0);
    }
    choice = 0;

    while (choice < 1 || choice > 6) {
        std::cout << "Enter the number next to the prayer you will use for attack.\n";
        std::cout << "1. Piety\n";
        std::cout << "2. Incredible reflexes\n";
        std::cout << "3. Improved reflexes\n";
        std::cout << "4. Clarity of thought\n";
        std::cout << "5. Nothing\n";
        std::cout << "6. Exit\n";
        std::cin >> choice;

        if (choice == 1)
            this->attPrayer = "PIETY";
        else if (choice == 2)
            this->attPrayer = "INCREDIBLE";
        else if (choice == 3)
            this->attPrayer = "IMPROVED";
        else if (choice == 4)
            this->attPrayer = "CLARITY";
        else if (choice == 5)
            this->attPrayer = "NOTHING";
        else if (choice == 6)
            exit(0);
    }
    choice = 0;

    while (choice < 1 || choice > 6) {
        std::cout << "Enter the number next to the prayer you will use for strength.\n";
        std::cout << "1. Piety\n";
        std::cout << "2. Ultimate strength\n";
        std::cout << "3. Superhuman strength\n";
        std::cout << "4. Burst of strength\n";
        std::cout << "5. Nothing\n";
        std::cout << "6. Exit\n";
        std::cin >> choice;

        if (choice == 1)
            this->strPrayer = "PIETY";
        else if (choice == 2)
            this->strPrayer = "ULTIMATE";
        else if (choice == 3)
            this->strPrayer = "SUPERHUMAN";
        else if (choice == 4)
            this->strPrayer = "BURST";
        else if (choice == 5)
            this->strPrayer = "NOTHING";
        else if (choice == 6)
            exit(0);
    }
    choice = 0;

    // Set up tables for each stat combination
    this->attBonusTable = new int[((endAtt - startAtt + 1) * (endStr - startStr + 1) * (endDef - startDef + 1)) + 1];
    this->strBonusTable = new int[((endAtt - startAtt + 1) * (endStr - startStr + 1) * (endDef - startDef + 1)) + 1];
    this->speedTable = new float[((endAtt - startAtt + 1) * (endStr - startStr + 1) * (endDef - startDef + 1)) + 1];

    int i = startAtt, ii = startStr, iii = startDef, counter = 1;
    while (i <= endAtt) {
        while (ii <= endStr) {
            while (iii <= endDef) {
                attBonusTable[counter] = getAttBonus(i, ii, iii);
                strBonusTable[counter] = getStrBonus(i, ii, iii);
                speedTable[counter] = getSpeed(i, ii, iii);
                counter++;
                iii++;
            }
            iii = startDef;
            ii++;
        }
        ii = startStr;
        i++;
    }
}

// Destructor to clean up pointer arrays
Equipment::~Equipment() {
    //delete[] attBonusTable;
    //delete[] strBonusTable;
    //delete[] speedTable;
}