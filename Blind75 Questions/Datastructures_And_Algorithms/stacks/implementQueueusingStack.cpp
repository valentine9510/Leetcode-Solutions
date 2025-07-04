#include <stack>
using namespace std;

class MyQueue {
private:
    stack<int> input;
    stack<int> output;

    // Helper to move elements from input to output only when output is empty
    void shiftStacks() {
        if (output.empty()) {
            while (!input.empty()) {
                output.push(input.top());
                input.pop();
            }
        }
    }

public:
    MyQueue() {
        // constructor
    }

    void push(int x) {
        input.push(x);
    }

    int pop() {
        shiftStacks();
        int front = output.top();
        output.pop();
        return front;
    }

    int peek() {
        shiftStacks();
        return output.top();
    }

    bool empty() {
        return input.empty() && output.empty();
    }
};
