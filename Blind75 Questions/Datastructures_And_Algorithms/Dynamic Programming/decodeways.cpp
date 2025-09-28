#include <bits/stdc++.h>

using namespace std;

/*
You have intercepted a secret message encoded as a string of numbers. The message is decoded via the following mapping:

"1" -> 'A'

"2" -> 'B'

...

"25" -> 'Y'

"26" -> 'Z'

However, while decoding the message, you realize that there are many different ways you can decode the message because some codes are contained in other codes ("2" and "5" vs "25").

For example, "11106" can be decoded into:

"AAJF" with the grouping (1, 1, 10, 6)
"KJF" with the grouping (11, 10, 6)
The grouping (1, 11, 06) is invalid because "06" is not a valid code (only "6" is valid).
Note: there may be strings that are impossible to decode.

Given a string s containing only digits, return the number of ways to decode it. If the entire string cannot be decoded in any valid way, return 0.
*/


class Solution {
public:
    unordered_map<string, int> store; //memoization
    int numDecodings(string s) {
        if(store.find(s) != store.end()) return store[s];

        if(s.empty()) return 1;

        int soln = 0;

        for(int i = 1; i <= 26; i++){
            if(i <= 9 && (s[0] == ('0' + i))) {
                string new_s = s;
                new_s.erase(0,1);
                soln += numDecodings(new_s);
            } else if( s.substr(0,2) == to_string(i) ) { //if first 2 elements are to be removed
                string new_s = s;
                new_s.erase(0,2);
                soln += numDecodings(new_s);
            }
        }

        store[s] = soln;
        return soln;
    }
};

class Solution {
public:
    unordered_map<string, int> memo;

    int numDecodings(string s) {
        // Base case: empty string = 1 valid decoding
        if (s.empty()) return 1;

        if (memo.find(s) != memo.end()) return memo[s];

        int ways = 0;

        // Option 1: take one digit
        if (s[0] != '0') {
            ways += numDecodings(s.substr(1));
        }

        // Option 2: take two digits (if possible)
        if (s.size() >= 2) {
            int val = stoi(s.substr(0, 2));
            if (val >= 10 && val <= 26) { // valid 2-digit decode
                ways += numDecodings(s.substr(2));
            }
        }

        return memo[s] = ways;
    }
};

