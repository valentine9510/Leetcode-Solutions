#include <bits/stdc++.h>
using namespace std;

/*
    Methodology / Pattern

    Pattern: “Array + Hash Map”
    Keep all values in a vector<int> arr so you can pick a random index in O(1).
    Track each value’s index in unordered_map<int,int> pos.
    Insert: if val not present, push_back to arr and record index in pos.
    Remove: to delete val at index i, swap arr[i] with the last element, update that moved element’s index in pos, then pop_back() and erase val from pos. All O(1).
    getRandom: pick a random index k in [0, arr.size()-1] and return arr[k].
    Brute-force alternative you might think of: store only in unordered_set and on getRandom() copy to a vector then pick. That’s O(n) per call — not acceptable.
*/



class RandomizedSet {
private:
    vector<int> arr;                        // stores the elements
    unordered_map<int, int> pos;            // val -> index in arr

    // Random engine: seed once; uniform across indices
    // thread_local is safe if this were used with threads; optional for interviews
    mt19937 rng;
public:
    RandomizedSet() : rng(random_device{}()) {
        // nothing else to do
    }
    
    // Inserts a value to the set. Returns true if the set did not already contain the element.
    bool insert(int val) {
        if (pos.count(val)) return false;           // already present
        pos[val] = (int)arr.size();                 // index where it will be placed
        arr.push_back(val);                         // append to vector
        return true;
    }
    
    // Removes a value from the set. Returns true if the set contained the element.
    bool remove(int val) {
        auto it = pos.find(val);
        if (it == pos.end()) return false;          // not present

        int i = it->second;                         // index of val
        int lastIdx = (int)arr.size() - 1;
        int lastVal = arr[lastIdx];

        // Move last element into position i (if i != lastIdx)
        arr[i] = lastVal;
        pos[lastVal] = i;                           // update moved element's index

        // Remove last element
        arr.pop_back();
        pos.erase(it);                              // erase val from map

        return true;
    }
    
    // Get a random element from the set.
    int getRandom() {
        // Precondition: arr is non-empty based on problem statement;
        // if not guaranteed, handle arr.empty() as needed.
        uniform_int_distribution<int> dist(0, (int)arr.size() - 1);
        return arr[dist(rng)];
    }
};
