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

class Trie {
private:
    static const int ALPHABET_SIZE = 26;
    vector<Trie*> children;
    bool isEndOfWord; //true if it is the end of a word 
public:
    Trie() {
        //set up array
        children.resize(ALPHABET_SIZE);
        for(int i = 0; i<children.size(); i++){
            children.at(i) = NULL; //initialize to NULL
        }

        this->isEndOfWord = false; //set end of word false
    }
    
    void insert(string word) {
        Trie* trieCrawl = this;

        for(int i=0; i < word.length(); i++){
            int index = tolower(word.at(i)) - 'a'; //get index in the alphabet array

            if(trieCrawl->children.at(index) == NULL){
                trieCrawl->children.at(index) = new Trie(); //allocate on heap
            }

            trieCrawl = trieCrawl->children.at(index);
        }

        //reached end of trie so can mark this as a leaf
        trieCrawl->isEndOfWord = true;
    }
    
    bool search(string word) {
        Trie* trieCrawl = this;

        for(int i=0; i < word.length(); i++){
            int index = tolower(word.at(i)) - 'a'; //get index in the alphabet array

            if(trieCrawl->children.at(index) == NULL){
                return false;
            }

            trieCrawl = trieCrawl->children.at(index);
        }

        //reached end of trie so can mark this as a leaf
        if(trieCrawl->isEndOfWord == false) return false;

        //we have reached the end
        return true;
        
    }
    
    bool startsWith(string prefix) {
        Trie* trieCrawl = this;

        for(int i=0; i < prefix.length(); i++){
            int index = tolower(prefix.at(i)) - 'a'; //get index in the alphabet array

            if(trieCrawl->children.at(index) == NULL){
                return false;
            }

            trieCrawl = trieCrawl->children.at(index);
        }

        return true;
    }

    // Returns true if root has no children, else false
    bool isEmpty(Trie* root)
    {
        for (int i = 0; i < ALPHABET_SIZE; i++)
            if (root->children[i])
                return false;
        return true;
    }

    Trie* remove (Trie* root, string key, int depth = 0){
        /**
         * @brief 3 Base cases
         * 
         *  Key may not be in trie - 1
         *  We are a prefix of another word - 2
         *  Key is unique and does not share path with any other key - 3
         *  Deleted node shares a prefix with another key - 4 (Delete nodes up to prefix) 
         *  
         * To remove a word, you need to consider several cases:

         * The word doesn't exist in the trie: In this case, you do nothing.
         * The word is a prefix of another word: For example, if "bat" is a word, and "batman" is also in the trie, you shouldn't delete nodes past the 't' in "bat".
         * The word shares a prefix with another word: For example, if "bat" and "bath" are both in the trie, you need to ensure that deleting "bath" doesn't affect "bat".
         * The word is unique: If it's the only word that leads to a specific path, you can delete nodes back up to the first character where the path diverges.
         * 
         */

        //Tree is empty
        if(root == NULL) return root;

        //If the last character is the one being handled
        if(depth == key.size()){
            // This node is no more end of word after
            // removal of given key
            if (root->isEndOfWord)
                root->isEndOfWord = false;
    
            // If given is not prefix of any other word
            if (isEmpty(root)) {
                delete (root);
                root = NULL;
            }
    
            return root;
        }

        // If not last character, recur for the child
        // obtained using ASCII value
        int index = key[depth] - 'a';
        root->children[index] = 
            remove(root->children[index], key, depth + 1);
    
        // If root does not have any child (its only child got 
        // deleted), and it is not end of another word.
        if (isEmpty(root) && root->isEndOfWord == false) {
            delete (root);
            root = NULL;
        }
    
        return root;

    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */



/**
 * @brief Personal training implementation
 * 
 */

class Tries {
private:
    static const int ALPHABET_SIZE = 26;
    bool isEndOfWord;
    vector<Tries*> children;
public:
    Tries() {
        this->isEndOfWord = false;
        for(int i = 0; i < ALPHABET_SIZE; i++){
            children.push_back(NULL); //initialise the children to be NULL
        }
    }
    
    void insert(string word) {
        Tries* trieCrawl = this;

        for(char curr_letter : word){
            int index = tolower(curr_letter) - 'a';

            if(trieCrawl->children.at(index) == NULL){
                trieCrawl->children.at(index) = new Tries(); //insert a new node to make it not NULL
            }

            trieCrawl = trieCrawl->children.at(index);
        }

        trieCrawl->isEndOfWord = true; //end of crawl so update this
    }
    
    bool search(string word) {
        Tries* trieCrawl = this;

        for(char curr_letter : word){
            int index = tolower(curr_letter) - 'a';

            if(trieCrawl->children.at(index) == NULL){
                return false; //not there
            }

            //if it is there
            trieCrawl = trieCrawl->children.at(index);
        }

        //reached end of word, this should be an end to it

        return trieCrawl->isEndOfWord;
    }
    
    bool startsWith(string prefix) {
        Tries* trieCrawl = this;

        for(char curr_letter : prefix){
            int index = tolower(curr_letter) - 'a';

            if(trieCrawl->children.at(index) == NULL){
                return false; //not there
            }

            //if it is there
            trieCrawl = trieCrawl->children.at(index);
        }

        //prefix is done
        return true;        
    }


};