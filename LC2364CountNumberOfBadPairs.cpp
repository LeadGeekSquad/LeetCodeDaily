#include<vector>
#include<unordered_map>
using namespace std;


class Solution {
    public:
        long long countBadPairs(vector<int>& nums) {
            
    
            // LC:2364 Count Number of Bad Pairs
            // https://leetcode.com/problems/count-number-of-bad-pairs/description/
    

            /**
            intuition:
               - if we use our simple brute force approach its gonna give us time
                    limit exceed because of O(n^2) time complexity
               - so than, with other approach we can try to find all the good pairs
                    and then deduct it from the total pairs to find the bad pairs
               - the formula to find the total pairs is (n * (n-1)) / 2 where n is
                    the size
               - as we can rearrange the equation, we can check for values
                    nums[i]-i, if we found more than 1 count that means a good pair exist
               - to optimize we can try to find the count of (nums[i]-i) and store
                    it as the key and it's count(the frequency) as value.
               - after finding the nums[i]-i and storing it in the map as key and
                    count, iterate over it and add it to the good pair counts
               - also find total pairs which can be made out of that good pair
                    counts by using the formula to find the total pairs
               - deduct goodPair counts from totalPairs
               - return badPairs
    
               Note: as the value gets too bigger while multiplying count, type
            casting to long long is recommended here
    
    
            **/
    
            unordered_map<int, int> valueCount;
            long long goodPairs = 0;
            long long numsSize = nums.size();
            long long totalPairs = (numsSize * (numsSize - 1)) / 2;
    
            // lets find the count of each key
            for (int i = 0; i < numsSize; i++) {
                valueCount[nums[i] - i]++;
            }
    
            // iterate over each key to find the count of total good pairs
            for (auto const& [key, count] : valueCount) {
                long long totalGoodPairs = (long long)(count) * (count - 1) / 2;
                goodPairs += totalGoodPairs;
            }
    
            // return badPairs which is (totalPairs-goodPairs)
            return totalPairs - goodPairs;
    
            /**
                Time complexity O(n)   such that n is the size of nums vector
                Space Complexity O(n)  such that n is the size of valueCount map, in
            worst case it would be of size nums vector
            **/
    
            /**
            brute force approach -> O(n^2) Time Complexity
            long long badPair = 0;
            for(int i = 0 ; i < nums.size() - 1; i++) {
                for(int j = i+1 ; j < nums.size(); j++) {
                    if( i < j && ( j - i != nums[j] - nums[i])) {
                        badPair++;
                    }
                }
            }
            return badPair;
            **/
        }
    };