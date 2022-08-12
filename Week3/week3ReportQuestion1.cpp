//
//  File Name: week3ReportQuestion1.cpp
//  Program: Masters of Computer Science
//  Course: Specalised Programming
//  Problem URL: https://community.topcoder.com/stat?c=problem_statement&pm=15099
//  Test Case URL: https://community.topcoder.com/stat?c=problem_solution&cr=40732861&rd=17298&pm=15099
//  Test Cases Passes: 25 / 25
//
//  Created by Pranshu Raj Goel on 11/8/2022.
//
/*
 Problem Statement for HungryCowsEasy


 Problem Statement
         
 There are several hungry cows and several barns, all located on the same straight line. All barns are located at distinct postitions.

 You are given the coordinates of the cows in the int[] cowPositions and the coordinates of barns in the int[] barnPositions. In particular, the i-th element of cowPositions is the coordinate of the i-th cow, and the i-th element of barnPositions is the coordinate of the i-th barn. (Both cows and barns are numbered starting from zero.)

 Each cow will go to the nearest barn to have dinner. If two barns have the same smallest distance from a cow, the cow will choose the barn with the smaller coordinate. Multiple cows can have dinner in the same barn.

 Which barn will each cow go to? Return a int[] with as many elements as there are cows. For each i, the i-th element of the return value should be the number of the barn where the i-th cow will go.

  
 Definition
         
 Class:    HungryCowsEasy
 Method:    findFood
 Parameters:    int[], int[]
 Returns:    int[]
 Method signature:    int[] findFood(int[] cowPositions, int[] barnPositions)
 (be sure your method is public)
     
  
 Constraints
 -    cowPositions will contain between 1 and 50 elements, inclusive.
 -    Each element of cowPositions will be between -1,000,000,000 and 1,000,000,000, inclusive.
 -    barnPositions will contain between 1 and 50 elements, inclusive.
 -    Each element of barnPositions will be between -1,000,000,000 and 1,000,000,000, inclusive.
 -    All elements of barnPositions will be distinct.
  
 Examples
 0)
         
 {0}
 {-5, 5}
 Returns: {0 }
 There is a single cow located at coordinate 0 and two barns at coordinates -5 and 5, respectively. They are both at the same distance from the cow, so the cow will choose the one with the smaller coordinate, which is -5. Thus, cow 0 will have its dinner in barn 0.
 1)
         
 {7, 7}
 {7, 10000}
 Returns: {0, 0 }
 There are two barns: barn 0 at coordinate 7 and barn 1 at coordinate 10000. Both cows are currently at the location of barn 0, and therefore both of them will have their dinner there. (Recall that multiple cows can share the same barn at dinnertime.)
 2)
         
 {2, 6, 0, 4, 8}
 {3, -1, 5, 1, 7}
 Returns: {3, 2, 1, 0, 4 }
 Note that the coordinates of cows and barns are not necessarily sorted.

 The correct return value describes the following outcome:

 Cow 0 (coordinate=2) will eat its dinner in barn 3 (coordinate=1).
 Cow 1 (coordinate=6) will eat its dinner in barn 2 (coordinate=5).
 Cow 2 (coordinate=0) will eat its dinner in barn 1 (coordinate=-1).
 Cow 3 (coordinate=4) will eat its dinner in barn 0 (coordinate=3).
 Cow 4 (coordinate=8) will eat its dinner in barn 4 (coordinate=7).
 This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2010, TopCoder, Inc. All rights reserved.




 This problem was used for:
        TCO19 Single Round Match 739 Round 1 - Division II, Level One
 
 ----------------------------------------------------
 Output
 
 Result of 00th test: Passed
 Result of 01th test: Passed
 Result of 02th test: Passed
 Result of 03th test: Passed
 Result of 04th test: Passed
 Result of 05th test: Passed
 Result of 06th test: Passed
 Result of 07th test: Passed
 Result of 08th test: Passed
 Result of 09th test: Passed
 Result of 10th test: Passed
 Result of 11th test: Passed
 Result of 12th test: Passed
 Result of 13th test: Passed
 Result of 14th test: Passed
 Result of 15th test: Passed
 Result of 16th test: Passed
 Result of 17th test: Passed
 Result of 18th test: Passed
 Result of 19th test: Passed
 Result of 20th test: Passed
 Result of 21th test: Passed
 Result of 22th test: Passed
 Result of 23th test: Passed
 Result of 24th test: Passed
 Total Failed Test Cases: 0
 Program ended with exit code: 0
 
 */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class HungryCowsEasy {
    public:
    vector<int> findFoodVerbose(vector<int> cowPositions, vector<int> barnPositions) {
        unordered_map<int, vector<int>> cowPositionMap, barnPositionMap;
        for(auto ilt = cowPositions.begin(); ilt != cowPositions.end(); ilt++)
            (cowPositionMap[*ilt]).push_back(ilt - cowPositions.begin());
        sort(cowPositions.begin(), cowPositions.end());
        
        for(auto ilt = barnPositions.begin(); ilt != barnPositions.end(); ilt++)
            (barnPositionMap[*ilt]).push_back(ilt - barnPositions.begin());
        sort(barnPositions.begin(), barnPositions.end());
        
            cout << "-------------------------------------------------------" << endl;
            cout << "cowPositions: " << endl << "{ "; for(auto ilt = cowPositions.begin();ilt != cowPositions.end(); ilt++) cout << (ilt == cowPositions.begin()? "" : ", ") << (ilt - cowPositions.begin()) << ": " << *ilt; cout << "}" << endl;
            cout << "cowPositionMap: " << endl;
            for(auto ilt = cowPositionMap.begin();ilt != cowPositionMap.end(); ilt++){
                cout << ilt->first << " :: { ";
                for(auto ilt1 = (ilt->second).begin(); ilt1 != (ilt->second).end(); ilt1++)
                    cout << (ilt1 == (ilt->second).begin()? "" : ", ") << (ilt1 - (ilt->second).begin()) << ": " << (*ilt1);
                cout << "}" << endl;
            }
            cout << endl;
            cout << "barnPositions: " << endl << "{ "; for(auto ilt = barnPositions.begin();ilt != barnPositions.end(); ilt++) cout << (ilt == barnPositions.begin()? "" : ", ") << (ilt - barnPositions.begin()) << ": " << *ilt; cout << "}" << endl;
            cout << "barnPositionMap: " << endl;
            for(auto ilt = barnPositionMap.begin();ilt != barnPositionMap.end(); ilt++){
                cout << ilt->first << " :: { ";
                for(auto ilt1 = (ilt->second).begin(); ilt1 != (ilt->second).end(); ilt1++)
                    cout << (ilt1 == (ilt->second).begin()? "" : ", ") << (ilt1 - (ilt->second).begin()) << ": " << (*ilt1);
                cout << "}" << endl;
            }
            cout << "*******************************************************" << endl;

        vector<int> result(cowPositions.size());
        for(auto ilt = cowPositions.begin(); ilt != cowPositions.end(); ilt++) {
            vector<int>::iterator closest, cow2barn = lower_bound(barnPositions.begin(), barnPositions.end(), *ilt);
            if (cow2barn == barnPositions.end())                                // cow is at right side of the barn window
                closest = cow2barn - 1;
            else if (*cow2barn == *ilt)                                         // cow is at the barn location
                closest = cow2barn;
            else if (cow2barn == barnPositions.begin() && *cow2barn > *ilt)     // cow is at left side of the barn window
                closest = cow2barn;
            else {                                                              // cow is at between 2 the barn location
                if((*cow2barn - *ilt) >= (*ilt - *(cow2barn - 1)))              // .... left barn is closer or at equi-distant from the cow
                    closest = cow2barn - 1;
                else closest = cow2barn;                                        // .... right barn is closer from the cow
            }
                cout << *(cowPositionMap[*ilt].rbegin()) << "th cow ( at distance of " << *ilt << ")" << endl;
                cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
                cout << "cow is at right side of the barn window ==> (cow2barn == barnPositions.end()): " << (cow2barn == barnPositions.end()) << endl;
                cout << "cow is at the barn location ==>(*cow2barn == *ilt): " << (*cow2barn == *ilt) << endl;
                cout << "cow is at left side of the barn window ==> (cow2barn == barnPositions.begin() && *cow2barn > *ilt): " << (cow2barn == barnPositions.begin() && *cow2barn > *ilt) << endl;
                if(!(cow2barn == barnPositions.end()) && !(*cow2barn == *ilt) && !(cow2barn == barnPositions.begin() && *cow2barn > *ilt))
                    cout << "cow is at between 2 the barn location ==> " << *(cowPositionMap[*ilt].rbegin()) << "th cow location: " << *ilt << " | " << *(barnPositionMap[*(cow2barn - 1)].rbegin()) << "th barn is on left at "  << *(cow2barn - 1) << " (distance: " << (*ilt - *(cow2barn - 1)) << ") | " << *(barnPositionMap[*cow2barn].rbegin()) << "th barn is on right at " << *cow2barn << " (distance: " << (*cow2barn - *ilt) << ") " << endl;
                cout << "cow is at between 2 the barn location -> left barn is closer or at equi-distant from the cow ==> ((*cow2barn - *ilt) >= (*(cow2barn - 1) - *ilt)): " << ((*cow2barn - *ilt) >= (*(cow2barn - 1) - *ilt)) << endl;
                cout << "cow is at between 2 the barn location -> right barn is closer ==> ((*cow2barn - *ilt) < (*(cow2barn - 1) - *ilt)): " << ((*cow2barn - *ilt) < (*(cow2barn - 1) - *ilt)) << endl;
                
                cout << *(cowPositionMap[*ilt].rbegin()) << "th cow ( at distance of " << *ilt << ") eats at " << *(barnPositionMap[*closest].rbegin()) << "th barn ( at distance of " << *closest << ")" << endl;
                cout << "*******************************************************" << endl;
            *(result.begin() + *(cowPositionMap[*ilt].rbegin())) = *(barnPositionMap[*closest].rbegin());
            cowPositionMap[*ilt].pop_back();
        }
        return result;
    };
    vector<int> findFood(vector<int> cowPositions, vector<int> barnPositions) {
        unordered_map<int, vector<int>> cowPositionMap, barnPositionMap;
        for(auto ilt = cowPositions.begin(); ilt != cowPositions.end(); ilt++) (cowPositionMap[*ilt]).push_back(ilt - cowPositions.begin());
        sort(cowPositions.begin(), cowPositions.end());
        for(auto ilt = barnPositions.begin(); ilt != barnPositions.end(); ilt++) (barnPositionMap[*ilt]).push_back(ilt - barnPositions.begin());
        sort(barnPositions.begin(), barnPositions.end());
        
        vector<int> result(cowPositions.size());
        for(auto ilt = cowPositions.begin(); ilt != cowPositions.end(); ilt++) {
            vector<int>::iterator closest, cow2barn = lower_bound(barnPositions.begin(), barnPositions.end(), *ilt);
            if (cow2barn == barnPositions.end())                                // cow is at right side of the barn window
                closest = cow2barn - 1;
            else if (*cow2barn == *ilt)                                         // cow is at the barn location
                closest = cow2barn;
            else if (cow2barn == barnPositions.begin() && *cow2barn > *ilt)     // cow is at left side of the barn window
                closest = cow2barn;
            else {                                                              // cow is at between 2 the barn location
                if((*cow2barn - *ilt) >= (*ilt - *(cow2barn - 1)))              // .... left barn is closer or at equi-distant from the cow
                    closest = cow2barn - 1;
                else closest = cow2barn;                                        // .... right barn is closer from the cow
            }
            
            *(result.begin() + *(cowPositionMap[*ilt].rbegin())) = *(barnPositionMap[*closest].rbegin());
            cowPositionMap[*ilt].pop_back();
        }
        return result;
    };
};

