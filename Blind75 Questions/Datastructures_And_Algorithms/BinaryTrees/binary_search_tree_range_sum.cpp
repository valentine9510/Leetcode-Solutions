/**
 * @file binary_search_tree_range_sum.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2024-08-21
 * 
 * @copyright Copyright (c) 2024
 * 
 */

/*
    The problem "Range Sum of BST" asks to find the sum of values of all nodes within a given range 
    [L,R] in a Binary Search Tree (BST).

    Problem Breakdown:
    BST Property:

    In a BST, the left child is always smaller than the parent, and the right child is always greater than the parent.
    Approach:

    We can perform a depth-first search (DFS) or breadth-first search (BFS) to traverse the tree.
    Since we only need the sum of nodes in the range 
    [L,R], we can prune the search:
    If the node's value is less than 
    L, there is no need to explore the left subtree.
    If the node's value is greater than 
    R, there is no need to explore the right subtree.
    Otherwise, add the node's value to the sum and continue exploring both subtrees.
*/

#include <iostream>
using namespace std;

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int rangeSumBST(TreeNode* root, int L, int R) {
        if (!root) {
            return 0;  // Base case: if node is NULL
        }
        
        // If node's value is less than L, explore the right subtree
        if (root->val < L) {
            return rangeSumBST(root->right, L, R);
        }
        
        // If node's value is greater than R, explore the left subtree
        if (root->val > R) {
            return rangeSumBST(root->left, L, R);
        }
        
        // If node's value is within [L, R], add its value and explore both subtrees
        return root->val + rangeSumBST(root->left, L, R) + rangeSumBST(root->right, L, R);
    }
};

int main() {
    // Create a sample BST
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(15);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(7);
    root->right->right = new TreeNode(18);

    Solution solution;
    int L = 7, R = 15;
    int result = solution.rangeSumBST(root, L, R);
    cout << "The sum of values in range [" << L << ", " << R << "] is: " << result << endl;

    return 0;
}
