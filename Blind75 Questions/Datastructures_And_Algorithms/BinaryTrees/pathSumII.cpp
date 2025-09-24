#include <bits/stdc++.h>

using namespace std;

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
    void pathSumDFS(vector<vector<int>>&soln, TreeNode* root, int targetSum, vector<int>& curr_soln){
        if(!root) return;

        curr_soln.push_back(root->val);

        if ((root->val-targetSum) == 0 && !root->left && !root->right)  soln.push_back(curr_soln);

        /* Go left */
        pathSumDFS(soln, root->left, targetSum-root->val, curr_soln);
        /* Go right */
        pathSumDFS(soln, root->right, targetSum-root->val, curr_soln);

        /* Back track by removing curr node */
        curr_soln.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> soln;
        vector<int> curr;

        pathSumDFS(soln, root, targetSum, curr);
        return soln;
    }
};