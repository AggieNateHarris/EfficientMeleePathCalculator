#ifndef GRAPH_H
#define GRAPH_H
#include <vector>
#include "ExpCalculations.h"
#include "GearUp.h"

const double INF = std::numeric_limits<double>::max();

struct location {
    int attack = 1;
    int strength = 1;
    int defence = 1;
};

struct vertex {
    vertex* nextLink = NULL;
    vertex* previousLink = NULL;
    location loc;
    bool status = false;                    // true denotes this vertex has been looked at and placed in the queue, false denotes it hasn't
    float shortestPath = INF;
    double weight = NULL;
};

class Graph{
public:
    Graph(int startAtt, int startStr, int startDef, int var1, int var2, int var3, GearUp gearUp);    // Var are endpoint of 1,2,3,...n.
                                            // Graph(99,99,99) would create adjacency list of startpoint: (1,1,1) -> (w)(2,1,1) -> (w)(1,2,1) -> (w)(1,1,2)
                                                                                                        //(1,2,1) -> (w)(1,3,1) -> (w)(2,2,1) -> (w)(1,2,2)  and so on to (99,99,99)  ... w is weight
    vertex* indexList;
    void printGraph(GearUp gearUp);
};

#endif

