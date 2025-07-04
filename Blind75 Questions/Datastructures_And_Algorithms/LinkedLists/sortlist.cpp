#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/* Given the head of a linked list, return the list after sorting it in ascending order. */

class Solution {
public:
    /* Bubble sort */
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) return head;

        bool swapped = true;

        while (swapped) {
            swapped = false;
            ListNode* curr = head;

            while (curr && curr->next) {
                if (curr->val > curr->next->val) {
                    swap(curr->val, curr->next->val);
                    swapped = true;
                }
                curr = curr->next;
            }
        }

        return head;
    }
};

class Solution {
public:
    /* Merge sort */
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next)
            return head;

        //Split into left and right
        ListNode *middle = getMiddle(head);
        ListNode *right = middle->next;
        middle->next = nullptr;

        //Mergesort left and right
        head = sortList(head);
        right = sortList(right);

        //Merge
        head = merge(head, right);

        return head;

    }

    ListNode *merge(ListNode *left, ListNode* right){
        ListNode dummy(0);
        ListNode *tail = &dummy;

        while (left && right)
        {
            if(left->val < right->val){
                tail->next = left;
                left = left->next;
            } else {
                tail->next = right;
                right = right->next;
            }

            tail = tail->next;
        }

        tail->next = left ? left : right;

        return dummy.next;
    }

    ListNode *getMiddle(ListNode* head){
        ListNode*slow = head;
        ListNode*fast = head->next;

        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        return slow;
    }
};
