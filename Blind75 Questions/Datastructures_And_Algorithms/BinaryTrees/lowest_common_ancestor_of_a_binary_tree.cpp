/**
 * @file lowest_common_ancestor_of_a_binary_tree.cpp
 * @author Valentine Roland
 * @brief Lowest Common Ancestor of a Binary Tree
 * @version 0.1
 * @date 2024-08-13
 * 
 * @copyright Copyright (c) 2024
 * 
 */


#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <set>
#include <sstream>
#include <queue>
#include <stack>
#include <list>
#include <map>
#include <unordered_map>
#include <math.h>

/*
Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”

 

Example 1:

Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
Output: 3
Explanation: The LCA of nodes 5 and 1 is 3.

Example 2:

Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
Output: 5
Explanation: The LCA of nodes 5 and 4 is 5, since a node can be a descendant of itself according to the LCA definition.
Example 3:

Input: root = [1,2], p = 1, q = 2
Output: 1
 
Constraints:

The number of nodes in the tree is in the range [2, 105].
-109 <= Node.val <= 109
All Node.val are unique.
p != q
p and q will exist in the tree.
*/

/**
 * 1. Use a recursive function
 *      If the current node (root) is nullptr, return nullptr because there's no ancestor to be found.
 *      If the current node is either p or q, return root because if one of these nodes is the ancestor of the other, that node is the LCA.
 * 
 * 2. Recursively call the function on the left and right subtrees to search for p and q.
 *      TreeNode* left = lowestCommonAncestor(root->left, p, q);
 *       TreeNode* right = lowestCommonAncestor(root->right, p, q);
 * 
 * 3. Analyze the results of the recursive calls
 *      If both Left and Right are not null, it means that p and q are found in different subtrees of the current node so this root is the LCA
 * 
 * 4. If only left or right is NULL:
 *      Then p and q are found in one subtree so return the non-null result
 * 
 * 5. If both are null, then p and q are not found, so return nullptr
 * 
 * 
 *  Time Complexity: O(N), where N is the number of nodes in the tree. In the worst case, you might have to traverse all nodes.
 *  Space Complexity: O(H), where H is the height of the tree due to the recursive call stack.
 */


//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // Base case
        if (root == nullptr || root == p || root == q) {
            return root;
        }
        
        // Recur on left and right subtree
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        
        // If both left and right are not null, this is the LCA
        if (left != nullptr && right != nullptr) {
            return root;
        }
        
        // Otherwise, return the non-null value, one of them will be null
        return left != nullptr ? left : right;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == nullptr || root == p || root == q)
            return root;

        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        if(left && right) return root; //Both are not null!, so this is root

        return left ? left : right;

    }

};