#include <bits/stdc++.h>

using namespace std;

/*
There are n cities connected by some number of flights. You are given an array flights where flights[i] = [fromi, toi, pricei] indicates that there is a flight from city fromi to city toi with cost pricei.

You are also given three integers src, dst, and k, return the cheapest price from src to dst with at most k stops. If there is no such route, return -1.

*/

/*
    Graphs

    Transform from edge list to adjcacency list

    Find all possible routes if possible and find the cheapest
*/


class Solution {
public:
    unordered_map<int, vector<pair<int, int>>> flightMap; //Key --> Value, Weight

    void edgeListToAdjacency(vector<vector<int>>& flights){

        for(auto flight : flights){
            flightMap[flight[0]].push_back(make_pair(flight[1], flight[2]));
        }
    }

    int flightFinder(int src, int dst, int k, int curr_total){
        if(k < 0) return -1;
        if(src == dst) return curr_total;

        int cheapest_flight = INT_MAX;
        bool impossible = false;

        k--;

        for(auto flight: flightMap[src]){
            int temp_flight = flightFinder(flight.first, dst, k, curr_total + flight.second);

            if(temp_flight > 0){
                cheapest_flight = std::min(cheapest_flight, temp_flight);
            } else {
                impossible = true;
            }
        }

        if(cheapest_flight != INT_MAX) return cheapest_flight;

        return -1;
    }

    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        edgeListToAdjacency(flights);

        return flightFinder(src, dst, k, 0);
    }
};



class Solution {
public:
    unordered_map<int, vector<pair<int,int>>> flightMap;
    vector<vector<int>> memo; // memo[u][kEdgesLeft] = cheapest from u with kEdgesLeft edges

    void build(const vector<vector<int>>& flights){
        for (auto &f: flights) flightMap[f[0]].push_back({f[1], f[2]});
    }

    int dfs(int u, int dst, int kEdgesLeft) {
        if (u == dst) return 0;                 // arrive first
        if (kEdgesLeft == 0) return -1;         // no edges left

        int &m = memo[u][kEdgesLeft];
        if (m != INT_MIN) return m; //Get from memoization

        int best = INT_MAX;
        for (auto [new_src, cost] : flightMap[u]) {
            int sub = dfs(new_src, dst, kEdgesLeft - 1);
            if (sub >= 0 && cost + sub < best) best = cost + sub;
        }
        m = (best == INT_MAX) ? -1 : best;
        return m;
    }

    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        build(flights);
        memo.assign(n, vector<int>(K + 2, INT_MIN)); // K+1 edges allowed
        return dfs(src, dst, K + 1);
    }
};


