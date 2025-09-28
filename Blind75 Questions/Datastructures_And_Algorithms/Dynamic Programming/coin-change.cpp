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
#include <headers.h>

using namespace std;

/** * 
 You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.
Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.
You may assume that you have an infinite number of each kind of coin.

Example 1:

Input: coins = [1,2,5], amount = 11
Output: 3
Explanation: 11 = 5 + 5 + 1
Example 2:

Input: coins = [2], amount = 3
Output: -1
Example 3:

Input: coins = [1], amount = 0
Output: 0
 * 
 */
class Solution {
private:
    unordered_map<int, int> storage; //key->coin, value-> minimum ways, memory to optimize our algorithm
public:
    int coinChange(vector<int>& coins, int amount) {
        /**
         * @brief I want to use DP 
         * Base case is if my balance is negative or is zero
         * 
         * if it positive, check to see if my array can help me complete it to zero
         * 
         * //add memoization for a map
         * 
         */
        if(storage.find(amount) != storage.end()) return storage[amount]; //if the value is in our map, just return it

        if(amount == 0) return 0; //current amout
        if(amount < 0 ) return -1; //couldn't find a path

        int minimum = INT_MAX;

        for(int coin : coins){
            int temp = coinChange(coins, amount-coin);

            if(temp != -1){ //we found a way
                minimum = std::min(minimum, temp); //get the minimum value
            }
        }

        if(minimum == INT_MAX) storage[amount] = -1; //we didnt find a way
        else storage[amount] = minimum+1;//return paths plus this one

        return storage[amount]; 
        
    }
};


int main(){
    
    return 0;
}

/**
 * @brief
 * Use dfs
 * 
 * Keep count of how many coins we have used. 
 * Keep track of the smallest number, or set it to -1
 *          when amount is zero, update the number
 *  
 */
unordered_map<int, int> store;
int coinChange(vector<int>& coins, int amount) {
    if(amount < 0) return -1;
    if(amount == 0) return 0;
    if(store.find(amount) != store.end()) store[amount];

    int minCoins = INT_MAX;
    minCoins = numeric_limits<int>::max();

    for(int i = 0; i < coins.size(); i++){
        int res = coinChange(coins, amount-coins[i]);

        if(res != -1) minCoins = std::min(minCoins, res);
    }

    store[amount] = (minCoins == INT_MAX) ? -1 : minCoins+1; //add our current coin as well

    return store[amount];
}





unordered_map<int,int> store;
int coinChange(vector<int>& coins, int amount) {
    if(amount < 0) return -1;
    if(amount = 0) return 0;
    if(store.find(amount) != store.end()) return store[amount];

    int min_ways = numeric_limits<int>::max();

    for(auto curr_coin : coins){
        int res = coinChange(coins, amount-curr_coin);

        if(res != -1) min_ways = std::min(min_ways, res);
    }

    if(min_ways != numeric_limits<int>::max()) store[amount] = min_ways + 1; /* Value is not updated */
    else store[amount] = -1;

    return store[amount];
}
