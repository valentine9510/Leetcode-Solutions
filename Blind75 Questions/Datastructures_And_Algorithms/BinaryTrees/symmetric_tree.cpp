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
/*
    A) Recursive mirror check (primary)

    What’s being tested: recursion + understanding of mirror property.
    Idea: Two trees are mirrors iff:
    Both null → true
    One null → false
    left->val == right->val and isMirror(left->left, right->right) and isMirror(left->right, right->left)
*/

// Time: O(n), Space: O(h) recursion stack
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        return isMirror(root->left, root->right);
    }
private:
    bool isMirror(TreeNode* a, TreeNode* b) {
        if (!a && !b) return true;
        if (!a || !b) return false;
        if (a->val != b->val) return false;
        return isMirror(a->left, b->right) && isMirror(a->right, b->left);
    }
};
