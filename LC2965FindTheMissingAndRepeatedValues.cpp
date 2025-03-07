#include<iostream>
#include<vector>
using namespace std;


class Solution {
    public:
        vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
    
            /**
                LC:2965 Find Missing and Repeated Values
                https://leetcode.com/problems/find-missing-and-repeated-values/description/
            **/
            
    
            //answer should have repeated first and then missing number
            //we will create a map and store the elements in the grid and its count, as key and value pair
            //when we detect that the element is repeated we will assign that element to our repeated variable
            //for finding the missing element, we will iterate over the map using the range 1 to grid.size(), if an    element is not found within that range , we can consider that element as the missing element.
            //atlast we return the repeated and missing element 
            // for optimized solution there is a math formula based approach that we can utilize which helps us to save the space, by solving it in constant space
    
            
            // Math Forumula based approach, which could help us save space
    
            int n = grid.size();
            long long total_size = n * n;
    
            long long expectedSum = ( total_size * (total_size + 1) ) / 2;    // n(n+1)/2
            long long expectedSumSquare = ( total_size * (total_size + 1) * (2 * total_size + 1) ) / 6;   // n(n+1)(2n+1)/6
    
            // Calculating actual sum and actual sum of squares
            long long actualSum = 0, actualSumSquare = 0;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    int num = grid[i][j];
                    actualSum += num;
                    actualSumSquare += (long long)num * num;
                }
            }
    
            // Compute differences
            long long diff = expectedSum - actualSum;  // M - R
            long long sumDiff = expectedSumSquare - actualSumSquare;  // M² - R²
    
            long long sumOfMissingRepeated = sumDiff / diff; // M + R
    
            int missing = (diff + sumOfMissingRepeated) / 2;
            int repeated = sumOfMissingRepeated - missing;
    
            return {repeated, missing};
    
    
    
            /** Unoptimized Approach where space complexity is O(n^2)
    
            vector<int> answer(2,0);
            int total_size = grid.size() * grid[0].size();
            int repeated = 0;
            int missing = 0;
            unordered_map<int,int> map;
    
            for(int i = 0 ; i < grid.size(); i++) {
                for(int j = 0 ; j < grid[0].size(); j++) {
                    if(map.contains(grid[i][j])) {
                        map[grid[i][j]]++;
                        repeated = grid[i][j];
                    } else {
                        map[grid[i][j]]++;
                    }
                }
            }
    
           for(int i = 1 ; i <= total_size ; i++) {
                if(!map.contains(i)) {
                    missing = i;
                }
           }
    
           answer[0] = repeated;
           answer[1] = missing;
    
           return answer;
    
           **/   
        }
        
        //Time Complexity : O(n^2)
        //Space Complexity : O(n^2)
    };
