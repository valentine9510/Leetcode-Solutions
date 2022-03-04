#ifndef _PRACTICE2
#define _PRACTICE2

#include <iostream>
#include <vector>


/* Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct. */
bool containsDuplicate(vector<int>& nums);
/*
Given two strings s and t, return true if t is an anagram of s, and false otherwise.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.
*/
bool isAnagram(string s, string t);

/*
Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].

The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

You must write an algorithm that runs in O(n) time and without using the division operation.
*/
vector<int> productExceptSelf(vector<int>& nums);

/**
 * Given the head of a singly linked list, reverse the list, and return the reversed list.
 */
ListNode* reverseList(ListNode* head);

/**
 * @brief Given head, the head of a linked list, determine if the linked list has a cycle in it. 
 * There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to. Note that pos is not passed as a parameter.
 * Return true if there is a cycle in the linked list. Otherwise, return false.
 *  
 * @param head 
 * @return true 
 * @return false 
 */
bool hasCycle(ListNode *head);

/**
 * @brief You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).
 * Find two lines that together with the x-axis form a container, such that the container contains the most water.
 * Return the maximum amount of water a container can store.
 * Notice that you may not slant the container.
 * 
 * @param height 
 * @return int 
 */
int maxArea(vector<int>& height);      

/**
 * @brief Suppose an array of length n sorted in ascending order is rotated between 1 and n times. 
 * For example, the array nums = [0,1,2,4,5,6,7] might become:
 * [4,5,6,7,0,1,2] if it was rotated 4 times. 
 * [0,1,2,4,5,6,7] if it was rotated 7 times. 
 * Notice that rotating an array [a[0], a[1], a[2], ..., a[n-1]] 1 time results in the array 
 * [a[n-1], a[0], a[1], a[2], ..., a[n-2]].
 * Given the sorted rotated array nums of unique elements, return the minimum element of this array.
 * You must write an algorithm that runs in O(log n) time.
 * 
 * @param nums 
 * @return int 
 */
int findMin(vector<int>& nums);

/**
 * @brief Given the head of a linked list, remove the nth node from the end of the list and return its head.
 */
ListNode* removeNthFromEnd(ListNode* head, int n);

/**
 * @brief Given an integer array nums, return all the triplets 
 * [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.
 * Notice that the solution set must not contain duplicate triplets.
 * 
 */
vector<vector<int>> threeSum(vector<int>& nums);

/**
 * @brief You are given a string s and an integer k. You can choose any character of the string 
 * and change it to any other uppercase English character. You can perform this operation at most k times.
 * Return the length of the longest substring containing the same letter you can get after performing the above operations.
 * @return int 
 */
int characterReplacement(string s, int k);

/**
 * Rotational Cipher
 * One simple way to encrypt a string is to "rotate" every alphanumeric character by a certain amount. 
 * Rotating a character means replacing it with another character that is a certain number of steps away in normal alphabetic or numerical order.
 * For example, if the string "Zebra-493?" is rotated 3 places, the resulting string is "Cheud-726?". 
 * Every alphabetic character is replaced with the character 3 letters higher (wrapping around from Z to A), 
 * and every numeric character replaced with the character 3 digits higher (wrapping around from 9 to 0). 
 * Note that the non-alphanumeric characters remain unchanged.
 * Given a string and a rotation factor, return an encrypted string.
 * Signature
 * string rotationalCipher(string input, int rotationFactor) 
 * Input
 * 1 <= |input| <= 1,000,000
 * 0 <= rotationFactor <= 1,000,000
 * Output
 * Return the result of rotating input a number of times equal to rotationFactor.
 * Example 1
 * input = Zebra-493?
 * rotationFactor = 3
 * output = Cheud-726?
 * */
string rotationalCipher(string input, int rotationFactor);

/**
 * @brief Contiguous Subarrays
 * You are given an array arr of N integers. For each index i, you are required to determine the number of contiguous subarrays that fulfill the following conditions:
 * The value at index i must be the maximum element in the contiguous subarrays, and
 * These contiguous subarrays must either start from or end on index i.
 * Signature
 * int[] countSubarrays(int[] arr)
 * Input
 * Array arr is a non-empty list of unique integers that range between 1 to 1,000,000,000
 * Size N is between 1 and 1,000,000
 * Output
 * An array where each index i contains an integer denoting the maximum number of contiguous subarrays of arr[i]
 * Example:
 * arr = [3, 4, 1, 6, 2]
 * output = [1, 3, 1, 5, 1]
 * Explanation:
 * For index 0 - [3] is the only contiguous subarray that starts (or ends) with 3, and the maximum value in this subarray is 3.
 * For index 1 - [4], [3, 4], [4, 1]
 * For index 2 - [1]
 * For index 3 - [6], [6, 2], [1, 6], [4, 1, 6], [3, 4, 1, 6]
 * For index 4 - [2]
 * So, the answer for the above input is [1, 3, 1, 5, 1] 
 */
