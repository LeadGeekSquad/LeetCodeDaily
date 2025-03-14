#include<vector>
#include<unordered_set>
using namespace std;


class Solution {
    public:
        vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    
            // LC:349 Intersection of Two Arrays
            // https://leetcode.com/problems/intersection-of-two-arrays/description/
    
    
            //optimized approach 
            // - we convert one of the array to set, for instant lookup while also eliminating duplicates.
            // - than we iterate over the other array, and check for the values in the set, if exist we add them to the answer vector
            // - to improvise, we can compare the size of the arrays and create the set of the smaller array to optimize the space so that it takes min space
    
            unordered_set<int> answer;
            unordered_set<int> set1(nums1.begin(),nums1.end());
    
            for(int num : nums2) {
                if(set1.count(num)) {
                    answer.insert(num);
                }
            }
    
            return {answer.begin(),answer.end()};
    
    
            // Time Complexity: O(n+m)   it is the time taken to iterate over array and creating a set
            // Space Complexity: O(min(m,n))  as our set will be created from the smallest size of the array, and the result array can atmost have that number of intersecting elements, so we take minimum of n and m.
    
    
    
            /**
    
            // approach: bruteforce
    
            vector<int> answer;
    
            for(int n : nums1) {
                for(int n2 : nums2) {
                    if(n2 == n) {
                        if(answer.size()!=0) {
                            bool dupFlag = false;
                            for(int ans : answer) {
                                if(ans == n2) {
                                    dupFlag = true;
                                    break;
                                }
                            }
                            if(!dupFlag) {
                                    answer.push_back(n2);
                            }
                        } else {
                            answer.push_back(n2);
                        }
                    }
                }
            }
    
            return answer;
    
            //Time compelxity: O(n * m)  where n,m are the size of nums1 and nums2
            //Space Complexity: O(1)     no extra space utilized
    
            **/
        }
    };