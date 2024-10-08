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

using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    //keep track of largest length found
    //keep track of start index
    //for each element, place it into a set. if we find a repeating element, max = max(max, sizeofSet)
    //Complexity : Time 0(n), Space 0(n)
    int lengthOfLongestSubstring(string s) {
        int longest =0;
        unordered_set<char>store;
        deque<char> slidingWindow;
        
        for(int i =0; i < s.size(); i++){
            auto res = store.insert(s.at(i));
            slidingWindow.push_back(s.at(i));


            if(res.second == false){ //This means insertion failed because there was an object already in the set

                //remove items from set and dequeue before repeated object
                while (slidingWindow.front() != s.at(i))
                {
                    store.erase(slidingWindow.front()); //remove items from set

                    slidingWindow.pop_front(); //remove the initial elements from the top of the sliding window
                }

                //found the element
                slidingWindow.pop_front();
            }

            //update the largest element
            if(slidingWindow.size() > longest) longest = slidingWindow.size();

        }

        return longest;
    }
};


int main(){
    Solution soln;
    string s = "abcabcbb";
    cout << "Solution : lengthOfLongestSubstring in " << s << " is " << soln.lengthOfLongestSubstring(s) << endl;
    return 0;
}
