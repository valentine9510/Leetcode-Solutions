#include <bits/stdc++.h>

using namespace std;

/*
210. Course Schedule II
Medium
Topics
premium lock icon
Companies
Hint
There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return the ordering of courses you should take to finish all courses. If there are many valid answers, return any of them. If it is impossible to finish all courses, return an empty array.

 

Example 1:

Input: numCourses = 2, prerequisites = [[1,0]]
Output: [0,1]
Explanation: There are a total of 2 courses to take. To take course 1 you should have finished course 0. So the correct course order is [0,1].
Example 2:

Input: numCourses = 4, prerequisites = [[1,0],[2,0],[3,1],[3,2]]
Output: [0,2,1,3]
Explanation: There are a total of 4 courses to take. To take course 3 you should have finished both courses 1 and 2. Both courses 1 and 2 should be taken after you finished course 0.
So one correct course order is [0,1,2,3]. Another correct ordering is [0,2,1,3].
Example 3:

Input: numCourses = 1, prerequisites = []
Output: [0]
*/


/*

Looks like a graph issue

Change the prerequisites to and adjacency list and fill in a set

keep removing elements from the set, if we cannot remove all the elements, then we cant take all the courses
keep watch for cycles

0 -> 1,2
1 -> 3
2 -> 3
*/


class Solution {
public:
    unordered_set<int> course_set;
    unordered_map<int,vector<int>> course_map; //pre-req to values

    void edgeToAdjacency (vector<vector<int>> &pre_reqs){
        for(int i = 0; i < pre_reqs.size(); i++){
            int pre_req_course = pre_reqs[i][1];
            int course = pre_reqs[i][0];

            //add to map
            course_map[pre_req_course].push_back(course);

            //add to set
            course_set.insert(pre_req_course);
            course_set.insert(course);
        }
    }

    //explore from a node to the end!
    vector<int> explore(int course, unordered_set<int> current_visited, vector<int> curr_order){
        //if the value is not in the set, then it is a cycle

        //remove from set

        // if set is empty, return vector

        // check if the children paths lead to anything

        //return empty set

    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        //check for all nodes to find a path
    }
};

/*
    1) Kahn’s Algorithm (BFS Topological Sort)

    Idea: Build a graph u -> v for prerequisite u must be taken before v (i.e., u is prereq of v). 
    Track indegrees; start with all nodes whose indegree is 0; pop, append to order, and decrease indegrees of neighbors. 
    If we place all n courses, order is valid; otherwise there’s a cycle.

*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // Build adjacency list and indegree array.
        // Edge a -> b means: take a before b (a is prerequisite of b).
        vector<vector<int>> adj(numCourses);
        vector<int> indeg(numCourses, 0);

        for (const auto& p : prerequisites) {
            int course = p[0], prereq = p[1];
            adj[prereq].push_back(course);
            indeg[course]++;
        }

        // Start with all courses that have no prerequisites.
        queue<int> q;
        for (int i = 0; i < numCourses; ++i)
            if (indeg[i] == 0) q.push(i);

        vector<int> order;
        order.reserve(numCourses);

        while (!q.empty()) {
            int u = q.front(); q.pop();
            order.push_back(u);

            // "Take" u; reduce indegree of its dependents.
            for (int v : adj[u]) {
                if (--indeg[v] == 0) q.push(v);
            }
        }

        // If we didn't schedule all courses, there is a cycle -> impossible.
        if ((int)order.size() != numCourses) return {};
        return order;
    }
};

/* DFS With Cycle Detection */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for (auto& p : prerequisites) {
            int course = p[0], prereq = p[1];
            adj[prereq].push_back(course); // prereq -> course
        }

        vector<int> color(numCourses, 0); // 0=unvisited,1=visiting,2=visited
        vector<int> order;                // will hold reverse topological order
        order.reserve(numCourses);

        function<bool(int)> dfs = [&](int u) -> bool {
            color[u] = 1; // visiting
            for (int v : adj[u]) {
                if (color[v] == 1) return false;            // back-edge -> cycle
                if (color[v] == 0 && !dfs(v)) return false; // propagate failure
            }
            color[u] = 2; // done
            order.push_back(u); // postorder
            return true;
        };

        for (int i = 0; i < numCourses; ++i) {
            if (color[i] == 0 && !dfs(i)) return {}; // cycle found
        }

        reverse(order.begin(), order.end());
        return order;
    }
};
