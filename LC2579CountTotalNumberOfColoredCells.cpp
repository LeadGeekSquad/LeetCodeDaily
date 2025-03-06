#include<iostream>

class Solution {
    public:
    
        /**
            LC:2579 Count Total Number of Colored Cells
            https://leetcode.com/problems/count-total-number-of-colored-cells/description/
        **/
    
        /**
            intuition:
            - this should be fairly simple to think of
            - after 1st minute, we can notice that from 2nd minute upto the nth minute it is doubling by 4
            - so after 1st minute, it would be growing linearly like 4,8,12,16,20....k+4
            - so at every minute after 1st minute, we just keep adding those doubling values to our answer
            - To optimize it to solve in constant time O(1), we can just use the formula 1+2n(n−1)
        **/
    
    
        //optimized approach formula based
        long long coloredCells(int n) {
            return 1LL + 2LL * n * (n-1);
        }
            //Time complexity: O(1)  
            //Space complexity: O(1)
    
    
        /** O(n) approach
         * 
        long long coloredCells(int n) {
    
            long long answer = 1;
    
            if(n == 1) {
                return answer;
            }
    
            int i = 2;
            while(i <= n) {
                answer += (4 * (i-1)); 
                i++;
            }
    
            return answer;
    
        }
        **/    
    
        
        /**
            Time Complexity: O(n)   as we go through from 1 to n minutes
            Space Complexity: O(1)  no extra space utilized, we achieved this in constant space
        **/
    };