#include<vector>
using namespace std;


class Solution {
    public:
        string removeOccurrences(string s, string part) {
    
            // LC1910 Remove All Occurrences Of a Substring
            // https://leetcode.com/problems/remove-all-occurrences-of-a-substring/description/
    
            
    
            // intutition
            // approach iterate over string s until the size of string part
            // take a string which we can implement as a stack, we will add the chars from s in here
            // if we found the sequence of part in our s, we will strip that sequence and check for the last M size substr in our string stack
            // we can return the new string stack
    
            
            string stack;
            int partLen = part.size();

            for (char c : s) {
            stack.push_back(c);
            // Check if the last `partLen` characters in the stack match `part`
            if (stack.size() >= partLen && stack.substr(stack.size() - partLen, partLen) == part) {
                stack.erase(stack.size() - partLen, partLen); // Remove the matched substring
            }
        }
        return stack;
    
        }
    
        // Time Complexity: O(s.size() * part.size())   as for almost every char we add to the stack string, we check go back and check for the last M elements in the stack to compare withe the string part
    
        // Space Complexity: O(s.size())   as the max size of the answer string stack could be s.size() in case of no substring sequence found in string s
    };