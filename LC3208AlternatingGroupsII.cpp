#include<vector>
using namespace std;


class Solution {
    public:
        int numberOfAlternatingGroups(vector<int>& colors, int k) {
    
            /**
                LC:3208 Alternating Groups II
                https://leetcode.com/problems/alternating-groups-ii/description/
             **/
    
    
            /**
                Approach:
                - colors[i] is red when i = 0
                - colors[i] is blue when i = 1
                - we will be using sliding window to optimize our solution from O(n*k) to O(n)
                - to make it circular we will do % n while iterating over colors
                - we see if the color is alternate, if yes the window increases as a part of the for loop
                - if not alternate we set our left pointer to i
                - we check if the window size is greater than k, we increase our left to maintain the window size of k
                - we check if our window size is equal to k, we increment our result by 1
                - notice that we start our second pointer which is i from 1, just to compare the alternate colors value at colors[i] with colors[i-1], we know that if the colors are same they are not alternate and that is why we move our left pointer to i
                - small nugget to remember if you start the loop from 0, make sure to do (i + n) % n OR (i - 1 + n) % n
                
    
            **/ 
    
             int n = colors.size();
             int result = 0;
             int left = 0;
             //int altCount = 0;
    
             for(int i = 1 ; i < n + k - 1 ; i++) {
    
                if( colors[i % n] == colors[(i - 1) % n] ) {
                    left = i;
                }
    
                if( i - left + 1 > k) {
                    left++;
                }
    
                if( i - left + 1 == k) {
                    result++;
                }
             }
    
             return result;
            
        }
    
        /**
            Time Complexity: O(n)     as we iterate through the entire array of colors (n + k - 1)
            Space Complexity: O(1)    no extra space is being utilized
        **/
    };