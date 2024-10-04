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
// #include <headers.h>

using namespace std;


class Solution {
public:
    /*
        You are given numCourses and a list of prerequisites. 
        Each prerequisite is a pair where the second course must be taken before the first one. 
        You need to determine if you can finish all the courses, i.e., if you can take all courses without any conflicts.
        
        This problem essentially asks whether the directed graph of courses and prerequisites has a cycle. If there is a cycle, it is impossible to complete all courses.

        1. We are given an edge list
        2. Turn it into a map (adjacency list)
        3. Check if there is a path from course 0 to the last course (numCourses-1)

        //edge case, course may have no prerequisites
    */


    /**
     * @brief Base case is a course withouth any prerequisites
     * Use adjency list
     * Time complexity (O + P)
     * @param numCourses 
     * @param prerequisites 
     * @return true 
     * @return false 
     */
    bool dfs(unordered_map<int, vector<int>>& storage, set<int>& visitSet, int course){
        if(visitSet.find(course) != visitSet.end()){
            //if we have visited it
            return false;
        }
        if(storage.at(course).empty()) return true; //we have no pre-requisites so we can take this course

        visitSet.insert(course);

        for(int preReqCourse : storage.at(course)){ //for each pre-req in the list of courses, can we take it ?
            if (dfs(storage, visitSet, preReqCourse) == false) return false;
        }

        //else course can be taken, you can remove it from the set, for the next cycle
        visitSet.erase(course); //not being visited

        //since we can take the course, remove it from map
        storage.at(course) = {};

        return true;


    }



    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        //create my map
        unordered_map<int, vector<int>> storage; 

        for(int i = 0; i < numCourses; i++){
            storage[i] = {}; //initialise empty map
        }

        for(auto coursePair : prerequisites){
            storage.at(coursePair[0]).push_back(coursePair[1]); //add to the prerequisites
        }

        //now we have our map
        set<int> visitSet; 

        //loop through all courses and see if you can take them 
        for(int i = 0; i < numCourses; i++){
            if(dfs(storage, visitSet, i) == false) return false;
        }

        return true; 

    }
};




/**
 * @brief Chat GPT Solution -- wrong
 * 
 */

class Solution {
public:
    // Function to check if we can finish all courses
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        // Step 1: Create a graph representation
        vector<vector<int>> graph(numCourses); // Adjacency list
        vector<int> visited(numCourses, 0); // 0 = unvisited, 1 = visiting, 2 = visited, using codes - you can also be removed the visited from a sit
        
        // Build the graph from prerequisites
        for(auto pre : prerequisites) {
            graph[pre.second].push_back(pre.first);
        }
        
        // Step 2: Use DFS to detect a cycle
        for(int i = 0; i < numCourses; i++) {
            if(!dfs(graph, visited, i)) {
                return false; // Cycle detected
            }
        }
        
        return true; // No cycle detected
    }
    
private:
    // Helper DFS function to detect a cycle
    bool dfs(vector<vector<int>>& graph, vector<int>& visited, int course) {
        // If we're visiting the course, it means we've found a cycle
        if(visited[course] == 1) {
            return false; // Cycle detected
        }
        
        // If the course has already been visited, no need to check again
        if(visited[course] == 2) {
            return true;
        }
        
        // Mark the course as being visited
        visited[course] = 1;
        
        // Visit all neighbors (courses that depend on this one)
        for(int neighbor : graph[course]) {
            if(!dfs(graph, visited, neighbor)) {
                return false; // Cycle detected
            }
        }
        
        // Mark the course as fully visited
        visited[course] = 2;
        
        return true; // No cycle detected in this path
    }
};


/* Personal implementation */
class Solution {
private:
    bool dfs(unordered_map<int, vector<int>> &course_map, unordered_set<int> &visitedSet, int course){
        //check for cycle
        //add the value to the set
        //check for cycles in neighbors
        //remove from the set
        //return true;
        //edge case, course may have no prerequisites
        //remove complete courses from the map

        if(visitedSet.find(course) != visitedSet.end()) return false;

        //if the course is not in the map, then it has no preReqs and we can take it
        if(course_map.at(course).empty()) return true;

        visitedSet.insert(course);
        for(int i = 0; i < course_map.at(course).size(); i++){
            if(dfs(course_map, visitedSet, course_map.at(course).at(i)) == false) return false; //one of the neighbors has a cycle
        }

        //remove from the set for the next round
        visitedSet.erase(course);

        //since we can take the course, remove it from map
        course_map.at(course) = {};

        return true;
    }

public:
    bool canFinish(int numCourses, std::vector<std::vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> course_map;
        unordered_set<int> visitedSet;

        for(int i = 0; i < numCourses; i++){
            course_map[i] = {}; //initialise empty map
        }

        for(auto coursePair : prerequisites){
            course_map.at(coursePair[0]).push_back(coursePair[1]); //add to the prerequisites
        }

        //Go through the courses and see if we can find a cycle
        for(int i = 0; i < numCourses; i++){
            if(dfs(course_map, visitedSet, i) == false) return false;
        }

        return true;
    }
};
