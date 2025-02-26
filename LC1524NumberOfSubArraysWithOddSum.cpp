#include<vector>
using namespace std;


class Solution {
    public:
        int numOfSubarrays(vector<int>& arr) {
    
            /**
                LC:1524 Number of Sub-arrays With Odd Sum
                https://leetcode.com/problems/number-of-sub-arrays-with-odd-sum/description/
            **/
    
            
            /**
                intuition:
                - based on some basic math we will try to aprroach this problem
                - as we know that odd + odd = even , even + even = even , odd + even = odd , even + odd = odd
                - based on the prefix sum we will try to check how many subarrays we have with odd sum
                - we will keep track of oddCount and evenCount everytime we calculate the prefix
                - if it's even we add odd count to the result and if it's odd we add even count to the result
                - because to get the odd sums (our target), when we subtract an even from an odd value or vice-versa
                - return the result
                - don't forget to take the mod of the result value could go much higher
            **/
    
    
            const int MOD = 1e9 + 7; // since the answer can be very large we take MOD of the result
            int oddCount = 0, evenCount = 1; // evenCount = 1 to handle prefixSum itself being odd, or we can assume that we begin the prefix sum with 0 which is even
            int prefixSum = 0, result = 0;
    
            for (int num : arr) {
            prefixSum += num;
    
            if (prefixSum % 2 == 0) {  //even
                result = (result + oddCount) % MOD;  // Add previous odd counts
                evenCount++;  // Update even count
            } else { //odd
                result = (result + evenCount) % MOD;  // Add previous even counts
                oddCount++;  // Update odd count
            }
        }
    
        return result;
            
            
            /**
                Time complexity: O(n)   iterating through all the elements of the array
                Space complexity: O(1)  no extra space utilized
            **/
    
    
            //========================================================================
    
            /**
                Using brute force approach definitely give us Time Complexity of O(n^3) which gives us TLE
                We need to optimize the solution
            
            int sum = 0;
    
            for(int i = 0 ; i < arr.size() ; i++) {
                for(int j = i ; j < arr.size() ; j++) {
                    int temp = 0;
                    for(int k = i ; k <= j ; k++) {
                        temp += arr[k];
                    }
                    if(temp % 2 != 0) {
                        sum += 1;
                    }
                }
            }
    
            return sum;
            **/
    
    
        }
    
        
    };