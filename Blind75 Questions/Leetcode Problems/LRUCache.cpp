/**
 * @file LRUCache.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2024-08-19
 * 
 * @copyright Copyright (c) 2024
 * 
 */

/*
    Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.

    Implement the LRUCache class:

    LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
    int get(int key) Return the value of the key if the key exists, otherwise return -1.
    void put(int key, int value) Update the value of the key if the key exists. Otherwise, add the key-value pair to the cache. If the number of keys exceeds the capacity from this operation, evict the least recently used key.
    The functions get and put must each run in O(1) average time complexity.

    

    Example 1:

    Input
    ["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
    [[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
    Output
    [null, null, null, 1, null, -1, null, -1, 3, 4]

    Explanation
    LRUCache lRUCache = new LRUCache(2);
    lRUCache.put(1, 1); // cache is {1=1}
    lRUCache.put(2, 2); // cache is {1=1, 2=2}
    lRUCache.get(1);    // return 1
    lRUCache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
    lRUCache.get(2);    // returns -1 (not found)
    lRUCache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
    lRUCache.get(1);    // return -1 (not found)
    lRUCache.get(3);    // return 3
    lRUCache.get(4);    // return 4
    

    Constraints:

    1 <= capacity <= 3000
    0 <= key <= 104
    0 <= value <= 105
    At most 2 * 105 calls will be made to get and put.
*/

/*
Have a map
    Key -> int(Input Key)
    Value -> iterator to list

Have a list
    Double linked list
    stores pairs<int, int> 
        First is Input Key
        Second is Input Value



*/


#include <bits/stdc++.h>
using namespace std;

class LRUCache {
private:
    int capacity;
    list<pair<int, int>> cacheList; // Stores key-value pairs
    unordered_map<int, list<pair<int, int>>::iterator> cacheMap; // Maps keys to list iterators

public:
    LRUCache(int capacity) : capacity(capacity) {}
    
    int get(int key) {
        // Check if the key is in the cache
        if (cacheMap.find(key) == cacheMap.end()) {
            return -1; // Key not found
        }
        
        // Key found, move the key to the front (most recently used)
        cacheList.splice(cacheList.begin(), cacheList, cacheMap[key]);
        
        // Return the value associated with the key
        return cacheMap[key]->second;
    }
    
    void put(int key, int value) {
        // If the key is already in the cache, update its value and move it to the front
        if (cacheMap.find(key) != cacheMap.end()) {
            cacheMap[key]->second = value;
            cacheList.splice(cacheList.begin(), cacheList, cacheMap[key]);
            return;
        }
        
        // If the cache is at capacity, remove the least recently used element
        if (cacheList.size() == capacity) {
            // Remove the element from the map and list
            int lruKey = cacheList.back().first;
            cacheList.pop_back();
            cacheMap.erase(lruKey);
        }
        
        // Insert the new key-value pair at the front of the list
        cacheList.emplace_front(key, value);
        cacheMap[key] = cacheList.begin();
    }

};


/*
Have a map
    Key -> int(Input Key)
    Value -> iterator to list

Have a list
    Double linked list
    stores pairs<int, int> 
        First is Input Key
        Second is Input Value

get function
    If value is not in map
        return -1

    Move to front

    return value

put function
    If value in Map
        Update Value
        Move the Value to the front

    If Value is not in Map and List is at Capacity
        Remove the Last Value in the List
        Remove that key from the Map

        Insert new Value into the Map
        Place Value at Front of List


*/
class LRUCache {
private:
    int capacity;
    unordered_map<int, list<pair<int,int>>::iterator> inputMap; //Map-key -> Key, Map-Value-> iterator to list
    list<pair<int,int>> inputList; //First -> Key, Second-> Value

public:
    LRUCache(int capacity){
        this->capacity = capacity;
    }
    
    int get(int key) {
        if(inputMap.find(key) == inputMap.end()) return -1; //not in map

        //Value is in map, move it to front
        inputList.splice(inputList.begin(),inputList, inputMap.at(key));

        return inputMap.at(key)->second; //return value
    }
    
    void put(int key, int value) {
        if(inputMap.find(key) != inputMap.end()){
            //Value is in map
            inputMap.at(key)->second = value; //update value

            //move to front
            inputList.splice(inputList.begin(), inputList, inputMap[key]);

            return;
        }

        //Value is not in map

        //Remove last if we are at capacity
        if(inputList.size() >= capacity){
            auto delete_element = inputList.back();

            //remove from map
            inputMap.erase(delete_element.first);

            //remove from list
            inputList.pop_back(); 
        }

        //Add to list and map
        inputList.emplace_front(key,value);

        //Add to map
        inputMap.insert(std::make_pair(key, inputList.begin()));
        
    }
};