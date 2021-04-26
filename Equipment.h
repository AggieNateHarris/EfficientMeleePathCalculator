#ifndef EQUIPMENT_H
#define EQUIPMENT_H
#include <string>
#include<map>

class Equipment
{
public:
    int* attRollTable;
    int* strRollTable;
    int* speedTable;

    std::string getWeapon(int att, int str, int def);
    std::string getHelm(int att, int str, int def);
    std::string getNecklace(int att, int str, int def);
    std::string getCape(int att, int str, int def);
    std::string getTorso(int att, int str, int def);
    std::string getShield(int att, int str, int def);
    std::string getLegs(int att, int str, int def);
    std::string getBoots(int att, int str, int def);
    std::string getGloves(int att, int str, int def);
    std::string getRing(int att, int str, int def);
    int getAttBonus(int att, int str, int def);
    int getStrBonus(int att, int str, int def);
    int getAttPotionBoost(int att);
    int getStrPotionBoost(int str);
    float getAttPrayerBoost();
    float getStrPrayerBoost();
    int getSpeed(int att, int str, int def); // Seconds per attack, EX: 4 tic = 2.4 seconds. -> 4 * 0.6 = 2.4
    int getOppDefBonus();
    int getOppDefLvl();
    int getOppHpLvl();
    void settings(int startAtt, int startStr, int startDef, int endAtt, int endStr, int endDef);

    std::map<std::string, int> equipmentAtt = {
        {"RPG", 0},
        {"NOTHING", 0},
        {"RUNEWARHAMMER", 53},
        {"OBBYMAUL", 80},
        {"DRAGONWARHAMMER", 95},
        {"BRINESABRE", 47},
        {"GRANITEHAMMER", 57},
        {"ANCIENTSTAFF", 40},
        {"LEAFBLADEDSWORD", 67},
        {"DRAGONSWORD", 65},
        {"DRAGONSCIMITAR", 67},
        {"SARACHNISCUDGEL", 70},
        {"SARADOMINSWORD", 82},
        {"ABYSSALDAGGER", 75},
        {"ABYSSALBLUDGEON", 102},
        {"ABYSSALWHIP", 82},
        {"ABYSSALWHIPCONTROLLED", 82},
        {"BLESSEDSARASWORD", 100},
        {"ABYSSALTENTACLE", 90},
        {"BLADEOFSAELDOR", 94},
        {"INQUISITORSMACE", 95},
        {"GHRAZIRAPIER", 94},

        {"OBBYHELM", 0},
        {"INQUISITORSHELM", 8},

        {"BERSERKERNECKLACE", -10},

        {"OBBYPLATE", 0},
        {"INQUISITORSPLATE", 12},

        {"OBBYLEGS", 0},
        {"INQUISITORSLEGS", 12}
    };

    std::map<std::string, int> equipmentStr = {
        {"RPG", 0},
        {"NOTHING", 0},
        {"RUNEWARHAMMER", 62},
        {"OBBYMAUL", 85},
        {"DRAGONWARHAMMER", 85},
        {"BRINESABRE", 46},
        {"GRANITEHAMMER", 56},
        {"ANCIENTSTAFF", 50},
        {"LEAFBLADEDSWORD", 50},
        {"DRAGONSWORD", 63},
        {"DRAGONSCIMITAR", 66},
        {"SARACHNISCUDGEL", 70},
        {"SARADOMINSWORD", 82},
        {"ABYSSALDAGGER", 75},
        {"ABYSSALBLUDGEON", 85},
        {"ABYSSALWHIP", 82},
        {"ABYSSALWHIPCONTROLLED", 82},
        {"BLESSEDSARASWORD", 88},
        {"ABYSSALTENTACLE", 86},
        {"BLADEOFSAELDOR", 89},
        {"INQUISITORSMACE", 89},
        {"GHRAZIRAPIER", 89},

        {"OBBYHELM", 3},
        {"INQUISITORSHELM", 4},

        {"BERSERKERNECKLACE", 7},

        {"OBBYPLATE", 3},
        {"INQUISITORSPLATE", 4},

        {"OBBYLEGS", 1},
        {"INQSUITORSLEGS", 2}
    };

    std::map<std::string, float> equipmentSpeed = {
        {"RPG", 1.8},
        {"NOTHING", 2.4},
        {"RUNEWARHAMMER", 3.6},
        {"OBBYMAUL", 4.2},
        {"DRAGONWARHAMMER", 3.6},
        {"BRINESABRE", 2.4},
        {"GRANITEHAMMER", 2.4},
        {"ANCIENTSTAFF", 2.4},
        {"LEAFBLADEDSWORD", 2.4},
        {"DRAGONSWORD", 2.4},
        {"DRAGONSCIMITAR", 2.4},
        {"SARACHNISCUDGEL", 2.4},
        {"SARADOMINSWORD", 2.4},
        {"ABYSSALDAGGER", 2.4},
        {"ABYSSALBLUDGEON", 2.4},
        {"ABYSSALWHIP", 2.4},
        {"ABYSSALWHIPCONTROLLED", 2.4},
        {"BLESSEDSARASWORD", 2.4},
        {"ABYSSALTENTACLE", 2.4},
        {"BLADEOFSAELDOR", 2.4},
        {"INQUISITORSMACE", 2.4},
        {"GHRAZIRAPIER", 2.4}
    };

