#include<numeric>
#include<iostream>
using namespace std;

class Solution {
public:
    string gcdOfStrings(string str1, string str2) {

        // LC:1071 Greatest Common Divisor Of Strings
        // https://leetcode.com/problems/greatest-common-divisor-of-strings/description/


        //intuition: we can treat this question similar to finding the greatest common divisor of two numbers
        
        //before we find the gcd, we should check for the common string if added in either sequence
        //checking if the pattern is common when two string are added
        if(str1 + str2 != str2 + str1) {
            return "";
        }

        //find the greatest common divisor of length of two strings
        int common_gcd = gcd(str1.length(),str2.length()) ;

        //return the substr of length common_gcd from any of our strings
        //we can either use, str1 or str2 to return the common substring
        return str1.substr(0,common_gcd);


        //Time complexity: O(n+m)
        //Space complexity: O(n+m)

    }
};