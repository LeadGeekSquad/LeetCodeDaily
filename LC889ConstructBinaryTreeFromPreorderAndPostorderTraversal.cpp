#include<vector>
#include<unordered_map>
using namespace std;



//Definition for a binary tree node.
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

class Solution {

    /**
        LC:889 Construct Binary Tree from Preorder and Postorder Traversal
        https://leetcode.com/problems/construct-binary-tree-from-preorder-and-postorder-traversal/description/
    **/


    /**
        intuition:
        - to identify the root, we see the root of the tree which is the first element in the preorder traversal
        - for left subtree, the left child of the root is the next element in the preorder traversal
        - we find the position of the left child in the postorder traversal to find the size of the left subtree
        - recursively, we use the size of the left subtree to split the preorder and postorder arrays into left and right subtree

    **/


public:

    TreeNode* helper(vector<int>& pre, vector<int>& post, int pre_start, int pre_end, int post_start, int post_end, unordered_map<int, int>& post_map) {
        if (pre_start > pre_end || post_start > post_end) return nullptr;
        TreeNode* root = new TreeNode(pre[pre_start]);
        if (pre_start == pre_end) return root;
        
        int left_child_val = pre[pre_start + 1];
        int left_post_idx = post_map[left_child_val];
        int left_size = left_post_idx - post_start + 1;
        
        root->left = helper(pre, post, pre_start + 1, pre_start + left_size, post_start, left_post_idx, post_map);
        root->right = helper(pre, post, pre_start + left_size + 1, pre_end, left_post_idx + 1, post_end - 1, post_map);
        
        return root;
    }

    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        unordered_map<int, int> post_map;
        for (int i = 0; i < post.size(); ++i) {
            post_map[post[i]] = i;
        }
        return helper(pre, post, 0, pre.size()-1, 0, post.size()-1, post_map);
    }

    
    /**
        Time Complexity: O(n)   n is the recursive splitting of the array

        Space Complexity: O(n)   atmost the hashmap would be of size n
    **/
};
