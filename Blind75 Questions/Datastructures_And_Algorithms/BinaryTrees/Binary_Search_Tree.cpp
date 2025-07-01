/**
 * @file Binary_Search_Tree.cpp
 * @author Valentine Ssebuyungo
 * @brief  All about Binary Search Trees
 * @version 0.1
 * @date 2023-11-30
 * 
 * @copyright Copyright (c) 2023
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


//Insert into binary tree
BST_Node *insert_BST(BST_Node* root, int value);
//BFS
void bst_bfs_print(BST_Node * root);
//DFS
void bst_dfs_print(BST_Node * root);
//Find a node in BST
bool find_value_in_bst (BST_Node* root, int value);
//Delete a node in a BST
BST_Node* find_maximum_value_bst(BST_Node* root);
BST_Node* find_minimum_value_bst(BST_Node* root);
BST_Node* delete_node_in_bst(BST_Node* root, int value);
//Check if a tree is a BST
bool is_binary_search_tree(BST_Node* root);
//Find the height of a BST
//Is Binary Tree Balanced
int findBSTHeight(BST_Node* root);
bool isBalanced(BST_Node* root);
//Find Lowest Common Ancestor of BST
//Find Diameter of BST
int longestPathToLeaf(BST_Node* root);
int diameterOfBinaryTree(BST_Node* root);


// int main (){
//     cout << "testing" << endl;
//     BST_Node* temp = insert_BST(NULL, 5);
//     temp = insert_BST(temp, 3);
//     insert_BST(temp, 7);
//     insert_BST(temp, 2);
//     insert_BST(temp, 4);
//     insert_BST(temp, 6);
//     insert_BST(temp, 8);

//     std::cout << "Is the tree a BST? " << (is_binary_search_tree(temp) ? "Yes" : "No") << std::endl;

//     bst_bfs_print(temp);

//     cout << endl << "Deleting 6" << endl;
//     temp = delete_node_in_bst(temp, 6);
//     bst_bfs_print(temp);

//     cout << endl << "Deleting 3" << endl;
//     temp = delete_node_in_bst(temp, 3);
//     bst_bfs_print(temp);

//     cout << endl << "Deleting 7" << endl;
//     temp = delete_node_in_bst(temp, 7);
//     bst_bfs_print(temp);

//     return 0;
// }

/**
 * @brief Insert Values into a BST
 * 
 * @param root 
 * @param value 
 * @return BST_Node* 
 */
BST_Node *insert_BST(BST_Node* root, int value){
    if(root == NULL){
        root = new BST_Node(value, NULL, NULL);
        return root;
    }

    if(value <= root->val){ //insert left
        root->left = insert_BST(root->left, value);       
    } else { //insert right
        root->right = insert_BST(root->right, value); 
    }

    return root;
}

/**
 * @brief Find values in a BST
 * 
 * @param root 
 * @param value 
 * @return true 
 * @return false 
 */
bool find_value_in_bst (BST_Node* root, int value){
    if(root == NULL) return false;
    if(root->val == value) return true;

    if(root->val < value) return find_value_in_bst(root->left, value);
    else return find_value_in_bst(root->right, value);

    return false;
}

/**
 * @brief Use Breadth First Search to print out a BST
 * 
 * @param root 
 */
void bst_bfs_print(BST_Node * root){
    if(root == NULL) return;

    queue<BST_Node *> nodesQueue;
    int level = 0;
    nodesQueue.push(root);

    while (!nodesQueue.empty()) {
        int levelLength = nodesQueue.size();
        std::cout << "Level " << level << ": ";
        for (int i = 0; i < levelLength; ++i) {
            BST_Node* node = nodesQueue.front();
            nodesQueue.pop();

            // Print the node value
            std::cout << node->val << " ";

            // Add child nodes in the queue
            if (node->left) nodesQueue.push(node->left);
            if (node->right) nodesQueue.push(node->right);
        }
        std::cout << std::endl;
        level++;
    }
    
}

/**
 * @brief Use Depth First Search to print out a BST
 * 
 * @param root 
 */
void bst_dfs_print(BST_Node * root){
    if(root == NULL) return;

    cout << root->val << "->";

    bst_dfs_print(root->left);
    bst_dfs_print(root->right);
    
}

/**
 * @brief Delete a node in a BST
 * 
 * Three cases
 * No child
 * One child
 * 2 Children
 * 
 * @param root 
 * @param value 
 */
BST_Node* delete_node_in_bst(BST_Node* root, int value){
    if(root == NULL) return NULL;
    else if(value < root->val){ //go left
        root->left = delete_node_in_bst(root->left, value);
    } else if (value > root->val){
        root->right = delete_node_in_bst(root->right, value);
    } else {
        //handle deletion as we have found it
        //Case 1 : No Children
        if(root->left == NULL && root->right == NULL){
            delete root; //free memory
            root = NULL;
        } else if (root->left == NULL) { //Case 2 : One Children, Only Right
            BST_Node* temp = root;
            root = root->right;
            delete temp;

        } else if (root->right == NULL) { //Case 2 : One Children, Only Left

            BST_Node* temp = root;
            root = root->left;
            delete temp;
            
        } else { //Case 3 : 2 Children

            //Find minimum node in right child
            BST_Node* mintemp = find_minimum_value_bst(root->right);

            //replace that node with this one
            root->val = mintemp->val;

            //delete the other node
            root->right = delete_node_in_bst(root->right, mintemp->val);

        }  
    }

    return root;
}

