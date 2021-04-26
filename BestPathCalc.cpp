#include "BestPathCalc.h"
#include <queue>

// == overload to allow equality comparisons of location objects
bool operator==(location a, location b) {
    if (a.attack == b.attack && a.strength == b.strength && a.defence == b.defence)
        return true;
    else
        return false;
}

// < overload to allow for greater than, less than comparisons of vertex objects
bool operator<(vertex a, vertex b) {
    return b.shortestPath < a.shortestPath; // reversed a and b because this will be used for a stl priority_queue, which is default max heap, I want min heap
}

// == overload to allow for equality comparisons for vertex objects
bool operator==(vertex a, vertex b) {
    return a.shortestPath == b.shortestPath;
}

// calculatePath takes as input a graph object which contains a graph made of adjacency lists
// along with a location object denoting the starting melee stats and another for ending stats
// It will then calculate the shortest path to get from the start to end stats using dijkstra's
// algorithm. The weights on edges denote the time in hours to get from one vertex to another
// A vector of pathInfo objects will be returned, at the time of writing this a pathInfo object
// will contain a location object and a float. The vector will hold a pathInfo object for every
// vertex in the answer path where the location holds the vertex location and float the pathtime
std::vector<pathInfo> BestPathCalc::calculatePath(Graph inputG, location start, location end) {
    // The vector of pathInfo that will be returned
    std::vector<pathInfo> returnPath;
    
    // A flag used for when the end location has been encountered
    bool found = false;

    // priority queue in the form of a min-heap, default is max-heap but I overloaded the vertex
    // comparison operator to be the opposite of normal allowing for default min-heap
    std::priority_queue<vertex> minHeap;
    
    // Start the queue with adjacency list 1, list 0  is isn't a standard list part of graph
    minHeap.push(inputG.indexList[1]);
    // Set list 1 status to true, denoting it has been put into the queue
    inputG.indexList[1].status = true;
    
    // Keep running until the queue is empty, we will stop adding values when end loc is top of queue
    while (!minHeap.empty()) {
        
        // Two vertex pointers initialized, one will be for top queue value, other will start
        // as top queue value and be moved to the connected outgoing vertices
        vertex* holder = new vertex;
        vertex* nextLinksHolder = new vertex;
        holder->loc = minHeap.top().loc;
        // minHeap doesn't contain vertex pointers and aren't updated properly so what minHeap gives
        // is the next location, point holder to real values correlated with the location
        holder = find(start, holder->loc, end, inputG);
        
        // If the top queue location = ending location, change found flag to true to stop adding to queue
        if (minHeap.top().loc == end)
            found = true;

        // nextLink originally set to top queue value and will traverse across the list of outgoing
        // vertices connected to the top queue value
        *nextLinksHolder = minHeap.top();
        while (nextLinksHolder->nextLink != NULL) {
            // index is meant to be attached to the real values that are updated and changed
            // the 'real' values are the index values of the graph's adjacency list, the starting of lists
            // the real values hold the shortest path to that vertex information that needs updating
            vertex* index = find(start, nextLinksHolder->nextLink->loc, end, inputG);
            // update shortest path value of vertex v if incoming vertex u's shortest path + (u,v) edge
            // weight is smaller than the already contained shortest path at v
            if (index->shortestPath > (holder->shortestPath + nextLinksHolder->nextLink->weight)) {
                index->shortestPath = holder->shortestPath + nextLinksHolder->nextLink->weight;
                index->previousLink = holder;
            }
            // If status is false, and not done, this vertex location hasn't been added to the queue yet, add it
            if (index->status == false) {
                if (!found) {
                    minHeap.push(*index);
                    index->status = true;
                }
            }
            // move the current vertex to the next in the list for the top vertex of the queue
            nextLinksHolder = nextLinksHolder->nextLink;

            // pointer clean up
            index = nullptr;
            delete index;
        }
        // done with top value of the queue, pop it
        minHeap.pop();

        // pointer clean up
        holder = nullptr;
        nextLinksHolder = nullptr;
        delete holder, nextLinksHolder;
    }

    // create vertex pointer that points to the final destination
    vertex* endVertexPointer = find(start, end, end, inputG);

    // path is the individual pieces of path info that will be combined into a vector to be returned
    pathInfo path;

    // get the path info for the final destination
    path.loc = endVertexPointer->loc;
    path.time = endVertexPointer->shortestPath;
    returnPath.push_back(path);

    // return backwards from the final destination getting the path info along the way
    while (endVertexPointer->previousLink != NULL) {
        path.loc = endVertexPointer->previousLink->loc;
        path.time = endVertexPointer->previousLink->shortestPath;
        returnPath.push_back(path);
        endVertexPointer = endVertexPointer->previousLink;
    }
    
    // pointer clean up
    endVertexPointer = nullptr;
    delete endVertexPointer;

    return returnPath;
}

// find takes a start location, check location, and end location as well as a graph made of adjacency lists
// It will then find the index in the adjacency list referring to the same location as check location
// and return the address to that position in the adjacency list
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