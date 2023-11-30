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
public:
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

        for(int preReqCourse : storage.at(course)){
            if (dfs(storage, visitSet, preReqCourse) == false) return false;
        }

        //else course can be taken, you can remove it 
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

int main(){
    
    return 0;
}
