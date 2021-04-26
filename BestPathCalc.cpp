#include "BestPathCalc.h"
#include <queue>

bool operator==(location a, location b) {
    if (a.attack == b.attack && a.strength == b.strength && a.defence == b.defence)
        return true;
    else
        return false;
}

bool operator<(vertex a, vertex b) {
    return b.shortestPath < a.shortestPath; // reversed a and b because this will be used for a stl priority_queue, which is default max heap, I want min heap
}

bool operator==(vertex a, vertex b) {
    return a.shortestPath == b.shortestPath;
}

std::vector<pathInfo> BestPathCalc::calculatePath(Graph inputG, location start, location end) {
    std::vector<pathInfo> returnPath;
    bool found = false;
    std::priority_queue<vertex> minHeap;
    minHeap.push(inputG.indexList[1]);
    inputG.indexList[1].status = true;
    while (!minHeap.empty()) {
        vertex* holder = new vertex;
        vertex* nextLinksHolder = new vertex;
        holder->loc = minHeap.top().loc;
        holder = find(start, holder->loc, end, inputG);
        if (minHeap.top().loc == end)
            found = true;
        *nextLinksHolder = minHeap.top();
        while (nextLinksHolder->nextLink != NULL) {
            vertex* index = find(start, nextLinksHolder->nextLink->loc, end, inputG);
            if (index->shortestPath > (holder->shortestPath + nextLinksHolder->nextLink->weight)) {
                index->shortestPath = holder->shortestPath + nextLinksHolder->nextLink->weight;
                index->previousLink = holder;
            }
            if (index->status == false) {
                if (!found)
                    minHeap.push(*index);
                index->status = true;
            }
            nextLinksHolder = nextLinksHolder->nextLink;
        }
        minHeap.pop();
    }
    vertex* endVertexPointer = find(start, end, end, inputG);
    pathInfo path;
    path.loc = endVertexPointer->loc;
    path.time = endVertexPointer->shortestPath;
    returnPath.push_back(path);
    while (endVertexPointer->previousLink != NULL) {
        path.loc = endVertexPointer->previousLink->loc;
        path.time = endVertexPointer->previousLink->shortestPath;
        returnPath.push_back(path);
        endVertexPointer = endVertexPointer->previousLink;
    }
    return returnPath;
}

vertex* BestPathCalc::find(location startLoc, location checkLoc, location endLoc, Graph inputG) {
    // Third digit strength refers to att in (att, str, def) in a location object, the strength is the number of
    // combinations of str and def that must be gone through before att will be raised by 1
    // Uses absolute start and end points
    int thirdDigitStrength = ((endLoc.strength - startLoc.strength) * (endLoc.defence - (startLoc.defence - 1))) + (endLoc.defence - (startLoc.defence - 1));

    // Second digit strength refers to str in (att, str, def) in a location object, the strength is the number of
    // combinations of def that must be gone through before str will be raised by 1
    // Uses absolute start and end points
    int secondDigitStrength = (endLoc.defence - (startLoc.defence - 1));

    // the ranges are the number of values between the starting and ending, ending included
    // def includes the starting value whereas the others do not, so the def formula includes a -1
    // Uses absolute start and desired endpoint
    int attRange = checkLoc.attack - startLoc.attack;
    int strRange = checkLoc.strength - startLoc.strength;
    int defRange = checkLoc.defence - (startLoc.defence - 1);

    // The exact spot in the graph's indexList for a specified location object can be found with the formula below
    // because of the order the adjacency lists are populated
    return &inputG.indexList[(attRange * thirdDigitStrength) + (strRange * secondDigitStrength) + (defRange)];
}