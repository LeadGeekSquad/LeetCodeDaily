#include<iostream>
using namespace std;


class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {

        // LC:1790 Check if One String Swap Can Make Strings Equal
        // https://leetcode.com/problems/check-if-one-string-swap-can-make-strings-equal/description/


        //if both strings are same
        if(s1 == s2) {
            return true;
        }

        //checking if both strings are of different size
        if(s1.size() != s2.size()) {
           return false;
        }

        int first_index = -1;
        int second_index = -1;

        //we will find our first two indexes that has distinct characters
        for(int i = 0 ; i < s1.size() ; i++) {
            if(s1[i] != s2[i] && first_index < 0) {
                first_index = i;
            } else if(s1[i] != s2[i] && second_index < 0) {
                second_index = i;
            }

            //break the loop early if we have found our first and second indistinct index
            if(first_index >= 0 && second_index >= 0) {
                break;
            }
        }

        //swap either of the string with distinct indexes
        if(first_index >= 0 && second_index >= 0) {
            swap(s1[first_index],s1[second_index]);
        }

        if(s1 == s2) {
            return true;
        }


        return false;


        // Time Complexity O(n)  
        // Space Complexity O(1)


        /** another way to return answer directly without comparing the entire string

        return ( s1[first_index] == s2[second_index] ) && ( s1[second_index] == s2[first_index] );

        **/


    }
};