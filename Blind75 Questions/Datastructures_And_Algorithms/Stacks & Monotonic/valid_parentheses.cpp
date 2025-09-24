#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> s_store;

        for(char curr : s) {
            // If open, push
            if(curr == '(' || curr == '{' || curr == '[') {
                s_store.push(curr);
            }
            // If close, check stack
            else {
                if(s_store.empty()) return false; // case 1: no opener
                
                char top = s_store.top();
                s_store.pop();

                // case 2: mismatch
                if( (curr == ')' && top != '(') ||
                    (curr == '}' && top != '{') ||
                    (curr == ']' && top != '[') ) {
                    return false;
                }
            }
        }

        // Must have closed everything
        return s_store.empty();
    }
};
