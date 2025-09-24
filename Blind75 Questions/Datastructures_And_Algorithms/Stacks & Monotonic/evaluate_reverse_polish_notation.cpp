#include <bits/stdc++.h>

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

        for(string &curr : tokens){
            if(isNumber(curr)){
                numbers.push(std::stoi(curr));
            } else {
                /* We have an evaluation */
                int rhs = numbers.top();
                numbers.pop();

                int lhs = numbers.top();
                numbers.pop();

                int result;

                if(curr == "+")
                    result = lhs + rhs;
                else if(curr == "-")
                    result = lhs - rhs;
                else if(curr == "*")
                    result = lhs * rhs;
                else if(curr == "/")
                    result = lhs / rhs;

                numbers.push(result);
            }
        }

        return numbers.top();
    }
private:
    bool isNumber(string input){
        return std::isdigit(input.back());
    }
};

int main(){
    Solution soln;
    vector<string> tokens = {"2","1","+","3","*"};

    cout << " Answer is : " << soln.evalRPN(tokens);
    return 0;
}
