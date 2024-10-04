/**
 * @file time_based_key_value_store.cpp
 * @author Valentine Roland
 * @brief 
 * @version 0.1
 * @date 2024-08-13
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <bits/stdc++.h>
#include <string>


using namespace std;

/**
 * Design a time-based key-value data structure that can store multiple values for the same key at different time stamps and retrieve the key's value at a certain timestamp.

 *   Implement the TimeMap class:

 *  TimeMap() Initializes the object of the data structure.
    void set(String key, String value, int timestamp) Stores the key key with the value value at the given time timestamp.
    String get(String key, int timestamp) Returns a value such that set was called previously, with timestamp_prev <= timestamp. If there are multiple such values, it returns the value associated with the largest timestamp_prev. If there are no values, it returns "".
    

    Example 1:

    Input
    ["TimeMap", "set", "get", "get", "set", "get", "get"]
    [[], ["foo", "bar", 1], ["foo", 1], ["foo", 3], ["foo", "bar2", 4], ["foo", 4], ["foo", 5]]
    Output
    [null, null, "bar", "bar", null, "bar2", "bar2"]

    Explanation
    TimeMap timeMap = new TimeMap();
    timeMap.set("foo", "bar", 1);  // store the key "foo" and value "bar" along with timestamp = 1.
    timeMap.get("foo", 1);         // return "bar"
    timeMap.get("foo", 3);         // return "bar", since there is no value corresponding to foo at timestamp 3 and timestamp 2, then the only value is at timestamp 1 is "bar".
    timeMap.set("foo", "bar2", 4); // store the key "foo" and value "bar2" along with timestamp = 4.
    timeMap.get("foo", 4);         // return "bar2"
    timeMap.get("foo", 5);         // return "bar2"
 * 
 */

/**
 * @brief Plan
 * 
 * 1. Have a map that stores keys
 * 2. The will be another map whose key is the "Value", and the value is the minimum value for that particular key
 * 
 */

#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

/*

Explanation:
Data Structure:
We use an unordered_map<string, vector<pair<int, string>>> where the key is a string, and the value is a vector of pairs, with each pair containing a timestamp and its corresponding value.
Set Function:

The set function adds the (timestamp, value) pair to the vector associated with the key. We assume that timestamps are given in non-decreasing order.
Get Function:

The get function performs a binary search on the vector of (timestamp, value) pairs. The goal is to find the largest timestamp that is less than or equal to the given timestamp.

We use a binary search by adjusting the left and right pointers:
    If the middle timestamp is less than or equal to the given timestamp, we move the left pointer to mid + 1 to search for a potentially larger timestamp.
    If the middle timestamp is greater, we move the right pointer to mid - 1.
     the loop, right will point to the largest valid timestamp, if it exists.

    Result:
        If a valid timestamp is found (right >= 0), return the associated value.
        If no such timestamp exists, return an empty string.

Efficiency:
    The set function is O(1) for each call, assuming the timestamps are inserted in order.
    The get function is O(log n) due to the binary search, where n is the number of timestamps for the key.

*/

class TimeMap {
public:
    // Store key -> vector of pairs {timestamp, value}
    unordered_map<string, vector<pair<int, string>>> store;

    // Constructor
    TimeMap() {}

    // Set function to store the key-value pair with a timestamp
    void set(string key, string value, int timestamp) {
        store[key].push_back({timestamp, value});
    }

    // Get function to retrieve the value at a specific timestamp
    string get(string key, int timestamp) {
        if (store.find(key) == store.end()) {
            return ""; // If the key doesn't exist, return an empty string
        }

        const vector<pair<int, string>>& timeValuePairs = store[key];

        // Binary search to find the largest timestamp <= given timestamp
        int left = 0, right = timeValuePairs.size() - 1;
        string result = ""; // Default value if no valid timestamp is found

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (timeValuePairs[mid].first <= timestamp) {
                result = timeValuePairs[mid].second; // Update the result to the current mid
                left = mid + 1;            // Move to the right half
            } else {
                right = mid - 1;           // Move to the left half
            }
        }

        return result; // If no valid timestamp found, return an empty string
    }
};

int main() {
    TimeMap timeMap;
    timeMap.set("foo", "bar", 1);
    cout << timeMap.get("foo", 1) << endl; // Output: "bar"
    cout << timeMap.get("foo", 3) << endl; // Output: "bar"
    timeMap.set("foo", "bar2", 4);
    cout << timeMap.get("foo", 4) << endl; // Output: "bar2"
    cout << timeMap.get("foo", 5) << endl; // Output: "bar2"

    return 0;
}




class TimeMap {
public:
    // Store key -> {timestamp, value}
    unordered_map<string, map<int, string>> store;

    // Constructor
    TimeMap() {}

    // Set function to store the key-value pair with a timestamp
    void set(string key, string value, int timestamp) {
        store[key][timestamp] = value;
    }

    // Get function to retrieve the value at a specific timestamp
    string get(string key, int timestamp) {
        if (store.find(key) == store.end()) {
            return ""; // If the key doesn't exist, return an empty string
        }

        // Use upper_bound to find the first timestamp greater than the given one
        auto it = store[key].upper_bound(timestamp);
        if (it == store[key].begin()) {
            return ""; // If no timestamp is less than or equal, return an empty string
        }
        --it; // Move to the largest timestamp less than or equal to the given timestamp
        return it->second;
    }
};