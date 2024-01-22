/**
 * @file DynamicProgramming.cpp
 * @author Valentine Ssebuyungo
 * @brief 
 * @version 0.1
 * @date 2024-01-09
 * 
 * @copyright Copyright (c) 2024
 * 
 */

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

/**
 * @brief Place magazine in map, key is char; value is number of times that char occurs
 * Go through every value in the ransomNote, if it found in the map and the value of chars is more than 0 then move to next value
 * return true if you manage to complete ransomNote
 * 
 */

bool canConstruct(string ransomNote, string magazine) {
    unordered_map<char, int> magazineStore;

    for(char i : magazine){ //update store magazine
        if(magazineStore.find(i) == magazineStore.end()){
            //not in magazine
            magazineStore.insert(make_pair(i,1));
        } else {
            magazineStore.at(i)++; //else add on the count
        }
    }

    //now go through ransomNote
    for(int i = 0; i < ransomNote.size(); i++){
        if(magazineStore.find(ransomNote[i]) == magazineStore.end()){
            return false; //not in map
        } else {
            //in map
            magazineStore.at(ransomNote[i])--;

            if(magazineStore.at(ransomNote[i]) < 0){
                return false;
            }
        }
    }

    return true;
}