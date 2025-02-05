#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    string mergeAlternately(string word1, string word2) {

        // LC:1768 MergeStringsAlternatively
        // https://leetcode.com/problems/merge-strings-alternately/description/

        string ans = "";

        int str1_size = word1.size();
        int str2_size = word2.size();

        //finding the common length among both string to iterate 
        int loop_size = min(str1_size,str2_size);

        //looping and adding the characters to the answer string until common length of the two strings
        for(int i = 0 ; i < loop_size ; i++) {
            ans += word1[i];
            ans += word2[i];
        }

        //if length of word1 is greater than word2, append the remaining characters from word1 to ans
        //else if length of word2 is greater than word1, append the remaining character from word2 to ans. 
        if(str1_size > str2_size) {
            for(int i = loop_size ; i < str1_size ; i++) {
                ans += word1[i];
            }
        } else if(str2_size > str1_size){
            for(int i = loop_size ; i < str2_size ; i++)
                ans += word2[i];
        }


        return ans;
        
        //Time Complexity: O(n + m) where n is the size of word1, and m is the size of word2
        //Space Complexity: O(n + m) where n is the size of word1, and m is the size of word2
    }
};


/**
More precise, clear and less redundant approach with same asymptotic notation

we can use two index, one to track the length of word1 and other to track the length of word2

string ans = "";
int word1_index = 0; int word2_index = 0;
int word1_size = word1.size() ; int word2_size = word2.size();

while(word1_index < word1_size || word2_index < word2_size) {
    
    if(word1_index < word1_size) {
        ans += word1[word1_index];
        word1_index++;
    }

    if(word2_index < word2_size) {
        ans += word2[word2_index];
        word2_index++;
    }

}

return ans;


**/