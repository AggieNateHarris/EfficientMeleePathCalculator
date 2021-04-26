#ifndef BESTPATHCALC_H
#define BESTPATHCALC_H
#include "Graph.h"

// pathInfo is used when returning the shortest path solution path
struct pathInfo {
    location loc = { 1, 1, 1 };
    float time = INF;
};

class BestPathCalc
{
public:
    // calculatePath takes as input a graph object which contains a graph made of adjacency lists
    // along with a location object denoting the starting melee stats and another for ending stats
    // It will then calculate the shortest path to get from the start to end stats using dijkstra's
    // algorithm. The weights on edges denote the time in hours to get from one vertex to another
    // A vector of pathInfo objects will be returned, at the time of writing this a pathInfo object
    // will contain a location object and a float. The vector will hold a pathInfo object for every
    // vertex in the answer path where the location holds the vertex location and float the pathtime
    static std::vector<pathInfo> calculatePath(Graph inputG, location start, location end);

    // find takes a start location, check location, and end location as well as a graph made of adjacency lists
    // It will then find the index in the adjacency list referring to the same location as check location
    // and return the address to that position in the adjacency list
    static vertex* find(location startLoc, location checkLoc, location locEnd, Graph inputG);
};

#endif