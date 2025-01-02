#include <bits/stdc++.h>

using namespace std;


/**
 * @brief 
 * 
 * Swap Nodes in Pairs
Medium
Topics
Companies
Given a linked list, swap every two adjacent nodes and return its head. You must solve the problem without modifying the values in the list's nodes (i.e., only nodes themselves may be changed.)

Example 1:
Input: head = [1,2,3,4]
Output: [2,1,4,3]
Explanation:
Example 2:
Input: head = []
Output: []
Example 3:
Input: head = [1]
Output: [1]
Example 4:
Input: head = [1,2,3]
Output: [2,1,3]

Constraints:
The number of nodes in the list is in the range [0, 100].
0 <= Node.val <= 100
 * 
 */

/**
 * Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 */

 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

/**
 * @brief Keep track of left and right
 * 
 * Swap them 
 * 
 * left->next = right->nextafter
 * right->next = left
 * 
 * put them back and advance
 * 
 * I have to keep track of the previous value ?
 * 
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next) return head;

        ListNode* dummy = new ListNode(0);  // Dummy node to handle edge cases
        dummy->next = head;

        ListNode* prev = dummy;
        ListNode* left = head;
        ListNode* right = left->next;

        while (left && right) {
            // Swap the nodes
            left->next = right->next;
            right->next = left;
            prev->next = right;

            // Move pointers to the next pair
            prev = left;
            left = left->next;
            if(left)
                right = left->next;
            else
                right = NULL;
        }
        
        return dummy->next;
    }
};
