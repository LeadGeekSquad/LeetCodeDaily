#include<vector>
using namespace std;


class Solution {
    public:
        vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
    
            /**
                LC:2570 Merge Two 2D Arrays by Summing Values
                https://leetcode.com/problems/merge-two-2d-arrays-by-summing-values/description/
            **/
    
            //approach:
            // - iterate over two arrays by using two pointers
            // - check if whose id is greater, nums1 or nums2 , and check if the same id is also present in both the arrays
            // - if it is present in both of the arrays, and then we add the values of the two and insert in our answer array
            // - else if the id is not present in both of the arrays, we just add the id and value to our answer array
    
            vector<vector<int>> answer;
    
            int rowNums1 = nums1.size();
            int colNums1 = nums1[0].size();
            int rowNums2 = nums2.size();
            int colNums2 = nums2[0].size();
    
            int num1Pointer = 0;
            int num2Pointer = 0;
    
    
            while(num1Pointer < rowNums1 || num2Pointer < rowNums2) {
    
                if( num1Pointer < rowNums1 && num2Pointer < rowNums2 ) {
                    if( nums1[num1Pointer][0] < nums2[num2Pointer][0] ) {
                        answer.push_back({nums1[num1Pointer][0],nums1[num1Pointer][1]});
                        num1Pointer++;
                    } else if ( nums1[num1Pointer][0] == nums2[num2Pointer][0] ) {
                        answer.push_back({nums1[num1Pointer][0], nums1[num1Pointer][1] + nums2[num2Pointer][1]});
                        num1Pointer++;
                        num2Pointer++;
                    } else {
                        answer.push_back({nums2[num2Pointer][0], nums2[num2Pointer][1]});
                        num2Pointer++;
                    }
                } else if (num1Pointer < rowNums1) {
                    answer.push_back({nums1[num1Pointer][0],nums1[num1Pointer][1]});
                    num1Pointer++;
                } else if (num2Pointer < rowNums2) {
                    answer.push_back({nums2[num2Pointer][0], nums2[num2Pointer][1]});
                    num2Pointer++;
                }
                
            }
    
            return answer;
            
        }
    
        /**
            Time Complexity: O(rowNums1 + rowNums2)   where rowNums1 and rowNums2 are the respective sizes of the two vectors, as we iterate through each id
    
            Space Complexity: O(rowNums1 + rowNums2)  where rowNums1 and rowNums2 are the respective sizes of the two vectors, this happens in case if they are all unique
        **/    
        
    };