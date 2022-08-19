//
//  File Name: week3ReportQuestion3.cpp
//  Program: Masters of Computer Science
//  Course: Specalised Programming
//  Problem URL: https://leetcode.com/problems/perfect-squares/
//  Submission URL: https://leetcode.com/submissions/detail/777596854/
//  Test Cases Passes: 588 / 588
//
//  Created by Pranshu Raj Goel on 19/08/2022.
//
/*
Given an integer n, return the least number of perfect square numbers that sum to n.

A perfect square is an integer that is the square of an integer; in other words, it is the product of some integer with itself. For example, 1, 4, 9, and 16 are perfect squares while 3 and 11 are not.

 

Example 1:

Input: n = 12
Output: 3
Explanation: 12 = 4 + 4 + 4.
Example 2:

Input: n = 13
Output: 2
Explanation: 13 = 4 + 9.
 

Constraints:

1 <= n <= 104
Accepted
558,211
Submissions
1,069,727
*/

#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int numSquares(int n) {
        unordered_map<int, int> map;
        vector<int> map_key;
        for(int i = 1; i <= n; i++) {
            if(i * i <= n) {
                map[i * i] = 1;
                map_key.push_back(i * i);
            }
            
            if(map[i] == 1) {
                continue;
            }
            else {
                for(vector<int>::iterator itr = map_key.begin(); itr != map_key.end(); itr++) {
                    if(*itr >= i) break;
                    else if(map[i] == 0 || (map[i] > map[i - *itr] + 1))
                        map[i] = map[i - *itr] + 1;
                }
            }
        }
        return map[n];
    }
};