vector<int> CountSubarrays(vector <int> arr);

/**
 * @brief Pair Sums
 * Given a list of n integers arr[0..(n-1)], determine the number of different pairs of elements within it which sum to k.
 * If an integer appears in the list multiple times, each copy is considered to be different; that is, 
 * two pairs are considered different if one pair includes at least one array index which the other doesn't, 
 * even if they include the same values.
 * 
 * Signature
 * int numberOfWays(int[] arr, int k)
 * 
 * Input
 * n is in the range [1, 100,000].
 * Each value arr[i] is in the range [1, 1,000,000,000].
 * k is in the range [1, 1,000,000,000].
 * 
 * Output
 * Return the number of different pairs of elements which sum to k.
 * 
 * Example 1
 * n = 5
 * k = 6
 * arr = [1, 2, 3, 4, 3]
 * output = 2
 * The valid pairs are 2+4 and 3+3.
 * 
 * Example 2
 * n = 5
 * k = 6
 * arr = [1, 5, 3, 3, 3]
 * output = 4
 */
int numberOfWays(vector<int>& arr, int k);

/**
 * @brief Largest Triple Products \n
 * You're given a list of n integers arr[0..(n-1)]. You must compute a list output[0..(n-1)] such that, \n
 * for each index i (between 0 and n-1, inclusive), output[i] is equal to the product of the three largest elements out of \n
 * arr[0..i] (or equal to -1 if i < 2, as arr[0..i] then includes fewer than three elements). \n
 * Note that the three largest elements used to form any product may have the same values as one another, \n
 * but they must be at different indices in arr. \n \n \n
 * 
 * 
 * Signature \n
 * int[] findMaxProduct(int[] arr) \n
 * 
 * 
 * Input \n
 * n is in the range [1, 100,000]. \n
 * Each value arr[i] is in the range [1, 1,000]. \n
 * 
 * 
 * Output
 * Return a list of n integers output[0..(n-1)], as described above.
 * 
 * Example 1
 * n = 5
 * arr = [1, 2, 3, 4, 5]
 * output = [-1, -1, 6, 24, 60]
 * The 3rd element of output is 3*2*1 = 6, the 4th is 4*3*2 = 24, and the 5th is 5*4*3 = 60.
 * 
 * 
 * Example 2
 * n = 5
 * arr = [2, 1, 2, 1, 2]
 * output = [-1, -1, 4, 4, 8]
 * The 3rd element of output is 2*2*1 = 4, the 4th is 2*2*1 = 4, and the 5th is 2*2*2 = 8.
 */
vector<int> findMaxProduct(vector <int> arr);


/**
 * @brief Magical Candy Bags
You have N bags of candy. The ith bag contains arr[i] pieces of candy, and each of the bags is magical!
It takes you 1 minute to eat all of the pieces of candy in a bag (irrespective of how many pieces of candy are inside), and as soon as you finish, the bag mysteriously refills. If there were x pieces of candy in the bag at the beginning of the minute, then after you've finished you'll find that floor(x/2) pieces are now inside.
You have k minutes to eat as much candy as possible. How many pieces of candy can you eat?
Signature
int maxCandies(int[] arr, int K)
Input
1 ≤ N ≤ 10,000
1 ≤ k ≤ 10,000
1 ≤ arr[i] ≤ 1,000,000,000
Output
A single integer, the maximum number of candies you can eat in k minutes.
Example 1
N = 5 
k = 3
arr = [2, 1, 7, 4, 2]
output = 14
In the first minute you can eat 7 pieces of candy. That bag will refill with floor(7/2) = 3 pieces.
In the second minute you can eat 4 pieces of candy from another bag. That bag will refill with floor(4/2) = 2 pieces.
In the third minute you can eat the 3 pieces of candy that have appeared in the first bag that you ate.
In total you can eat 7 + 4 + 3 = 14 pieces of candy.
 */
int maxCandies(vector <int> arr, int k);

/**
 * Number of Visible Nodes
 * There is a binary tree with N nodes. You are viewing the tree from its left side and can see only the leftmost nodes at each level. Return the number of visible nodes.
 * Note: You can see only the leftmost nodes, but that doesn't mean they have to be left nodes. The leftmost node at a level could be a right node.
 * Signature
 * int visibleNodes(Node root) {
 * Input
 * The root node of a tree, where the number of nodes is between 1 and 1000, and the value of each node is between 0 and 1,000,000,000
 * Output
 * An int representing the number of visible nodes.
 * Example
 *             8  <------ root
 *            / \
 *          3    10
 *         / \     \
 *        1   6     14
 *           / \    /
 *          4   7  13            
 * output = 4
 * 
 * 
 * */
