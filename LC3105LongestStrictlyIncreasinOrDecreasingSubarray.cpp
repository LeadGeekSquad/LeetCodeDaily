#include<iostream>
#include<vector>
#include<initializer_list>
#include<algorithm>
using namespace std;

class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {

        // LC:3105 Longest Strictly Increasing or Strictly Decreasing Subarray
        // https://leetcode.com/problems/longest-strictly-increasing-or-strictly-decreasing-subarray/description/
        

        //intuition: while iterating over nums from index 1, we compare the value with previous index.
        // if the elements are increasing we reset our decreasing_count to 1.
        // if the elements are decreasing we reset our increasing_count to 1.
        // The reset should be performed because of the nature of the monotonic array being strictly increasing or decreasing.
        // After every iteration we check for the highest length of the among the counts and max_length.
        // If we don't reset the count we will have incorrect count of the increasing and decreasing sequence.
        // Atlast, we return the highest length of the subarray.

        if (nums.empty()) {
            return 0;
        }
            
        int increasing_count = 1;
        int decreasing_count = 1;
        int max_length = 1;

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[i - 1]) { //sequence is increasing
                increasing_count++;
                decreasing_count = 1;   // reset decreasing count
            } else if (nums[i] < nums[i - 1]) { //sequence is decreasing
                decreasing_count++;
                increasing_count = 1;   // reset increasing count
            } else {                    // equal elements break the increasing and decreasing sequence
                increasing_count = 1;   //reset increasing count
                decreasing_count = 1;   //reset decreasing count
            }

            max_length = max({max_length, increasing_count, decreasing_count});  //check max_length after every iteration
        }

        return max_length;

        //Time Complexity: O(n)   Space Complexity: O(1)
    }
};