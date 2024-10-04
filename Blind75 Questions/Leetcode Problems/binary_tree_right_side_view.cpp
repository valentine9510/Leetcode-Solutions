/**
 * @file binary_tree_right_side_view.cpp
 * @author Valentine Roland
 * @brief 
 * @version 0.1
 * @date 2024-08-17
 * 
 * @copyright Copyright (c) 2024
 * 
 */

/*
Given the root of a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

 

Example 1:


Input: root = [1,2,3,null,5,null,4]
Output: [1,3,4]
Example 2:

Input: root = [1,null,3]
Output: [1,3]
Example 3:

Input: root = []
Output: []
 

Constraints:

The number of nodes in the tree is in the range [0, 100].
-100 <= Node.val <= 100
*/

#include <bits/stdc++.h>
using namespace std;

//  Definition for a binary tree node.
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

/*
    Have a vector for levels

    Do a BFS on the Tree and keep updating the numbers on the level
*/
class Solution {
public:
    vector<int> rightSideView_bfs(TreeNode* root) {
        queue<pair<TreeNode*, int>> tree_queue; //node : level
        vector<int> result;

        if(root == NULL) return {};

        tree_queue.push(std::make_pair(root,0));

        while (tree_queue.empty() == false)
        {
            TreeNode* node = tree_queue.front().first;
            int level = tree_queue.front().second;
            tree_queue.pop();

            if(result.size() < (level+1)) result.push_back(node->val); //first time on this level
            else result[level] = node->val; //replace node at level, the last node we see here is the truth

            //Add children to queue
            if(node->left != NULL) tree_queue.push(std::make_pair(node->left,level+1));
            if(node->right != NULL) tree_queue.push(std::make_pair(node->right,level+1));
        }

        return result;        
    }


    void dfs(TreeNode* root, vector<int>& result, int level){
        if(root == NULL) return;

        //update result
        if(result.size() < (level+1)) result.push_back(root->val); //first time on this level
        else result[level] = node->val; //replace node at level, the last node we see here is the truth

        //go left
        dfs(root->left, result, level+1);

        //go right
        dfs(root->right, result, level+1);

    }

    vector<int> rightSideView_dfs(TreeNode* root) {
        vector<int> result;

        dfs(root, result, 0);

        return result;        
    }
};