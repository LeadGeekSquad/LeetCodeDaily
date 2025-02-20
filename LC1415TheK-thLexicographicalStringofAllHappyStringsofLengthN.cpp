#include<string>
using namespace std;


class Solution {


    // LC:1415 The K-th Lexicographical String of All Happy Strings of Length n
    // https://leetcode.com/problems/the-k-th-lexicographical-string-of-all-happy-strings-of-length-n/description/


    /**
        Intuition:
        - we will be using recursive backtracking here
        - taking an empty string result
        - we will generate all the happy strings while checking no two consecutive characters are the same
        - we will keep a count, and terminate early if the Kth string is found
        - to find all the possibilities of the strings we will be backtracking


    **/   

private:
    void backtrack(int n, string current, int& count, int k, string& result) {
        if (current.length() == n) {
            count++;
            if (count == k) result = current;
            return;
        }
        
        for (char ch : {'a', 'b', 'c'}) {
            if (current.empty() || current.back() != ch) {
                backtrack(n, current + ch, count, k, result);
                if (!result.empty()) return; // Stop when k-th string is found
            }
        }
    }

public:
    string getHappyString(int n, int k) {
        string result;
        int count = 0;
        backtrack(n, "", count, k, result);
        return result;
    }


    /**
        Time Complexity  O(2^n)   where we have 3 choices for the first character of the string and then 2^(n-1) for the rest of the characters, so the asymptotic notation is O(2^n)

        Space Complexity  O(n)    where atmost the depth of the recursion tree could go upto n

    **/
};