#include <bits/stdc++.h>

using namespace std;

/*
    You are given the head of a singly linked-list. The list can be represented as:

L0 → L1 → … → Ln - 1 → Ln
Reorder the list to be on the following form:

L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
You may not modify the values in the list's nodes. Only nodes themselves may be changed.
*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/* Steps */
/*
    Find the middle of the list

    Reverse from end to middle;

    Merge the 2 lists
*/

// Definition for singly-linked list.
// struct ListNode { int val; ListNode *next; ListNode(): val(0), next(nullptr) {}
//                   ListNode(int x): val(x), next(nullptr) {}
//                   ListNode(int x, ListNode *n): val(x), next(n) {} };

class Solution {
public:
    static ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr) {
            ListNode* next = curr->next; // save
            curr->next = prev;           // reverse
            prev = curr;                 // advance prev
            curr = next;                 // advance curr  <-- you were missing this
        }
        return prev;
    }

    void reorderList(ListNode* head) {
        if (!head || !head->next) return;

        // 1) Find middle (slow at start of 2nd half)
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = nullptr;
        while (fast && fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        // 2) Split into [head .. prev] and [slow .. end]
        prev->next = nullptr;

        // 3) Reverse second half
        ListNode* second = reverseList(slow);

        // 4) Merge two halves in-place: first, second, first, second, ...
        ListNode* first = head;
        while (second) {
            ListNode* n1 = first->next;
            ListNode* n2 = second->next;

            first->next = second;
            second->next = n1;

            first = n1 ? n1 : second; // advance first if possible
            second = n2;
        }
        // Done. List is modified in place.
    }
};
