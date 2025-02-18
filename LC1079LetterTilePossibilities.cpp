#include<unordered_map>
#include<vector>
using namespace std;


class Solution {

    // LC:1079 Letter Tile Possibilities
    // https://leetcode.com/problems/letter-tile-possibilities/description/


    /**
        intuition:
        - we will be using recursive backtracking here
    **/


    private:
    int backtrack(unordered_map<char, int>& freq) {
        int count = 0;
        
        for (auto& [ch, f] : freq) {
            if (f > 0) {
                // Use this character
                count++;
                freq[ch]--;
                
                // Recurse for next character
                count += backtrack(freq);
                
                // Backtrack: undo the choice
                freq[ch]++;
            }
        }
        
        return count;
    }
public:
    int numTilePossibilities(string tiles) {
        unordered_map<char, int> freq;
        
        // Step 1: Count frequency of each character
        for (char c : tiles) {
            freq[c]++;
        }
        
        return backtrack(freq);
    }

    /**
        Time Complexity  O(n!) where n is all the unique elements in the tiles string
        Space Complexity  O(n) where n is size of the map, mostly less than or equal to 26 as it will store unique alphabets
    **/
};