/**
 * @file binary_tree_from_preorder_and_inorder.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2024-08-17
 * 
 * @copyright Copyright (c) 2024
 * 
 */

/*
Construct Binary Tree from Preorder and Inorder Traversal
Medium
Topics
Companies
Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree and inorder is the inorder traversal of the same tree, construct and return the binary tree.

 

Example 1:


Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
Output: [3,9,20,null,null,15,7]
Example 2:

Input: preorder = [-1], inorder = [-1]
Output: [-1]

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

/*
    We are given pre-order so we visite in pre-order fashion

    We use in-order to see the validity of our roots
 */
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> inorder_map;  // Map to store inorder values and their indices
        for (int i = 0; i < inorder.size(); ++i) {
            inorder_map[inorder[i]] = i;
        }
        int preorder_index = 0;
        return buildTreeHelper(preorder, inorder, inorder_map, preorder_index, 0, inorder.size() - 1);
    }

private:
    TreeNode* buildTreeHelper(vector<int>& preorder, vector<int>& inorder, unordered_map<int, int>& inorder_map,
                              int& preorder_index, int inorder_start, int inorder_end) {
        // Base case: if there are no elements to construct the tree
        if (inorder_start > inorder_end) {
            return nullptr;
        }

        // The current root's value is at preorder_index in the preorder list
        int root_val = preorder[preorder_index];
        TreeNode* root = new TreeNode(root_val);

        // Increment preorder_index for the next recursive call, must be passed by reference because we want all calls to update it!
        preorder_index++;

        // Recursively build the left and right subtrees

        int inorder_index = inorder_map[root_val]; //Get inorder index

        //All elements on the left must be before inorder, so their max index is inorder-1
        root->left = buildTreeHelper(preorder, inorder, inorder_map, preorder_index, inorder_start, inorder_index - 1); 

        // All elements on the right must be before after, so their min index is inorder-1
        root->right = buildTreeHelper(preorder, inorder, inorder_map, preorder_index, inorder_index + 1, inorder_end); 

        return root;
    }
};



















































class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        //create inorder map : value->index
        unordered_map<int,int> inorder_map;
        for(int i = 0; i < inorder.size(); i++){
            inorder_map[inorder[i]] = i;
        }

        //call helper
        return buildTreeHelper(preorder, inorder, inorder_map, 0, 0, inorder.size()-1);
    }

private:
    TreeNode* buildTreeHelper(vector<int>& preorder, vector<int>& inorder, unordered_map<int,int>& inorder_map, int preOrder_index, int inorder_start, int inorder_end){
        if(inorder_start > inorder_end) return nullptr; //we can't add to this

        //We visit in order
        TreeNode* root = new TreeNode(preorder[preOrder_index]);
        preOrder_index++; //update for next run

        //Get in-orderindex
        int inorder_index = inorder_map[root->val];

        //Go left and right
        root->left = buildTreeHelper(preorder, inorder, inorder_map, preOrder_index, inorder_start, inorder_index-1); //all nodes must be left
        root->right = buildTreeHelper(preorder, inorder, inorder_map, preOrder_index, inorder_index+1, inorder_end); //all nodes must be right

        return root;
    }
};



