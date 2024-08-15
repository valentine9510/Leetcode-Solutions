/**
 * @file LinkedLists.cpp
 * @author your name (you@domain.com)
 * @brief All about Linked Lists
 * @version 0.1
 * @date 2023-11-16
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <bits/stdc++.h>
#include <cctype>
#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
#include <sstream>
#include <queue>
#include <stack>
#include <list>
#include <map>
#include <unordered_map>
#include <math.h>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

using namespace std;

//Functions
//Insert into linked list
ListNode* insert_Into_Linked_List(ListNode* head, int value);
//Reverse linked list
void reverse_linked_list(ListNode ** head);
ListNode * reverse_linked_list(ListNode *head);
//Remove all nodes with a certain value in linked list
void remove_all_nodes_matching_value(ListNode ** head, int value);
//Insert Node into nth position
void insert_Linked_List_Into_Position_N(ListNode** head, int value, int position);
//Remove Node at nth position
void remove_linked_list_value_at_Position_N(ListNode** head, int position);
//print linked list
void print_linked_list(ListNode* head);
//Detect a cycle in a linked list
bool hasCycle(ListNode *head);
bool detectLoop(ListNode* list);

// int main (){
//     ListNode* head = NULL;

//     head = insert_Into_Linked_List(head, 3);
//     head = insert_Into_Linked_List(head, 1);
//     head = insert_Into_Linked_List(head, 2);
//     head = insert_Into_Linked_List(head, 3);
//     head = insert_Into_Linked_List(head, 3);
//     head = insert_Into_Linked_List(head, 4);
//     head = insert_Into_Linked_List(head, 3);

//     cout << "Linked List In Order " << endl;
//     print_linked_list(head);

//     cout << endl << "Reverse Linked List Single Pointer" << endl;
//     head = reverse_linked_list(head);
//     print_linked_list(head);

//     cout << endl << "Reverse Linked List Double Pointer" << endl;
//     reverse_linked_list(&head);
//     print_linked_list(head);

//     cout << endl << "Remove all nodes that have the value of 3" << endl;
//     remove_all_nodes_matching_value(&head, 3);
//     print_linked_list(head);

//     cout << endl << "Insert 3 into position 1" << endl;
//     insert_Linked_List_Into_Position_N(&head, 3, 1);
//     print_linked_list(head);

//     cout << endl << "Insert 15 into position 2" << endl;
//     insert_Linked_List_Into_Position_N(&head, 15, 2);
//     print_linked_list(head);

//     cout << endl << "Insert 185 into position 10" << endl;
//     insert_Linked_List_Into_Position_N(&head, 185, 10);
//     print_linked_list(head);

//     return 0;
// }

ListNode* insert_Into_Linked_List(ListNode* head, int value){
    ListNode* newNode = new ListNode; //store on heap
    newNode->val = value;
    newNode->next = NULL;

    if(head == NULL) return newNode; //return head

    ListNode* curr = head;
    while (curr->next != NULL)
    {
        curr = curr->next;
    }

    //at this point, we are at the last element
    curr->next = newNode;

    //return head of list
    return head; 
}

void print_linked_list(ListNode* head){
    if(head == NULL){
        cout << "NULL" << endl;
        return;
    } 

    cout << head->val << "->";
    print_linked_list(head->next);
}

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

void remove_all_nodes_matching_value(ListNode ** head, int value){
    ListNode *curr = *head;
    ListNode *prev = NULL;

    while (curr != NULL)
    {
        if(curr->val == value){
            //handle the removing of the value

            //if head
            if(prev == NULL){ //we are on head
                
                ListNode* temp = curr;
                curr = curr->next;
                *head = curr; //update head

                //free temp
                delete temp;
            } else { //not head
                ListNode* temp = curr;
                prev->next = curr->next; //connect the 2
                curr = curr->next; //advance current

                delete temp;
            }
        } else {
            prev = curr;
            curr = curr->next;
        }
    }
    
    
}

void insert_Linked_List_Into_Position_N(ListNode** head, int value, int position){
    if(position == 1 || *head == NULL){
        ListNode* temp = new ListNode(value);
        temp->next = *head;
        *head = temp; //update head
        return;
    }

    //it is in the middle of the list
    ListNode*curr = *head;
    int positionCount = 2;

    while (curr->next != NULL)
    {
        if(positionCount == position){
            //insert logic
            ListNode* temp = new ListNode(value);
            temp->next = curr->next;
            curr->next = temp;

            return;
        }

        curr = curr->next;
        positionCount++;
    }
    
    //if we reach here next is null so we can just add it to the end of the list
    ListNode* temp = new ListNode(value);
    curr->next = temp;

}

void remove_linked_list_value_at_Position_N(ListNode** head, int position){
    if(head == NULL) return;
    if(position == 1){
        //we are modifying the head
        ListNode *temp = *head;
        *head = (*head)->next; //update head

        delete temp; //free node from stack
    }

    ListNode *current = (*head);

    for(int i = 0; i < position-2; i++){
        if(current == NULL) return; //return because that position does not exist in this linked list
        
        current = current->next; // we want to stop right before the node we have to remove
    }

    //now we have to remove the next value
    ListNode *toRemove = current->next;

    current->next = toRemove->next; //match the gap

    delete toRemove;

    return;

}

/**
 * @brief Plan
 * Loop through the list and change the value at the node, if the next value is something I set to, then there is a cycle
 * Have a set that can store nodes, if the value is in the set, there is a cycle
 * 
 * @param head 
 * @return true 
 * @return false 
 */
bool hasCycle2(ListNode *head) {
    set<ListNode *> chest;

    while(head != NULL){
        if (chest.insert(head).second == false ) return true; //Value node is in the set
        head=head->next;
    }

    return false;
}

bool hasCycle(ListNode *head) {
    ListNode* slow = head;
    ListNode*fast = NULL;
    if(head != NULL){
        fast = head->next;
    }

    while (slow!=NULL && fast!=NULL)
    {
        if(slow == fast) return true;

        if(fast->next != NULL){ //update fast
            if(slow == fast->next) return true;
            fast = fast->next->next;
        } else {
            fast= fast->next;
        }

        slow = slow->next; //update slow
    }
    
    return false; //they both hit null so no cycle
        
}

bool detectLoop(ListNode* list)
{
    struct ListNode *slow_p = list;
    struct ListNode *fast_p = list;
 
    while (slow_p && fast_p && fast_p->next) {
        slow_p = slow_p->next;
        fast_p = fast_p->next->next;
        if (slow_p == fast_p) {
            return 1;
        }
    }
    return 0;
}

ListNode* middleNode(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    
    return slow; 
}