#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    bool check(vector<int>& nums) {

        /**
        int assume_flip_index = -1;

        //finding the flipping index for the array in increasing order
        //this means if the arr[i] > arr[i+1], this condition breaks the increasing order array
        for(int i = 0 ; i < nums.size()-1 ; i++) {
            if(nums[i] > nums[i+1]) {
                assume_flip_index = i+1;
                break;
            }
        }

        //condition to check for already soreted array
        if(assume_flip_index == -1) {
            return true;
        } 

        //reverse the array from start to flip index and then from flip index to end
        reverse( nums.begin() , (nums.begin() + assume_flip_index) );
        reverse( (nums.begin() + assume_flip_index) , nums.end() );
    
        //if the array is sorted and rotated than after reversing we should
        //get our array in decreasing order
        for(int i = 0 ; i < nums.size()-1 ; i++) {
            if(nums[i] < nums[i+1]) {
                return false;
            }
        }

        return true;

        //Time Complexity: O(n)  Space Complexity: O(1)

        **/
        


    /******* Optimized approach - just looping once through the aray *******/

    //intuition: if the array is sorted and rotated there would be an index which will be less than the previous index
    //if that occurs more than once than we can assume that the array wasn't sorted or rotated properly
    //using %n to make the array cyclic for comparing the last element with the first element

    int count = 0;
    int n = nums.size();

    // Count how many times the sorting order is breached
    for(int i = 0; i < n; i++) {
        if(nums[i] > nums[(i + 1) % n]) {
            count++;
        }
    }

    // The array is properly sorted and rotated if the breach count is atmost 1
    return count <= 1;

    //Time Complexity: O(n)  Space Complexity: O(1)

        
    }
};