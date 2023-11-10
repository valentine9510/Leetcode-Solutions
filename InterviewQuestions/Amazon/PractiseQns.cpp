/******************************************************************
 * Amazon Challenge Solution
 * main.cpp
 * 
 * 
 * 
 * ***************************************************************/
#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <set>
#include <sstream>
#include <queue>
#include <stack>
#include <list>
#include <map>
#include "PractiseQns.h"

/* 
146. LRU Cache
Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.

Implement the LRUCache class:

LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
int get(int key) Return the value of the key if the key exists, otherwise return -1.
void put(int key, int value) Update the value of the key if the key exists. Otherwise, add the key-value pair to the cache. If the number of keys exceeds the capacity from this operation, evict the least recently used key.
The functions get and put must each run in O(1) average time complexity.
*/
/**
 * @brief Plan
 * Use a deque
 * 
 */
class LRUCache {
private:
    int capacity;
    list<pair<int,int>> currItems;
public:
    LRUCache(int capacity) : capacity{capacity} {
    } 

    int get(int key){
        auto it = find_if(currItems.begin(),currItems.end(),[&key](pair<int,int> x){ return x.first == key;});

        if(it == currItems.end()) return -1;
        int value = it->second;
        //Update as most recently used
        this->put(key,value);
        return value;
    }

    void put(int key, int value){
        //Check if element is in list
        auto it = find_if(currItems.begin(),currItems.end(),[&key](pair<int,int> x){ return x.first == key;});
        //If in list
            //copy element
            //delete current element
            //place object at front
        //If not in list
            //if capacity is full, pop_back, place element at front
            //if capacity is not full, place element at front

        if(it != currItems.end()){
            currItems.erase(it);
        } else {
            if(currItems.size() >= capacity){
                //remove least used
                currItems.pop_back();
            }
        }
        currItems.emplace_front(std::make_pair(key,value));
    }
};

