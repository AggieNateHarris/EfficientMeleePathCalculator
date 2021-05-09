#include "ExpCalculations.h"
#include "Equipment.h"
#include "Graph.h"
#include "BestPathCalc.h"
#include <iostream>
#include "GearUp.h"

int main() {
    // create an equipment object
    Equipment player;
    // create a gear up object
    GearUp gearUp;

    // pick a starting location, ( att, str, def ), initialize a location struct with that information
    int startAtt = 1, startStr = 1, startDef = 1;
    location start = { startAtt, startStr, startDef };
    // pick an ending location, ( att, str, def ), initialize a location struct with that information
    int endAtt = 10, endStr = 10, endDef = 10;
    location end = { endAtt, endStr, endDef };

    // set equipment through the equipment.settings() function
    player.settings(startAtt, startStr, startDef, endAtt, endStr, endDef);

    // take info gathered in settings() and transfer it over to the GearUp object
    gearUp.fillTableRolls(player);
    gearUp.fillPotionBoosts(player);
    gearUp.fillPrayerBoosts(player);
    gearUp.fillOppInfo(player);

    // Create a graph made up of adjacency lists, this requires starting and ending locations a long with a GearUp object
    Graph adjList(startAtt, startStr, startDef, endAtt, endStr, endDef, gearUp);

    // create a vector<pathInfo> variable and set it equal to the best path calculated by BestPathCalc::calculatePath()
    std::vector<pathInfo> path = BestPathCalc::calculatePath(adjList, start, end);
    
    // print out the path and information collected from the BestPathCalc::calculatePath() function
    for (int i = 0; i < path.size(); i++) {
        std::cout << "( " << path[i].loc.attack << ", " << path[i].loc.strength << ", " << path[i].loc.defence << " ) - Time: " << path[i].time << "\n";
    }
    return 0;
}

// TODO: Allow for exp rate change for seasonal game modes where exp rates are changed
// TODO: Finish commenting everything, equipment
// TODO: Fix unique controlled style to spread xp and +1 att and str stance
// TODO: clean up pointers