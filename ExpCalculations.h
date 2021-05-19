#ifndef EXPCALCULATIONS_H
#define EXPCALCULATIONS_H
#include <iostream>
#include "GearUp.h"
#include "Graph.h"

// Exp to be gained between each level, starting at 0->1 = 0, 1->2 = 83 ...
const int ExpTable[99] = {
0,
83,
91,
102,
112,
124,
138,
151,
168,
185,
204,
226,
249,
274,
304,
335,
369,
408,
450,
497,
548,
606,
667,
737,
814,
898,
990,
1094,
1207,
1332,
1470,
1623,
1791,
1977,
2182,
2409,
2658,
2935,
3240,
3576,
3947,
4358,
4810,
5310,
5863,
6471,
7144,
7887,
8707,
9612,
10612,
11715,
12934,
14278,
15764,
17404,
19214,
21212,
23420,
25856,
28546,
31516,
34795,
38416,
42413,
46826,
51699,
57079,
63019,
69576,
76818,
84812,
93638,
103383,
114143,
126022,
139138,
153619,
169608,
187260,
206750,
228269,
252027,
278259,
307221,
339198,
374502,
413482,
456519,
504037,
556499,
614422,
678376,
748985,
826944,
913019,
1008052,
1112977,
1228825
};

// This class is dedicated to the exp calculations required for the program
class ExpCalculations
{
public:
    // Finds the exp between levels (end - 1) -> (end) using ExpTable struct
    static int expLeft(int end);

    // Finds the exp/hr when given starting stats, current stats, end stats, stance and a GearUp object with gear information
    static double expHr(float expPerDamage, int startAtt, int startStr, int startDef, int checkAtt, int checkStr, int checkDef, int endAtt, int endStr, int endDef, int stance, GearUp gearUp);

    // Finds the node in the table set up in GearUp of a certain set of stats being checked
    static int findLocation(int startAtt, int startStr, int startDef, int checkAtt, int checkStr, int checkDef, int endAtt, int endStr, int endDef);
};

#endif