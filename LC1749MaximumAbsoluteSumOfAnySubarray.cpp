#include<vector>
using namespace std;


class Solution {
    public:
        int maxAbsoluteSum(vector<int>& nums) {
    
            /**
                LC:1749 Maximum Absolute Sum of Any Subarray
                https://leetcode.com/problems/maximum-absolute-sum-of-any-subarray/description/
            **/
            
    
            /**
               Approach:
               - I will use the kadane's algorithm to find the max subarray sum
               - Similarly, we will use kadane's algorithm to find the min subarray sum
               - once we have the both, we will consider the greater value among both, 
               - finding max among both by taking absolute value of min subarray sum and max subarray sum
               - we return the max value among those two
            **/
    
            int max_sum = 0;
            int min_sum = 0;
            int curr_max = 0;
            int curr_min = 0;
    
    
            for(int num : nums) {

                curr_max = max(num, curr_max + num); // Standard Kadane's for max subarray
                curr_min = min(num, curr_min + num); // Kadane's for min subarray (negative max)
    
                max_sum = max(max_sum, curr_max);
                min_sum = min(min_sum, curr_min);

            }
    
    
            return max(max_sum, abs(min_sum));
        }
    
        /**
            Time Complexity: O(n)      as we iterate through n elements, where n is the size of the input
            Space Complexity: O(1)     no extra space utilized  
        **/
    };