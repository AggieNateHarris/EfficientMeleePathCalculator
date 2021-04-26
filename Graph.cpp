#include "Graph.h"
#include <iostream>
#include <vector>

// Graph input is the level ranges, makes adjacency lists for start, start + 1, ..., end.
// Graph(1,1,1,99,99,99) would create adjacency list of startpoint: (1,1,1) -> (w)(2,1,1) -> (w)(1,2,1) -> (w)(1,1,2)
                                                                  //(1,2,1) -> (w)(1,3,1) -> (w)(2,2,1) -> (w)(1,2,2)  and so on to (99,99,99)  ... w is weight
Graph::Graph(int startAtt, int startStr, int startDef, int endAtt, int endStr, int endDef, Equipment player)
{
    // Cap inputs to avoid using too much memory. The number of adjacency lists is tied to the range of combinations that will be made of (x att, y str, z def)
    // Also ensure that the starting values are lower than ending values
    if (((endAtt-startAtt-1) * (endStr-startStr-1) * (endDef-startDef-1)) < 5000000 && startAtt <= endAtt && startStr <= endStr && startDef <= endDef) {
        
        // indexList is a vertex pointer tied to a graph object. Create a dynamic array large enough for every possible vertex with indexList at the head
        this->indexList = new vertex[((endAtt - startAtt + 1) * (endStr - startStr + 1) * (endDef - startDef + 1)) + 1];
        this->indexList[0].weight = ((endAtt - startAtt + 1) * (endStr - startStr + 1) * (endDef - startDef + 1));
        int counter = 1;
        int i = startAtt, ii = startStr, iii = startDef;
        while (i <= endAtt) {
            while (ii <= endStr) {
                while (iii <= endDef) {
                    if (i == startAtt && ii == startStr && iii == startDef)
                        this->indexList[counter].shortestPath = 0;
                    else
                        this->indexList[counter].shortestPath = INF;

                    this->indexList[counter].loc = { i, ii, iii };

                    vertex* holder = new vertex;
                    vertex* holder2 = new vertex;
                    vertex* holder3 = new vertex;
                    if (i < endAtt) {
                        holder->loc = { i + 1,ii,iii };
                        if (ii < endStr)
                            holder->nextLink = holder2;
                        else if (iii < endDef)
                            holder->nextLink = holder3;

                        holder->weight = ExpCalculations::expLeft(holder->loc.attack) / ExpCalculations::expHr(i, ii, iii, 1, player); // Time in hours to gain required exp
                    }
                    if (ii < endStr) {
                        holder2->loc = { i, ii + 1, iii };
                        if (iii < endDef)
                            holder2->nextLink = holder3;
                        holder2->weight = ExpCalculations::expLeft(holder2->loc.strength) / ExpCalculations::expHr(i, ii, iii, 2, player);
                    }
                    if (iii < endDef) {
                        holder3->loc = { i, ii, iii + 1 };
                        holder3->weight = ExpCalculations::expLeft(holder3->loc.defence) / ExpCalculations::expHr(i, ii, iii, 3, player);
                    }

                    if (i < endAtt)
                        this->indexList[counter].nextLink = holder;
                    else if (ii < endStr)
                        this->indexList[counter].nextLink = holder2;
                    else if (iii < endDef)
                        this->indexList[counter].nextLink = holder3;

                    counter++;
                    iii++;
                }
                ii++;
                iii = startDef;
            }
            i++;
            ii = startStr;
        }
    }
    else {
        std::cout << "Error: Memory overflow, try a smaller range! Or starting stats exceeded ending stats.\n";
    }

}

void Graph::printGraph(Equipment player) {
    for (int i = 1; i < this->indexList[0].weight; i++) {
        std::cout << '\n';
        vertex* copy = &this->indexList[i];


        location orig = copy->loc;


        while (copy != NULL) {
            std::cout << "( " << copy->loc.attack << ", " << copy->loc.strength << ", " << copy->loc.defence << " ) - Path:" << copy->shortestPath << " " << copy->weight << " ";
                //<< " ExpHr:" << ExpCalculations::expHr(copy->loc.attack, copy->loc.strength, copy->loc.defence, innerCounter, player) << "\n";


            if (copy->loc.attack > orig.attack)
                ExpCalculations::expHr(copy->loc.attack, copy->loc.strength, copy->loc.defence, 1, player);
            else if (copy->loc.strength > orig.strength)
                ExpCalculations::expHr(copy->loc.attack, copy->loc.strength, copy->loc.defence, 2, player);
            else
                ExpCalculations::expHr(copy->loc.attack, copy->loc.strength, copy->loc.defence, 3, player);


            copy = copy->nextLink;
        }
    }
}