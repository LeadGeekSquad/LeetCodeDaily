#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {

        // LC:1800 Maximum Ascending Subarray Sum
        // https://leetcode.com/problems/maximum-ascending-subarray-sum/description/


        //intuition: we will try to find the sum of the contiguous elements which are greater than previous element
        //if the increasing subarray sequence breaks, we update the max value and then reset the new subarray sequence beginning from that element
        //At the end we compare the max value incase if the subarray has ascending sequence


        //declare and initialize max_value and temp_sum with the first element of the array
        //incase if the array is of size 1, we can return the first element, because the max sum will be of first element incase of size 1
        int max_value = nums[0];
        int temp_sum = nums[0];

        //checking for increasing order, if the increasing sequence breaks update the max_value and reset temp_sum to nums[i]
        //because nums[i] will be the begin position of the new subarray
        for(int i = 1 ; i < nums.size() ; i++) {
            if(nums[i] > nums[i-1]) {
                temp_sum += nums[i];
            } else {
                max_value = max(max_value,temp_sum);
                temp_sum = nums[i];
            }
        }

        //atlast if the sequence ends in ascending order, we updated the max_value here
        max_value = max(max_value,temp_sum);
        

        return max_value;

    }
};