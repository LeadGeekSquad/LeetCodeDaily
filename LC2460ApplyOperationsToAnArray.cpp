#include<vector>
using namespace std;


class Solution {
    public:
        vector<int> applyOperations(vector<int>& nums) {
    
            /**
                LC:2460 Apply Operations to an Array
                https://leetcode.com/problems/apply-operations-to-an-array/description/
            **/
    
            // Approach:
            // check if nums[i] == nums[i+1], if true multiply it by 2 and set nums[i+1] to 0 , else skip this operation
            // after performing all operations we shift all the 0's to the end and result the array
    
            //single pass solution
    
            int nonZeroIndex = 0;
    
            for(int i=0 ; i < nums.size() ; i++) {
    
                if( i < nums.size() - 1 && nums[i] == nums[i+1] ) {
                    if(nums[i] == nums[i + 1]) {
                        nums[i] *= 2;
                        nums[i+1] = 0;
                    }
                }
    
                if(nums[i] != 0) {
                    if( i != nonZeroIndex) {
                        swap(nums[i],nums[nonZeroIndex]);
                    }
                    nonZeroIndex++;
                }
    
            }
    
            return nums;
    
            // Time complexity: O(n)
            // Space complexity: O(1)
    
    
    
            /**
    
             // Solution using Two for-loops
             // this still has the same time complexity as above
    
            for(int i = 0 ; i < nums.size()-1; i++) {
                if(nums[i] == nums[i+1]) {
                    nums[i] *= 2;
                    nums[i+1] = 0;
                }
            }
    
            int nonZeroIndex = 0;
            for(int i = 0 ; i < nums.size() ; i++) {
                if(nums[i] != 0) {
                    if(i != nonZeroIndex) {
                        swap(nums[i],nums[nonZeroIndex]);
                    }
                    nonZeroIndex++;
                }
            }
    
            return nums;
    
            **/
    
        }
    };