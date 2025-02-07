#include<vector>
using namespace std;

class Solution {
    public:
        bool canPlaceFlowers(vector<int>& flowerbed, int n) {
    
            // LC:605 Can Place Flowers
            // https://leetcode.com/problems/can-place-flowers/description/
    
            
            //0 means empty
            //1 means not empty
            // n is the number of new flowers need to planted
            //plant at adjacent positions only
    
            //also handle edge case when the size of flowerbed is 1 with value as 0, and the flower to plant is just 1 or 0, return true
    
            /**
            intuition:
            - we will iterate over the flowerbed vector once,
            - while iterating we keep checking for the value at previous and next index, if previous and next index is 0, we can plant a flower, 
            and should be moving to next to next index, while decrementing our n by 1
            - but the challenge here would be to circumvent conditions where we could potentially face out of bound conditions while iterating over flowerbed vector.
            - we could face that when our index is 0, we can't check for previous index, as we are on the very first index
            - similary when we are at index flowerbed.size()-1 we can't check for next index, as we are on the very last index
            **/
    
    
            int size = flowerbed.size();
    
            for(int i = 0 ; i < size ; i++) {
    
                //anytime while iterating if n becames 0, we have planted all of our n flowers and we can simply return true
                if(n == 0) {
                    return 1; 
                }
    
                if( (flowerbed[i]==0) && (i == 0 || flowerbed[i-1] == 0) && (i == size-1 || flowerbed[i+1] == 0) ) {
                    flowerbed[i] == 1;  //plant the flower at index i
                    n--; // decrease the flowers need to be planted by 1
                    i++; //increment the index as we can't plant the next flower adjacent to where we just planted the flower
                }
            }
    
            return n == 0; //checking if the flower is planted at the last index and n becomes 0
            
        }
    
        /**
    
        Time Complexity O(n)   where n is the size of the vector flowerbed
        Space Complexity O(1)  no extra space utilized
    
        **/
    };