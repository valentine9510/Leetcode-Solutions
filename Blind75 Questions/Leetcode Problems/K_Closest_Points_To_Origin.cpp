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


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    /**
     * @brief Go through all the points and store then in a heap
     * Use a priority queue to keep track of the max elements
     * 
     * @param points 
     * @param k 
     * @return vector<vector<int>> 
     */
    // Function to calculate the sum of squares of elements in a vector
    static int sumOfSquares(const std::vector<int>& vec) {
        int sum = 0;
        for (int num : vec) {
            sum += abs(num * num);
        }
        return sum;
    }

    // Custom comparator for the priority queue
    struct CompareVector {
        bool operator()(const std::vector<int>& a, const std::vector<int>& b) {
            return sumOfSquares(b) < sumOfSquares(a); //min heap, we want the smallest values first
        }
    };

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<vector<int>, vector<vector<int>>, CompareVector> maxH;

        for(vector<int> element : points){
            maxH.push(element); //push vectors onto the max heap
        }

        vector<vector<int>> res;

        while(k > 0){
            res.push_back(maxH.top());
            maxH.pop();
            k--;
        }

        return res;
    }

    vector<vector<int>> kClosest2(vector<vector<int>>& points, int k) {
        sort(points.begin(), points.end(), [](const std::vector<int>& a, const std::vector<int>& b){
            return sumOfSquares(b) > sumOfSquares(a); //min heap, we want the smallest values first
        });

        vector<vector<int>> res;
        int i = 0;
        while(i < k){
            res.push_back(points[i]);
            i++;
        }

        return res;
    }
};

struct CompareFunction
{
    bool operator()(vector<int>&a, vector<int>&b){
        int squareA = 0;
        std::accumulate(a.begin(), a.end(), squareA, [](int &x){ return x*x; });

        int squareB = 0;
        std::accumulate(b.begin(), b.end(), squareB, [](int &x){ return x*x; });

        return squareB > squareA; //Biggest values first, return true if second value is larger
    }
};

vector<vector<int>> kClosestPersonal(vector<vector<int>>& points, int k){ //K Closes personal
    priority_queue<vector<int>, vector<vector<int>>, CompareFunction > my_heap;
    vector<vector<int>> results;

    for(auto point : points){
        my_heap.push(point);
    }

    for(int i = 0; i < k; i++){
        results.push_back(my_heap.top());
        my_heap.pop();
    }

    return results;
}


int main(){

    // Priority queue with custom comparator
    std::priority_queue<std::vector<int>, std::vector<std::vector<int>>, Solution::CompareVector> pq;

    // Adding some vectors to the priority queue
    pq.push({1, 2, 3});
    pq.push({10, 10});
    pq.push({3, 4, 5});

    // Displaying the vectors in the priority queue
    while (!pq.empty()) {
        std::vector<int> topVec = pq.top();
        pq.pop();

        std::cout << "Vector:";
        for (int num : topVec) {
            std::cout << " " << num;
        }
        std::cout << " (Sum of Squares: " << Solution::sumOfSquares(topVec) << ")" << std::endl;
    }

    vector<std::vector<int>> points = {{1, 2, 3}, {10,10}, {1,2,5}};

    return 0;
}
