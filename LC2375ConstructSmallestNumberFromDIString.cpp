#include<stack>
#include<string>
using namespace std;


class Solution {
    public:
        string smallestNumber(string pattern) {
    
            // LC:2375 Construct Smallest Number From DI String
            // https://leetcode.com/problems/construct-smallest-number-from-di-string/description/
    
    
            /**
                intuition:
                - stack is a data structure which could help us here in maintaining the increasing and decreasing order
                - we would start adding numbers in the stack from 1
                - if we encounter 'I' we will pop the stack, because this will help us in maintaining the increasing order
                - if we encounter 'D' we don't pop directly, we wait until we find the next 'I'
                - we do this for each character present in the pattern string
                - after iterating over all the characters of the pattern string we pop the stack to maintain our decreasing order
                - starting our num from 1 will help us in constructing the smallest number.
            **/
    
            stack<int> numbers;
            string answer;
            int num = 1; 
    
            for(char ch: pattern) {
                numbers.push(num++);
    
                if(ch == 'I') {
                    while(!numbers.empty()) {
                        int temp = numbers.top();
                        answer += to_string(temp);
                        numbers.pop();
                    }
                }
            }
    
            //after iterating over evey element we add the last increased num in the stack
            numbers.push(num);
    
            //if the stack is not, we empty the stack and add the numbers to the answer string
            while(!numbers.empty()) {
                int temp = numbers.top();
                answer += to_string(temp);
                numbers.pop();
            }
    
            //return answer string
            return answer;
            
        }
    
        /**
            Time Complexity: O(n)  As we push and pop every element that we are adding to the numbers stack
            Space Complexity: O(n)  The extra space our stack utilizes
        **/
    };