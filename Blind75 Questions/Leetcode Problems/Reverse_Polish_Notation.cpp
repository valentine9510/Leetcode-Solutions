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
    //Plan
    //Place evey digit in a stack
        //for every operator that I get work on the last 2 numbers on the stack, push result onto the stack
        //push result onto stack
    int evalRPN(vector<string>& tokens) {
        stack<int> numbers;

        for(string element : tokens){
            if(isdigit( element.at(0)) ){ //we have a digit
                numbers.push(element.at(0) - '0'); //push the number
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
