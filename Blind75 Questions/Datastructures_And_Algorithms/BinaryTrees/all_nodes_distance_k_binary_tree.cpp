#include <bits/stdc++.h>

using namespace std;

/*
    Given the root of a binary tree, the value of a target node target, and an integer k, return an array of the values of all nodes that have a distance k from the target node.

    You can return the answer in any order.
*/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/*  BFS Solution 

Idea:
Make the tree “undirected” by remembering each node’s parent. Then do a BFS starting at target, expanding to left, right, and parent. The kth BFS layer is your answer.

Why it works:
BFS explores nodes by distance. When you’ve popped k layers, everything currently in the queue is exactly distance k.

Complexity:

Time: O(N) to build parents + BFS.

Space: O(N) for the parent map + visited.
*/


class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if (!root || !target) return {};       // Edge case: empty tree or target is null
        if (k == 0) return {target->val};      // Distance 0 means just the target node itself

        // ----------------------------
        // STEP 1: Build a parent map so we can move "upwards" in the tree
        // ----------------------------
        unordered_map<TreeNode*, TreeNode*> parent;
        buildParents(root, nullptr, parent);   // DFS: record parent of each node

        // ----------------------------
        // STEP 2: BFS from the target node
        // ----------------------------
        queue<TreeNode*> q;                    // Queue for level-order traversal
        unordered_set<TreeNode*> visited;      // Prevent revisiting nodes (avoid cycles)

        q.push(target);
        visited.insert(target);

        int dist = 0;                          // Current BFS level (distance from target)

        while (!q.empty()) {
            int sz = q.size();                 // Number of nodes at this BFS layer

            if (dist == k) {
                // ----------------------------
                // STEP 3: If we've reached distance k,
                // all nodes currently in the queue are exactly distance k away
                // ----------------------------
                vector<int> ans;
                ans.reserve(sz);
                while (sz--) {
                    ans.push_back(q.front()->val);
                    q.pop();
                }
                return ans; // Done!
            }

            // ----------------------------
            // STEP 4: Expand neighbors (children + parent) for next layer
            // ----------------------------
            while (sz--) {
                TreeNode* cur = q.front(); q.pop();

                // Left child
                if (cur->left && !visited.count(cur->left)) {
                    visited.insert(cur->left);
                    q.push(cur->left);
                }
                // Right child
                if (cur->right && !visited.count(cur->right)) {
                    visited.insert(cur->right);
                    q.push(cur->right);
                }
                // Parent
                if (parent[cur] && !visited.count(parent[cur])) {
                    visited.insert(parent[cur]);
                    q.push(parent[cur]);
                }
            }
            ++dist; // Finished one BFS layer, increase distance
        }

        // If we exhaust the tree without reaching distance k
        return {};
    }

private:
    // Helper: Record parent pointers with DFS
    void buildParents(TreeNode* node, TreeNode* par,
                      unordered_map<TreeNode*, TreeNode*>& parent) {
        if (!node) return;
        parent[node] = par;                    // Link this node to its parent
        buildParents(node->left, node, parent);
        buildParents(node->right, node, parent);
    }
};


class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> ans;
        dfs(root, target, k, ans);  // Run DFS to search for target and collect results
        return ans;
    }

private:
    // -------------------------------------------------
    // Helper 1: Collect all nodes at distance `d` below a given node
    // -------------------------------------------------
    void collectDown(TreeNode* node, int d, vector<int>& ans) {
        if (!node || d < 0) return;             // Base case: null node or overshot depth
        if (d == 0) {                           // If we reached exactly distance `d`
            ans.push_back(node->val);           // Record this node’s value
            return;
        }
        // Recurse into children, decreasing distance
        collectDown(node->left, d - 1, ans);
        collectDown(node->right, d - 1, ans);
    }

    // -------------------------------------------------
    // Helper 2: DFS to find the target and calculate distances
    //
    // Returns:
    //   - distance from current node to target if found
    //   - -1 if target not found in this subtree
    // -------------------------------------------------
    int dfs(TreeNode* node, TreeNode* target, int k, vector<int>& ans) {
        if (!node) return -1;                   // Reached null -> not found
        if (node == target) {
            // Case 1: Found the target
            // Collect all nodes in its subtree at depth k
            collectDown(node, k, ans);
            return 0;                           // Distance(target, target) = 0
        }

        // Case 2: Look for target in left subtree
        int L = dfs(node->left, target, k, ans);
        if (L != -1) {
            // Target found in left subtree at distance L
            if (L + 1 == k) {
                // Current node itself is distance k
                ans.push_back(node->val);
            } else {
                // Otherwise, need to collect nodes from right subtree
                // that are k - (L+2) down (one step up + one step down)
                collectDown(node->right, k - (L + 2), ans);
            }
            return L + 1; // Distance from current node to target
        }

        // Case 3: Look for target in right subtree
        int R = dfs(node->right, target, k, ans);
        if (R != -1) {
            // Target found in right subtree at distance R
            if (R + 1 == k) {
                ans.push_back(node->val);
            } else {
                collectDown(node->left, k - (R + 2), ans);
            }
            return R + 1;
        }

        // Case 4: Target not in this subtree
        return -1;
    }
};