struct Node {
  int data; 
  Node* left ; 
  Node* right; 
  Node() {
    data = 0; 
    left = NULL; 
    right = NULL; 
  }
  Node(int data) {
    this->data = data; 
    this->left = NULL; 
    this->right = NULL; 
  }
};

int visibleNodes(Node* root);

/**
 * @brief Median Stream
 * You're given a list of n integers arr[0..(n-1)]. You must compute a list output[0..(n-1)] such that, for each index i (between 0 and n-1, inclusive), output[i] is equal to the median of the elements arr[0..i] (rounded down to the nearest integer).
 * The median of a list of integers is defined as follows. If the integers were to be sorted, then:
 * If there are an odd number of integers, then the median is equal to the middle integer in the sorted order.
 * Otherwise, if there are an even number of integers, then the median is equal to the average of the two middle-most integers in the sorted order.
 * Signature
 * int[] findMedian(int[] arr)
 * Input
 * n is in the range [1, 1,000,000].
 * Each value arr[i] is in the range [1, 1,000,000].
 * Output
 * Return a list of n integers output[0..(n-1)], as described above.
 * Example 1
 * n = 4
 * arr = [5, 15, 1, 3]
 * output = [5, 10, 5, 4]
 * The median of [5] is 5, the median of [5, 15] is (5 + 15) / 2 = 10, the median of [5, 15, 1] is 5, and the median of [5, 15, 1, 3] is (3 + 5) / 2 = 4.
 * Example 2
 * n = 2
 * arr = [1, 2]
 * output = [1, 1]
 * The median of [1] is 1, the median of [1, 2] is (1 + 2) / 2 = 1.5 (which should be rounded down to 1).
 */
vector <int> findMedian(vector <int> arr);

/**
 * @brief 
 * Slow Sums
 * Suppose we have a list of N numbers, and repeat the following operation until we're left with only a single number: 
 * Choose any two numbers and replace them with their sum. Moreover, we associate a penalty with each operation equal to the 
 * value of the new number, and call the penalty for the entire list as the sum of the penalties of each operation.
 * For example, given the list [1, 2, 3, 4, 5], we could choose 2 and 3 for the first operation, 
 * which would transform the list into [1, 5, 4, 5] and incur a penalty of 5. 
 * The goal in this problem is to find the highest possible penalty for a given input.
 * 
 * Signature:
 * int getTotalTime(int[] arr)
 * 
 * Input:
 * An array arr containing N integers, denoting the numbers in the list.
 * Output format:
 * An int representing the highest possible total penalty.
 * 
 * Constraints:
 * 1 ≤ N ≤ 10^6
 * 1 ≤ Ai ≤ 10^7, where *Ai denotes the ith initial element of an array.
 * The sum of values of N over all test cases will not exceed 5 * 10^6.
 * 
 * Example
 * arr = [4, 2, 1, 3]
 * output = 26
 * First, add 4 + 3 for a penalty of 7. Now the array is [7, 2, 1]
 * Add 7 + 2 for a penalty of 9. Now the array is [9, 1]
 * Add 9 + 1 for a penalty of 10. The penalties sum to 26.
 */
int getTotalTime(vector <int> arr);

/**
 * @brief Element Swapping
Given a sequence of n integers arr, determine the lexicographically smallest sequence which may be obtained from it after performing at most k element swaps, each involving a pair of consecutive elements in the sequence.
Note: A list x is lexicographically smaller than a different equal-length list y if and only if, for the earliest index at which the two lists differ, x's element at that index is smaller than y's element at that index.
Signature
int[] findMinArray(int[] arr, int k)
Input
n is in the range [1, 1000].
Each element of arr is in the range [1, 1,000,000].
k is in the range [1, 1000].
Output
Return an array of n integers output, the lexicographically smallest sequence achievable after at most k swaps.
Example 1
n = 3
k = 2
arr = [5, 3, 1]
output = [1, 5, 3]
We can swap the 2nd and 3rd elements, followed by the 1st and 2nd elements, to end up with the sequence [1, 5, 3]. This is the lexicographically smallest sequence achievable after at most 2 swaps.
Example 2
n = 5
k = 3
arr = [8, 9, 11, 2, 1]
output = [2, 8, 9, 11, 1]
We can swap [11, 2], followed by [9, 2], then [8, 2].
 */
vector <int> findMinArray(vector <int> arr, int k);
#endif //PRACTICE2