using namespace std;
int main(){
    // BstNode *root = NULL;
    // root = InsertBST(root,15);
    // root = InsertBST(root,10);
    // root = InsertBST(root,20);
    // root = InsertBST(root,25);
    // root = InsertBST(root,8);
    // root = InsertBST(root,12);

    // root = DeleteBstNode(root,10);
    // cout << "LevelOrder : ";
    // LevelOrderTraversal(root);
    // cout << "\n\n";
    // cout << "PreOrder : ";
    // PreOrder(root);
    // cout << "\n\n";
    // cout << "InOrder : ";
    // InOrder(root);
    // cout << "\n\n";
    // cout << "PostOrder : ";
    // PostOrder(root);
    // cout << "\n\n";
    // vector<string> numbers {"", "aaa", "aba", "valentine", "lool", "babad"};
    // for(auto i : numbers){
    //     cout << "String "<< i << " : Longest Palindrome is : " << longestPalindrome3(i) << endl;
    // }

    // vector<int> tests {2,3,6,7};
    // auto temp = combinationSum(tests,7);
    // for(auto i : temp){
    //     for(auto j : i) cout << j << " ";
    //     cout << endl;
    // }
    vector<vector<char>> board = {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
    vector<vector<char>> board2 = {{'A','B'}};
    cout <<  boolalpha << wordSearch(board2,"BA");


    

    
    return 0;
}

/**
 * @brief Plan
 * 
 * Have a deque
 *      Loop through the nums array
 *          maxLen = max(maxLen, dequeLen);
 *          while(object < dequeBack){
 *                  popBack;
 *           }
 *          pushback object;
 */
int lengthOfLIS(vector<int>& nums){
    int maxLength = 0;
    deque<int> tempDeque;

    for(auto i = 0; i < nums.size(); i++){
        while(tempDeque.size() > 0 && nums[i] <= tempDeque.back() && nums[i] > tempDeque.front()){
            tempDeque.pop_back();
        }
        tempDeque.push_back(nums[i]);
        maxLength = std::max(tempDeque.size(), maxLength);
    }

    return maxLength;
}

/* Plan go through nums and add to zero, one and two 
start at 0 and start filling it in again while reducing numbers

*/
void sortColors(vector<int>& nums){
    int zero = 0;
    int one = 0;
    int two = 0;

    for(int i = 0; i < nums.size(); i++)
    {
        if(nums[i] == 0)
            zero++;

        else if(nums[i] == 1)
            one++;

        else if(nums[i] == 2)
            two++;
    }

    int k = 0;

    while(zero--){
        nums[k] = 0;
        k++;
    }

    while(one--){
        nums[k] = 1;
        k++;
    }

    while(two--){
        nums[k] = 2;
        k++;
    }
}

/**
 * @brief WordLadder
 * 
 * Plan
 * Find end word
 *  if not found, return -1;
 *  if found
 *      Go back, step by step find the word with the least difference, count the steps
 *          if you reach the beginning break;
 * 
 */
int ladderLength(string beginWord, string endWord, vector<string>& wordList){

}

/**
 * @brief Word search plan 
 * I plan to use recursion
 * So keep a  grid of visitedCells
 * Word search helper
 *  Base cases : if outofbounds return false
 *              If input string length is 0, return true;
 *              if visited return false;
 *              if current cell value is not the next char in string return false;
 * 
 *  if it the next one;
 *  mark visited
 *  //Go left, Go down, Go right, Go left
 * //return OR of all directions
 */

bool wordSearchHelper(int row, int col, vector<vector<char>>& board, vector<vector<bool>> visitedBoard , string word){
    if(word.size() == 0) return true;
    if(row < 0 || row >= board.size() || col < 0 || col >= board.at(row).size()) return false;
    if(visitedBoard.at(row).at(col) == true) return false;

    if(board.at(row).at(col) != word.at(0)){
        return false;
    }

    //Pop off the first character in the word
    word.erase(word.begin());
    //Mark visited
    visitedBoard.at(row).at(col) = true;

    bool up = wordSearchHelper(row+1,col,board,visitedBoard,word);
    bool down = wordSearchHelper(row-1,col,board,visitedBoard,word);
    bool left = wordSearchHelper(row,col-1,board,visitedBoard,word);
    bool right = wordSearchHelper(row,col+1,board,visitedBoard,word);

    return (left || right || up || down );
}

bool wordSearch(vector<vector<char>>& board, string word){
    if(board.size() == 0) return false;

    vector<vector<bool>> visitedBoard (board.size(), vector<bool> (board.at(0).size(), false));

    for (size_t i = 0; i < board.size(); i++) //If you wanna backtrack, you need to go through all positions
    {
        for(auto j = 0; j < board.at(i).size(); j++){
            if(board.at(i).at(j) == word.at(0) && wordSearchHelper(i,j,board,visitedBoard,word)) return true;
              
        }
    }
    

    return false;

}


/**
 * @brief Plan
 * While true :
 *      for each index :
 *          check if another index can merge :
 *              //If end1 >= start2 && end2 >= end1, merge;  merge beginning is min of both, end is max of ends, erase both from vector, readjust sizes
 *      if not merges found, break;
 * 
 * If overlapping merge both
 * flag the one to be removed, 
 * or remove it and update size
 *
 */
vector<vector<int>> mergeIntervals(vector<vector<int>>& intervals){

    while(true){
        bool merge = false;
        for (auto i = 0; i < intervals.size(); i++){
            for(auto j = i+1; j < intervals.size(); j++){
                if(intervals.at(i).at(1) >= intervals.at(j).at(0) && intervals.at(j).at(1) >= intervals.at(i).at(0)){ //If end1 >= start2 && end2 >= end1, merge
                    vector<int> temp {std::min(intervals.at(i).at(0),intervals.at(j).at(0)) , std::max(intervals.at(i).at(1),intervals.at(j).at(1))};
                    intervals.at(i).swap(temp);
                    intervals.erase((intervals.begin()+j));
                    merge = true;
                }
            }
        }
        if(!merge) break;
    }
        

    
    return intervals;
}

vector<vector<int>> mergeIntervals2(vector<vector<int>>& intervals){ //Online solution
    if(intervals.size() == 0) return intervals;
    sort(intervals.begin(), intervals.end(),[](vector<int> x, vector<int> y){ return x[0] < y[0]; });
    vector<vector<int>> output {intervals.at(0)};

    for (auto i = 1; i < intervals.size(); i++){
        if(intervals.at(i).at(0) <= output.back().at(1)){ //Check for overlap , if start <= end
            output.back().at(1) = std::max(intervals.at(i).at(1), output.back().at(1)); //The beginnings are already sorted, end is the max of the 2 ends
        } else { //if non overlapping
            output.push_back(intervals.at(i));
        }
        
    } 
   
    return output;
}

/**
 * @brief Plan
 * Scroll through list look for end (keep count of the number of elements)
 * Move head forward by size - k%N steps
 * Keep track of previous node and set next to NULL 
 */
ListNode* rotateRight(ListNode* head, int k){
    if(head == NULL) return NULL;
    ListNode *temp = head;

    int listSize = 1;
    while(temp->next != NULL){
        listSize++;
        temp = temp->next;
    }
    cout << "Number of element is : " << listSize << endl;

    if(listSize == 1) return head;

    temp->next = head; //Make a circular list

    //Move head forward a size - k%N steps
    int steps = listSize - (k%listSize);

    while (steps > 0)
    {
        head = head->next;
        temp = temp->next; //One step behind head
        steps--;
    }

    temp->next = NULL; //end list

    return head;
}

/**
 * @brief Plan
 * 
 */
void combinationSumHelper(vector<int>& candidates, int target, vector<vector<int>>&ans, vector<int> currentVec = {}){
    if(target == 0){
        sort(currentVec.begin(),currentVec.end());
        for(auto tempArray : ans){
            if(tempArray.size() == currentVec.size()  && equal(tempArray.begin(),tempArray.end(),currentVec.begin())) return;  //If any equal leave
        }
        ans.push_back(currentVec);

        return;
    }
    if(target < 0) return;

    for(auto i : candidates){
        vector<int> temp {currentVec};
        temp.push_back(i);
        combinationSumHelper(candidates,(target-i),ans,temp); //Try
    }
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target){
    if(candidates.size() == 0) return vector<vector<int>> {};
    vector<vector<int>> result;
    combinationSumHelper(candidates, target,result);

    return result;    
}

/**
 * @brief Plan Tabulation
 * Create a vector of 2D vectors of size Target+1
 * For item in targetSum
 *  if table value is NOT null
 *      For each number in candidates 
 *          if table index + num is in bounds
 *              For each of the append arrays from previous location
 * 
 */
vector<vector<int>> combinationSum2(vector<int>& candidates, int target){
    if(candidates.size() == 0) return vector<vector<int>> {};
    vector<vector<int>> result;
    combinationSumHelper(candidates, target,result);

    return result;    
}

/**
 * @brief Plan
 * Use a set, For each col/ row make sure that values are not repeated in the set
 * Look in 3*3 sections
 * Validate rows/Validate columns/Validate3*3
 */
bool validateThreebyThree(int row,int col,vector<vector<char>>& board){
    if(row >= board.size() || col >= board.at(row).size()) return true;
    //vector<pair<int,int>> topEdges = {make_pair(0,0),}
    set<char> numbers;
    for(auto i = row; i< row+3;i++){
        for(auto j = col; j < col+3; j++){
            if(board.at(i).at(j) != '.' && numbers.insert(board.at(i).at(j)).second == false) return false; //If insert fails 
        }
    }
    //Check down

    //Check right
    return validateThreebyThree(row+3,col,board) && validateThreebyThree(row,col+3,board);
}

/**
 * @brief For each column, insert elements into set and if insertion fails, return false
 */
bool isValidSudoku(vector<vector<char>>& board){
    if(board.size() == 0) return false;

    /* Validate rows */
    for(auto i = 0; i < board.size(); i++){
      set<char> numbers;  
      for(auto j = 0; j<board.size();j++){
          if(board.at(i).at(j) != '.' && numbers.insert(board.at(i).at(j)).second == false) return false; //If insert fails
      }
    }

    /* Validate cols */
    for(auto i = 0; i < board.size(); i++){
      set<char> numbers;  
      for(auto j = 0; j<board.size();j++){
          if(board.at(j).at(i) != '.' && numbers.insert(board.at(j).at(i)).second == false) return false; //If insert fails
      }
    }

    return validateThreebyThree(0,0,board);
}

/**
 * @brief Slide from Left to right
 * max = max(max,currentIndex)
 * 
 * if i >= k-1
 * maxList.push_back(i)
 * 
 * ONLINE Solution
 * initialise left to hold the last position of the window
 * 
 * Have a deque that will store the indexes (We are trying to create a decreasing deque)
 * 
 * For each index in nums
 *      while deque is not empty pop off the last added values if they are less than the current index val
 * 
 *      push_back the current_index
 * 
 *      if left > deque.front() (first added value) : pop the front
 * 
 *      if(i+1 >= k) : add the value represented by the deque.front() to the maxList, left++;
 * 
 */
vector<int> maxSlidingWindow(vector<int>& nums, int k){
    if(nums.size() == 0) return {};
    vector<int> maxList;

    deque<int> tempDeque;
    int left = 0;
    for(auto i = 0; i < nums.size(); i++){
        //Remove smaller values from the deque
        while (!tempDeque.empty() && nums.at(tempDeque.back()) < nums.at(i)) //Trying to get a decreasing queue
        {
            tempDeque.pop_back();
        }
        tempDeque.push_back(i);

        //Remove left value from window
        if (left > tempDeque.front()){
            tempDeque.pop_front(); //remove last added value to deque
        }

        if(i+1 >= k){
            maxList.push_back( nums.at(tempDeque.front()) );
            left++;
        }
        
    }
    return maxList;
}


/**
 * @brief Plan
 * Use recursion
 * 1. Add our location onto current distance;
 * 
 * 2. Base case if that we have reached the corner of the grid, 
 * if our current distance is less than the answer distance, replace the ans distance 
 * 
 * Go right
 * Go down
 */
void minPathSumHelper(int row, int col,vector<vector<int>>& grid, int &minTotalDistance, int currentDistance){
    //Bounds check
    if(col >= grid.at(row).size() && row >= grid.size()) return;

    currentDistance += grid.at(row).at(col);
    
    if(row == (grid.size()-1) && col == (grid.at(row).size()-1)){
        minTotalDistance = std::min(minTotalDistance,currentDistance);
        return;
    }

    //Go right
    if(col+1 < grid.at(row).size()){ //Bounds check
        minPathSumHelper(row, col+1, grid, minTotalDistance, currentDistance);
    }

    //Go down
    if(row+1 < grid.size()){ //Bounds check
        minPathSumHelper(row+1, col, grid,  minTotalDistance, currentDistance);
    }
}

int minPathSum(vector<vector<int>>& grid){
    int distance = INT_MAX;

    if(grid.size() == 0) distance = 0;
    else minPathSumHelper(0,0,grid,distance,0);

    return distance;
}

/**
 * @brief Plan : Create an infinity filled grid with extra one col and extra one row
 * Set last row, second last col = 0;
 * In the given grid, scroll from bottom corner and for the whole grid, add the minimum of the value in the right and that in the bottom
 * 
 */
int minPathSum2(vector<vector<int>>& grid){
    if(grid.size()==0) return 0;

    int rows = grid.size();
    int cols = grid.at(0).size();

    vector<vector<int>> temp (rows+1,vector<int>(cols+1,INT_MAX)); //Initiate an array with INT_MAX with an extra row and column
    temp.at(rows).at(cols-1) = 0; //set value to 0
    
    for(auto i = rows-1; i >= 0; i--){
        for(auto j = cols-1; j >= 0; j--){
            temp.at(i).at(j) = grid.at(i).at(j)
                + std::min(temp.at(i+1).at(j),temp.at(i).at(j+1)); //keep adding up min until origin
        }
    }
    
    return temp.at(0).at(0);
}

/**
 * @brief Plan
 * Have a boolean 2D array initialised to false
 * Go through Grid from Left to Right
 * If I find a 1 and is false , add one to islands and send to helper
 * 
 * Helper
 * if out of bounds return
 * if it is 0 return
 * Mark visited
 * 
 * Go left,
 * Go down,
 * Go right,
 * Go up,
 */
void numIsandsHelper(int row, int col, vector<vector<char>>& grid, vector<vector<bool>>& boolGrid){
    //Out of bounds -> return
    if(col >= grid.at(row).size() || row >= grid.size()) return;
    // if zero -> return
    if(grid.at(row).at(col) == '0') return;

    //Mark visited
    boolGrid.at(row).at(col) = true;

    //Else move on and false out neighbours right
    if(col+1 < grid.at(row).size() && grid.at(row).at(col+1) == '1' && boolGrid.at(row).at(col+1) == false){
        numIsandsHelper(row,col+1,grid,boolGrid);
    }
    //Else move on and false out neighbours down
    if(row+1 < grid.size() && grid.at(row+1).at(col) == '1' && boolGrid.at(row+1).at(col) == false){
        numIsandsHelper(row+1,col,grid,boolGrid);
    }

    //Else move on and false out neighbours up
    if(row-1 >= 0 && grid.at(row-1).at(col) == '1' && boolGrid.at(row-1).at(col) == false){
        numIsandsHelper(row-1,col,grid,boolGrid);
    }
    //Else move on and false out neighbours left
    if(col-1 >= 0 && grid.at(row).at(col-1) == '1' && boolGrid.at(row).at(col-1) == false){
        numIsandsHelper(row,col-1,grid,boolGrid);
    }
}

int numIslands(vector<vector<char>>& grid){
    int islandsFound = 0;
    if (grid.size() == 0 ) return islandsFound;
    vector<vector<bool>> boolGrid (grid.size(),vector<bool> (grid.at(0).size(),false));

    for(auto i = 0; i < grid.size(); i++){
        int gridWidth = grid.at(i).size();

        for(auto j = 0; j < gridWidth; j++){

            if(grid.at(i).at(j) == '1' && boolGrid.at(i).at(j) == false) {

                islandsFound++; //Found an island
                int currentRow = i; int currentCol = j; //Start falsing out other islands around this
                numIsandsHelper(i,j,grid,boolGrid);
            }
        }
    }

    return islandsFound;
}

/**
 * @brief Plan
 * Find max length through this node
 * Find max length through left and right
 * return the largest of the 3;
 */
int maxDepth(TreeNode* root){
    if(root == NULL) return 0;
    return 1 + std::max(maxDepth(root->left), maxDepth(root->right));
}
int diameterOfBinaryTree(TreeNode* root){
    if(root == NULL) return 0;
    int maxVal = 0;
    if(root->left == NULL) maxVal = maxDepth(root->right);
    else if(root->right == NULL) maxVal = maxDepth(root->left);
    else maxVal = maxDepth(root->left) + maxDepth(root->right);
    return std::max(maxVal,std::max(diameterOfBinaryTree(root->left),diameterOfBinaryTree(root->right)));
}

/**
 * @brief Return longest path to a leaf node
 * 
 */
int longestPathToLeaf(TreeNode* root){
    if(root==NULL) return 0;
    if(root->left == NULL && (root->right == NULL)) return 1;

    return 1 + max(longestPathToLeaf(root->left), longestPathToLeaf(root->right));
}

/**
 * @brief Base case
 * Node has not root -> diameter is 0
 * Node has one root -> return maxDiameter of root
 * Node has two roots -> maxOf( 2 + longestpathToLeafOnLeft + OnRight, diameter of right, diameter of left )
 * 
 */
int diameterOfBinaryTree(TreeNode* root) {
    if(root == NULL) return 0;
    if(root->left == NULL && (root->right == NULL)) return 0;

    //find diameter of this node
    int diameter = longestPathToLeaf(root->right) + longestPathToLeaf(root->left);
    int leftTreeDiameter = diameterOfBinaryTree(root->left);
    int rightTreeDiameter = diameterOfBinaryTree(root->right);

    int maxDiameter = max(diameter, leftTreeDiameter);
    maxDiameter = max(maxDiameter, rightTreeDiameter);

    return maxDiameter;

}


/**
 * @brief if NULL return
 * Add current value to current_list
 * if it is a leaf node and sum = val, add current list to answer list
 * help left,
 * help right;
 */
void pathSumHelper(TreeNode* root, int sum, vector<vector<int>> &ans, vector<int>v={}){
    if(root == NULL){
        return;
    }
    v.push_back(root->val);
    if(root->val == sum && root->left == NULL && root->right == NULL){
        ans.push_back(v);
        return;
    }

    pathSumHelper(root->left, sum-root->val, ans, v);
    pathSumHelper(root->right, sum-root->val, ans, v);
    }
vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
    vector<vector<int>> ans;
    pathSumHelper(root, targetSum, ans);
    return ans;
}

