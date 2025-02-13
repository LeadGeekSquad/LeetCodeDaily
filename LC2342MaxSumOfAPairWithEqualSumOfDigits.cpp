#include<vector>
#include<unordered_map>
using namespace std;


class Solution {
    public:
        int maximumSum(vector<int>& nums) {
    
            // LC2342 Max Sum of a Pair With Equal Sum of Digits
            // https://leetcode.com/problems/max-sum-of-a-pair-with-equal-sum-of-digits/description/
    
    
            /**
            Intuition:
            - iterate over the nums vector, in a map digitSumIndex we store the sum of the digits as key and it's value as a vector of index values,
            - to keep the vector updated with 2 greater values pairs, we can use the vector of size 2 and update the values as we find bigger/smaller values for position 0 & 1 for that vector
            - compare nums[i] with vector[0], if greater change the vector[0] to nums[i] and vector[1] to vector[2]. similar to finding first largest and second largest
            - after the map is updated with all the digits and indexes values, iterate over the map to get the value vector whose element at position[1] is not -1
            - iterate over the sequence of pairs of values in a vector, if vector[1]!= -1, we keep counting and updating the max
    
            **/
    
             
    
            int maxSum = -1 ;
            unordered_map<int,vector<int>> digitSumIndex ;
    
            for(int i = 0 ; i < nums.size() ; i++) {
                int digit = nums[i];
                int totalOfDigits = 0;
                    while( digit != 0) {
                        int lastdigit = digit % 10;
                        totalOfDigits += lastdigit;
                        digit /= 10 ;
                    }
                
                if(digitSumIndex.find(totalOfDigits) != digitSumIndex.end()) {
                    
                    auto &p = digitSumIndex[totalOfDigits] ;
                    if(nums[i] > p[0]) {
                        p[1] = p[0];
                        p[0] = nums[i];
                    }
                    else if (nums[i] > p[1]) {
                        p[1] = nums[i];
                    }
                } else {
                    digitSumIndex[totalOfDigits] = {nums[i],-1};
                }
                
            } 
    
            for(const auto& vectValues : digitSumIndex) {
                auto& myVect = vectValues.second; //getting the vector from the map
                
    
                if(myVect[1] != -1) {  //because if this wasn't updated from -1, likely there was no second largest
                    maxSum = max(maxSum,myVect[0]+myVect[1]); 
                }
                
            }
    
            return maxSum;
            
        }
    
        /**
    
        Time complexity O(n)  where n is the size of input nums vector. Also for every single number in n, we count the digits which is K, so(n * K)
    
        Space Complexity O(n)  in the worst case the size of digitSumIndex map will be n, where all the numbers will be having distinct sum of digits
    
        **/
    };
