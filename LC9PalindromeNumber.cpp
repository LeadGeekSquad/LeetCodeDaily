using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {

        // LC:9 Palindrome Number
        // https://leetcode.com/problems/palindrome-number/description/

        //checking for negative
        // if(x < 0) {
        //     return false;
        // }

        //checking for single digit numbers from 0 to 9
        // if(x < 10) {
        //     return true;
        // }

        // Numbers ending in 0 (except 0 itself) cannot be palindromes e.g. 340, 10, 7000
        //checking for x ending in 0, and start as non zero 
        // if (x % 10 == 0 && x != 0) { 
        //     return false;
        // }

        if (x < 0 || (x % 10 == 0 && x != 0)) {
            return false;
        }

        int reversedHalf = 0;
        while (x > reversedHalf) {
            int digit = x % 10;
            reversedHalf = reversedHalf * 10 + digit;
            x /= 10;
        }

        // For even and odd length numbers
        // in case of even X, eg. 656, we can directly compare the reverse and the reduced X
        // in case of odd X, eg. 44144, we will have one remaining digit in reverse which can be ignored,
        // because that will be middle digit of the odd number

        return x == reversedHalf || x == reversedHalf / 10;

        

        //Note: This is simple yet tricky question because of the constraint

        //Time complexity: O(log x)
        //Space complexity: O(1)

        
    }

    /**

    // string num = to_string(x); //takes O(x) space where x is the size of the digits in the number

        // int start = 0;
        // int end = num.size()-1;

        //takes O(x) time, as it iterates over the string of n size
        // while(start < end) {
        //     if(num[start++] != num[end--]) {
        //         return false;
        //     }
        // }

        //return true;

        //Unoptimzed approach : Time complexity O(x) ; Space complexity O(x)

    **/

    
};