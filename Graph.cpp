#include "Graph.h"
#include <iostream>
#include <vector>

// Graph input is the level ranges, makes adjacency lists for start, start + 1, ..., end.
// Graph(1,1,1,99,99,99) would create adjacency list of startpoint: (1,1,1) -> (w)(2,1,1) -> (w)(1,2,1) -> (w)(1,1,2)
                                                                  //(1,2,1) -> (w)(1,3,1) -> (w)(2,2,1) -> (w)(1,2,2)  and so on to (99,99,99)  ... w is weight
Graph::Graph(int startAtt, int startStr, int startDef, int endAtt, int endStr, int endDef, GearUp gearUp)
{
    // Cap inputs to avoid using too much memory. The number of adjacency lists is tied to the range of combinations that will be made of (x att, y str, z def)
    // Also ensure that the starting values are lower than ending values
    if (((endAtt-startAtt-1) * (endStr-startStr-1) * (endDef-startDef-1)) < 5000000 && startAtt <= endAtt && startStr <= endStr && startDef <= endDef) {
        
        // indexList is a vertex pointer tied to a graph object. Create a dynamic array large enough for every possible vertex with indexList at the head
        this->indexList = new vertex[((endAtt - startAtt + 1) * (endStr - startStr + 1) * (endDef - startDef + 1)) + 1];
        
        // Initialize indexList list 0's weight to the number of vertices in the graph
        this->indexList[0].weight = ((endAtt - startAtt + 1) * (endStr - startStr + 1) * (endDef - startDef + 1));
        
        // counter is incremented for every new vertex and is used to index in indexList
        int counter = 1;

        // startAtt, startStr, startDef will all be used in the following triple for loop where vertices will be initialized
        // during initialization vertices will get their weight, list of outgoing vertices, and a shortest path of INF
        int i = startAtt, ii = startStr, iii = startDef;
        // First loop takes care of 'third digit', aka attack, aka x in ( x, y, z )
        while (i <= endAtt) {
            // Second loop takes care of 'second digit', aka strength, aka y in ( x, y, z )
            while (ii <= endStr) {
                // Third loop takes care of 'first digit' aka defence, aka z in (x, y, z )
                while (iii <= endDef) {

                    // If the very starting vertex, set shortest path to 0
                    // Else not first vertex and set the shortest path to INF to be updated later
                    if (i == startAtt && ii == startStr && iii == startDef)
                        this->indexList[counter].shortestPath = 0;
                    else
                        this->indexList[counter].shortestPath = INF;

                    // Initialize current vertex's location using i, ii, iii
                    this->indexList[counter].loc = { i, ii, iii };

                    // holder pointers will be used to initialize the outgoing vertice list for current vertex
                    // each vertex will have at most 3 outgoing vertice so at most all 3 holders will be used
                    // it is possible to not need all of them in a case of ( max, x, y) where only x and y
                    // can increase and therefore only 2 outgoing edges are possible
                    vertex* holder = new vertex;
                    vertex* holder2 = new vertex;
                    vertex* holder3 = new vertex;

                    // if attack can be increased, increase it and place it in holder, initialize rest of list
                    // which can include str increase or def increase, also initialize weight
                    if (i < endAtt) {
                        holder->loc = { i + 1,ii,iii };
                        if (ii < endStr)
                            holder->nextLink = holder2;
                        else if (iii < endDef)
                            holder->nextLink = holder3;
                        // weight for a vertex is equal to exp to be gained for the level divided by exp/hr
                        // weight is the edge weight between vertices, this is in hour units
                        holder->weight = ExpCalculations::expLeft(holder->loc.attack) / ExpCalculations::expHr(startAtt, startStr, startDef, i, ii, iii, endAtt, endStr, endDef, 1, gearUp); // Time in hours to gain required exp
                    }

                    // if strength can be increased, increase it and place it in holder2, initialize rest of list
                    // which can include def increase, also initialize weight
                    if (ii < endStr) {
                        holder2->loc = { i, ii + 1, iii };
                        if (iii < endDef)
                            holder2->nextLink = holder3;
                        holder2->weight = ExpCalculations::expLeft(holder2->loc.strength) / ExpCalculations::expHr(startAtt, startStr, startDef, i, ii, iii, endAtt, endStr, endDef, 2, gearUp);
                    }

                    // if defence can be increased, increase it and place it in holder3, initialize rest of list
                    // also initialize weight
                    if (iii < endDef) {
                        holder3->loc = { i, ii, iii + 1 };
                        holder3->weight = ExpCalculations::expLeft(holder3->loc.defence) / ExpCalculations::expHr(startAtt, startStr, startDef, i, ii, iii, endAtt, endStr, endDef, 3, gearUp);
                    }

                    // If i is less than max attack, that means attack can be increased and the increased
                    // attack level will be in the list, connect base vertex to holder
                    // if attack can't be increased, move on to check strength, then defence if str fails
                    if (i < endAtt)
                        this->indexList[counter].nextLink = holder;
                    else if (ii < endStr)
                        this->indexList[counter].nextLink = holder2;
                    else if (iii < endDef)
                        this->indexList[counter].nextLink = holder3;

                    // pointer clean up
                    holder = nullptr;
                    holder2 = nullptr;
                    holder3 = nullptr;
                    delete holder, holder2, holder3;

                    // Gone through 1 vertex, increase counter aswell as third digit defence
                    counter++;
                    iii++;
                }
                // Gone through a set of third digits, increase second digit and reset third digit
                ii++;
                iii = startDef;
            }
            // Gone through a set of second digit, increase first digit and reset second digit
            i++;
            ii = startStr;
        }
    }

    // The start and end points for att, str, def were too big, enter smaller values
    else
        std::cout << "Error: Memory overflow, try a smaller range! Or starting stats exceeded ending stats.\n";

}


void Graph::printGraph(GearUp gearUp) {

    // go through every vertex in the graph, indexList list 0 will uniquely have the number of vertices for it's weight
    for (int i = 1; i < this->indexList[0].weight; i++) {
        std::cout << '\n';
        vertex* copy = &this->indexList[i];


        location orig = copy->loc;


        while (copy != NULL) {
            std::cout << "( " << copy->loc.attack << ", " << copy->loc.strength << ", " << copy->loc.defence << " ) - Path:" << copy->shortestPath << " " << copy->weight << " ";
                //<< " ExpHr:" << ExpCalculations::expHr(copy->loc.attack, copy->loc.strength, copy->loc.defence, innerCounter, player) << "\n";


            //if (copy->loc.attack > orig.attack)
            //    ExpCalculations::expHr(copy->loc.attack, copy->loc.strength, copy->loc.defence, 1, gearUp);
            //else if (copy->loc.strength > orig.strength)
            //    ExpCalculations::expHr(copy->loc.attack, copy->loc.strength, copy->loc.defence, 2, gearUp);
            //else
            //    ExpCalculations::expHr(copy->loc.attack, copy->loc.strength, copy->loc.defence, 3, gearUp);


            copy = copy->nextLink;
        }
    }
}