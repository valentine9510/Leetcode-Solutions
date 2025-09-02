#include <bits/stdc++.h>


using namespace std;

/*
 Add Two Numbers
Solved
Medium
Topics
Companies
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself. 

Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.
Example 2:

Input: l1 = [0], l2 = [0]
Output: [0]
Example 3:

Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
Output: [8,9,9,9,0,0,0,1]
 

Constraints:

The number of nodes in each linked list is in the range [1, 100].
0 <= Node.val <= 9
It is guaranteed that the list represents a number that does not have leading zeros.
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* dummy = new ListNode(0);  // Dummy node to simplify list construction
        ListNode* current = dummy;
        
        while (l1 != NULL || l2 != NULL || carry != 0) {
            int sum = carry;
            
            if (l1 != NULL) {
                sum += l1->val;
                l1 = l1->next;
            }
            
            if (l2 != NULL) {
                sum += l2->val;
                l2 = l2->next;
            }
            
            carry = sum / 10;  // Calculate carry for next iteration
            int value = sum % 10;  // Current node value
            
            current->next = new ListNode(value);
            current = current->next;
        }
        
        return dummy->next;  // Return the next node after dummy
    }
};






class Solution {
    public:
        ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
            ListNode head = ListNode(0);
            ListNode *tail = &head;

            int carry = 0;

            while (l1 || l2 || carry)
            {
                int sum = 0;
                if(l1){
                    sum += l1->val;
                    l1 = l1->next;
                }

                if(l2){
                    sum += l2->val;
                    l2 = l2->next;
                }

                sum += carry; 

                ListNode* temp = new ListNode;
                tail->next = temp;
                tail = tail->next;

                tail->val = sum%10;
                carry = sum/10;
            }

            return head.next;
        }
};