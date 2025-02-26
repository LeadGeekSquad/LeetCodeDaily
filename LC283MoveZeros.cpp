#include<vector>
using namespace std;


class Solution {
    public:
        void moveZeroes(vector<int>& nums) {
    
            // LC:283 Move Zeros
            // https://leetcode.com/problems/move-zeroes/description/
    
    
            /**
                intuition:
                - keep track of the position for non-zero values to insert using an nonZeroIndex var
                - start iterating over the vector, if the value at index is zero, we keep moving
                - if the value at index is a non-zero value, we check if the non-zero index != index, to avoid unnecessary write.
                - if different, we swap the value at nums[index] and nums[zeroIndex]
                - increment our nonZeroIndex by 1, as the next non-zero value will be inserted at the next position.
            **/
    
    
            // optimal approach for less writes and less redundant operations when assining the value to nonZeroIndex position if they are the same
    
            int n = nums.size();
    
            int nonZeroIndex = 0;
    
            for(int i = 0 ; i < n ; i++) {
                if(nums[i] != 0) {
                    if(i != nonZeroIndex) {
                        swap(nums[i],nums[nonZeroIndex]);
                    }
                    nonZeroIndex++;
                }
            }
    
            /**
                Time Complexity: O(n)   as we iterate through all the element of the array
                Space Complexity: O(1)   no extra space is being utilized
            **/
    
    
            /**
                Same Time & Space complexity but more redundant as we have write operations multiple times
    
            int n = nums.size();
    
            int nonZeroIndex = 0;
    
            for(int i = 0 ; i < n ; i++) {
                if(nums[i] != 0) {
                    nums[nonZeroIndex++] = nums[i];
                }
            }
    
            for(int i = nonZeroIndex; i < n; i++) {
                nums[i] = 0;
            }
    
            **/
        }
    };