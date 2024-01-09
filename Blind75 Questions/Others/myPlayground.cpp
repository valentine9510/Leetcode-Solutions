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
#include <algorithm>

using namespace std;

int main(void){
    vector<int> temp = {41,94,15,17,68,89};

    sort(temp.rbegin(), temp.rend());

    for (auto i : temp){
        cout << i << " ";
    }

    cout << endl;


}

bool exploreFunction(unordered_map<int, vector<int>> &graph, set<int> & visitedSet, int node){
    //check if we can explore
    if( visitedSet.insert(node).second == false ){
        //already in set 
        return false;
    }

    //explore through all the neighbors by DFS
    for(int i = 0; i < graph.at(node).size(); i++){
        exploreFunction(graph, visitedSet, graph.at(node).at(i)); //visit all nodes
    }

    return true;
}

int connectedComponentsCount(std::unordered_map<int, std::vector<int>> graph) {
    int count = 0;
    set<int> visitedSet;

    for(auto graphIterator = graph.begin(); graphIterator != graph.end(); graphIterator++){
        if(exploreFunction(graph, visitedSet, graphIterator->first) == true){
            count ++;
        }
    }

    return count;
}