/**
 * @brief Find maximum value in BST
 * 
 * @param root 
 * @return BST_Node* 
 */
BST_Node* find_maximum_value_bst(BST_Node* root){
    if(root == NULL) return root;

    BST_Node* temp = root;
    while (temp->right != NULL)
    {
        temp = temp->right;
    }
    
    return temp;
}

/**
 * @brief Find minimum value in BST
 * 
 * @param root 
 * @return BST_Node* 
 */
BST_Node* find_minimum_value_bst(BST_Node* root){
    if(root == NULL) return root;

    BST_Node* temp = root;
    while (temp->left != NULL)
    {
        temp = temp->left;
    }
    
    return temp;
}

bool IsSubtreeLesser(BST_Node* root, int value){
    if(root == NULL) return true; 
    return ((root->val <= value) && IsSubtreeLesser(root->left, value) && IsSubtreeLesser(root->right, value));
}

bool IsSubtreeGreater(BST_Node* root, int value){
    if(root == NULL) return true; 
    return ((root->val > value) && IsSubtreeGreater(root->left, value) && IsSubtreeGreater(root->right, value)); 
}

/**
 * @brief Check if a tree is BST
 * Time complexity of your implementation is n^2;
 * @param root 
 * @return true 
 * @return false 
 */
bool is_binary_search_tree(BST_Node* root){
    if(root == NULL) return true;
    return((IsSubtreeLesser(root->left, root->val))&&(IsSubtreeGreater(root->right, root->val))&&(is_binary_search_tree(root->right))&&(is_binary_search_tree(root->left)));
}

/**
 * @brief Find BST Height
 * 
 * @param root 
 * @return int 
 */
int findBSTHeight(BST_Node* root){
    if(root == NULL) return 0;

    int leftHeight = findBSTHeight(root->left);
    int rightHeight = findBSTHeight(root->right);

    if(leftHeight == -1 || rightHeight == -1 || (abs(leftHeight - rightHeight)>1)){
        return -1; //unequal
    }

    return 1 + max(leftHeight, rightHeight);
}

/**
 * @brief Get the simple height of a BST
 * The height of a tree is the number of edges on the longest path from root to leaf.
 * An empty tree has height -1, a tree with just a root has height 0.
 * 
 * @param root The root node of the tree
 * @return int The height of the BST
 */
int getTreeHeight(BST_Node* root) {
    // Base case: empty tree has height -1
    if(root == NULL) return -1;
    
    // Recursively find the height of left and right subtrees
    int leftHeight = getTreeHeight(root->left);
    int rightHeight = getTreeHeight(root->right);
    
    // The height is 1 + the maximum of left and right subtree heights
    return 1 + max(leftHeight, rightHeight);
}

/**
 * @brief Find height of left and height of right
 * Difference should be less than one
 * 
 * @param root 
 * @return true 
 * @return false 
 */
bool isBalanced(BST_Node* root) {
    if(root == NULL) return true;
    return (findBSTHeight(root) != -1 );
}


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

/**
 * @brief Find the lowest Common Ancestor of a binary search tree
 * 
 * @param root 
 * @param p 
 * @param q 
 * @return TreeNode* 
 */
BST_Node* lowestCommonAncestor(BST_Node* root, BST_Node* p, BST_Node* q) {
    int small = min(p->val, q->val);
    int large = max(p->val, q->val);
    while (root != nullptr) {
        if (root->val > large) // p, q belong to the left subtree
            root = root->left;
        else if (root->val < small) // p, q belong to the right subtree
            root = root->right;
        else // Now, small <= root.val <= large -> This root is the LCA between p and q
            return root;
    }
    return nullptr;
}

BST_Node* lowestCommonAncestor(BST_Node* root, BST_Node* p, BST_Node* q) {
    // Base case: if root is null, return null
    if (root == nullptr) return nullptr;

    // If both p and q are greater than root, LCA must be in the right subtree
    if (p->val > root->val && q->val > root->val)
        return lowestCommonAncestor(root->right, p, q);

    // If both p and q are less than root, LCA must be in the left subtree
    if (p->val < root->val && q->val < root->val)
        return lowestCommonAncestor(root->left, p, q);

    // If one node is on the left and the other is on the right, root is the LCA
    return root;
}

/**
 * @brief Plan
 * 1. Base case root == null, return root \n
 * 2. swap left and right subtree \n
 * 3. invert right \n
 * 4. invert left \n
 * 5. return root \n
 */
BST_Node* invertTree(BST_Node* root){
    if(root == NULL) return root;

    BST_Node* temp = root->left;
    root->left = root->right;
    root->right = temp;

    root->left = invertTree(root->left);
    root->right = invertTree(root->right);
    
    return root;
}

/**
 * @brief Plan
 * Recursion
 * 1+ max(rightSub, leftSub);
 * 
 * Base case : if (root == NULL) return 0;
 */
int maxDepth(BST_Node* root){
    if(root == NULL) return 0;
    return 1 + std::max(maxDepth(root->left), maxDepth(root->right));
}




