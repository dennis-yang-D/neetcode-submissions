class MinStack {
    stack<int> numStack;
    unordered_map<int, int> counts;
    stack<int> minStack;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        numStack.push(val);
        counts[val]++;
        if(minStack.empty() || minStack.top() > val) {
            minStack.push(val);
        }
    }
    
    void pop() {
        int temp = numStack.top();
        numStack.pop();
        counts[temp]--;
        if(counts[minStack.top()] == 0) {
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
