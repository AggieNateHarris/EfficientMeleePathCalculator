#include "ExpCalculations.h"
#include "Equipment.h"
#include "Graph.h"
#include "BestPathCalc.h"
#include <iostream>

int main() {
    std::cout << "hello there" << '\n';
    //double expRate = ExpCalculations::expHr(1, 2, 1, 1);
    //std::cout << expRate << '\n';
    Equipment player;
    int startAtt = 2, startStr = 3, startDef = 1;
    int endAtt = 60, endStr = 75, endDef = 45;
    player.settings(startAtt, startStr, startDef, endAtt, endStr, endDef);
    Graph adjList(startAtt, startStr, startDef, endAtt, endStr, endDef, player);
    //std::cout << adjList.indexList[267].loc.attack << '\n';
    //vertex* testLoc = BestPathCalc::find({ 20,20,20 }, { 27, 22, 36 }, { 32, 30, 40 }, adjList);
    //std::cout << testLoc->loc.attack << " " << testLoc->loc.strength << " " << testLoc->loc.defence << " " << '\n';
    //adjList.printGraph(player);
    location start = { startAtt, startStr, startDef };
    location end = { endAtt, endStr, endDef };
    std::vector<pathInfo> path = BestPathCalc::calculatePath(adjList, start, end);
    for (int i = 0; i < path.size(); i++) {
        std::cout << "( " << path[i].loc.attack << ", " << path[i].loc.strength << ", " << path[i].loc.defence << " ) - Time: " << path[i].time << "\n";
    }
    return 0;
}