/**
 * @brief Plan : Find the middle of the array (Recursion)
 * Insert middle
 * root->left = Insert left of mid in array
 * root ->right = Insert left of mid in array
 * 
 */
TreeNode* sortedArrayToBST(vector<int> values){
    if(values.size() == 0) return NULL;

    TreeNode* BSThead = NULL;
    int mid = values.size()/2;
    //Insert middle
    BSThead = InsertBST(BSThead,values.at(mid));

    //Insert left
    vector<int> left;
    if(mid-1 >= 0){
        copy(values.begin(),values.begin()+mid,std::back_inserter(left));
        BSThead->left = sortedArrayToBST(left);
    }
    
    //Insert right
    vector<int> right;
    if(mid+1 < values.size()){
        copy(values.begin()+mid+1,values.end(),std::back_inserter(right));
        BSThead->right = sortedArrayToBST(right);
    }
    

    return BSThead;
}

ListNode* midListNode(ListNode* head){
    ListNode* slow = head; ListNode* fast = head; ListNode* prev = head;
    while(fast != NULL && fast->next!= NULL){
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    if(prev != NULL) prev->next = NULL;
    return slow;
}
/* Plan 
1. Scan through list and insert into an array
2. Find the middle of the array and keep inserting from left to right
*/
TreeNode* sortedListToBST(ListNode* head) {
    // if(head == NULL) return NULL;

    // TreeNode* BSThead = NULL;
    // vector<int> values;
    
    // while(head != NULL){
    //     values.push_back(head->val);
    //     head = head->next;
    // }

    // return sortedArrayToBST(values);

    /* Without using a sorted array 
        We can also use a fast and slow pointer
    */
    if(head == NULL) return NULL;
    ListNode* midNode = midListNode(head);
    TreeNode* root = new TreeNode(midNode->val);

    if(head == midNode) return root; //If they are the same look through

    root->left = sortedListToBST(head);
    root->right = sortedListToBST(midNode->next);

    return root;
}

TreeNode* InsertBST(TreeNode *root, int data){
    if(root == NULL){
        root = new TreeNode(data);
        return root;
    } else if(data <= root->val) {
        root->left = InsertBST(root->left,data);
    } else {
        root->right = InsertBST(root->right,data);
    }
    return root;
}

/**
 * @brief Plan 
 * initiate head = NULL, temp = head;
 * while : true -> infinite loop
 *      Loop through vector lists
 *          Have a pair where first element is index, second is value <-1,INT_MAX>
 *          if element is not NULL && element < pair.second : minPair = <index, value>
 *      if pair has not changed, means all elements are null
 *      else 
 *          Add node to new Linked list
 *          List.at(minPair.first) = List.at(minPair.first)->next;
 */
ListNode* mergeKLists(vector<ListNode*>& lists){
    ListNode *head = NULL;
    ListNode *temp = head;

    while(true){
        pair<int,int> minPair = std::make_pair(-1,INT_MAX);
        for(auto i = 0; i < lists.size(); i++){ 
            if(lists.at(i) != NULL && lists.at(i)->val < minPair.second){
                minPair = std::make_pair(i,lists.at(i)->val);
            } 
        }

        if(minPair == std::make_pair(-1,INT_MAX)) { //No change
            break;
        }else{
            if(temp == NULL){ // First time
                head = new ListNode(minPair.second);
                temp = head;
            } else { // Other times
                temp->next = new ListNode(minPair.second);
                temp = temp->next;
            }
            //Move forward in lists
            lists.at(minPair.first) = lists.at(minPair.first)->next;
        }
    }

    return head;
}

/**
 * @brief Plan
 * If an item is an opening bracket, add it to the stack
 * else If it is a closing bracket, 
 *  if stack is empty, return false
 *  check the last opened bracket
 *      if they are not equal return false;
 *      if they are equal, pop the top off the stack
 * 
 * return true if stack is empty, false otherwise
 * 
 * Complexity is n
 * Space is n
 */
bool isBalancedBrackets(string s) {
    if (s.size()==1) {
     return false;
    }
    
    stack<char> tempStack;
    
    for(char i : s){
        if ((i == '(') || (i == '{') || i == '[') {
           tempStack.push(i); 
        } else {
            if (tempStack.size() == 0) {
             return false;
            }
            
            if ((i == ')') && tempStack.top()=='(') {
                tempStack.pop();
            } else if ((i == '}') && tempStack.top()=='{') {
                tempStack.pop();
            } else if ((i == ']') && tempStack.top()=='[') {
                tempStack.pop();
            } else {
                //cout << "No matching brackets" << endl;
                return false;
            }
        }
    }
    
    return (tempStack.size()==0);
}

/**
 * @brief Plan
 * Have a number = 0 and keep adding for every value that I find
 * If a number is lower than the one before it, subtract
 * 
 * 
 */
int romanToInt(string s){
    int number = 0;
    int current = 0; int before = 0;
    for(int i = s.size()-1; i >= 0; i--){
        if (s.at(i) == 'I') current = 1;
        else if (s.at(i) == 'V') current = 5;
        else if (s.at(i) == 'X') current = 10;
        else if (s.at(i) == 'L') current = 50;
        else if (s.at(i) == 'C') current = 100;
        else if (s.at(i) == 'D') current = 500;
        else if (s.at(i) == 'M') current = 1000;

        if((i+1) < s.size()){ //Load before
        if (s.at(i+1) == 'I') before = 1;
        else if (s.at(i+1) == 'V') before = 5;
        else if (s.at(i+1) == 'X') before = 10;
        else if (s.at(i+1) == 'L') before = 50;
        else if (s.at(i+1) == 'C') before = 100;
        else if (s.at(i+1) == 'D') before = 500;
        else if (s.at(i+1) == 'M') before = 1000;
        }

        if(current < before) number -= current;
        else number += current;     
    }
    return number;
}

/**
 * @brief Plan
 * Extract thousands
 * Extract hundrends
 * Extract Tens
 * Extract Ones
 * 
 * Or have a dictionary
 * 
 * Thousands - Each thousand is 'M'
 * Hundreds
 * 100-300 'C'
 * 400 'CD'
 * 500-800 D + 'C'
 * 900 'CM'
 * 
 * Tens
 * 10-30 'X'
 * 40 'XL'
 * 50-80 L + 'C'
 * 90 'XC'
 * 
 * Ones - Same thing
 * 
 * OR 
 * Just have dictionaries of numbers
 *  
 */
string intToRoman(int num){
    string one = "I"; string five = "V"; 
    string ten = "X"; string fifty = "L";
    string oneHundred = "C";
    string fiveHundred = "D";
    string oneThousand = "M";

    string answer = "";

    int extractedThousands = num/1000;
    num-=(extractedThousands*1000);
    int extractedHundrends = num/100;
    num-=(extractedHundrends*100);
    int extractedTens = num/10;
    num-=(extractedTens*10);
    int extractedOnes = num;
    // cout << "extractedThousands : " << extractedThousands << endl;
    // cout << "extractedHundrends : " << extractedHundrends << endl;
    // cout << "extractedTens : " << extractedTens << endl;
    // cout << "extractedOnes : " << extractedOnes << endl;

    //Thousands
    while (extractedThousands > 0)
    {
        answer += oneThousand;
        extractedThousands--;
    }

    //Hundreds
    if(extractedHundrends == 9){
        answer = answer + oneHundred + oneThousand;
    } else if (extractedHundrends >= 5){
        answer = answer + fiveHundred;
        //Add C's
        extractedHundrends -= 5;
        while (extractedHundrends > 0)
        {
            answer += oneHundred;
            extractedHundrends--;
        }
        
    } else if (extractedHundrends == 4){
        answer = answer + oneHundred + fiveHundred;
    } else {
        while (extractedHundrends > 0)
        {
            answer += oneHundred;
            extractedHundrends--;
        }
    }

    //Tens
    if(extractedTens == 9){
        answer = answer + ten + oneHundred;
    } else if (extractedTens >= 5){
        answer = answer + fifty;
        //Add C's
        extractedTens -= 5;
        while (extractedTens > 0)
        {
            answer += ten;
            extractedTens--;
        }
        
    } else if (extractedTens == 4){
        answer = answer + ten + fifty;
    } else {
        while (extractedTens > 0)
        {
            answer += ten;
            extractedTens--;
        }
    }

    //Ones
    if(extractedOnes == 9){
        answer = answer + one + ten;
    } else if (extractedOnes >= 5){
        answer = answer + five;
        //Add C's
        extractedOnes -= 5;
        while (extractedOnes > 0)
        {
            answer += one;
            extractedOnes--;
        }
        
    } else if (extractedOnes == 4){
        answer = answer + one + five;
    } else {
        while (extractedOnes > 0)
        {
            answer += one;
            extractedOnes--;
        }
    }

    return answer;

}

/*
Plan
1. int sum = 0;
For each element,
    Loop find sum = max(sum, element-futureelement)

Plan 2
    track min Price = 0
    track profit = 0

    For each element
    if < minPrice ; minPrice = element
    else if ((elementt - minPrice) > profit) profit = element-Price
    
*/
int maxProfit(vector<int>& prices) {
        int minprice = INT_MAX;
        int maxprofit = 0;
        
        for (int i = 0; i < prices.size(); i++) {
            if (prices[i] < minprice)
                minprice = prices[i];
            else if (prices[i] - minprice > maxprofit)
                maxprofit = prices[i] - minprice;
        }
        return maxprofit;
 }
/**
 * @brief Plan - Recursion
 * if(left and right NULL ) return true
 * if(either one is NULL) return false
 * if(left->val != right->val) return false
 * return compare( left->right, right->left) && compare(left->left, right->right)
 */
bool check(TreeNode * left , TreeNode *right){
        if(left == NULL && right == NULL){
            return true;
        }else if((left == NULL && right != NULL) || (left != NULL && right == NULL )){
            return false;
        }
        
        if(left->val != right->val){
            return false;
        }else{
            return(check(left->right,right->left) && check(left->left, right->right));
        }
       
    }
bool isSymmetric(TreeNode* root) {
        return check(root->left , root->right);
        
    }

/**
 * @brief Plan : recursion
 * 
 * if root is NULL : return true
 * 
 * return 
 * Check is right subtree is null or right subtree -> val > root AND
 * Check is left subtree is null or left subtree ->val <= root AND
 * RSB is valid AND
 * LSDB is valid
 *  
 */
bool isLesserBST(TreeNode* root, int value){
    if(root == NULL) return true;
    if(root->val >= value) return false;

    return isLesserBST(root->left,value) && isLesserBST(root->right,value);
}

bool isGreaterBST(TreeNode* root, int value){
    if(root == NULL) return true;
    if(root->val <= value) return false;

    return isGreaterBST(root->left,value) && isGreaterBST(root->right,value);
}

bool isValidBST(TreeNode* root){
    if(root == NULL) return true;

    return ((isValidBST(root->left)) && (isValidBST(root->right)) && (isLesserBST(root->left,root->val)) && 
        (isGreaterBST(root->right,root->val)));
}

/* Binary Tree Level Order Traversal 
Plan
1. Have a 2D list
2. if levelIndex.size >= List.size ==> resize to that Index+1 size
3. Insert root-> data at current level
4. levelOrder for other levels

*/
void levelOrder2(TreeNode* root, vector<vector<int>>*currList, int levelIndex){
    if(root == NULL) return;
    if(levelIndex >= currList->size()) currList->resize(levelIndex+1);
    currList->at(levelIndex).push_back(root->val);
    levelOrder2(root->left, currList, levelIndex+1);
    levelOrder2(root->right, currList, levelIndex+1);
}

/**
 * @brief Plan
 * 1. Base case root == null, return root \n
 * 2. swap left and right subtree \n
 * 3. invert right \n
 * 4. invert left \n
 * 5. return root \n
 */
BstNode* invertTree(BstNode* root){
    if(root == NULL) return root;

    BstNode* temp = root->left;
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
int maxDepth(BstNode* root){
    if(root == NULL) return 0;
    return 1 + std::max(maxDepth(root->left), maxDepth(root->right));
}

/**
 * @brief 
 * Recursion : if(q == NULL and p == NULL) return true;
 * if(q == NULL and p is not NULL) return false;
 * if(q is not NULL and p is NULL) return false;
 * if(q->data != p->data) return false;
 * return sametree(q->left,p->left) && sameTree(q->right, p->right)
 * 
 */
bool isSameTree(BstNode* p, BstNode* q) {
    if(q == NULL && p == NULL) return true;
    else if(q == NULL && p != NULL) return false;
    else if(q != NULL && p == NULL) return false;
    else if(q->data != p->data) return false;
    
    return (isSameTree(q->left,p->left) && isSameTree(q->right,p->right));
}

 BstNode *FindBSTMin(BstNode* root){
    if(root == NULL) return root;

    BstNode *current = root;
    while (current->left != NULL)
    {
        current = current->left;
    }

    return current;
    
}

 BstNode * FindBSTMax(BstNode* root){
    if(root == NULL) return root;

    BstNode *current = root;
    while (current->left != NULL)
    {
        current = current->left;
    }

    return current;
}

BstNode* DeleteBstNode(BstNode* root, int value){
    if(root == NULL) return root;
    if(value < root->data) root->left = DeleteBstNode(root->left, value);
    else if(value > root->data) root->right = DeleteBstNode(root->right,value);
    else{
        //Here value = root-data
        //case 1 -> no children
        if(root->left == NULL && root->right == NULL){
            delete root;
            root = NULL;
            return root;
        } //Case 2 -> One child -> connect root to the next child
        else if(root->left == NULL){
            BstNode *temp = root;
            root = root->right;
            delete temp;
            return root;
        } else if (root->right == NULL){
            BstNode *temp = root;
            root = root->left;
            delete temp;
            return root;
        }
        else { //Case 3 -> Two Children, find min in right substree and copy the value to this node, Delete the duplicate in Right tree
            BstNode *temp = FindBSTMin(root->right);
            root->data = temp->data;
            root->right = DeleteBstNode(root->right,temp->data); //Temp will be deleted in this call
        }
    }
    return root;
    
}
void PreOrder(BstNode*root){
    if(root == NULL) return;
    cout<<root->data << " ";
    PreOrder(root->left);
    PreOrder(root->right);
}
void InOrder(BstNode*root){
    if(root == NULL) return;
    InOrder(root->left);
    cout<<root->data << " ";
    InOrder(root->right);
}
void PostOrder(BstNode*root){
    if(root == NULL) return;
    PostOrder(root->left);
    PostOrder(root->right);
    cout<<root->data << " ";
}
void LevelOrderTraversal(BstNode* root){
    if(root == NULL){
        return;
    }
    queue<BstNode*> Q;
    Q.push(root);

    while (!Q.empty())
    {
        BstNode *current = Q.front();
        cout << current ->data << " ";
        if(current->left != NULL) Q.push(current->left);
        if(current->right != NULL) Q.push(current->right);
        Q.pop();
    }
    

}

BstNode *GetNewNode(int data){
    BstNode *newNode = new BstNode();
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

BstNode* InsertBST(BstNode *root, int data){
    if(root == NULL){
        root = GetNewNode(data);
        return root;
    } else if(data <= root->data) {
        root->left = InsertBST(root->left,data);
    } else {
        root->right = InsertBST(root->right,data);
    }
    return root;
}

bool searchBST(BstNode*root, int data){
    if(root == NULL) return false;
    else if (root->data == data) return true;
    else if(data <= root->data) return searchBST(root->left,data);
    else return searchBST(root->right,data);
}

vector<int> twoSum(vector<int>& nums, int target) {
    /* vector<int> solution;

    if(solution.size() < 2){

    }
    
    for(auto i = 0; i<nums.size(); i++){
        for(auto j = 0; j<nums.size(); j++){
            if((i != j) && ((nums.at(i) + nums.at(j)) == target)) {
                solution.push_back(i);
                solution.push_back(j);
                return solution;;
            }
        }
    } 

    return solution; */

    //Time Complexity n^2
    //Space complexity n

    //Have a map
    //Store : target-index value as the key, index as the value
    // If the target-index value exists as a key in the map, return current index and the value there
    vector<int> solution;
    std::map<int,int> remainders;

    for(auto i = 0; i<nums.size(); i++){
            if(remainders.find(nums.at(i)) != remainders.end()){
                //Value in map
                solution.push_back(i);
                solution.push_back(remainders[nums.at(i)]);
                return solution;
            } else {
                remainders.insert(std::make_pair((target - nums.at(i)),i));
            }
    }
    return solution;
        
}

/**
 * @brief Time Complexity
 * O(n)
 * 
 * @param l1 
 * @param l2 
 * @return ListNode* 
 */
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2){
    //Plan
    //Have a carryover=0, listNode* head = new ListNode(), listNode* temp = head;
    //While list1 != null and list2 != null (Looping through both lists)
    //list1value = (list1 != null)? list1.val:0;
    //list2value = (list1 != null)? list2.val:0;
    //temp
    //temp.val = (list1+list2+carryover)%10
    //carryOver = (valueOne + valueTwo+ carryOver)/10;
    //temp.next = new ListNode();
    //temp = temp->next;

    int carryOver = 0;
    ListNode* head = new ListNode();
    ListNode* temp = head;

    while (true)
    {
        int valueOne = 0 , valueTwo = 0;

        if(l1 != NULL){
            valueOne = l1->val;
            l1 = l1->next;
        }

        if(l2 != NULL){
            valueTwo = l2->val;
            l2 = l2->next;
        }

        temp->val = (carryOver+valueTwo+valueOne)%10;
        carryOver = (valueOne + valueTwo+carryOver)/10;

        if (l1 == NULL && l2 == NULL){
            if(carryOver != 0){
                temp->next = new ListNode(carryOver);                
            }
            break;
        }
        temp->next = new ListNode();
        temp = temp->next;
    }

    return head;
    
}

/**
 * @brief Plan
 * Copy all elements to a new vector
 * copy in a sorted format
 * 
 * Find median spot
 * Index (index[size-1] )/2 if total size is odd
 * else (index[size/2] + index[size/2 -1 ]) if size is even
 * 
 * Time complexity
 * O(m+n) copying
 * O(m+n) looping
 * @param nums1 
 * @param nums2 
 * @return double 
 */
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2){

    int totalSize = nums1.size()+nums2.size();
    double median = 0;
    vector<int> total;
    int size1 = 0;
    int size2 = 0;

    while (size1 < nums1.size() && size2 < nums2.size())
    {
        if(nums1.at(size1) <= nums2.at(size2)){
            total.push_back(nums1.at(size1));
            size1++;
        } else {
            total.push_back(nums2.at(size2));
            size2++;
        }
    }

    while (size1 < nums1.size()){
        total.push_back(nums1.at(size1));
        size1++;
    }

    while (size2 < nums2.size()){
        total.push_back(nums2.at(size2));
        size2++;
    }

    //All are copied

    //Find median now
    if(total.size()%2 == 0){
        median = ( total.at(total.size()/2) + total.at(total.size()/2 - 1))/2.000;
    } else { //Odd
        median = total.at( (total.size()-1)/2.000 );
    }

    
    return median;
}

bool isPalindrome(string &s){
    if (s.size() == 1) return true;

    int index1 = 0;
    int index2 = 0;

    if(s.size()%2==0){
        index1 = s.size()/2;
        index2 = index1 - 1;
    } else { //Odd
        index1=s.size()/2 - 1;
        index2=s.size()/2 + 1;
    }

    while(index2 < s.size()){
        if(s.at(index1) != s.at(index2)) return false;
        index1--;
        index2++;
    }

    // for(int i = 0; i < s.size()/2; i++){
    //     if(s.at(i) != s.at(s.size() - 1 - i)) return false;
    // }

    return true;
}

/**
 * @brief Binary search
 * check for mid
 * if mid, return
 * if target > mid, low = mid+1
 * if target < mid, high = mid-1
 * 
 * @param nums 
 * @param target 
 * @return int 
 */
int search(vector<int>& nums, int target) {
    int retVal = -1;
    int low = 0;
    int high = nums.size()-1;

    while (low <= high)
    {
        int mid = low + (high-low)/2;
        if(target == nums.at(mid)){
            retVal = mid;
            break;
        } else if (target > nums.at(mid)) {
            low = mid+1;
        } else {
            high = mid-1;
        }
    }

    return retVal;
}

/**
 * @brief Palindrome has a pair of every letter
 * Traverse through the list as I place the values into a hashmap
 * Key is char : Value is the number of times the letter occurs
 * After that, count the occurances of each letter using frequency/2 
 * if total_frequency*2 == sizeofS, return sizeofS
 * else return freq*2 + 1
 * 
 * https://leetcode.com/problems/longest-palindrome/description/
 * 
 */
int longestPalindrome_blinkList75(string s) {
    int totalFrequency = 0;
    unordered_map<char, int> store;

    for(char letter : s){
        if(store.find(letter) == store.end()){
            //not in store
            store.insert(make_pair(letter,1));
        } else {
            store.at(letter)++; //increase on the count
        }
    }

    for(auto storeIterator = store.begin(); storeIterator != store.end(); storeIterator++){
        totalFrequency += storeIterator->second/2; //Only add pairs
    }

    if(totalFrequency*2 == s.size()) return s.size();

    return totalFrequency*2 + 1;
}

//Plan
//Find substrings
//If it is longer than the currentLongest, replace currentLongest
string longestPalindrome(string s){
    string longest = "";
    set<string> memoize;

    if(s.size() < 2){
        return s;
    }

    for(auto i = s.size(); i >= 1; i--){ //For each length
        //get substring
        //cout << "i - " << i;
        for(auto j = 0; j <= s.size()-i; j++) { //j+length
            //cout << "   j - " << j;
            
            string temp = s.substr(j,i); 
            //Look for string in set
            if(memoize.find(temp) != memoize.end()){
                //Found in set
                break;
            } else {
                memoize.insert(temp); //insert into set
            }
            
            //cout << "   temp - " << temp << endl;
            if(temp.size() > longest.size() && isPalindrome(temp)) {
                longest = temp;
                return longest;
            } 
        }
    }

    return longest;
}

/**
 * @brief Plan
 * For each character,
 * Keep expanding outwards while having it as the center and look for palindromes, check for even length and check for odd length
 */
string longestPalindrome3(string s){
    string solution = "";

    for(auto i = 0; i < s.size(); i++){
        //Look for odd
        int start = i;int end = i;
        while (start >= 0 && end < s.size() && (s.at(start) == s.at(end)) ) //Check in bounds and if they are equal
        {          
            if((end-start+1) > solution.size()){ //Longer than current palindrome
                solution = s.substr(start,(end-start+1));
            }
            start--; end++;
        }

        
        //Look for evens
        start = i; end = i+1;
        while (start >= 0 && end < s.size() && (s.at(start) == s.at(end)) ) //Check in bounds and if they are equal
        {
            if((end-start+1) > solution.size()){ //Longer than current palindrome
                solution = s.substr(start,(end-start+1));
            }
            start--; end++;
        }
        
    }

    return solution;
}

/**
 * @brief Plan
 * Scan string from back to front
 * if current_element is a digit and next_element is not a digit break;
 * if it is a whitespace ignore
 * if I find '-' the number is negative
 * if
 */
int myAtoi(string s){
    //Simple solution - Check string stream
    // int temp = 0;
    
    // if(s.size() >= 1){
    //     stringstream ss{s};
    //     ss>>temp;
    // }

    //Advanced solution
    bool isNegative = false;
    long long int temp2 = 0;
    int mulitple = 1;
    int index = 0;

    while(index < s.size() && s.at(index) == ' '){
        index++;
    }

    if(index < s.size() && s.at(index) == '-'){
        isNegative = true;
        index++;
    } else if (index < s.size() && s.at(index) == '+'){
        index++;
    }

    while(index < s.size() && isdigit(s.at(index))){
        int distance = s.at(index) - '0';
        if(((temp2*10) + distance) > INT32_MAX) return !isNegative ? INT_MAX:INT_MIN;
        temp2 = (temp2*10) + distance;
        index++;
    }

    if(isNegative) temp2 *= -1;

    return (int)temp2;
        
}