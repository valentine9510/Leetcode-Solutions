#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root == nullptr) return root;

        TreeNode* temp = root->right;

        root->right = invertTree(root->left);
        root->left = invertTree(temp);

        return root;
    }
};