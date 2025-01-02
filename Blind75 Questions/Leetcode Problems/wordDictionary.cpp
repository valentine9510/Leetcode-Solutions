#include <bits/stdc++.h>

using namespace std;

/*
211. Design Add and Search Words Data Structure
Design a data structure that supports adding new words and finding if a string matches any previously added string.

Implement the WordDictionary class:

WordDictionary() Initializes the object.
void addWord(word) Adds word to the data structure, it can be matched later.
bool search(word) Returns true if there is any string in the data structure that matches word or false otherwise. word may contain dots '.' where dots can be matched with any letter.
 

Example:

Input
["WordDictionary","addWord","addWord","addWord","search","search","search","search"]
[[],["bad"],["dad"],["mad"],["pad"],["bad"],[".ad"],["b.."]]
Output
[null,null,null,null,false,true,true,true]

Explanation
WordDictionary wordDictionary = new WordDictionary();
wordDictionary.addWord("bad");
wordDictionary.addWord("dad");
wordDictionary.addWord("mad");
wordDictionary.search("pad"); // return False
wordDictionary.search("bad"); // return True
wordDictionary.search(".ad"); // return True
wordDictionary.search("b.."); // return True
 
*/

/*
Implement a trie
*/
class WordDictionary {
public:
    struct TrieNode {
        bool isEnd = false;
        TrieNode* children[26] = {nullptr};
    };

    TrieNode* root;

    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* node = root;
        for (char c : word) {
            if (node->children[c - 'a'] == nullptr) {
                node->children[c - 'a'] = new TrieNode();
            }
            node = node->children[c - 'a'];
        }
        node->isEnd = true;
    }
    
    bool search(string word) {
        return dfs(word, 0, root);
    }

    bool dfs(string& word, int index, TrieNode* node) {
        if (index == word.size()) {
            return node->isEnd;
        }
        char c = word[index];
        if (c == '.') {
            // Try all 26 possible paths
            for (int i = 0; i < 26; i++) {
                if (node->children[i] && dfs(word, index + 1, node->children[i])) {
                    return true;
                }
            }
            return false;
        } else {
            // Proceed normally if character is not '.'
            TrieNode* nextNode = node->children[c - 'a'];
            return nextNode && dfs(word, index + 1, nextNode); //this checks if it is NULL
        }
    }
};

