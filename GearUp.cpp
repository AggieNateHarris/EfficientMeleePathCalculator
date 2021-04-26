#include "GearUp.h"

void GearUp::fillAttRollTable(Equipment gear) {
    this->attRollTable = gear.attRollTable;
}

void GearUp::fillStrRollTable(Equipment gear) {
    this->strRollTable = gear.strRollTable;
}

void GearUp::fillSpeedTable(Equipment gear) {
    this->speedTable = gear.speedTable;
}