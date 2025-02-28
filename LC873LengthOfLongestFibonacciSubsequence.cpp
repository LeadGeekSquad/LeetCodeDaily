#include<vector>
#include<unordered_map>
using namespace std;


class Solution {
    public:
    
        /**
            LC:873 Length of Longest Fibonacci Subsequence
            https://leetcode.com/problems/length-of-longest-fibonacci-subsequence/description/
        **/
    
        
        /**
            intuition:
            - a brute force approach trying all the pairs would be super slow and will give us TLE
            - we will store all the elements of arr in the hashmap to find if the element i + j is present in the array
            - we use two nested loops to iterate over pairs of indices (j, i) where j < i
            - we check for each pair, arr[i] - arr[j] should exist as a valid previous element arr[k], and index[k] should be less than j
            - if the value arr[i] - arr[j] exists in the array in the index map, we update the dynamic programming table dp[j * n + i]
            - else we initialize the value to 2 because any pair of two numbers could form the starting sequence of length 2
        **/
    
    
        int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size(), maxLength = 0;
        unordered_map<int, int> index;
        unordered_map<int, int> dp;
    
        // Store index of each element for quick lookup
        for (int i = 0; i < n; i++) {
            index[arr[i]] = i;
        }
    
        // Iterate over pairs (j, i) where j < i
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                int x = arr[i] - arr[j];
                if (index.find(x) != index.end() && index[x] < j) {
                    int k = index[x];
                    dp[j * n + i] = dp[k * n + j] + 1;
                    maxLength = max(maxLength, dp[j * n + i]);
                } else {
                    dp[j * n + i] = 2;  // Default start length will be 2
                }
            }
        }
    
        return maxLength > 2 ? maxLength : 0;  // Return 0 if no Fibonacci sequence found
        }
    
        /**
            Time Complexity: O(N^2)   for iterating over i,j pairs
            Space Complexity: O(N^2)  it is because of storing fib like sequence  
        **/
    };