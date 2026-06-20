class MinStack {
    // 1 stack sol keeps track of the current stack + min stack in the same stack
    // curr is first, min is second
    stack<pair<int, int>> numStack;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        if(numStack.empty()) {
            numStack.push({val, val});
        }
        else {
            numStack.push({val, min(val, numStack.top().second)});
        }
    }
    
    void pop() {
        numStack.pop();
    }
    
    int top() {
        return numStack.top().first;
    }
    
    int getMin() {
        return numStack.top().second;
    }
};
