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



// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:
    unordered_map<Node*, Node*> mapStorage; // Store old node as key and new node as value

    Node* cloneGraph(Node* node) {
        if (node == NULL) return node;

        // Check if the node has already been cloned
        if (mapStorage.find(node) != mapStorage.end()) {
            return mapStorage[node]; // Return the cloned node
        }

        // Create a new node with the value of the original node
        Node* temp = new Node(node->val);

        // Store the new node in the  before 
        mapStorage[node] = temp;

        // Clone all the neighbors
        for (Node* neighbor : node->neighbors) {
            temp->neighbors.push_back(cloneGraph(neighbor));
        }

        return temp;
    }
};


int main(){
     Node* temp; 
     Solution soln; 
     soln.cloneGraph(temp);

     cout << "Clone graph done" << endl;
    return 0;
}
