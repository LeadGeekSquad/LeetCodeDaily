#include<iostream>
#include<string>
#include<stack>
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
        LC:1028 Recover a Tree From Preorder Traversal
        https://leetcode.com/problems/recover-a-tree-from-preorder-traversal/description/
    **/


    /**
        intuition:
        - input will be a string which represents a preorder traversal of a bianry tree
        - the given number are nodes and the dashes represent the depth
        - we will parse the strings first and split it into pairs
        - we use stack here to track the current path from the root node we are building
        - for each new node in the parsed list, we pop the node from the stack until we find the parent
        - if the parent has left child, we attach the new node as left child, or else as right child
    **/



public:

    vector<pair<int, int>> parse(const string& s) {
    vector<pair<int, int>> res;
    int n = s.size();
    int i = 0;
    while (i < n) {
        int depth = 0;
        while (i < n && s[i] == '-') {
            depth++;
            i++;
        }
        int num = 0;
        while (i < n && isdigit(s[i])) {
            num = num * 10 + (s[i] - '0');
            i++;
        }
        res.emplace_back(num, depth);
    }
    return res;
}

    TreeNode* recoverFromPreorder(string S) {
        auto nodes = parse(S);
    if (nodes.empty()) return nullptr;
    
    TreeNode* root = new TreeNode(nodes[0].first);
    stack<pair<TreeNode*, int>> st;
    st.push({root, nodes[0].second});
    
    for (int i = 1; i < nodes.size(); ++i) {
        int val = nodes[i].first;
        int depth = nodes[i].second;
        
        while (st.top().second >= depth) {
            st.pop();
        }
        
        TreeNode* parent = st.top().first;
        TreeNode* child = new TreeNode(val);
        if (parent->left == nullptr) {
            parent->left = child;
        } else {
            parent->right = child;
        }
        st.push({child, depth});
    }
    
    return root;
    }

    /**
        Time Complexity: O(n)   as we iterate through the entire string

        Space Complexity:O(n)   storing the parsed pairs in the stack, atmost we would store n pairs in the stack
    **/
};