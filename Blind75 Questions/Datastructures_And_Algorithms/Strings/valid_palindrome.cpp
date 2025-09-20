#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0;
        int right = s.size() - 1;

        while (left <= right) {
            // Skip non-alphabetic and non-numeric characters
            if (!isalnum(s[left])) {
                left++;
            } else if (!isalnum(s[right])) {
                right--;
            } else {
                // Compare characters after converting to lowercase
                if (tolower(s[left]) != tolower(s[right]))
                    return false;

                left++;
                right--;
            }
        }

        return true;
    }
};
