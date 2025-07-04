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

// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };

using namespace std;

struct BST_Node
{
    int val;
    BST_Node * left;
    BST_Node * right;

    BST_Node(): BST_Node{0, nullptr, nullptr} {}
    BST_Node(int x): BST_Node{x, nullptr, nullptr} {}
    BST_Node(int x, BST_Node* left, BST_Node* right): val(x), left(left), right(right) {}
};

/**
 * @brief Return longest path to a leaf node
 * 
 */
int longestPathToLeaf(BST_Node* root, int& diameter){
    if (root == NULL) return 0;

    int leftHeight = longestPathToLeaf(root->left, diameter);
    int rightHeight = longestPathToLeaf(root->right, diameter);

    int localDiameter = leftHeight + rightHeight;

    diameter = max(diameter, localDiameter);
    
    return 1 + max(leftHeight, rightHeight);
}

/**
 * @brief Base case
 * Node has not root -> diameter is 0
 * Node has one root -> return maxDiameter of root
 * Node has two roots -> maxOf( 2 + longestpathToLeafOnLeft + OnRight, diameter of right, diameter of left )
 * 
 */
int diameterOfBinaryTree(BST_Node* root) {
    int diameter = 0;
    longestPathToLeaf(root, diameter);
    return diameter;

}