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
    void explore(TreeNode* root, long long currSum, long long targetSum, int &ways) {
        if (!root) return;

        currSum += root->val;
        if (currSum == targetSum) ways++;

        explore(root->left, currSum, targetSum, ways);
        explore(root->right, currSum, targetSum, ways);
    }

    int pathSum(TreeNode* root, int targetSum) {
        if (!root) return 0;

        int answer = 0;

        // Start a new path from this node
        explore(root, 0, targetSum, answer);

        // Try starting paths from the left and right children
        answer += pathSum(root->left, targetSum);
        answer += pathSum(root->right, targetSum);

        return answer;
    }
};
