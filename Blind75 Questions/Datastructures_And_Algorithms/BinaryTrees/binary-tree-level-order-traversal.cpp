#include <bits/stdc++.h>
#include <cctype>
#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
#include <sstream>
#include <queue>
#include <stack>
#include <list>
#include <map>
#include <unordered_map>
#include <math.h>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    //Have a 2D array
        //row is the depth
        //columns are the values
            //we have to go left first then right to make sure it is in order
public:
    void levelOrderHelper(TreeNode* root, vector<vector<int>> &soln, int depth = 0){
        if(root == NULL) return;

        while (soln.size() < depth+1){
            //While size is less than depth
            //add empty arrays
            soln.push_back({});
        }

        //add our value
        soln.at(depth).push_back(root->val);

        //go left and then go right
        levelOrderHelper(root->left, soln, depth+1);
        //go right
        levelOrderHelper(root->right, soln, depth+1);
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> soln;
        levelOrderHelper(root, soln, 0);   

        return soln;     
    }

    vector<vector<int>> levelOrder2(TreeNode* root) {
        vector<vector<int>> soln;

        if(root == NULL) return soln;

        queue<pair<TreeNode*, int>> level_queue;
        level_queue.push({root,0});

        while (level_queue.empty() == false)
        {
            TreeNode * curr_node = level_queue.front().first;
            int curr_level = level_queue.front().second;

            //remove element from queue
            level_queue.pop();

            //Add nodes to solution
            if(soln.size() < (curr_level+1)){
                soln.push_back({curr_node->val}); //Add new node if the solution has not seen this level before
            } else {
                soln.at(curr_level).push_back(curr_node->val);
            }

            //Add children to queue
            if(curr_node->left != NULL) level_queue.push({curr_node->left, curr_level+1});
            if(curr_node->right != NULL) level_queue.push({curr_node->right, curr_level+1});
        }

        return soln;     
    }
};

int main(){
    
    return 0;
}
