#include<vector>
#include<unordered_map>
#include<queue>
using namespace std;


class Solution {
    public:
    
        /**
            LC:2467 Most Profitable Path in a Tree
            https://leetcode.com/problems/most-profitable-path-in-a-tree/description/
        **/
    
        /**
            intuition:
            - we will build the tree using an adjacency list to efficiently traverse ndoes and edges
            - we use BFS to find Bob's shortest path to node 0
            - we will track Bob's arrival time at each node on his path
            - Nodes which are not on Bob's path are marked with INT_MAX
            - we use DFS to traverse through all possible paths for Alice from 0 to leaf nodes
            - based on the conditions who reaches first the profit is added
            - a leaf is detected where it's not the root node and has only 1 connection
            - edge case would be having a single node where we split the profit between Alice and Bob
        **/
    
    
        vector<int> bobArrival;
        unordered_map<int, vector<int>> tree;
        int maxProfit = INT_MIN;
    
        void dfsAlice(int node, int parent, int time, int totalProfit, vector<int>& profit) {
            // Compute profit correctly
            if (time < bobArrival[node]) {
                totalProfit += profit[node]; // Full profit
            } else if (time == bobArrival[node]) {
                totalProfit += profit[node] / 2; // Half profit
            }
    
            // Leaf node condition
            if ((node != 0 && tree[node].size() == 1) || tree[node].empty()) {
                maxProfit = max(maxProfit, totalProfit);
                return;
            }
    
            // Recur for children
            for (int child : tree[node]) {
                if (child != parent) {
                    dfsAlice(child, node, time + 1, totalProfit, profit);
                }
            }
        }
    
        int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
            int n = amount.size();
            bobArrival.assign(n, INT_MAX);
    
            // Handle single-node edge case
            if (n == 1) {
                return amount[0] / 2; // Both Alice and Bob are at 0
            }
    
            // Step 1: Build tree from edges
            for (auto& e : edges) {
                tree[e[0]].push_back(e[1]);
                tree[e[1]].push_back(e[0]);
            }
    
            // Step 2: Find Bob's path using BFS and compute arrival times
            vector<int> parent(n, -1);
            queue<int> q;
            q.push(bob);
            parent[bob] = -1;
            bool found = false;
    
            while (!q.empty() && !found) {
                int u = q.front();
                q.pop();
                for (int v : tree[u]) {
                    if (parent[v] == -1 && v != parent[u]) {
                        parent[v] = u;
                        if (v == 0) {
                            found = true;
                            break;
                        }
                        q.push(v);
                    }
                }
            }
    
            // Reconstruct the path from bob to 0
            vector<int> path;
            int current = 0;
            while (current != bob) {
                path.push_back(current);
                current = parent[current];
                if (current == -1) break; // In case of no path, though per problem constraints it exists
            }
            path.push_back(bob);
            reverse(path.begin(), path.end());
    
            // Assign arrival times
            for (int i = 0; i < path.size(); ++i) {
                bobArrival[path[i]] = i;
            }
    
            // Step 3: DFS for Alice
            dfsAlice(0, -1, 0, 0, amount);
    
            return maxProfit;
        }
    
        /**
            Time Complexity: O(n)   as every node and edge is processed exactly once in BFS/DFS
    
            Space Complexity: O(n)   as the tree will have exactly n nodes and the auxilary data structures can atmost be of size n
        **/
    };