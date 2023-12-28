/**
 * @file Binary_Search_Tree.cpp
 * @author Valentine Ssebuyungo
 * @brief  All about Graph Questions
 * @version 0.1
 * @date 2023-11-30
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <set>
#include <sstream>
#include <queue>
#include <stack>
#include <list>
#include <map>
#include <unordered_map>
#include <math.h>

using namespace std;

///////////////////////////////////////////////////////
/////////////////////   HEADERS  //////////////////////
///////////////////////////////////////////////////////
/**
 * @brief Find a path btn 2 nodes
 * 
 */
bool hasPath(std::unordered_map<std::string, std::vector<std::string>> graph, std::string src, std::string dst);

/**
 * @brief Given an edge list, can you find a connection btn 2 nodes * 
 */
std::unordered_map<std::string, std::vector<std::string>> edgeList_to_adjacency_list(std::vector<std::tuple<std::string, std::string>> edges);
bool undirectedPath(std::vector<std::tuple<std::string, std::string>> edges, std::string src, std::string dst);

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
int connectedComponentsCount(std::unordered_map<int, std::vector<int>> graph);

/**
 * @brief 
 * Write a function, largestComponent, 
 * that takes in an unordered_map representing the adjacency list of an undirected graph. 
 * The function should return the size of the largest connected component in the graph.
 * 
 * Plan 
 * Use DFS
 * For each element in map, explore as far as we can go
 * track difference in size of set
 */
int largestComponent(std::unordered_map<int, std::vector<int>> graph);

/**
 * @brief Write a function, shortestPath, that takes in a vector of edges for an undirected graph and two nodes (nodeA, nodeB). 
 * The function should return the length of the shortest path between A and B. 
 * Consider the length as the number of edges in the path, not the number of nodes. 
 * If there is no path between A and B, then return -1.
 * 
 * Plan
 * Edges to adjency list
 * 
 */
int shortestPath(std::vector<std::tuple<std::string, std::string>> edges, std::string nodeA, std::string nodeB);

/**
 * @brief minimum island
Write a function, minimumIsland, that takes in a grid containing Ws and Ls. 
W represents water and L represents land. 
The function should return the size of the smallest island. 
An island is a vertically or horizontally connected region of land.
 * 
 */
int islandCount(vector<vector<char>>& grid);


/**
 * @brief 
 * 
 * @param grid 
 * @return int 
 */
int minimumIsland(vector<vector<char>>& grid);

///////////////////////////////////////////////////////
////////////////////// SOLUTION 1 //////////////////////
///////////////////////////////////////////////////////

/**
 * @brief has path
 * 
 * Write a function, hasPath, that takes in an unordered map representing the adjacency list of a directed acyclic graph and two nodes (src, dst). 
 * The function should return a boolean indicating whether or not there exists a directed path between the source and destination nodes.
 * 
 */
bool hasPath(std::unordered_map<std::string, std::vector<std::string>> graph, std::string src, std::string dst) {
  // todo
  if(src == dst) return true; //we found it
  
  //Use DFS, can we go to the node
  for(int i = 0; i < graph.at(src).size(); i++){
    //scroll through array and ensure that each of the nodes can reach our desired node
    if(hasPath(graph, graph.at(src).at(i), dst) == true){
        return true;
    }

  }
  return false; //after DFS none has reached the desired note
}

///////////////////////////////////////////////////////
////////////////////// SOLUTION 2 //////////////////////
///////////////////////////////////////////////////////

/**
 * @brief Write a function, undirectedPath, that takes in a vector of edges for an undirected graph and two nodes (nodeA, nodeB). 
 * The function should return a boolean indicating whether or not there exists a path between nodeA and nodeB.
 * 
 * In these scenarios, turn the edge list into an adjacency list
 * 
 */
std::unordered_map<std::string, std::vector<std::string>> edgeList_to_adjacency_list(std::vector<std::tuple<std::string, std::string>> edges) {
    std::unordered_map<std::string, std::vector<std::string>> solution;

    for(auto edge : edges){
      string firstPoint = std::get<0>(edge);
      string secondPoint = std::get<1>(edge);

      if(solution.find(firstPoint) == solution.end()) solution[firstPoint] = {};
      if(solution.find(secondPoint) == solution.end()) solution[secondPoint] = {};

      solution[firstPoint].push_back(secondPoint); //add first -> second
      solution[secondPoint].push_back(firstPoint); //add second -> first
    }

    return solution;
}

