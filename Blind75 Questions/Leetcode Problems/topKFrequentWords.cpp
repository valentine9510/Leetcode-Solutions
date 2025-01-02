#include <bits/stdc++.h>

using namespace std;

/**
 * @brief 
 * 
 * Given an array of strings words and an integer k, return the k most frequent strings.

Return the answer sorted by the frequency from highest to lowest. Sort the words with the same frequency by their lexicographical order.

 

Example 1:

Input: words = ["i","love","leetcode","i","love","coding"], k = 2
Output: ["i","love"]
Explanation: "i" and "love" are the two most frequent words.
Note that "i" comes before "love" due to a lower alphabetical order.
Example 2:

Input: words = ["the","day","is","sunny","the","the","the","sunny","is","is"], k = 4
Output: ["the","is","sunny","day"]
Explanation: "the", "is", "sunny" and "day" are the four most frequent words, with the number of occurrence being 4, 3, 2 and 1 respectively.
 
 * 
 */

/*
Given keep a map to keep track of the frequencies

keep a min heap
*/
class Solution {
public:
    struct compareVector {
        bool operator()(const pair<string,int> &a, const pair<string,int> b){
            if(a.second == b.second)
                return b.first < a.first; //smaller word comes first

            return b.second > a.second; //max heap, bigger freq comes first
        }
    };
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> store;
        vector<string> soln;

        //add them to queue
        for(auto temp : words)
            store[temp]++;

        //make priority min heap
        priority_queue<pair<string,int>, vector<pair<string, int>>, compareVector> words_heap;

        //push elements onto the min heap, we only push elements that 
        for(auto store_pair : store)
            words_heap.push(store_pair);

        //empty heap into array
        while (k > 0)
        {
            soln.push_back(words_heap.top().first);
            words_heap.pop();
            k--;
        }
        
        return soln;
    }
};