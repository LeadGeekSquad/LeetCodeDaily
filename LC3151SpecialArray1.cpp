#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {

        if (nums.size() < 2) {
            return true;
        }

        int first_element = nums[0] % 2;

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] % 2 != first_element) {
                first_element = nums[i] % 2;
            } else {
                return false;
            }
        }

        return true;

        //Time Complexity: O(n) 
        //Space Complexity: O(1)

        /**
            Similar complexity different approach

            for (int i = 0; i < nums.size() - 1; ++i) {
                if (nums[i] % 2 == nums[i + 1] % 2) {  // Check if parities are the same
                    return false;
                }
            }
            return true;

        **/
    }
};