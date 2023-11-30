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
        else {
            storage[amount] = minimum+1;
        }

        return storage[amount]; //return paths plus this one
        
    }
};


int main(){
    
    return 0;
}
