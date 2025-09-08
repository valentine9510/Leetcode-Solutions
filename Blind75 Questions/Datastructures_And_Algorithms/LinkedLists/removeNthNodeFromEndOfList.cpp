#include <bits/stdc++.h>

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

/*
19. Remove Nth Node From End of List
Solved
Medium
Topics
Companies
Hint
Given the head of a linked list, remove the nth node from the end of the list and return its head.

 

Example 1:


Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]
Example 2:

Input: head = [1], n = 1
Output: []
Example 3:

Input: head = [1,2], n = 1
Output: [1]
 
*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

using namespace std;

/* Effecient solution */
// Definition for singly-linked list.
// struct ListNode {
//     int val;
//     ListNode *next;
//     ListNode() : val(0), next(nullptr) {}
//     ListNode(int x) : val(x), next(nullptr) {}
//     ListNode(int x, ListNode *next) : val(x), next(next) {}
// };

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // Dummy simplifies removing the head (when n == length)
        ListNode* dummy = new ListNode(0, head);

        ListNode* fast = dummy;
        ListNode* slow = dummy;

        // 1) Advance fast by n + 1 steps so slow lands at (prev of target)
        //    Alternatively: advance by n steps from head and then move both until fast->next == nullptr
        for (int i = 0; i < n + 1; ++i) {
            fast = fast->next;  // valid because dummy is one extra node before head
        }

        // 2) Move both pointers until fast reaches the end
        while (fast != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }

        // 3) slow is now before the node to delete
        ListNode* toDelete = slow->next;
        slow->next = toDelete->next;

        // Optional in LeetCode (no memory checks), but safe to free:
        delete toDelete;

        // 4) Return real head
        ListNode* newHead = dummy->next;
        delete dummy;
        return newHead;
    }
};


class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        stack<ListNode*> store;
        

        ListNode *temp = head;

        while (temp != NULL)
        {
            store.push(temp);
            temp = temp->next;
        }

        //temp is null
        while (store.empty() == false)
        {
            n--; //update n

            ListNode *new_temp = store.top();
            store.pop();

            if(n == 0){
                //found our number to be deleted
                delete new_temp;
            } else {
                new_temp->next = temp; //begins as NULL
                temp = new_temp;
            }
        }

        head = temp; //we have update all the list

        return head;
        
        
    }
};



class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {       
        stack<ListNode *>store;

        ListNode *curr = head;

        while (curr)
        {
            store.push(curr);
            curr = curr->next;
        }

        while (!store.empty())
        {
            n--;
            curr = store.top();
            store.pop();

            if(n == 0){
                //edge condition

                //head
                if(curr == head){
                    head = curr->next;
                    delete curr;
                } else {
                    //middle or last
                    ListNode *connector = store.top();
                    connector->next = curr->next;
                    delete curr;
                }
                break;
            }
        }
        return head;
        
    }
};