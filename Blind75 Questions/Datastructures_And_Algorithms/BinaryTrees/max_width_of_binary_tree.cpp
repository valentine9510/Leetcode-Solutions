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




class Solution {
public:
    struct BFS_node {
        struct TreeNode* node;
        unsigned int level;
        unsigned int index;
    };
    int widthOfBinaryTree(TreeNode* root) {
        queue<BFS_node> nodes;
        unsigned int min = UINT_MAX; 
        unsigned int max = 0;
        int curr_level;
        unsigned int max_diameter = 0;

        if(!root)
            return 0;

        nodes.push({root,0,0});
        curr_level = 0;

        while (!nodes.empty())
        {
            BFS_node curr_node = nodes.front();
            nodes.pop();

            if(curr_node.level > curr_level){
                curr_level = curr_node.level;
                min = UINT_MAX; //reset indices
                max = 0; //reset indices
            } 
            
            
            //update diameters
            min = std::min(min,curr_node.index);
            max = std::max(max,curr_node.index);
            max_diameter = std::max(max_diameter, (max-min)+1);

            //push nodes
            if(curr_node.node->left) 
                nodes.push({curr_node.node->left, curr_node.level+1, curr_node.index*2+1});
            if(curr_node.node->right) 
                nodes.push({curr_node.node->right, curr_node.level+1, curr_node.index*2+2});
        }

        return max_diameter;
        
    }
};

// LeetCode 662: Maximum Width of Binary Tree
// BFS level-order with per-level index normalization to prevent overflow.

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(): val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *l, TreeNode *r): val(x), left(l), right(r) {}
};

class Solution {
public:
    long long widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;

        // Queue holds pairs of (node pointer, index in a complete-tree layout).
        // Use 64-bit to be safe with multiplication.
        queue<pair<TreeNode*, unsigned long long>> q;
        q.push({root, 0ULL});
        unsigned long long maxWidth = 0;

        while (!q.empty()) {
            int levelSize = (int)q.size();
            // The first index at this level (for normalization).
            unsigned long long base = q.front().second;

            // Track first and last normalized indices at this level.
            unsigned long long first = 0, last = 0;

            for (int i = 0; i < levelSize; ++i) {
                auto [node, idx] = q.front(); q.pop();
                // Normalize to prevent growth: make the first index 0.
                unsigned long long cur = idx - base;
                if (i == 0) first = cur;
                if (i == levelSize - 1) last = cur;

                // Push children with complete-tree indices derived from 'cur'
                if (node->left)  q.push({node->left,  2ULL * cur + 1});
                if (node->right) q.push({node->right, 2ULL * cur + 2});
            }

            // Width for this level
            maxWidth = max(maxWidth, last - first + 1);
        }

        return (long long)maxWidth;
    }
};

