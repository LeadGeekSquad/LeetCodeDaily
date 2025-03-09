#include<vector>
using namespace std;


class Solution {
    public:
         vector<int> closestPrimes(int left, int right) {
    
        // LC:2523 Closest Prime Numbers in Range
        // https://leetcode.com/problems/closest-prime-numbers-in-range/description/
        
        /**
         *  Approach:
         * - we create a boolean Array of size right + 1;
         * - we use sieve of eratosthenes to Mark Non-Prime numbers
         * - we find the prime numbers in the range of left to right
         * - we check if there are atleast two primes as we need to make a pair
         * - we find the closest prime pair
         * - atlast, we return the closest prime pair
         * 
         *  */    

        vector<bool> isPrime(right + 1, true);
        isPrime[0] = isPrime[1] = false; // 0 and 1 are not prime
    
        // Sieve of Eratosthenes
        for (int i = 2; i * i <= right; i++) {
            if (isPrime[i]) {
                for (int j = i * i; j <= right; j += i) {
                    isPrime[j] = false;
                }
            }
        }
    
        // Extract prime numbers within the range [left, right]
        vector<int> primes;
        for (int i = left; i <= right; i++) {
            if (isPrime[i]) {
                primes.push_back(i);
            }
        }
    
        // If there are less than 2 primes, return {-1, -1}
        if (primes.size() < 2) {
            return {-1, -1};
        }
    
        // Find the closest prime pair
        int minDiff = INT_MAX;
        vector<int> closestPair = {-1, -1};
    
        for (size_t i = 1; i < primes.size(); i++) {
            int diff = primes[i] - primes[i - 1];
            if (diff < minDiff) {
                minDiff = diff;
                closestPair = {primes[i - 1], primes[i]};
            }
        }
    
        return closestPair;

        }

        /**
         * Time Complexity: O(n logn logn)    where n is the right value
         * Space Complexity: O(n)
         */

    };