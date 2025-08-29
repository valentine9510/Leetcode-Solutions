#include <bits/stdc++.h>

using namespace std;


/**
 * @brief Similar to counting islands
 * 
 * Plan
 * keep track of all visited nodes
 * 
 * For each component in graph
 *  Check if it is visited set, if not 
 *      Count++
 * 
 *  After, then visit each of its components
 */
/**
 * @brief 
 * 
 * @param graph 
 * @param visitedSet Must be by reference otherwise we fail
 * @param node 
 * @return true 
 * @return false 
 */
bool explore(std::unordered_map<int, std::vector<int>> graph, set<int> & visitedSet, int node){
  auto result = visitedSet.insert(node);
  if(result.second == false) return false; //it is in the set as insertion has failed

  for(int i = 0; i < graph.at(node).size(); i++){
    explore(graph, visitedSet, graph.at(node).at(i));
  }

  return true;
}

int connectedComponentsCount(std::unordered_map<int, std::vector<int>> graph) {
  set<int> visitedSet;
  int count =0;

  for(auto it = graph.begin(); it != graph.end(); it++){
    if(explore(graph, visitedSet, it->first) == true){
      count++;
    }
  }

  return count;
}