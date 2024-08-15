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

//FUNCTION HEADERS
int fibonacci(int val, unordered_map<int, int> fib_map);
bool canConstruct(string ransomNote, string magazine);
int gridTraveler(int m, int n, unordered_map<string, int> & gridStore);
int gridTraveler_basic(int m, int n);

bool canSum (int targetSum, vector<int> numbers, unordered_map<int,bool> &store);
bool canSum_basic (int targetSum, vector<int> numbers);
void canSumTester(void);

vector<int>* howSum(int targetSum, vector<int>& numbers, unordered_map<int, vector<int>*>& memo);
void howSum_tester();

bool howSum2(int targetSum, const vector<int>& numbers, unordered_map<int, vector<int>>& memo, vector<int>& result);
void howSum2_tester(void);


//MAIN
int main (void){
    // canSumTester();
    // howSum_tester();
    howSum2_tester();

    return 0;
}

/**
 * @brief Fibonacci memoized
 * 
 * @param val 
 * @param fib_map 
 * @return int 
 */
int fibonacci(int val, unordered_map<int, int> fib_map){
    if(fib_map.find(val) != fib_map.end()) return fib_map[val]; //if we already have the value

    if(val <= 2) return 1;
    
    fib_map[val] = fibonacci(val-1, fib_map) + fibonacci(val-2, fib_map); 

    return fib_map[val];
}


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

/**
 * @brief Grid traveller
 * Base cases -> if one of the edges is 0 -> you cant move
 *            -> if the box is 1,1, you can do nothing
 * 
 * 
 */
int gridTravelerTester (void){
    unordered_map<string, int> gridStore;
    cout << gridTraveler(1,1,gridStore) << endl;
    gridStore.clear();

    cout << gridTraveler(2,3,gridStore)  << endl;
    gridStore.clear();

    cout << gridTraveler(3,2,gridStore) << endl;
    gridStore.clear();

    cout << gridTraveler(3,3,gridStore) << endl;
    gridStore.clear();

    cout << gridTraveler(5,5,gridStore) << endl;
    gridStore.clear();

    cout << gridTraveler(10,10,gridStore) << endl;
    gridStore.clear();


    return 0;
}

int gridTraveler_basic(int m, int n){
    if(m == 1 && n == 1) return 1;
    if(m == 0 || n == 0) return 0;

    return gridTraveler_basic(m-1,n) + gridTraveler_basic(m, n-1);
}

//gridTraveler memoized
int gridTraveler(int m, int n, unordered_map<string, int>& gridStore){
    stringstream inputs; 
    inputs << m << "," << n;
    // cout << "Input str " << inputs.str() << endl;

    if(gridStore.find(inputs.str()) != gridStore.end()){
        // cout << "Used memoized store in map" << endl;
        return gridStore.at(inputs.str());
    } 

    if(m == 1 && n == 1) return 1;
    if(m == 0 || n == 0) return 0;

    gridStore[inputs.str()] = gridTraveler(m-1, n, gridStore) + gridTraveler(m, n-1, gridStore);
    return gridStore[inputs.str()];
}

/*
Write a function -cansum(targetsum, numbers)' that takes in a 
targetSum and an array of numbers as arguments. 
The function should return a boolean indicating whether or not it 
is possible to generate the targetSum using numbers from the array. 
You may use an element of the array as many times as needed. 
You may assume that input numbers are nonnegative. 
*/
bool canSum_basic (int targetSum, vector<int> numbers){
    if(targetSum == 0) return true;
    if(targetSum < 0 ) return false;

    for(int i = 0; i  < numbers.size(); i++){
        int remainder = targetSum - numbers.at(i);
        if(canSum_basic(remainder, numbers) == true){
            return true;
        }
    }

    return false;
}

bool canSum (int targetSum, vector<int> numbers, unordered_map<int,bool> &store){
    if(store.find(targetSum) != store.end()) return store.at(targetSum);
    if(targetSum == 0) return true;
    if(targetSum < 0 ) return false;

    for(int i = 0; i < numbers.size(); i++){
        int remainder = targetSum - numbers.at(i);
        if(canSum(remainder, numbers,store) == true){
            store[targetSum] = true;
            return true;
        }
    }

    store[targetSum] = false;
    return false;
}

void canSumTester(void){
    unordered_map<int,bool> store;
    
    cout << canSum(7, {2,3}, store) << endl;
    store.clear();

    cout << canSum(7, {5,4,3,7}, store) << endl;
    store.clear();

    cout << canSum(7, {2,4}, store) << endl;
    store.clear();

    cout << canSum(8, {2,3,5}, store) << endl;
    store.clear();

    cout << canSum(300, {7,14}, store) << endl;
    store.clear();
}

