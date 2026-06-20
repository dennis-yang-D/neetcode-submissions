class MinStack {
    stack<int> numStack;
    stack<int> minStack;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        numStack.push(val);
        if(minStack.empty() || minStack.top() >= val) {
            minStack.push(val);
        }
    }
    
    void pop() {
        int temp = numStack.top();
        numStack.pop();
        if(minStack.top() == temp) { //we always check if the min elt is actually left
        // Case 3 1 2: 2 never appears in minStack when you insert it. 2 also gets popped first, so
        // the min stack will never actually have to change.
            minStack.pop();
        }
    }
    
    int top() {
        return numStack.top();
    }
    
    int getMin() {
        return minStack.top();
    }
};
