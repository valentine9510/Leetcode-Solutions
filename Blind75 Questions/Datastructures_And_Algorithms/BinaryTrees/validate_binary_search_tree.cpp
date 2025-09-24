#include <bits/stdc++.h>

using namespace std;

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


class Solution {
public:
    // Helper that enforces: low < node->val < high (strict)
    bool dfs(TreeNode* node, long long low, long long high) {
        if (!node) return true; // empty subtree is valid

        // Current node must lie strictly between low and high
        if (!(low < node->val && node->val < high)) return false;

        // Left subtree: allowed range becomes (low, node->val)
        // Right subtree: allowed range becomes (node->val, high)
        return dfs(node->left, low, node->val) &&
               dfs(node->right, node->val, high);
    }

    bool isValidBST(TreeNode* root) {
        // Use wide sentinels to avoid overflow with INT_MIN/INT_MAX.
        // long long ensures comparisons are safe when node->val is int.
        return dfs(root, std::numeric_limits<long long>::min(),
                         std::numeric_limits<long long>::max());
    }
};



class Solution {
    bool isValidBST(TreeNode* root) {
        return dfs(root, std::numeric_limits<long long>::min(), std::numeric_limits<long long>::max());
    }
    bool dfs (TreeNode *node, long long low, long long high){
        if(!node) return true;

        //Value must lie within range left < node < right
        if(!(low < node->val && node->val < high))
            return false;

        return dfs(node->left, low, node->val) && dfs(node->right, node->val, high);
    }
};