/*
Write a function • howsum( targetSum, numbers) • 
that takes in a 
targetSum and an array of numbers as arguments. 
The function should return an array containing any combination of 
elements that add up to exactly the targetSum. If there is no 
combination that adds up to the targetSum, then return null. 
If there are multiple combinations possible, you may return any 
single one. 

Method
Subtract from the targetSum from each of the numbers

Base cases : TargetSUm is 0 -> we have a combination, do not add combination to results
             Target is less than 0 -> no combination
*/
void howSum_tester() {
    vector<int> numbers = {2, 3, 5};
    unordered_map<int, vector<int>*> memo;
    int targetSum = 8;

    vector<int>* result = howSum(targetSum, numbers, memo);

    if(result != nullptr) {
        cout << "Combination found: ";
        for(int num : *result) {
            cout << num << " ";
        }
        cout << endl;
    } else {
        cout << "No combination found" << endl;
    }

    // Clean up dynamically allocated memory
    for(auto& pair : memo) {
        delete pair.second;
    }
}

vector<int>* howSum(int targetSum, vector<int>& numbers, unordered_map<int, vector<int>*>& memo) {
    if(memo.find(targetSum) != memo.end()) return memo[targetSum];
    if(targetSum == 0) return new vector<int>();
    if(targetSum < 0) return nullptr;

    for(int num : numbers) {
        int remainder = targetSum - num;
        vector<int>* remainderResult = howSum(remainder, numbers, memo);
        if(remainderResult != nullptr) {
            vector<int>* result = new vector<int>(*remainderResult);
            result->push_back(num);
            memo[targetSum] = result;
            return result;
        }
    }

    memo[targetSum] = nullptr;
    return nullptr;
}

bool howSum2(int targetSum, const vector<int>& numbers, unordered_map<int, vector<int>>& memo, vector<int>& result) {
    if (memo.find(targetSum) != memo.end()) {
        if (memo[targetSum].empty()) return false; // Indicating failure
        result = memo[targetSum];
        return true;
    }
    if (targetSum == 0) return true;
    if (targetSum < 0) return false;

    for (int num : numbers) {
        int remainder = targetSum - num;
        vector<int> remainderResult;
        if (howSum2(remainder, numbers, memo, remainderResult)) {
            remainderResult.push_back(num);
            memo[targetSum] = remainderResult;
            result = remainderResult;
            return true;
        }
    }

    memo[targetSum] = {}; // Indicating failure
    return false;
}

void howSum2_tester(void) {
    vector<int> numbers = {2, 3, 5};
    unordered_map<int, vector<int>> memo;
    int targetSum = 8;

    vector<int> result;
    if (howSum2(targetSum, numbers, memo, result)) {
        cout << "Combination found: ";
        for (int num : result) {
            cout << num << " ";
        }
        cout << endl;
    } else {
        cout << "No combination found" << endl;
    }
}

/*
Write a function 
• canconstruct(target, wordBank)• that accepts a target string and an array of strings. 

The function should return a boolean indicating whether or not the target' can be constructed by concatenating elements of the 
"wordBank" array. 
You may reuse elements of wordBank as many times as needed. 

base cases target is empty -> 
*/

bool canConstruct_basic(string target, vector<string> wordBank){
    if(target.empty() == true) return true;

    for(int i = 0; i < wordBank.size(); i++){
        //if wordbank is prefix of target
        //delete that string from target
        //if remainder is a hit, return true, otherwise try other strings
        if(target.find(wordBank[i]) == 0){
            string remainder = target;
            remainder.erase(0,wordBank.at(i).size());

            if (canConstruct_basic(remainder, wordBank) == true){
                return true;
            }

        }
    }

    //return false as all combinations failed
    return false;
}

bool canConstruct(string target, vector<string> &wordBank, unordered_map<string, bool>&store){
    if(store.find(target) != store.end()) return store.at(target);
    if(target.empty() == true) return true;

    for(int i = 0; i < wordBank.size(); i++){
        //if wordbank is prefix of target
        //delete that string from target
        //if remainder is a hit, return true, otherwise try other strings
        if(target.find(wordBank[i]) == 0){
            string remainder = target;
            remainder.erase(0,wordBank.at(i).size());

            if (canConstruct(remainder, wordBank,store) == true){
                store[target] = true;
                return true;
            }

        }
    }

    //return false as all combinations failed
    store[target] = false;
    return store[target];
}