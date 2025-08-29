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
Time complexity

Worst case (skewed tree): O(n²)
For each node you run explore over (almost) its entire subtree. Summing subtree sizes over all nodes is Θ(n²) in a chain-like tree.

Balanced tree (roughly): O(n log n)
The sum of subtree sizes (equivalently, sum of node depths over all nodes) is Θ(n log n) in a balanced binary tree.

Intuition: pathSum starts an explore from every node; each explore walks that node’s subtree once.

Space complexity: O(h), where h is the height of the tree
Max call stack depth is bounded by the tree height (you have one pathSum frame plus up to h explore frames at a time, which is still Θ(h)). That’s O(n) in the worst case, O(log n) if balanced.

If you need linear time, switch to the prefix-sum hashmap method, which is O(n) time and O(n) space.
*/
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


// LeetCode 437: Path Sum III
// Idea: Use prefix sums. If prefix_sum(u) - prefix_sum(v) == target, then the path (v->...->u) sums to target.
// Maintain a hashmap `freq` that counts how many times each prefix sum has appeared on the path from root to current node.

class Solution {
public:
    int pathSum(TreeNode* root, int targetSum) {
        // freq[p] = how many prefixes with sum == p we've seen along the current DFS path
        // Initialize with freq[0] = 1 to count paths that start at the root and sum exactly to target
        unordered_map<long long, int> freq;
        freq[0] = 1;

        // Start DFS with current prefix sum = 0
        return dfs(root, 0LL, (long long)targetSum, freq);
    }

private:
    int dfs(TreeNode* node,
            long long currPrefix,                 // prefix sum up to the parent
            long long target,                     // target sum (64-bit to avoid overflow)
            unordered_map<long long, int>& freq)  // hashmap of prefix-sum frequencies on the path
    {
        // Base case: empty subtree contributes 0 paths
        if (!node) return 0;

        // 1) Update the running prefix sum to include this node's value
        currPrefix += (long long)node->val;

        // 2) Count the number of previous prefixes that would make a path ending here sum to target.
        //    We need: currPrefix - prevPrefix == target  => prevPrefix == currPrefix - target
        int pathsEndingHere = 0;
        auto it = freq.find(currPrefix - target);
        if (it != freq.end()) {
            pathsEndingHere = it->second; // all those previous prefixes create valid paths ending at `node`
        }

        // 3) Add the current prefix sum to the map BEFORE exploring children,
        //    so that child paths can use it as a "previous prefix".
        freq[currPrefix]++;

        // 4) Recurse to children; accumulate total number of valid paths in the subtree
        int total = pathsEndingHere
                  + dfs(node->left,  currPrefix, target, freq)
                  + dfs(node->right, currPrefix, target, freq);

        // 5) Backtrack: remove this node's prefix sum from the map.
        //    This keeps `freq` representing only the path currently on the call stack.
        if (--freq[currPrefix] == 0) {
            freq.erase(currPrefix); // optional cleanup to keep the map small
        }

        // 6) Return total paths found in this subtree
        return total;
    }
};
