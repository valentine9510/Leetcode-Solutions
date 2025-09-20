#include <bits/stdc++.h>


using namespace std;

 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
public:
    bool hasCycle(ListNode *head) {
        struct ListNode *slow_p = head;
        struct ListNode *fast_p = head;
    
        while (fast_p && fast_p->next && fast_p->next->next) {
            slow_p = slow_p->next;
            fast_p = fast_p->next->next;

            if (slow_p == fast_p)
                return 1;

        }
        return 0;
            
    }
};