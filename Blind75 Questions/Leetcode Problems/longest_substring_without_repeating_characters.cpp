#include <bits/stdc++.h>

using namespace std;

/*
    keep track of largest length found
    keep track of start index
    for each element, place it into a set. if we find a repeating element, max = max(max, sizeofSet)
    Complexity : Time 0(n), Space 0(n)
*/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int longest =0;
        unordered_set<char>store;
        deque<char> slidingWindow;
        
        for(int i =0; i < s.size(); i++){
            auto res = store.insert(s.at(i));
            slidingWindow.push_back(s.at(i));

            /* Object already in set */
            if(res.second == false){
                /* Remove items from set and dequeue before repeated object */
                while (slidingWindow.front() != s.at(i))
                {
                    store.erase(slidingWindow.front()); 
                    slidingWindow.pop_front();
                }

                /* Remove the repeated element */
                slidingWindow.pop_front();
            }

            /* Update max */
            longest = std::max(longest, static_cast<int>(slidingWindow.size()));

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
