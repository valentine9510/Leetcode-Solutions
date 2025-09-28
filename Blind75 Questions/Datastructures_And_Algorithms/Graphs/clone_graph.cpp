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
    unordered_map<Node*, Node*> mapStorage; // Store old node as key and new node as value, helps in avoiding cycles

    Node* cloneGraph(Node* node) {
        if (node == NULL) return node;

        // Check if the node has already been cloned
        if (mapStorage.find(node) != mapStorage.end()) {
            return mapStorage[node]; // Return the cloned node
        }

        // Create a new node with the value of the original node
        Node* clone = new Node(node->val);

        // Store the new node in the  before 
        mapStorage[node] = clone;

        // Clone all the neighbors
        for (Node* neighbor : node->neighbors) {
            clone->neighbors.push_back(cloneGraph(neighbor));
        }

        return clone;
    }
};


int main(){
     Node* temp; 
     Solution soln; 
     soln.cloneGraph(temp);

     cout << "Clone graph done" << endl;
    return 0;
}


class Solution {
public:
    unordered_map<Node*, Node*> store;
    Node* cloneGraph(Node* node) {
        //use a map to store old->new
        if(!node) return node;
        if(store.find(node) != store.end()) return store[node];

        //base case is if the node is already in the graph or null
        Node *node_copy = new Node(node->val);
        store[node] = node_copy;

        //copy each of the neighbors
        for(int i = 0; i < node->neighbors.size(); i++){
            node_copy->neighbors.push_back(cloneGraph(node->neighbors[i]));
        }
        //traverse the graph, check for cycles

        return node_copy;
    }
};