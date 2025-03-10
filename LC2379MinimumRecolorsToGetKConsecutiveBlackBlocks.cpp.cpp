#include<string>
using namespace std;


class Solution {

    /**
     * LC:2379 Minimum Recolors to Get K Consecutive Black Blocks
     * https://leetcode.com/problems/minimum-recolors-to-get-k-consecutive-black-blocks/
     */

     /**
      * Approach:
      * - we will be using the sliding window technique to find the K consecutive black blocks
      * - we will have two pointers, to kind of create a window of size K
      * - we will have a whiteCount variable to keep track of how many recolors we will need
      * - in the worst case as our result we might have K recolors, so we create a variable result and assign it with K
      * - we keep iterating to the right until our window size while checking for W and increasing the white count
      * - to check if our i reaches the size of window K, we do i - left + 1
      * - and because we have reached the size of window, we will update the result with min values of (result,whiteCount)
      * - before we increment our left, we make sure that if the char at left is 'W' we remove from the whiteCount, as our window size is now being changed
      * - and then increment our left
      * - while we are in our window size limit, we check if our block[right] is 'W' we increment our whiteCount
      */
     
      public:
      int minimumRecolors(string blocks, int k) {
  
          int n = blocks.size();
          int result = k;
          int whiteCount = 0;
          int left = 0;
          //treat i as the right pointer, that will be moving towards the end
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
         * Time Complexity: O(n)  atmost we might be visiting few element 2 times
         * Space Complexity: O(1) no extra space utilized
         */
    };