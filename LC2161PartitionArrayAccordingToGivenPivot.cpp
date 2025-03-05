#include<vector>
using namespace std;


class Solution {
    public:
        vector<int> pivotArray(vector<int>& nums, int pivot) {
    
            /**
                LC:2161 Partition Array According to Given Pivot
                https://leetcode.com/problems/partition-array-according-to-given-pivot/description/
            **/
    
    
            /**
                Intuition:
                - at first, I thought of inplace swapping solution using dutch national flag algo so that we can save space, but the extra space solution is more simpler as we also need to maintain the order, because while using the dutch national flag algo the relative order is lost
                - we will create a new result array
                - in first iteration, we find the values that are less than the pivot and push them to our result array
                - in second iteration, we find the values that are equal than the pivot and push them to our result array
                - and, in the third iteration, we find the values that are greater than the pivot and push them to our result array
                - return the answer array
                
            **/
    
    
            vector<int> result;
            
            // Add elements less than pivot
            for (int num : nums) {
                if (num < pivot) {
                    result.push_back(num);
                }
            }
    
            // Add elements equal to pivot
            for (int num : nums) {
                if (num == pivot) {
                    result.push_back(num);
                }
            }
    
            // Add elements greater than pivot
            for (int num : nums) {
                if (num > pivot) {
                    result.push_back(num);
                }
            }
        
            return result;
    
        }
    
            /**
                Time complexity: O(n)
                Space complexity: O(n)
            **/
    };