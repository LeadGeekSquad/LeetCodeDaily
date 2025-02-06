#include<unordered_map>
#include<vector>
using namespace std;

class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {

        // LC:1726 Tuple with Same Product
        // https://leetcode.com/problems/tuple-with-same-product/description/
        

        /**
        intuition:
            we will try to solve this using permutation and combination

            iterate over array starting at index 0 while holding the index start iterating over the rest of the element next to index 0, 
            similary do for all the index until nums.size() - 1

            while iterating we will find the product of nums[i] * nums[j] and will put the product in the map as key while incrementing the value by 1.
            (a new map must be created which will store key,value of type int,  key will be the product and value will be the frequency, simply how many times we encounter that product) 

            Now, we have the map which has key as the product and value as it's frequency

            iterating over the map to compare the frequencies, which are greater than 2, because the product which appears more than or equal to twice,
            can only form a tuple (a,b,c,d) where a,b is first pair and b,a is second pair.

            And a valid tuple will have 8 permutations like (a,b,c,d) , (b,a,d,c) , (c,d,a,b) , (d,c,a,b) ... and so on
            (simply understand in a way the two pairs can be placed in different ways)

            To find the combnations to know many ways to selects the original pairs which has frequency greater than 2
            we use (frequency * (frequency-1)) / 2; a simple formula to find all the combinations of the pairs

            e.g. if our product has frequecy 3, we do 3 combination 2 (3c2), put that in the above equation to find total combinations
            (3 * (3-1)) / 2  = (3 * 2) / 2 = 3 total combinations are 3 for frequency 3

            And to find total tuples that combinations can have is 3 * 8 = 24 tuples for frequency 3

            Similarly, we need to calculate the total tuples for each value of frequency >= 2 and keep adding that to the count.


            Ugghh..I know this was a bit too much :)

        **/


        unordered_map<int,int> pairs;

        for(int i = 0 ; i < nums.size() - 1 ; i++) {
            for(int j = i + 1 ; j < nums.size() ; j++) {
                pairs[nums[i] * nums[j]]++;
            }
        }

        int count = 0;

        for(const auto total : pairs) {
            if(total.second >= 2 ) {
                     count +=  ( ( total.second * (total.second - 1) ) / 2 ) * 8 ;
            }
            
        }

        return count ; 
    }

    /**
        Time Complexity: O(n^2)  as we iterate over every element twice to find it's product
        Space Complexity: O(n^2)  in the worst case the size of our map could be as big as the size of all the product that is O(n^2)
    **/
};