#include<vector>
#include<stack>
using namespace std;


class Solution {
    public:
        string clearDigits(string s) {
    
            // LC:3174 Clear Digits
            // https://leetcode.com/problems/clear-digits/description/
    
            
            /**
                Approach 1
                intuition:
                 - if we are allowed to override the input string, this simulation approach is the most optimal,
                 - we take an index and initialize with 0
                 - we start iterating over the string, if the char is alphabet we add it to the index position and update the index by 1, this is to track our next position to place our alphabet.
                 - else if the char is number, we need to remove the preceding alphabet, we achieve this by decrementing our index by 1,
                 - but just to keep in my we cannot have our index < 0, so we have to keep the index value atleast 0 or above.
                 - This approach has Time complexity O(n) and Space Complexity O(1)  [Most Optimal]
    
    
            **/
    
            int index = 0;
    
            for(char c : s) {
                if(isalpha(c)) {
                    s[index] = c;
                    index++;
                } else {
                    index = max(index-1,0);
                }
            }
    
            return s.substr(0,index);
    
            //Time Complexity O(n)    such that n is the size of the input string
            //Space Complexity O(1)   No extra space utilized
    
    
    
    
            /**
                Approach 2
                intuition:
                - we use a stack to push and pop the characters from the input string
                - if the char at i is an alphabet, we push it to the stack
                - else if the char at i is a number, and if the stack is not empty, we try to remove the preceding alphabet by popping the last character from te stack
                - after iterating, if the stack is empty we return the ans which has empty string "".
                - if the stack is not empty, we pop out all the elements from the stack and append it to our ans string.
                - we reverse the ans string to arrange them in the correct order
                - we return the ans string
                - Time Complexity O(n)  Space Complexity O(n)  (this approach requires extra space)
    
    
            string ans = "";
            stack<char> chars;
    
            for(int i = 0 ; i < s.size() ; i++) {
                if(isalpha(s[i])) {
                    chars.push(s[i]);
                } else {
                    if(!chars.empty()) {
                        chars.pop();
                    }
                   
                }
            }
    
            if(chars.empty()) {
                return ans;
            }
    
            while(!chars.empty()) {
                char temp = chars.top();
                ans += temp;
                chars.pop();
            }
    
            reverse(ans.begin(),ans.end());
    
            return ans;
    
    
             // Time Complexity O(n)  
             // Space Complexity O(n)
    
            **/
            
        }
    };