#include<queue>
using namespace std;


class Solution {
    public:
    
        // LC3066 Minimum Operations to Exceed Threshold Value II
        // https://leetcode.com/problems/minimum-operations-to-exceed-threshold-value-ii/description/
    
    
    
        /**
            intuition:
            - we will be using a priority queue minheap to store all the elements of the input vector.
            - we will change the element order for the priority_queue so that it has the smallest element at the top. (in c++ by default the order of priority queue is largest element on the top)
            - As the priority queue minheap will have the smallest element on the top, this would help us to extract the two smallest values from nums
            - To perform the operation on our two smallest values from nums, our minheap size should atleast be 2
            - we start going through the two smallest values from our minheap, 
            - we check if the minheap size is atleast 2 and the top element is greater or equal to K, in this case we return the minOperations as the top element already has the size greater or equal to K
            - else we pop the first and the second element from the minheap and perform the calucation min(x, y) * 2 + max(x, y) and push the result in the minheap.
            - increment the minOperations by 1 as we performed the calculation
    
        **/
    
    
        int minOperations(vector<int>& nums, int k) {
    
            int minOperations = 0;
    
            std::priority_queue<long long, std::vector<long long>, std::greater<long long>> minHeap;
    
            for(int i = 0 ; i < nums.size() ; i++) {
                minHeap.push(nums[i]);
            }
    
            //pop the first and the second element from the priority queue
    
            while(minHeap.size()>=2) {
    
                if(minHeap.top() >= k) {
                    return minOperations;
                }
    
                long long smallest = minHeap.top();
                minHeap.pop();
    
                long long secondSmallest = minHeap.top();
                minHeap.pop();
    
                long long result = (min(smallest,secondSmallest) * 2) + max(smallest,secondSmallest);
                minHeap.push(result);
                minOperations += 1;
    
            }
    
            return minOperations;
        }
    
        /**
    
        Time Complexity  O(n.logn)   where n is the size of the input vector and logn is the time for inserting each element in the minheap, so it takes O(n.logn) time to push n elements in the minheap
    
        Space Complexity  O(n)      the size of the priority queue could be n at max, where n is the size of the input vector    
    
        **/
    };