    std::map<std::string, float> equipmentAttEffect = {
        {"NOTHING", 0},
        {"BERSERKERNECKLACE", 0},
        {"OBSIDIANARMOR", 0.1},
        {"INQUISITORONEPIECE", 0.005},
        {"INQUISITORTWOPIECE", 0.01},
        {"INQUISITORFULLSET", 0.025}
    };

    std::map<std::string, float> equipmentStrEffect = {
        {"NOTHING", 0},
        {"BERSERKERNECKLACE", 0.2},
        {"OBSIDIANARMOR", 0.1},
        {"INQUISITORONEPIECE", 0.005},
        {"INQUISITORTWOPIECE", 0.01},
        {"INQUISITORFULLSET", 0.025}
    };

    std::map<std::string, float> prayerAttBoost = {
        {"NOTHING", 1},
        {"CLARITY", 1.05},
        {"IMPROVED", 1.1},
        {"INCREDIBLE", 1.15},
        {"PIETY", 1.2}
    };

    std::map<std::string, float> prayerStrBoost = {
        {"NOTHING", 1},
        {"BURST", 1.05},
        {"SUPERHUMAN", 1.1},
        {"ULTIMATE", 1.15},
        {"PIETY", 1.23}
    };

    std::map<std::string, float> opponentDefLvl = {
        {"NOTHING", 0},
        {"ROCKCRAB", 1}
    };

    std::map<std::string, float> opponentDefBonus = {
        {"NOTHING", 0},
        {"ROCKCRAB", 0}
    };

    std::map<std::string, float> opponentHp = {
        {"NOTHING", 1},
        {"ROCKCRAB", 50}
    };

    // Default value for all equipment slots will be NOTHING
    std::string weapon1Att = "NOTHING";
    std::string weapon1Att40Str = "NOTHING";
    std::string weapon1Att60Str = "NOTHING";
    std::string weapon40Att = "NOTHING";
    std::string weapon50Att = "NOTHING";
    std::string weapon60Att = "NOTHING";
    std::string weapon70Att = "NOTHING";
    std::string weapon75Att = "NOTHING";

    std::string head30Def = "NOTHING";
    std::string head45Def = "NOTHING";
    std::string head55Def = "NOTHING";
    std::string head60Def = "NOTHING";
    std::string head70Def = "NOTHING";
    std::string head75Def = "NOTHING";

    std::string cape1Def = "NOTHING";              // Brackets not based on actual requirements, but option if you know
    std::string cape40Def = "NOTHING";             // your cape will change as you get higher def/cmb lvl
    std::string cape70Def = "NOTHING";
    
    std::string necklace1Def = "NOTHING";          // Brackets not basd on actual requirements, but option if you know
    std::string necklace40Def = "NOTHING";         // your necklace will change as you get higher def/cmb lvl
    std::string necklace70Def = "NOTHING";

    std::string torso30Def = "NOTHING";
    std::string torso40Def = "NOTHING";
    std::string torso60Def = "NOTHING";
    std::string torso65Def = "NOTHING";

    std::string shield1Def = "NOTHING";
    std::string shield10Def = "NOTHING";
    std::string shield20Def = "NOTHING";
    std::string shield30Def = "NOTHING";
    std::string shield40Def = "NOTHING";
    std::string shield60Def = "NOTHING";
    std::string shield70Def = "NOTHING";
    std::string shield75Def = "NOTHING";

    std::string legs1Def = "NOTHING";
    std::string legs30Def = "NOTHING";
    std::string legs60Def = "NOTHING";
    std::string legs65Def = "NOTHING";

    std::string gloves1Def = "NOTHING";
    std::string gloves32Def = "NOTHING";
    std::string gloves42Def = "NOTHING";
    std::string gloves80Def = "NOTHING";

    std::string boot1Def = "NOTHING";
    std::string boot50Def = "NOTHING";
    std::string boot60Def = "NOTHING";
    std::string boot75Def = "NOTHING";

    std::string ring1Def = "NOTHING";
    std::string ring50Def = "NOTHING"; // There isn't a def requirement for any rings, this is just an option if someone knows they will have a ring change between 1 def and 50 def

    std::string setBonus = "NOTHING";

    std::string attPotion = "NOTHING";
    std::string strPotion = "NOTHING";

    std::string attPrayer = "NOTHING";
    std::string strPrayer = "NOTHING";

    std::string opponent = "ROCKCRAB";
    //TODO: Fill this section out more completely, I envision user being able to select their weapon / gear
    //      at each level bracket / level unlock and a lot more versatility than current
};

#endif