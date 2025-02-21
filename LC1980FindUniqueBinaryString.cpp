#include<string>
#include<vector>
using namespace std;


class Solution {
    public:
        string findDifferentBinaryString(vector<string>& nums) {
    
            /**
                LC:1980 Find Unique Binary String
                https://leetcode.com/problems/find-unique-binary-string/description/
            **/
    
    
            /**
                Intuition:
                - To create a unique string from the given array of strings, we iterate through every string at the given index
                  and flip the bit at that given index inside that string
                - We add the flipped bit in our result string
                - and we return the result string 
                - we can achieve this using Cantor's diagonalization algorithm 
            **/
    
            
            string result;
    
            for(int i = 0 ; i < nums.size() ; i++) {
                result += (nums[i][i] == '0' ? '1' : '0') ;
            }
            
            return result;
        }
    
    
        /**
            Time Complexity: O(n)   where n is the size of the nums vector or the size of each string in the nums vector 
    
            Space Comlexity: O(n)   where n will be size of our result string, (size of result string is similar to size of the nums vector or the size of each string in the nums vector)
        **/
    };