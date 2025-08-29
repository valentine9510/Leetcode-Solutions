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

/* Chat GPT Solution */
class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        if (n == 0) return 0;

        vector<int> dp(n + 1, 0);
        dp[n] = 1;                          // empty suffix has 1 way
        dp[n - 1] = (s[n - 1] != '0');      // last char: 1 way if not '0'

        for (int i = n - 2; i >= 0; --i) {
            if (s[i] == '0') { dp[i] = 0; continue; }
            dp[i] = dp[i + 1];              // one digit
            if (s[i] == '1' || (s[i] == '2' && s[i + 1] <= '6'))
                dp[i] += dp[i + 2];         // two digits
        }
        return dp[0];
    }
};
