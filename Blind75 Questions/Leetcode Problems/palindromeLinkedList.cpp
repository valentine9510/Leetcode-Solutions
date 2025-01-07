#include <bits/stdc++.h>


using namespace std;

/*
234. Palindrome Linked List

Given the head of a singly linked list, return true if it is a 
palindrome  or false otherwise.

Example 1:
Input: head = [1,2,2,1]
Output: true
Example 2:
Input: head = [1,2]
Output: false 

Constraints:
The number of nodes in the list is in the range [1, 105].
0 <= Node.val <= 9

Follow up: Could you do it in O(n) time and O(1) space? */

/*
    Plan
    Fast and slow pointer

    Use a stack to keep track of what the first pointer is seeing
    If the second pointer hits the end of the list, then we pop stack and we should end up with an empty stack
*/


 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) 
            return true;

        // Step 1: Find the middle using slow and fast pointers
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Step 2: Reverse the second half of the list
        ListNode* secondHalf = reverseList(slow);

        // Step 3: Compare the first half and second half
        ListNode* firstHalf = head;
        ListNode* temp = secondHalf;

        bool isPalin = true;
        while (temp) {
            if (firstHalf->val != temp->val) {
                isPalin = false;
                break;
            }
            firstHalf = firstHalf->next;
            temp = temp->next;
        }

        // Step 4 (Optional): Restore the list by reversing the second half again
        reverseList(secondHalf);

        return isPalin;
    }

    // Helper function to reverse the linked list
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;

        while (curr) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        return prev;
    }
};