bool hasPathHelper (std::unordered_map<std::string, std::vector<std::string>> graph, std::string src, std::string dst, std::set<string> visitSet = {}) {
  if(src == dst) return true;
  if(visitSet.find(src) != visitSet.end()) return false; //we have already visited this so exit

  //insert into set
  visitSet.insert(src);

  for(int i = 0; i < graph.at(src).size(); i++){
    if(hasPathHelper(graph, graph.at(src).at(i), dst, visitSet) == true){
      return true;
    }
  }

  return false;
}

/**
 * @brief Use DFS
 * 
 * Use a set to track visited nodes
 * Use DFS to stroll through array
 * 
 * @param edges 
 * @param src 
 * @param dst 
 * @return true 
 * @return false 
 */
bool undirectedPath(std::vector<std::tuple<std::string, std::string>> edges, std::string src, std::string dst) {
  // todo
  std::unordered_map<std::string, std::vector<std::string>> graph = edgeList_to_adjacency_list(edges);


  return hasPathHelper(graph, src, dst);
}

///////////////////////////////////////////////////////
////////////////////// SOLUTION 3 /////////////////////
///////////////////////////////////////////////////////

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

///////////////////////////////////////////////////////
////////////////////// SOLUTION 4 /////////////////////
///////////////////////////////////////////////////////

int largestComponent(std::unordered_map<int, std::vector<int>> graph){
  std::set<int> visitedSet;
  int largestComponent = 0;

  for(auto it = graph.begin(); it != graph.end(); it++){
    int sizeBefore = visitedSet.size();

    explore(graph, visitedSet, it->first); 

    int sizeAfter = visitedSet.size();

    largestComponent = std::max(largestComponent, (sizeAfter - sizeBefore)); //keep track of maximum
  }

  return largestComponent;
}

///////////////////////////////////////////////////////
////////////////////// SOLUTION 5 /////////////////////
///////////////////////////////////////////////////////
int has_path_step_counter( std::unordered_map<std::string, std::vector<std::string>> graph, std::string nodeA, std::string nodeB, std::set<std::string> visitSet = {}, int currentSteps = 0 ){
  //base cases
  if(nodeA == nodeB) return currentSteps;

  //if nodeA in set, we have a cycle
  auto insertResult = visitSet.insert(nodeA);

  if(insertResult.second == false) return -1; //cycle

  currentSteps++;

  int minDistance = INT_MAX;

  //traverse
  for(int i = 0; i < graph.at(nodeA).size(); i++){
    int distance = has_path_step_counter(graph, graph.at(nodeA).at(i), nodeB, visitSet, currentSteps);
    if(distance != -1){
      minDistance = std::min(minDistance, distance);
    }
  }

  if(minDistance != INT_MAX){
      return minDistance;
  }

  return -1;
}

int shortestPath(std::vector<std::tuple<std::string, std::string>> edges, std::string nodeA, std::string nodeB){
  //find adjency list
  std::unordered_map<std::string, std::vector<std::string>> graph = edgeList_to_adjacency_list(edges); //to adjency list

  //has path nodeA nodeB
  return has_path_step_counter(graph, nodeA, nodeB);
}

int shortestPath2(std::vector<std::tuple<std::string, std::string>> edges, std::string nodeA, std::string nodeB){
  //find adjency list
  std::unordered_map<std::string, std::vector<std::string>> graph = edgeList_to_adjacency_list(edges); //to adjency list

  set<string> visitedSet = {};

  queue<pair<string, int>> queueStore = {};
  queueStore.push(make_pair(nodeA, 0));

  while(queueStore.empty() == false){ //while queue is not empty
    auto queueElement = queueStore.front();
    queueStore.pop();

    if(queueElement.first == nodeB) return queueElement.second; //return distance

    //add all elements on adjency list
    for(int i = 0; i < graph.at(queueElement.first).size(); i++){
      auto insertResult = visitedSet.insert(graph[queueElement.first].at(i));

      if(insertResult.second == true){ //only if insertion is successful
          queueStore.push(make_pair(graph[queueElement.first].at(i), queueElement.second+1)); //add new nodes with distance+1
      }

    }

  }

  return -1;
}
///////////////////////////////////////////////////////
////////////////////// SOLUTION 6 /////////////////////
///////////////////////////////////////////////////////
/**
 * @brief Plan
 * Have a boolean 2D array initialised to false
 * Go through Grid from Left to Right
 * If I find a 1 and is false , add one to islands and send to helper
 * 
 * Helper
 * if out of bounds return
 * if it is 0 return
 * Mark visited
 * 
 * Go left,
 * Go down,
 * Go right,
 * Go up,
 */
