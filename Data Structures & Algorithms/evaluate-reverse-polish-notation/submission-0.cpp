class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> num_stack;

        for(string c : tokens) {
            if(c != "+" && c != "-" && c != "*" && c != "/") {
                num_stack.push(stoi(c));
            }
            else {
                int a = num_stack.top();
                num_stack.pop();
                int b = num_stack.top();
                num_stack.pop();
                int ans;
                if(c == "+") {ans = b + a;}
                else if (c == "-") {ans = b - a;}
                else if (c == "*") {ans = b * a;}
                else {ans = b / a;}
                num_stack.push(ans);
            }
        }
        return num_stack.top();
    }
};
