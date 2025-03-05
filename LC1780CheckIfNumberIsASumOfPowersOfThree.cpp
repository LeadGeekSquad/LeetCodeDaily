using namespace std;


class Solution {
    public:
        bool checkPowersOfThree(int n) {
    
            /**
                LC:1780 Check if Number is a Sum of Powers of Three
                https://leetcode.com/problems/check-if-number-is-a-sum-of-powers-of-three/description/
            **/
    
            /**
                Intuition:
                - just keep in mind that we need distinct 3^K, assume if our n=2, we can't have two times 3^0 and 3^0 which gives us a sum 2, because it's not distinct
                - the possible remainders we get when we divide n by 3 are 0,1,2
                - this given us an idea, about when we have a remainder 2, we need 2 instances of 3^k which is not a viable option here
                - this means that if we get 2 as our remainder we can say that the number is not a sum of powers of three
                - if we get our remainder as 0 and 1, means our n is completely divisible by 3 incase of 0, or incase of 1, it needs just 1 instance of 3^k to make up our n
                - we keep dividing our n by 3, until it reaches 0
                - atlast we return true, if we never encountered our remainder as 2
            **/
    
    
            while (n > 0) {
                if (n % 3 == 2) {
                    return false;  // if we get remainder as 2, we return false, as it's not a sum of powers of 3
                }    
                n /= 3;  // we reduce n by dividing it by 3
            }
    
            return true;
             
        }
    
    
        /**
            Time Complexity: O(logn)  as we divide the n by 3 unitl it becomes zero
            Space Complexity: O(1)    no extra space is being utilized
        **/
    };