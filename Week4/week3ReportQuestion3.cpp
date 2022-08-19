//
//  File Name: week3ReportQuestion3.cpp
//  Program: Masters of Computer Science
//  Course: Specalised Programming
//  Problem URL: https://leetcode.com/problems/house-robber-ii/
//  Submission URL: https://leetcode.com/submissions/detail/777535338/
//  Test Cases Passes: 75 / 75
//
//  Created by Pranshu Raj Goel on 19/08/2022.
//
/*
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed. All houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, adjacent houses have a security system connected, and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

 

Example 1:

Input: nums = [2,3,2]
Output: 3
Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money = 2), because they are adjacent houses.
Example 2:

Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.
Example 3:

Input: nums = [1,2,3]
Output: 3
 

Constraints:

1 <= nums.length <= 100
0 <= nums[i] <= 1000
Accepted
460,835
Submissions
1,140,043
 */

#include <vector>

using namespace std;

class Solution {
    public:
        int linear_rob(vector<int>& nums) {
            if(nums.size() <= 2) return *max_element(nums.begin(), nums.end());
            for(vector<int>::iterator itr = nums.begin() + 2; itr != nums.end(); itr++) {
                *itr += *max_element(nums.begin(), itr - 1);
            }
            return *max_element(nums.begin(), nums.end());
        }
        int rob(vector<int>& nums) {
            if(nums.size() <= 3) {
                return *max_element(nums.begin(), nums.end());
            }
            else {
                vector<int> nums0;
                vector<int> numsn_1;
                nums0.insert(nums0.begin(), nums.begin(), nums.end() - 1);
                numsn_1.insert(numsn_1.begin(), nums.begin() + 1, nums.end());
                return max(linear_rob(nums0), linear_rob(numsn_1));
            }
        }
};
