#ifndef _PRACTISE_QNS
#define _PRACTISE_QNS

#include <iostream>
#include <vector>

using namespace std;

/**
BST
**/
struct BstNode {
    int data;
    BstNode *left;
    BstNode *right;
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

BstNode *GetNewNode(int data);
BstNode* InsertBST(BstNode *root, int data);
bool searchBST(BstNode*root, int data);
BstNode *FindBSTMin(BstNode* root);
BstNode *FindBSTMax(BstNode* root);
void LevelOrderTraversal(BstNode* root);
void PreOrder(BstNode*root);
void InOrder(BstNode*root);
void PostOrder(BstNode*root);
BstNode* DeleteBstNode(BstNode* root, int value);

/**
 * @brief Longest Increasing Subsequence
 */
int lengthOfLIS(vector<int>& nums);

/*
Sort Colors 

Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

You must solve this problem without using the library's sort function.
*/
void sortColors(vector<int>& nums);

/**
 * @brief Word Ladder
A transformation sequence from word beginWord to word endWord using a dictionary wordList is a sequence of words beginWord -> s1 -> s2 -> ... -> sk such that:

Every adjacent pair of words differs by a single letter.
Every si for 1 <= i <= k is in wordList. Note that beginWord does not need to be in wordList.
sk == endWord
Given two words, beginWord and endWord, and a dictionary wordList, return the number of words in the shortest transformation sequence from beginWord to endWord, or 0 if no such sequence exists.
 */
int ladderLength(string beginWord, string endWord, vector<string>& wordList);
/**
 * @brief 79. Word Search
Given an m x n grid of characters board and a string word, return true if word exists in the grid. 
The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.
 */
bool wordSearch(vector<vector<char>>& board, string word);
/**
 * 56. Merge Intervals
 * Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and
 *  return an array of the non-overlapping intervals that cover all the intervals in the input.
 * 
 */
vector<vector<int>> mergeIntervals(vector<vector<int>>& intervals);
vector<vector<int>> mergeIntervals2(vector<vector<int>>& intervals); //Online solution

/**
 * @brief Rotate List 
 */
ListNode* rotateRight(ListNode* head, int k);


/**
Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target. You may return the combinations in any order.

The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the frequency of at least one of the chosen numbers is different.

It is guaranteed that the number of unique combinations that sum up to target is less than 150 combinations for the given input.
 * 
 */
vector<vector<int>> combinationSum(vector<int>& candidates, int target);

/**
 * @brief Valid Sudoku
Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:

Each row must contain the digits 1-9 without repetition.
Each column must contain the digits 1-9 without repetition.
Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition.
Note:

A Sudoku board (partially filled) could be valid but is not necessarily solvable.
Only the filled cells need to be validated according to the mentioned rules.
 
 * 
 */
bool isValidSudoku(vector<vector<char>>& board);

/*
239. Sliding Window Maximum
You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.

Return the max sliding window.
*/
vector<int> maxSlidingWindow(vector<int>& nums, int k);

/* Minimum Path Sum */
int minPathSum(vector<vector<int>>& grid);

/*
200. Number of Islands
Share
Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.
*/
void numIsandsHelper(int row, int col, vector<vector<char>>& grid, vector<vector<bool>>& boolGrid);
int numIslands(vector<vector<char>>& grid);


/* 543. Diameter of Binary Tree */
int diameterOfBinaryTree(TreeNode* root);

/* 113. Path Sum II 
   Given the root of a binary tree and an integer targetSum, return all root-to-leaf paths where the sum of the node values in the path equals targetSum. Each path should be returned as a list of the node values, not node references.
   A root-to-leaf path is a path starting from the root and ending at any leaf node. A leaf is a node with no children.
*/
//void pathSumHelper(TreeNode* root, int sum, vector<vector<int>> &ans, vector<int>v={});
vector<vector<int>> pathSum(TreeNode* root, int targetSum);

/* 109. Convert Sorted List to Binary Search Tree */
TreeNode* InsertBST(TreeNode *root, int data);
TreeNode* sortedListToBST(ListNode* head);

/* Sorted array to BST */
TreeNode* sortedArrayToBST(vector<int> values);

/* Merge k Sorted Lists 
   You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.
   Merge all the linked-lists into one sorted linked-list and return it.
*/
ListNode* mergeKLists(vector<ListNode*>& lists);


/*  Valid Parentheses */
bool isBalancedBrackets(string s);


/* Integer to Roman */
string intToRoman(int num);

/*Roman to Integer*/
int romanToInt(string s);

/*
121. Best Time to Buy and Sell Stock

You are given an array prices where prices[i] is the price of a given stock on the ith day.
*/
int maxProfit(vector<int>& prices);
/*
101. Symmetric Tree
Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).
*/
bool isSymmetric(TreeNode* root);
/* Maximum Depth of Binary Tree : A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node. */
int maxDepth(BstNode* root);

/* Compare 2 trees */
bool isSameTree(BstNode* p, BstNode* q);

/* 226. Invert Binary Tree */
BstNode* invertTree(BstNode* root);

/* Binary Tree Level Order Traversal */
void levelOrder2(TreeNode* root, vector<vector<int>>*currList, int levelIndex);

/* 98. Validate Binary Search Tree 
Given the root of a binary tree, determine if it is a valid binary search tree (BST).

A valid BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
*/
bool isValidBST(TreeNode* root);
bool isGreaterBST(TreeNode* root, int value);
bool isLesserBST(TreeNode* root, int value);

/*
Implement the myAtoi(string s) function, which converts a string to a 32-bit signed integer (similar to C/C++'s atoi function).

The algorithm for myAtoi(string s) is as follows:

1. Read in and ignore any leading whitespace.
2. Check if the next character (if not already at the end of the string) is '-' or '+'. Read this character in if it is either. This determines if the final result is negative or positive respectively. Assume the result is positive if neither is present.
3. Read in next the characters until the next non-digit character or the end of the input is reached. The rest of the string is ignored.
4. Convert these digits into an integer (i.e. "123" -> 123, "0032" -> 32). If no digits were read, then the integer is 0. Change the sign as necessary (from step 2).
5. If the integer is out of the 32-bit signed integer range [-231, 231 - 1], then clamp the integer so that it remains in the range. Specifically, integers less than -231 should be clamped to -231, and integers greater than 231 - 1 should be clamped to 231 - 1.
6. Return the integer as the final result

*/
int myAtoi(string s);
/*
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.

Example 1:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Output: Because nums[0] + nums[1] == 9, we return [0, 1].
Example 2:

Input: nums = [3,2,4], target = 6
Output: [1,2]
Example 3:

Input: nums = [3,3], target = 6
Output: [0,1]
*/
vector<int> twoSum(vector<int>& nums, int target);

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

/**
 * You are given two non-empty linked lists representing two non-negative integers. 
 * The digits are stored in reverse order, and each of their nodes contains a single digit. 
 * Add the two numbers and return the sum as a linked list.
 * You may assume the two numbers do not contain any leading zero, except the number 0 itself.
 * 
 */
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2);


/**
 * Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

The overall run time complexity should be O(log (m+n)).

 

Example 1:

Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.
Example 2:

Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
 

Constraints:

nums1.length == m
nums2.length == n
0 <= m <= 1000
0 <= n <= 1000
1 <= m + n <= 2000
-106 <= nums1[i], nums2[i] <= 106
 * 
 */
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2);

/**
 * Given a string s, return the longest palindromic substring in s.

Example 1:

Input: s = "babad"
Output: "bab"
Explanation: "aba" is also a valid answer.
Example 2:

Input: s = "cbbd"
Output: "bb"
 

Constraints:

1 <= s.length <= 1000
s consist of only digits and English letters.
 * 
*/
bool isPalindrome(string &s);

/*
    Given a string s, return the longest palindromic substring in s.

 

Example 1:

Input: s = "babad"
Output: "bab"
Explanation: "aba" is also a valid answer.
Example 2:

Input: s = "cbbd"
Output: "bb"
 

Constraints:

1 <= s.length <= 1000
s consist of only digits and English letters
*/
string longestPalindrome(string s);
/* Understood and is working */
string longestPalindrome3(string s);
string longestPalindrome2(string s);

#endif //_PRACTISE_QNS