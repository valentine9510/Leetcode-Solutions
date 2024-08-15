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
    int evalRPN(std::vector<std::string>& tokens) {
        std::stack<int> stack;

        for (const std::string& token : tokens) {
            if (isNumber(token)) {
                stack.push(std::stoi(token));
            } else {
                int right = stack.top(); stack.pop();
                int left = stack.top(); stack.pop();
                int result = 0;

                if (token == "+") {
                    result = left + right;
                } else if (token == "-") {
                    result = left - right;
                } else if (token == "*") {
                    result = left * right;
                } else if (token == "/") {
                    result = left / right;
                } else {
                    throw std::invalid_argument("Invalid operator");
                }

                stack.push(result);
            }
        }

        return stack.top();
    }

private:
    bool isNumber(const std::string& token) {
        if (token.empty()) return false;
        if (token[0] == '-' && token.size() > 1) return std::all_of(token.begin() + 1, token.end(), ::isdigit);
        return std::all_of(token.begin(), token.end(), ::isdigit);
    }
};


class Solution {
public:
    //Plan
    //Place evey digit in a stack
        //for every operator that I get work on the last 2 numbers on the stack, push result onto the stack
        //push result onto stack
    int evalRPN(vector<string>& tokens) {
        stack<int> numbers;

        for(string element : tokens){
            if(isdigit( element.at(element.size()-1)) ){ //we have a digit, if the last value of the string is a digit, the first value maybe '+', '-', eg, +6, -6
                numbers.push(std::stoi(element)); //push the number
            } else {
                int lhs = numbers.top();
                numbers.pop();

                int rhs = numbers.top();
                numbers.pop();

                if(element == "+"){              
                    numbers.push(rhs+lhs);
                } else if(element == "-"){
                    numbers.push(rhs-lhs);
                } else if(element == "/"){
                    numbers.push(rhs/lhs);
                } else if(element == "*"){
                    numbers.push(rhs*lhs);
                }
            }
            
            
        }

        return numbers.top();
    }
};

int main(){
    Solution soln;
    vector<string> tokens = {"2","1","+","3","*"};

    cout << " Answer is : " << soln.evalRPN(tokens);
    return 0;
}
