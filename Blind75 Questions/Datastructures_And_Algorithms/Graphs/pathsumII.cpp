#include <bits/stdc++.h>

using namespace std;


/*
113. Path Sum II
Solved
Medium
Topics
Companies
Given the root of a binary tree and an integer targetSum, return all root-to-leaf paths where the sum of the node values in the path equals targetSum. Each path should be returned as a list of the node values, not node references.

A root-to-leaf path is a path starting from the root and ending at any leaf node. A leaf is a node with no children.

Example 1:


Input: root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
Output: [[5,4,11,2],[5,8,4,5]]
Explanation: There are two paths whose sum equals targetSum:
5 + 4 + 11 + 2 = 22
5 + 8 + 4 + 5 = 22
Example 2:


Input: root = [1,2,3], targetSum = 5
Output: []
Example 3:

Input: root = [1,2], targetSum = 0
Output: []
 

Constraints:

The number of nodes in the tree is in the range [0, 5000].
-1000 <= Node.val <= 1000
-1000 <= targetSum <= 1000
*/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/*
    Have a helper

    if(target == 0) add current vector onto the list
    if(target < 0) just return

    try the vectors onto the other paths
*/
class Solution {
public:
    void pathSumHelper(TreeNode* root, int targetSum, vector<int>& curr_vec, vector<vector<int>>& result) {
        // Base case
        if (!root) return;

        // Update current path and subtract node value from targetSum
        curr_vec.push_back(root->val);
        targetSum -= root->val;

        // Check if it's a leaf and targetSum is exactly 0
        if (targetSum == 0 && !root->left && !root->right) {
            result.push_back(curr_vec);
        }

        // Recur for left and right subtrees
        pathSumHelper(root->left, targetSum, curr_vec, result);
        pathSumHelper(root->right, targetSum, curr_vec, result);

        // Backtrack by removing the last node
        curr_vec.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> result;
        vector<int> curr_vec;

        pathSumHelper(root, targetSum, curr_vec, result);

        return result;
    }
};