void numIsandsHelper(int row, int col, vector<vector<char>>& grid, vector<vector<bool>>& boolGrid){
    //Out of bounds -> return
    if(row >= grid.size() || row < 0 || col >= grid.at(row).size() || col < 0 ) return;
    // if water -> return
    if(grid.at(row).at(col) == 'W') return;
    //if already visited, return
    if(boolGrid.at(row).at(col) == true) return; //we already visited this

    //Mark visited
    boolGrid.at(row).at(col) = true;

    //Else move on and false out neighbours right
     numIsandsHelper(row,col+1,grid,boolGrid);
    //Else move on and false out neighbours down
    numIsandsHelper(row+1,col,grid,boolGrid);

    //Else move on and false out neighbours up
      numIsandsHelper(row-1,col,grid,boolGrid);
    //Else move on and false out neighbours left
      numIsandsHelper(row,col-1,grid,boolGrid);
}

int islandCount(vector<vector<char>>& grid){
    int islandsFound = 0;
    if (grid.size() == 0 ) return islandsFound;
    vector<vector<bool>> boolGrid (grid.size(),vector<bool> (grid.at(0).size(),false));

    for(auto i = 0; i < grid.size(); i++){
        int gridWidth = grid.at(i).size();

        for(auto j = 0; j < gridWidth; j++){

            if(grid.at(i).at(j) == 'L' && boolGrid.at(i).at(j) == false) {

                islandsFound++; //Found an island
                int currentRow = i; int currentCol = j; //Start falsing out other islands around this
                numIsandsHelper(i,j,grid,boolGrid);
            }
        }
    }

    return islandsFound;
}

///////////////////////////////////////////////////////
////////////////////// SOLUTION 7 /////////////////////
///////////////////////////////////////////////////////
int minIsandsHelper(int row, int col, vector<vector<char>>& grid, vector<vector<bool>>& boolGrid){
    //Out of bounds -> return
    if(row >= grid.size() || row < 0 || col >= grid.at(row).size() || col < 0 ) return 0;
    // if water -> return
    if(grid.at(row).at(col) == 'W') return 0;
    //if already visited, return
    if(boolGrid.at(row).at(col) == true) return 0; //we already visited this

    //Mark visited
    boolGrid.at(row).at(col) = true;
    int islandSize = 1; //initialise to 1 as we have found this

    //Else move on and false out neighbours right
    islandSize += minIsandsHelper(row,col+1,grid,boolGrid);
    //Else move on and false out neighbours down
    islandSize += minIsandsHelper(row+1,col,grid,boolGrid);

    //Else move on and false out neighbours up
    islandSize +=  minIsandsHelper(row-1,col,grid,boolGrid);
    //Else move on and false out neighbours left
    islandSize +=  minIsandsHelper(row,col-1,grid,boolGrid);

    return islandSize;
}

int minimumIsland(vector<vector<char>>& grid){
    int minIsland = INT_MAX;
    if (grid.size() == 0 ) return minIsland;
    vector<vector<bool>> boolGrid (grid.size(),vector<bool> (grid.at(0).size(),false));

    for(auto i = 0; i < grid.size(); i++){
        int gridWidth = grid.at(i).size();

        for(auto j = 0; j < gridWidth; j++){

            if(grid.at(i).at(j) == 'L' && boolGrid.at(i).at(j) == false) {
                
                minIsland = std::min(minIsandsHelper(i,j,grid,boolGrid), minIsland );
            }
        }
    }

    return minIsland;
}