#include<string>
using namespace std;


class Solution {

    /**
     * LC:2379 Minimum Recolors to Get K Consecutive Black Blocks
     * https://leetcode.com/problems/minimum-recolors-to-get-k-consecutive-black-blocks/
     */

     /**
      * Approach:
      * - 
      */
     
      public:
      int minimumRecolors(string blocks, int k) {
  
          int n = blocks.size();
          int result = k;
          int whiteCount = 0;
          int left = 0;
  
          for(int i = 0 ; i < n; i++) {
  
              if(blocks[i] == 'W') {
                  whiteCount++;
              }
  
              if(i - left + 1 == k) {
                  result = min(result,whiteCount);
                  if(blocks[left] == 'W') {
                      whiteCount--;
                  }
                  left++;
              }
          }
  
          return result;
          
          
      }

        /**
         * Time Complexity:
         * Space Complexity:
         */
    };