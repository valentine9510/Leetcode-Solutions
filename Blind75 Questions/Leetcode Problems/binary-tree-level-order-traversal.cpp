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
};

int main(){
    
    return 0;
}
