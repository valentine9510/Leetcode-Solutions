/**
 * @file binary_search_tree_kth_smallest_element.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2024-08-18
 * 
 * @copyright Copyright (c) 2024
 * 
 */

/*
Given the root of a binary search tree, and an integer k, return the kth smallest value (1-indexed) of all the values of the nodes in the tree.

Example 1:
Input: root = [3,1,4,null,2], k = 1
Output: 1


Example 2:
Input: root = [5,3,6,2,4,null,null,1], k = 3
Output: 3


//In order traversel gives you the solution to this

*/

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
    int kthSmallest(TreeNode* root, int k) {
        int count = 0;
        int result = -1;
        inOrderTraversal(root, k, count, result);
        return result;
    }

private:
    void inOrderTraversal(TreeNode* node, int k, int& count, int& result) {
        if (!node) return;

        // Traverse the left subtree
        inOrderTraversal(node->left, k, count, result);

        // Increment the count of visited nodes
        count++;

        // If count equals k, we've found the kth smallest element
        if (count == k) {
            result = node->val;
            return;
        }

        // Traverse the right subtree
        inOrderTraversal(node->right, k, count, result);
    }
};