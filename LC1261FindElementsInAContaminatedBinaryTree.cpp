#include<iostream>
#include<unordered_set>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
 
 class FindElements {

    /**
        LC:1261 Find Elements in a Contaminated Binary Tree
        https://leetcode.com/problems/find-elements-in-a-contaminated-binary-tree/description/
    **/
    
    /**
        Intuition:
        - given the rule the root value will be 0. We start with the root
        - we restore the tree, for left child 2x+1 and for right child 2x+2
        - we apply the equation recursively by visiting all the nodes
        - we store the values in a hashset, to check if a number exists in the tree
        - when FindElements is called we check if the target is in the hashset
        - if exists we return true, or else we return false
    
    **/
   
    class TreeNode {
        public:
        int val;
        TreeNode *left;
        TreeNode *right;
    
        TreeNode(int data) {
            this->val = data;
            left = NULL;
            right = NULL;
        }
    };
    
    private:
        unordered_set<int> values; // Store all valid values
    
        void recover(TreeNode* node, int val) {
            if (!node) return;
            node->val = val;
            values.insert(val);
            recover(node->left, 2 * val + 1);
            recover(node->right, 2 * val + 2);
        }
    
    public:
        FindElements(TreeNode* root) {
            recover(root, 0); // Start recovering from root with value 0
        }
        
        bool find(int target) {
            return values.count(target);
        }
    
        /**
            Time Complexity: O(n)   as we traverse through each node in the tree
                       find() : O(1) checking if the target exist in hashset will be constant time lookup
    
            Space Complexity: O(n)   we store atmost n recovered values in the hashset
        **/
    };
    
    
    /**
     * Your FindElements object will be instantiated and called as such:
     * FindElements* obj = new FindElements(root);
     * bool param_1 = obj->find(target);
     */