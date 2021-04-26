#ifndef BESTPATHCALC_H
#define BESTPATHCALC_H
#include "Graph.h"

struct pathInfo {
    location loc = { 1, 1, 1 };
    float time = INF;
};

class BestPathCalc
{
public:
    static std::vector<pathInfo> calculatePath(Graph inputG, location start, location end);
    static vertex* find(location startLoc, location checkLoc, location locEnd, Graph inputG);
};

#endif