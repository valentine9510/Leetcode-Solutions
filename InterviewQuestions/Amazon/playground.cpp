#include <bits/stdc++.h>
#include <cctype>
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

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/**
 * @brief Left <=
 * Base q is in left and p is in right
 * Or q or p == root 
 * 
 * if(p,q aint in left) root = root->right
 * if(p,q aint in right) root = root->left
 * 
 * @param root 
 * @param p 
 * @param q 
 * @return TreeNode* 
 */
bool isValInBST(TreeNode* root, int val){
    if(root == NULL) return false;
    if(root->val == val) return true;

    if(val > root->val) return isValInBST(root->right,val);
    return isValInBST(root->left,val);
}
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if(root == NULL || root->val == p->val || root->val == q->val) return root; //base 1   

    TreeNode* temp = q;
    if(p->val > q->val){ //swap to ensure that p is always the lesser value
        q == p;
        p == temp;
    } 

    bool is_P_in_left = isValInBST(root->left, p->val);
    bool is_Q_in_right = isValInBST(root->right, q->val);
 
    if(is_P_in_left && is_Q_in_right){ //base 2
        return root; //LCA
    }

    //if they are not split, then they must be in either sides
    //left has both p and q
    if(is_P_in_left){
        root = lowestCommonAncestor(root->left,p,q);
    } else {
        root = lowestCommonAncestor(root->right,p,q);
    }

    return root;
}


int main(){

    cout << "Solution " << endl;

    return 0;
}
