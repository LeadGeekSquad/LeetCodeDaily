#include<iostream>
#include<vector>
using namespace std;


class Solution {
    public:
    
        // LC:1718 Construct the Lexicographically Largest Valid Sequence
        // https://leetcode.com/problems/construct-the-lexicographically-largest-valid-sequence/description/
    
    
        /**
            Intuition:
            we will be using backtracking to solve this problem
        **/
    
        bool backtrack(vector<int>& seq, vector<bool>& used, int n, int index) {
        if (index == seq.size()) return true;  // If all positions are filled, return true
    
        if (seq[index] != 0) // If already filled, move to next index
            return backtrack(seq, used, n, index + 1);
    
        // Try placing numbers from n to 1 (lexicographically largest first)
        for (int num = n; num >= 1; num--) {
            if (used[num]) continue; // Skip used numbers
    
            if (num == 1) { 
                // Special case: 1 appears once, just place it
                seq[index] = 1;
                used[num] = true;
                if (backtrack(seq, used, n, index + 1)) return true;
                seq[index] = 0;
                used[num] = false;
            } else {
                int j = index + num; // Compute second position
                if (j < seq.size() && seq[j] == 0) { // Ensure valid placement
                    seq[index] = seq[j] = num;
                    used[num] = true;
    
                    if (backtrack(seq, used, n, index + 1)) return true;
    
                    // Backtrack
                    seq[index] = seq[j] = 0;
                    used[num] = false;
                }
            }
        }
    
        return false; // No valid placement found, backtrack
    }
    
    vector<int> constructDistancedSequence(int n) {
        vector<int> seq(2 * n - 1, 0); // Initialize sequence with 0s
        vector<bool> used(n + 1, false); // Track used numbers
    
        backtrack(seq, used, n, 0); // Start backtracking from index 0
    
        return seq;
    }
    
    
       /**
            Time Complexity O(n!)  this could be the worst case because of backtracking
            Space Complexity O(n)  the size of the array (2n-1) which will be O(n)
       **/
    };