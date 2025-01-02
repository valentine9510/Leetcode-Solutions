#include <bits/stdc++.h>

using namespace std;

/**
 * @brief 
 * 
 * 
 * 328. Odd Even Linked List
Medium
Topics
Companies
Given the head of a singly linked list, group all the nodes with odd indices together followed by the nodes with even indices, and return the reordered list.

The first node is considered odd, and the second node is even, and so on.

Note that the relative order inside both the even and odd groups should remain as it was in the input.

You must solve the problem in O(1) extra space complexity and O(n) time complexity.
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
  * @brief Plan 
  * 
  * Keep track of the odd list and append both
  * 
  */
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next) return head;

        ListNode *odd_head = head;
        ListNode *even_head = head->next;
        ListNode *odd_curr = odd_head;
        ListNode *even_curr = even_head;

        // Traverse the list
        while (even_curr && even_curr->next) {
            odd_curr->next = even_curr->next;
            odd_curr = odd_curr->next;

            even_curr->next = odd_curr->next;
            even_curr = even_curr->next;
        }

        // Connect the odd list to the even list
        odd_curr->next = even_head;

        return odd_head;
    }
};
