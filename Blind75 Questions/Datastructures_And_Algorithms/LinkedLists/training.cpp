#include <bits/stdc++.h>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


void reverse_linked_list(ListNode** head){
    ListNode *curr = *head;
    ListNode *next = NULL;
    ListNode *prev = NULL;

    while (curr)
    {
        /* code */
        next = curr->next;
        prev = curr;
        curr = next;
    }

    *head = prev;
}


ListNode * reverse_linked_list(ListNode *head){
    ListNode *curr = head;
    ListNode *next = NULL;
    ListNode *prev = NULL;

    while (curr)
    {
        /* code */
        next = curr->next;
        prev = curr;
        curr = next;
    }

    return prev;
    
}

ListNode* insert_Into_Linked_List(ListNode* head, int value){
    if(head == NULL){
        //Update head
        ListNode *temp = new ListNode;
        temp->next = NULL;
        temp->val = value;

        return temp;
    }

    ListNode* curr = head;

    while (curr->next != NULL)
    {
        curr = curr->next;
    }

    ListNode *temp = new ListNode;
    temp->next = NULL;
    temp->val = value;
    
    curr->next = temp;

    return head;
}


void remove_all_nodes_matching_value(ListNode ** head, int value){
    ListNode* curr = *head;
    ListNode* prev = NULL;

    while (curr != NULL)
    {
        if(curr->val == value){
            //Remove node

            //Head
            if(curr == *head){
                ListNode* temp = curr;
                curr = curr->next;
                *head = curr;

                delete temp;
            } else {
                prev->next = curr->next; //connect the two
                ListNode* temp = curr;
                curr = curr->next;

                delete temp;
            }       
        } else {
            prev = curr;
            curr = curr->next;
        }
    }
    
}

bool hasCycle(ListNode *list){
    struct ListNode *slow_p = list;
    struct ListNode *fast_p = list;

    while (slow_p && fast_p && fast_p->next)
    {
        slow_p = slow_p->next;
        fast_p = fast_p->next->next;

        if(slow_p == fast_p)
            return true;
    }
    
    return false;   
    
}