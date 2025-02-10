#include<vector>
#include<numeric>
using namespace std;


class Solution {
public:
    int pivotIndex(vector<int>& nums) {
    
            // LC:724 Find Pivot Index
            // https://leetcode.com/problems/find-pivot-index/description/
    
    
           /**
           intuition: 
            - Find the total sum of all the elements in the array
            - We will start iterating over the array, as we iterate over the array we compare the leftSum with the rightsum which is 
              (totalSum - leftSum - nums[i])
            - if equal return the index or else add the nums[i] to the leftSum
            - if no pivot index found return -1  
           **/ 
    
           int totalSum = accumulate(nums.begin(),nums.end(),0);
           int leftSum = 0;
    
           for(int i = 0 ; i < nums.size() ; i++) {
                if(leftSum == totalSum - leftSum - nums[i]) {
                    return i;
                }
                leftSum += nums[i];
           }
    
           return -1;
    }

        /**
    
        Time Complexity O(n)   such that n is the size of the input array/vector
        Space Complexity O(1)  No such extra space is being utilized
    
        **/

};