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