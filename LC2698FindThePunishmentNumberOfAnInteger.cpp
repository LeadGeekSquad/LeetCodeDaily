#include<string>
using namespace std;



class Solution {
    public:
    
        // LC:2698 Find the Punishment Number of an Integer
        // https://leetcode.com/problems/find-the-punishment-number-of-an-integer/description/
    
    
        //Optimzed solution can be achieved using memoization by doing precomputation of each punishment number and then adding all
        // of them to find the sum of those punishment numbers. This could increase our space complexity, but can give us a better
        // time complexity
    
    
        /**
            intuition:
            - we will iterate from 1 to N to find all the square until N^2
            - we will convert the square to string to pass it to the recursive function
            - we will be using recursion here to find all the possible partition that sum up to i
            - our recursive function will return a bool value, if the the partition is equal to our i(which is the number we squared), it will return true, or else it will return false
            - if it returns true, we will add it to the squared sum
            - at the end we return that sum
    
            - in the recursive function, we send the string form of the squared number, target(the number we squared), current_sum, index we are at for the individual digits we are iterating in the string)
            - for base condition, we keep checking until we have checked the paritions of the entire string, and return the comparison of current_sum with target
    
        **/
    
    
        bool canPartition(string &s, int target, int current_sum, int index) {
        // Base case: if we've used all digits, check if sum matches target
        if (index == s.size()) {
            return current_sum == target;
        }
    
        int num = 0;
        // Try different partitions by forming numbers from substring
        for (int j = index; j < s.size(); j++) {
            num = num * 10 + (s[j] - '0');  // Form a number using digits
            
            // Continue partitioning if the sum so far is still <= target
            if (current_sum + num <= target) {
                if (canPartition(s, target, current_sum + num, j + 1)) {
                    return true;  // If we find one valid partition, return True
                }
            } else {
                break; // Stop early if sum exceeds target
            }
        }
    
        return false;  // If no partition works, return False
        }
    
        int punishmentNumber(int n) {
            int sum = 0;
    
        for (int i = 1; i <= n; i++) {
            int squared = i * i;
            string squaredStr = to_string(squared);
    
            // If a valid partitioning exists, add i^2 to the total sum
            if (canPartition(squaredStr, i, 0, 0)) {
                sum += squared;
            }
        }
    
        return sum;
        }
    
        /**
            Time Complexity: O(n^3)  where we iterate n times, and the recursive function has TC O(n^2), combining both of them it is O(n^3)
    
            Space Complexity: O(log n)  the total number of digits in a number when squared will be approximately O(2log N), so our space for the string of square of N will be (log n) 
    
        **/
    };