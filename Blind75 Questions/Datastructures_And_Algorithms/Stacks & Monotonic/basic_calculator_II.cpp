#include <bits/stdc++.h>

using namespace std;


/*
    Given a string s which represents an expression, evaluate this expression and return its value. 
    The integer division should truncate toward zero.
    You may assume that the given expression is always valid. All intermediate results will be in the range of [-231, 231 - 1].
    Note: You are not allowed to use any built-in function which evaluates strings as mathematical expressions, such as eval().

    

    Example 1:

    Input: s = "3+2*2"
    Output: 7
    Example 2:

    Input: s = " 3/2 "
    Output: 1
    Example 3:

    Input: s = " 3+5 / 2 "
    Output: 5
*/

/*
🚶 Step-by-Step Methodology
1. Parsing the string

Traverse character by character.

Skip spaces.

If digit: build the full number (multi-digit possible).

If operator: decide how to handle the previous number.

2. Operator precedence

+ and - → push number (positive or negative) to stack.

* and / → pop last number, apply operation, push result.

This way, precedence is naturally handled because multiplication/division are applied immediately, while addition/subtraction just push values.

3. Final result

Sum everything in the stack.  
*/

class Solution {
public:
    int calculate(string s) {
        stack<int> st;
        long num = 0;   // current number being built
        char op = '+';  // previous operator, assume '+' initially

        for (int i = 0; i < s.size(); i++) {
            char c = s[i];

            // If digit, build the number
            if (isdigit(c)) {
                num = num * 10 + (c - '0');
            }

            // If operator OR last character → process the number
            if ((!isdigit(c) && c != ' ') || i == s.size() - 1) {
                if (op == '+') {
                    st.push(num);
                } else if (op == '-') {
                    st.push(-num);
                } else if (op == '*') {
                    int last = st.top(); st.pop();
                    st.push(last * num);
                } else if (op == '/') {
                    int last = st.top(); st.pop();
                    st.push(last / num);  // integer division truncates toward 0
                }

                // Update operator and reset number
                op = c;
                num = 0;
            }
        }

        // Sum stack values
        int result = 0;
        while (!st.empty()) {
            result += st.top();
            st.pop();
        }

        return result;
    }
};

/* No stack option */
class Solution {
public:
    int calculate(string s) {
        long total = 0;    // sum of resolved terms so far
        long last  = 0;    // last term (pending for * or /)
        long num   = 0;    // current number being built
        char op    = '+';  // previous operator (assume '+' before first number)

        const int n = s.size();
        for (int i = 0; i < n; ++i) {
            char c = s[i];

            // Build multi-digit numbers
            if (isdigit(c)) {
                num = num * 10 + (c - '0');
            }

            // If we hit an operator or the end, resolve the previous op
            if ((!isdigit(c) && c != ' ') || i == n - 1) {
                if (op == '+') {
                    // Flush previous last into total and start a new positive term
                    total += last;
                    last = +num;
                } else if (op == '-') {
                    // Flush previous last into total and start a new negative term
                    total += last;
                    last = -num;
                } else if (op == '*') {
                    // Combine into the last term (higher precedence)
                    last = last * num;
                } else if (op == '/') {
                    // Integer division truncates toward zero in C++
                    // Safe because last is long and num != 0 by constraints
                    last = last / num;
                }

                op = c;   // update op to current operator
                num = 0;  // reset current number
            }
        }

        // Add the final pending term
        return static_cast<int>(total + last);
    }
};

