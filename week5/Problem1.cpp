/*
152. Maximum Product Subarray	
o	Problem URL: https://leetcode.com/problems/maximum-product-subarray/ 
o	Test Cases Passes: 188 / 188
o	Submission Details: https://leetcode.com/submissions/detail/782768235/ 
o	Language: C++
o	Source File: 

•	Which steps of the problem-solving process did you find easy?
•	Which steps did you struggle with?
Coming up with dynamic program array. However, when I completed the question, I got to know about the smarter approach using Kadane's algorithm which was more efficient in both time and space complexity.
•	What approaches did you use to overcome those difficulties?
Regular practice of the dynamic programming problems is needed perform better in these problems. Hence, I am doing regularly to get to know the approch and more efficient approach to the problem
•	Can you think of how you might approach the problem differently if you had to start again?
Have a greedy mindset when using dynamic programming problem can further simplify the problems. So, I will try to apply Dynamic Programming with greedy mindset rather than a way to shorten bruteforce.
*/
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int max_product, min_product, result;
        for(vector<int>::iterator itr = nums.begin(); itr != nums.end(); itr ++) {
            if(itr == nums.begin()) {
                max_product = *itr;
                min_product = *itr;
                result = *itr;
            }
            else {
                if(*itr < 0) {
                    swap(max_product, min_product);
                }
                max_product = max(*itr, max_product * (*itr));
                min_product = min(*itr, min_product * (*itr));
                result = max(max_product, result);
            }
        }
        return result;
    }
};
