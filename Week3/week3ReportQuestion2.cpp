//
//  File Name: week3ReportQuestion2.cpp
//  Program: Masters of Computer Science
//  Course: Specalised Programming
//  Problem URL: https://community.topcoder.com/stat?c=problem_statement&pm=14130
//  Test Case URL: https://community.topcoder.com/stat?c=problem_solution&cr=40346045&rd=16650&pm=14130
//  Test Cases Passes: 57 / 57
//
//  Created by Pranshu Raj Goel on 11/8/2022.
//
/*
 Problem Statement for BearPair


Problem Statement
        
Bear Limak loves algorithms, especially the ones with words and strings.



Limak's friend recently entered a programming competition and wrote a program. The program contains a string constant s. Limak would now like to challenge the program by making it exceed the time limit. To do that, he must find two different characters in s that are as far apart as possible.



Formally, Limak must find two integers i and j with the following properties:

Both i and j must be valid indices into s. That is, both numbers must be between 0 and n-1, inclusive, where n is the length of s.
The characters s[i] and s[j] must be different.
The difference between i and j must be as large as possible.


You are given the String s. If Limak cannot choose any integers with the required properties, return -1. Otherwise, return the largest possible difference between i and j.

 
Definition
        
Class:    BearPair
Method:    bigDistance
Parameters:    String
Returns:    int
Method signature:    int bigDistance(String s)
(be sure your method is public)
    
 
Constraints
-    s will have between 2 and 50 characters, inclusive.
-    Each character in s will be a lowercase English letter ('a' - 'z').
 
Examples
0)
        
"bear"
Returns: 3
Limak can choose the (0-based) indices 0 and 3. We have s[0]='b' and s[3]='r', which are indeed two different letters. The difference between the two indices is 3-0 = 3.
1)
        
"abcba"
Returns: 3
Here, one optimal solution is for Limak to choose the indices 1 and 4 (corresponding to 'b' and 'a', respectively). Another optimal solution is to choose indices 0 and 3 (letters 'a' and 'b'). In both cases the difference is 3.
2)
        
"oooohyeahpotato"
Returns: 13
3)
        
"zzzzzzzzzzzzzzzzzzzzz"
Returns: -1
Here, Limak can't choose two indices with different letters.
4)
        
"qw"
Returns: 1
5)
        
"xxyyxyxyyyyyyxxxyxyxxxyxyxyyyyyxxxxxxyyyyyyyyxxxxx"
Returns: 47
This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2010, TopCoder, Inc. All rights reserved.




This problem was used for:
       Single Round Match 680 Round 1 - Division II, Level One
 
 ----------------------------------------------------
 Output
 

 */

#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>

using namespace std;

class BearPair {
    public:
        int bigDistance(string s) {
            int max_dis = -1;
            for(int i=0;i<s.size();i++)
               for(int j=0;j<s.size();j++)
                  if(s[i]!=s[j])
                      max_dis=max(max_dis,abs(i-j));
            return max_dis;
        };
};

int main(void) {
    int failed = 0;
    vector<string> testCase = {"bear", "zzzzzzzzzzzzzzzzzzzzz", "qw", "xxyyxyxyyyyyyxxxyxyxxxyxyxyyyyyxxxxxxyyyyyyyyxxxxx", "oooohyeahpotato", "qqqqqqqqqqqpasbzqcefrbmzbeeklwxjuqahqq", "piiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiii", "waqunmledulebqqeesuhpctgdewwwww", "wwwwwwwwwbtvyqjfjdwwwwwwwwwwwwww", "ssssssssssss", "abcba", "aa", "zz", "yz", "yz", "aba", "abb", "aab", "aaa", "kkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkk", "vijjv", "qqqqqqqqqqqqkruagjeqftqqqqqqqqqqq", "srclwgmobsdiqppxjbtlkpaouzxmvvnhvmmmmmmmmmmmmm", "ooooonnhfcznftrtgxptbjoooooooooooooo", "bzmbr", "pp", "ewrpjvwkwinnoupgtrbvijxnaquwluqpqhhzedmbnbqbvikpzl", "qqqqqepaaxkzswfnssbfxkdbmtedgtcphuseeqqbeludelmnuq", "bbbbbbssxjzekhgixvzenwjpxtgqibrsahjtqbbbbbbbbbbbbb", "bb", "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx", "miraupmomiqa", "yvo", "vvvv", "pp", "tj", "ttpoozilzpxtjebarvgiylurwjjpoutfeodby", "johggvonllrwrdizeroqzpvbnkoaqvlagjstibupsomswqjoq", "ycjedfvwygrctuytlujzunyjvpumimquxdggcccccccccc", "aaaaazzzzzzzzzaaaaaaaaaaaaaaaa", "zzzzzzzzzzzaaaaaaaazzzzzzzzzzzzzz", "zyz", "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa", "abaaa", "abaaaaaaaa", "aaaaaaaabbba", "xxxxxxxxxxxxy", "abz", "bbbabbbbbbbbbb", "abcdab", "zzzazz", "aaaa", "aaaaa", "bbbbbbbbbbbbbbbbbab", "aaaaaa", "ab", "adbaaa"};
    vector<int> testCaseResult= {3, -1, 1, 47, 13, 35, 38, 29, 22, -1, 3, -1, -1, 1, 1, 1, 2, 2, -1, -1, 3, 21, 45, 30, 4, -1, 49, 48, 43, -1, -1, 11, 2, -1, -1, 1, 36, 48, 45, 24, 21, 1, -1, 3, 8, 10, 12, 2, 10, 5, 3, -1, -1, 17, -1, 1, 4};
    for(int i = 0; i < testCase.size(); i++) {
        BearPair testObj;
        cout << "Result of " << (i/10 == 0? "0": "") << i << "th test: " << ((testObj.bigDistance(testCase[i]) != testCaseResult[i])? failed++, "Failed": "Passed") << endl;
    }
    
    cout << "Total Failed Test Cases: " << failed << endl;
    return 0;
}





