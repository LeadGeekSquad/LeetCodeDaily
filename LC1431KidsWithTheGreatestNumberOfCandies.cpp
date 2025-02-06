#include<vector>
using namespace std;

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {

        // LC:1431 Kids With the Greatest Number of Candies
        // https://leetcode.com/problems/kids-with-the-greatest-number-of-candies/description/


        //Intuition: 
        
        //The question could be really confusing at first glance and could give a wrong intution.
        //Pay close attention to the example and you will find why it's bit misleading.
        // we first need to find the maxCandies among the array. After than only we should start adding the extra candies for comparison
        
        //create an bool answer vector of the same size as candies array, we can initialize it with false
        //iterate over the candies array and find the max number of candies, store this in maxCandies
        //add the value at currentIndex with the extra candies, compare it with the max Number of candies variable
            //if the sum is greater then or equal to maxcandies, we update the value at currentIndex in the answer vector to true 
            //at the end we need to return the bool answer vector 

        vector<bool> answer(candies.size(),0);
        int maxCandies = 0;
        
        for(int i = 0 ; i < candies.size() ; i++ ) {

            maxCandies = max(maxCandies,candies[i]);

        }

        for(int i = 0; i < candies.size() ; i++) {

            int sum = candies[i] + extraCandies;
            
            if(sum >= maxCandies) {
                answer[i] = 1;
            }
        }

        return answer;

        // Time Complexity O(n)
        // Space Complexity O(n)
    }
};
