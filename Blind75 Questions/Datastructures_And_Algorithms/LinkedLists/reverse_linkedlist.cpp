#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void reverse_linked_list(ListNode ** head){
    ListNode * curr = *head;
    ListNode * next = NULL;
    ListNode * prev = NULL;

    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    //By the time we reach here, we have ended the list
    *head = prev;    
}

ListNode * reverse_linked_list(ListNode *head){
    ListNode * curr = head;
    ListNode * next = NULL;
    ListNode * prev = NULL;

    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    //By the time we reach here, we have ended the list

    //return head
    return prev;   
}