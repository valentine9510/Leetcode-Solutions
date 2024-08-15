/**
 * @file product_of_array_except_self.cpp
 * @author Valentine Ssebuyungo
 * @brief  Min Stack
 * @version 0.1
 * @date 2024-08-11
 * 
 * @copyright Copyright (c) 2024
 * 
 */

/*
Definition for a binary tree node.
*/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/**
 * Given the root of a binary tree, determine if it is a valid binary search tree (BST).

    A valid BST is defined as follows:

    The left subtree of a node contains only nodes with keys less than the node's key.
    The right subtree of a node contains only nodes with keys greater than the node's key.
    Both the left and right subtrees must also be binary search trees.
    

    Example 1:


    Input: root = [2,1,3]
    Output: true
    Example 2:


    Input: root = [5,1,4,null,null,3,6]
    Output: false
    Explanation: The root node's value is 5 but its right child's value is 4.
    

    Constraints:

    The number of nodes in the tree is in the range [1, 104].
    -231 <= Node.val <= 231 - 1
 */
 
 /**
  * @brief Plan
  * 
  * Check if all values on the right larger than this value
  * Check if all the values on the left <= value
  * check if left is a bst
  * check if right is a bst
  * 
  * 
  * //Base case : root is NULL
  */
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if(root == nullptr) return true;
        return (isGreater(root->right, root->val) && 
            isLesser(root->left, root->val) && 
            isValidBST(root->left) && 
            isValidBST(root->right));
    }

    /**
     * @brief Are all nodes greater of equal to the value
     */
    bool isGreater(TreeNode* root, int data){
        if(root == nullptr) return true; //base case

        if(root->val <= data) return false; 

        return (isGreater(root->left, data) && isGreater(root->right, data));
    }

    /**
     * @brief Are all nodes lesser of equal to the value
     */
    bool isLesser(TreeNode* root, int data){
        if(root == nullptr) return true; //base case

        if(root->val >= data) return false; 

        return (isLesser(root->left, data) && isLesser(root->right, data));
    }
};