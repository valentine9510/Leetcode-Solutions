#include <bits/stdc++.h>

using namespace std;

/*
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

Example 1:

Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]
Example 2:

Input: n = 1
Output: ["()"]
 
Constraints:
*/

/*
bool isBalanced(string input)

vector<string> generateParenthesis(int n) {
    
}

For each permutation, check if it is balanced


*/

class Solution {
public:
    bool isBalanced(string &permutation){
        stack<char> openBrackets;

        for(char i : permutation){
            if(i == '(') {
                openBrackets.push(i);
            } else {
                if(openBrackets.empty())
                    return false;
                openBrackets.pop();
            }
        }

        return openBrackets.empty();
    }
    void backtrack(vector<string>& solution, int size, string& permutation, vector<bool>& used){
        //If goal is reached
            //add solution to result
                //result
        if(permutation.size() == size){
            if(isBalanced(permutation))
                solution.push_back(permutation);
            return;
        }

        //for choices
            //if choice is valid
                //add choice to current solution
                    //backtrack
                //remove choice from current solution
        for(int i = 0; i < size; i++){
            if(used[i] == false) { //if not used
                used[i] = true; //being used
                permutation.push_back(i < size/2 ? '(' : ')'); //add to current solution

                backtrack(solution, size, permutation, used);

                used[i] = false; //not being used
                permutation.pop_back(); //add to current solution
            }            
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<bool> used (n*2, false); //initialised to false
        string curr_permutation;
        vector<string> solution;

        backtrack(solution, n*2, curr_permutation, used);

        return solution;
    }
};

/*
To solve the "Generate Parentheses" problem, we need to generate all combinations of well-formed parentheses for a given n (number of pairs).

Key Idea:
Use backtracking to build the string step-by-step, choosing '(' or ')' at each step, but only when it’s valid:

We can add '(' if we haven't used up all n left parentheses.

We can add ')' only if the number of ')' used so far is less than the number of '(' used.
*/

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;

        backtrack(result, "", 0, 0, n);
        
        return result;
    }

    void backtrack(vector<string> &result, string curr, int open, int close, int max){
        if(curr.size() >= max*2)
            result.push_back(curr);
        
        //backtrack
        if(open < max)
            backtrack(result, curr + '(', open+1, close, max);

        if(close < open)
            backtrack(result, curr+')', open, close+1, max);
    }
};

class Solution {
public:
    void backtrack(vector<string> &soln, string curr, int open, int close, int max){
        if(curr.size() == max*2){
            soln.push_back(curr);
        }

        if(open < max) //Still have open brackets
            backtrack(soln, curr + "(", open+1, close, max);

        if(close < open)
            backtrack(soln, curr + ")", open, close+1, max);
    }

    vector<string> generateParenthesis(int n) {
        //Only generate valid possibilities
        vector<string> soln;

        backtrack(soln, "", 0, 0, n);

        return soln;
    }


};
