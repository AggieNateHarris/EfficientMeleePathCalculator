#include "Equipment.h"
#include <iostream>

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
    else if (def < 75)
        shield = this->shield70Def;
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
    else if (def >= 80)
        gloves = this->gloves80Def;
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

int Equipment::getSpeed(int att, int str, int def) {            // Seconds per attack, EX: 4 tic = 2.4 seconds. -> 4 * 0.6 = 2.4
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
                exit;
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
                exit;
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
                exit;
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
                exit;
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
                exit;
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
                exit;
        }
        choice = 0;
    }

    // When attack can be greater than 70 but starts below
    if (startAtt < 75 && endAtt >= 70) {
        while (choice < 1 || choice > 18) {
            std::cout << "For when attack is 70 or greater, choose your weapon.\n";
            std::cout << "1. Abyssal whip controlled\n";
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

            // Set this bracket and all above brackets to the same thing, they will be changed later if at all
            if (choice == 1) {
                this->weapon70Att = "ABYSSALWHIPCONTROLLED";
                this->weapon75Att = "ABYSSALWHIPCONTROLLED";
            }

            if (choice == 2) {
                this->weapon70Att = "ABYSSALWHIP";
                this->weapon75Att = "ABYSSALWHIP";
            }

            if (choice == 3) {
                this->weapon70Att = "ABYSSALBLUDGEON";
                this->weapon75Att = "ABYSSALBLUDGEON";
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
                exit;
        }
        choice = 0;
    }

    // When attack can be greater than 75 but starts below
    if (endAtt >= 75) {
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
            }

            if (choice == 5) {
                this->weapon75Att = "BLESSEDSARASWORD";
            }

            if (choice == 6) {
                this->weapon75Att = "ABYSSALWHIPCONTROLLED";
            }

            if (choice == 7) {
                this->weapon75Att = "ABYSSALWHIP";
            }

            if (choice == 8) {
                this->weapon75Att = "ABYSSALBLUDGEON";
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
                exit;
        }
        choice = 0;
    }
}