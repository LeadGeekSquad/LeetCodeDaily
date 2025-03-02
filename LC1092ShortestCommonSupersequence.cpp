#include<vector>
#include<string>
using namespace std;


class Solution {
    public:
        string shortestCommonSupersequence(string str1, string str2) {
    
            /**
                LC:1092 Shortest Common Supersubsequence
                https://leetcode.com/problems/shortest-common-supersequence/description/
            **/
    

            /**
                approach:
                - we calculate the longest common subsequence table
                - we build the shortest common supersequence
                - if we find any remaining characters, we add the remaining chars to scs
                - as we have built over string backward, we reverse it and return scs
            **/
            
            int m = str1.size(), n = str2.size();
            // Step 1: Calculate LCS table
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (str1[i - 1] == str2[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    
        // Step 2: Build SCS using LCS
        int i = m, j = n;
        string scs = "";
    
        while (i > 0 && j > 0) {
            if (str1[i - 1] == str2[j - 1]) {
                scs += str1[i - 1];  // Add common character
                i--, j--;
            } else if (dp[i - 1][j] > dp[i][j - 1]) {
                scs += str1[i - 1]; // Take from str1
                i--;
            } else {
                scs += str2[j - 1]; // Take from str2
                j--;
            }
        }
    
        // Step 3: Add remaining characters
        while (i > 0) scs += str1[i - 1], i--;
        while (j > 0) scs += str2[j - 1], j--;
    
        // Reverse to get correct order
        reverse(scs.begin(), scs.end());
        return scs;
    
        }
    
        /**
            Time Complexity: O(m * n)  as we are using the LCS table using dp
            Space Complexity: O(m * n)  as the dp table stores  LCS values, requiring O(m * n) space
        **/
    };