int main (void) {
    
    vector<vector<vector<int>>> inputTest = {
        {
             {0},
             {-5, 5},
             {0}
        },
         {
             {7, 7},
             {7, 10000},
             {0, 0}
        },
         {
             {2, 6, 0, 4, 8},
             {3, -1, 5, 1, 7},
             {3, 2, 1, 0, 4}
        },
         {
             {1000000000, 999999982, 999999964, 999999986, 999999985, 999999970, 999999984, 999999991, 999999967, 999999999, 999999987, 999999959, 999999997, 999999961, 999999957, 999999983, 999999995, 999999963, 999999968, 999999973, 999999992, 999999960, 999999989, 999999966, 999999979, 999999971, 999999976, 999999955, 999999954, 999999951, 999999988, 999999969, 999999981, 999999965, 999999975, 999999953, 999999990, 999999998, 999999958, 999999952, 999999996, 999999977, 999999956, 999999978, 999999993, 999999994, 999999962, 999999980, 999999974, 999999972},
             {999999956, 999999970, 999999990, 999999997, 999999995, 999999965, 1000000000, 999999994, 999999952, 999999975, 999999991, 999999989, 999999999, 999999955, 999999968, 999999983, 999999966, 999999993, 999999977, 999999986, 999999961, 999999985, 999999954, 999999974, 999999987, 999999971, 999999980, 999999967, 999999951, 999999958, 999999988, 999999962, 999999969, 999999963, 999999996, 999999992, 999999978, 999999976, 999999959, 999999960, 999999973, 999999957, 999999998, 999999979, 999999982, 999999953, 999999984, 999999964, 999999981, 999999972},
             {6, 44, 47, 19, 21, 1, 46, 10, 27, 12, 24, 38, 3, 20, 41, 15, 4, 33, 14, 40, 35, 39, 11, 16, 43, 25, 37, 13, 22, 28, 30, 32, 48, 5, 9, 45, 2, 42, 29, 8, 34, 18, 0, 36, 17, 7, 31, 26, 23, 49}
        },
         {
             {980000000, 140000000, 600000000, 80000000, 680000000, 820000000, 340000000, 440000000, 500000000, 660000000, 720000000, 120000000, 180000000, 800000000, 940000000, 740000000, 620000000, 700000000, 320000000, 560000000, 280000000, 20000000, 640000000, 160000000, 920000000},
             {540000000, 520000000, 780000000, 220000000, 0, 40000000, 860000000, 460000000, 200000000, 420000000, 240000000, 580000000, 880000000, 360000000, 480000000, 60000000, 380000000, 260000000, 960000000, 840000000, 100000000, 900000000, 400000000, 760000000, 300000000},
             {18, 20, 11, 15, 23, 19, 13, 9, 14, 11, 23, 20, 8, 2, 18, 23, 11, 23, 24, 0, 17, 4, 11, 8, 21}
        },
         {
             {980000000, -980000000, 860000000, 820000000, -460000000, 340000000, -900000000, 940000000, -620000000, 60000000, -780000000, -500000000, 380000000, 20000000, -300000000, -100000000, -220000000, -940000000, 180000000, 780000000, 420000000, 740000000, -340000000, 900000000, 500000000, 100000000, 300000000, 140000000, -580000000, -180000000, 660000000, -700000000, -20000000, -420000000, -60000000, 260000000, -740000000, -660000000, 700000000, 220000000, -140000000, -540000000, 460000000, -860000000, 540000000, -380000000, 620000000, -820000000, 580000000, -260000000},
             {-720000000, -760000000, 40000000, -120000000, 600000000, 960000000, -920000000, 440000000, 720000000, -640000000, 0, 800000000, 280000000, -680000000, 120000000, -600000000, 520000000, 920000000, -80000000, -320000000, -480000000, 240000000, -240000000, 360000000, -840000000, -160000000, 320000000, -520000000, -200000000, -360000000, -280000000, 760000000, -880000000, -560000000, 840000000, 680000000, -400000000, -960000000, 400000000, -440000000, -1000000000, 560000000, 880000000, 160000000, 80000000, 480000000, -800000000, 200000000, 640000000, -40000000},
             {5, 40, 34, 11, 20, 26, 6, 17, 9, 2, 46, 27, 23, 10, 19, 3, 22, 37, 43, 31, 38, 8, 29, 42, 45, 44, 12, 14, 15, 28, 48, 0, 49, 39, 18, 21, 1, 13, 35, 47, 25, 33, 7, 32, 16, 36, 4, 24, 41, 30}
        },
         {
             {8, 8, 3, 9, 2, 9, 6, 4, 2, 3},
             {3, 0, 18, 16, 15, 5, 20, 13, 7, 6},
             {8, 8, 0, 8, 0, 8, 9, 0, 0, 0}
        },
         {
             {7, 7, 8, 4, 4, 9, 0, 7, 3, 1},
             {5, 13, 2, 1, 10, 19, 3, 6, 15, 4},
             {7, 7, 7, 9, 9, 4, 3, 7, 6, 3}
        },
         {
             {4, 2, 5, 10, 5, 8, 2, 2, 2, 2},
             {10, 5, 3, 13, 1, 15, 0, 6, 12, 17},
             {2, 4, 1, 0, 1, 7, 4, 4, 4, 4}
        },
         {
             {9, 1, 5, 2, 0, 7, 4, 7, 10, 3},
             {15, 14, 2, 6, 19, 20, 3, 7, 9, 17},
             {8, 2, 3, 2, 2, 7, 6, 7, 8, 6}
        },
         {
             {1, 2, 9, 7, 10, 1, 5, 7, 6, 1},
             {16, 11, 4, 19, 1, 9, 7, 5, 0, 15},
             {4, 4, 5, 6, 5, 4, 7, 6, 7, 4}
        },
         {
             {134774521, -375212419, 969179417, -117274129, -47271743, 971182376, -555283071, 528908415, 766461345, -89902923, -132954684, 646446545, -209738587, -119978760, -802440602, 234728411, -685744752, -868072069, -855274836, -175788761, 677615915, -769728103, -176811659, 648961127, 501293644, 58348557, -920975016, -926425719, 712570347, 780769308, 813391812, -291051380, -701586167, 427810494, 124342036, 709313657, -980757438, 559764100, -989044870, -766108005, -981423570, 976437234, -738919240, 191401628, 828074644, -806810097, -270736044, -854586045, 262888781, -814096754},
             {880134565, -685626841, 748841752, -625976431, 10330846, 789919276, 794789670, -17227692, -777504563, 440983215, 965277169, -909030169, 569496541, 924514496, -120129357, -646368934, -646525984, 923021776, -991538434, -121409556, 709502782, 350429466, 491897231, 41318423, -569835900, -180590875, 90721843, -181072162, -15583263, -439458535, -349172730, -735992387, 344711993, 348585275, 541200469, -837933646, -464489576, 261829463, 675981182, 97123975, 731756231, 197876843, 782641732, -974009802, -963310571, -544321483, -408959925, 553826624, 173424795, 779793503},
             {39, 30, 10, 14, 7, 10, 45, 34, 49, 14, 19, 38, 27, 14, 8, 37, 1, 35, 35, 25, 38, 8, 25, 38, 22, 23, 11, 11, 20, 49, 6, 30, 1, 9, 39, 20, 43, 47, 18, 8, 43, 10, 31, 41, 6, 8, 30, 35, 37, 35}
        },
         {
             {-400782393, -332376687, -955840680, -627245678, -846839007, 105753620, -366767785, -463968555, -914378290, 648493989, 515817076, 73971359, 23821719, -547987900, 698582250, 190263847, 163164313, -765304865, -405857745, 655577668, -892116333, -533187418, -753792795, 30241650, -806885264, 107635414, 772762469, 395904509, 774092487, -874502126, -972217877, -960539718, -983359068, -553323009, 330360680, 422045286, -458480568, -385446181, -522612921, 152069951, 339410192, -606374810, -953827938, -835702327, -613157433, -917229670, 645066824, -39784827, -657055961, -18713336},
             {889177210, -255853029, 638010259, -894430698, -396799630, 875676170, 355219352, 780125897, -458881490, -479623130, 646379595, 134393508, -972377492, -297458232, -677968731, -135428144, -382851, -28316966, -914490361, -156712430, -297975438, -669913622, 351801484, -564953494, -51991002, -664681946, -237589055, -706418871, -757803974, -117177948, -672230197, -497036575, -737891134, -953268777, 458068227, -944521895, 480170306, -628763939, -422390692, 373898057, 273663983, 71644884, 513442349, -426166315, 380526893, -891687725, -649871441, 476701604, -356943635, 77137044},
             {4, 48, 33, 37, 45, 49, 48, 8, 18, 10, 42, 41, 16, 23, 10, 11, 11, 28, 4, 10, 45, 23, 28, 16, 28, 11, 7, 44, 7, 45, 12, 33, 12, 23, 22, 34, 8, 4, 31, 11, 22, 37, 33, 45, 37, 18, 10, 17, 46, 17}
        },
         {
             {729590290, -673613636, -758263469, 367416188, -164865721, -420643915, -828793184, -471268818, 181251355, -757565375, 361313789, 447971800, 80682630, -232548474, -929709370, 331470425, -875088933, -218489606, -565638364, -608005444, -797844989, 871583761, -729490517, 781949752, -137094571, 872086467, 488424397, -754106456, 615054997, -249897099, -667663384, 362338434, 800476603, 324066769, -397047225, -894921324, -720874016, -240795206, -529672238, -266593986, 116045274, -214203023, -120993767, -531571737, 557008471, 29392517, -757523446, 418105796, 306338777, 962479109},
             {-273601840, 323126502, 670190922, -653741392, -127718636, -370967264, 395100913, -278732492, 670647127, 598420679, -338246561, -978959743, 110423747, 958508558, -12276468, -417648720, -909321561, -406748919, -891315988, -365433821, 529695684, 120270712, 791300653, -964622303, -888951845, 52665060, 170082071, -932818104, 970936416, -512799271, -785495229, -896199672, 600711469, -18155409, -149594070, -443817495, 95672247, -677458514, -769777273, 658456706, 963025133, -335533091, -311559068, -970784576, -309123481, 519081493, 546162276, -14116561, 417950971, -761510837},
             {8, 37, 49, 6, 34, 15, 30, 35, 26, 49, 6, 48, 36, 0, 27, 1, 24, 0, 29, 3, 30, 22, 49, 22, 4, 22, 45, 49, 32, 0, 37, 6, 22, 1, 17, 31, 49, 0, 29, 0, 21, 0, 4, 29, 46, 25, 49, 48, 1, 40}
        },
         {
             {-437719064, 578948254, 263224675, -978375661, 232565212, 822447234, 477981329, 686413128, 994449204, -735749903, 724112241, 433188149, -591960786, 42331085, -966863380, -108961301, 780834337, -764105885, -134595196, -628024146, -564159133, -964080707, -655619912, -278117618, 372794230, -565843735, 596160221, -748595871, 91549617, 928976007, 584721728, -742209731, -760982097, -753146453, -255114519, -133106138, 79365880, -876050278, 897506020, -722191073, -832802829, 116117475, -597099491, 420886518, -427118311, 522508950, -740516536, 275497372, 368008901, -99507213},
             {315043398, -815945635, 656089561, -715376722, 92704035, -223354315, -215760999, -521424703, 19224515, 118372929, -955787362, 159165585, -336828087, 545360318, -948429215, 27961310, 327128962, -824369731, 460441180, 677637118, 270697702, 915812099, 185657141, 215905634, 611241369, 772460938, 127739114, 300002756, 987088758, -563755478, -340894303, -293604898, -37391477, -232421814, 671399453, -372229664, -752478375, 712598822, -350906072, -995599529, -552174316, 492969881, 363984296, -482963004, 559619633, -178192923, 946228172, 995484558, -790482492, 899034685},
             {43, 44, 20, 39, 23, 25, 41, 19, 47, 36, 37, 18, 29, 15, 10, 45, 25, 36, 45, 29, 29, 10, 3, 31, 42, 29, 24, 36, 4, 21, 44, 36, 36, 36, 33, 45, 4, 17, 49, 3, 17, 9, 29, 18, 35, 13, 36, 20, 42, 32}
        },
         {
             {700648406, 242874645, 269356102, 392718912, 36041143, 610348524, 214305941, 890813310, 202125347, -250126158, 59801889, 831513155, -662345977, -147032754, -415525825, -425661677, -804361870, 266164521, 831122766, -432256628, -704066255, 733319882, -880662726, -705968028, 545369206, -830326227, 200821282, 367916918, -717043305, -638803853, 487972676, 635108364, 787419510, 135438922, 866379622, 875372585, -771708719, -363349063, 870916536, 967902342, 250224168, 691134520, 730582151, -803037551, 428187294, -432762949, 28058487, -477765756, -743124691, -699587914},
             {-642183929, 358344934, -274371295, -736938460, -526042293, 389195964, -402671082, 411401589, -898799712, 11180813, -781367020, 463918555, -916991068, -611579335, -568616707, 262906011, 448678233, -569151288, 326158869, 805959894, 800023755, 926325616, 973264618, 605709355, -97403624, -956361069, -153858101, -4913875, -212449203, -743120453, -938654780, 405619876, -252784046, 715585260, -873254514, 353141673, -924495385, -539464542, -738236922, 22706701, 297139575, -929789786, -112243783, -811084143, 927428006, 940941796, -171258138, 312186776, -725475581, 722902723},
             {33, 15, 15, 5, 39, 23, 15, 21, 15, 32, 39, 19, 0, 26, 6, 6, 43, 15, 19, 6, 48, 49, 34, 48, 23, 43, 15, 1, 48, 0, 11, 23, 20, 39, 21, 21, 10, 6, 21, 22, 15, 33, 49, 43, 7, 6, 39, 4, 29, 48}
        },
         {
             {2, 6, 0, 4, 8},
             {3, -1, 5, 1, 7},
             {3, 2, 1, 0, 4}
        },
         {
             {2, 4, 6, 9},
             {5, 1, 3, 10},
             {1, 2, 0, 3}
        },
         {
             {7, 7},
             {7, 10000},
             {0, 0}
        },
         {
             {2, 6, 0, 4, 8},
             {7, -1, 5, 1, 3},
             {3, 2, 1, 4, 0}
        },
         {
             {-1000000000},
             {1000000000},
             {0}
        },
         {
             {13, 11, 9, 7, 5},
             {11, 13, 9, 7, 5},
             {1, 0, 2, 3, 4}
        },
         {
             {50, 50, 50},
             {75, 25, 60},
             {2, 2, 2}
        },
         {
             {9, 9},
             {1, 10},
             {1, 1}
        },
         {
             {1000000000},
             {-1000000000},
             {0}
        }
    };
;
    int failed = 0;
    for(vector<vector<vector<int>>>::iterator testcase = inputTest.begin(); testcase != inputTest.end(); testcase++) {
        HungryCowsEasy testObj;
        vector<int> result = testObj.findFood((*testcase)[0], (*testcase)[1]);

        cout << "Result of " << ((testcase - inputTest.begin())/10 == 0? "0": "") << (testcase - inputTest.begin()) << "th test: " << (result == (*testcase)[2]? "Passed": "Failed") << endl;
        if((result != (*testcase)[2])) {
            failed++;
            /*
                cout << "{ "; for(auto ilt = (*testcase)[2].begin();ilt != (*testcase)[2].end(); ilt++) cout << (ilt == (*testcase)[2].begin()? "": ", ") << (ilt - (*testcase)[2].begin()) << ": " << *ilt; cout << "}" << endl;
                cout << "{ "; for(auto ilt = result.begin();ilt != result.end(); ilt++) cout << (ilt == result.begin()? "": ", ") << (ilt - result.begin()) << ": " << *ilt; cout << "}" << endl;
                cout << endl;
             */
        }
    }
    cout << "Total Failed Test Cases: " << failed << endl;

    return 0;
}
