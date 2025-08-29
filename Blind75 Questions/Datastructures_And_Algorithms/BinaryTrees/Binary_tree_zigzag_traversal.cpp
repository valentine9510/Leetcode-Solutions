#include <bits/stdc++.h>

using namespace std;

/*
103. Binary Tree Zigzag Level Order Traversal
Medium
Topics
premium lock icon
Companies
Given the root of a binary tree, return the zigzag level order traversal of its nodes' values. (i.e., from left to right, then right to left for the next level and alternate between).

 

Example 1:


Input: root = [3,9,20,null,null,15,7]
Output: [[3],[20,9],[15,7]]
Example 2:

Input: root = [1]
Output: [[1]]
Example 3:

Input: root = []
Output: []
*/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};



class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> answer;
        queue<pair<TreeNode *, int>> tree_queue; // Node, level

        if(root)
            tree_queue.push({root, 0});

        while (!tree_queue.empty()) {
            TreeNode *curr = tree_queue.front().first;
            int curr_level = tree_queue.front().second;
            tree_queue.pop();  // ✅ Fix: Remove the node from the queue

            if(curr_level >= answer.size()) {
                answer.push_back({});
            }

            if(curr_level % 2 == 0) {
                answer[curr_level].push_back(curr->val);  // left to right
            } else {
                answer[curr_level].insert(answer[curr_level].begin(), curr->val);  // right to left
            }

            if(curr->left)
                tree_queue.push({curr->left, curr_level + 1});
            if(curr->right)
                tree_queue.push({curr->right, curr_level + 1});
        }

        return answer;
    }
};









class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> answer;
        if(!root) return {};

        queue<pair<TreeNode*, int>> queue; /* Track node and level */
        queue.push(std::make_pair(root, 0));

        while (!queue.empty())
        {
            TreeNode* curr_node = queue.front().first;
            int curr_level = queue.front().second;

            if(answer.size() < curr_level+1) answer.push_back({}); //add a new level

            if(curr_level %2 == 0) {
                answer[curr_level].push_back(curr_node->val); //Push back
            } else {
                answer[curr_level].insert(answer[curr_level].begin(), curr_node->val); //Push front
            }

            //Push children
            if(curr_node->left) queue.push(make_pair(curr_node->left, curr_level+1));
            if(curr_node->right) queue.push(make_pair(curr_node->right, curr_level+1));
        }

        return ans;
        
    }
};


