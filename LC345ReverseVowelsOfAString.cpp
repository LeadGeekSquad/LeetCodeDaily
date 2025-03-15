#include<iostream>
#include<vector>
using namespace std;


class Solution {
    public:
    
        // LC:345 Reverse Vowels of a String
        // https://leetcode.com/problems/reverse-vowels-of-a-string/description/
    
    
        /**
            intuition:
            - we will be using two pointers approach here
            - we will have one pointer at the start of the string and other at the end of the string
            - we move them towards each other unitl we find the vowel at start and end pointer
            - once we find the vowel at start and end pointer, we swap them move start and end pointer
            - if the start becomes greater than end, we return the string
        **/
    
    
        bool isVowel(char c) {
            return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
                    c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');  
        }
    
        string reverseVowels(string s) {
            
            int start = 0 ; 
            int end = s.size() - 1;
    
            while (start < end) {
                while (start < end && !isVowel(s[start])) {
                    start++;  //until the vowel is found at start position, move start forward
                }
                
                while (start < end && !isVowel(s[end])) {
                    end--;   //until the vowel is found at end position, move end backward
                }
                 
                //once both start and end positions are vowels we swap them
                if (start < end) {
                    swap(s[start++], s[end--]);  // after swapping vowels, increment start by 1 position and decrement end by 1 position
                }
            }
    
            return s;
    
    
            /**
                Time Complexity   O(n)
                Space Complexity  O(1)
            **/
        }
    
    
        /**
            another approach with same complexity
    
            string reverseVowels(string s) {
            int start = 0, end = s.size() - 1;
            
            while(start < end) {
    
                if(isVowel(s[start])) {
                    while(end > start) {
                        if(isVowel(s[end])) {
                            swap(s[start],s[end]);
                            start++;
                            end--;
                            break;
                        } else {
                            end--;
                        }
                    }
                } else {
                    start++;
                }
    
            }
            
            return s;
        }
        **/
    };