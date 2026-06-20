class Solution {
public:
    bool isValid(string s) {
        stack<char> bracketStack;

        for(char c : s) {
            if(c == '(' || c == '[' || c == '{') {
                bracketStack.push(c);
            }
            else {
                if(bracketStack.empty()) {return false;}
                if(bracketStack.top() == '(' && c != ')') {return false;}
                if(bracketStack.top() == '[' && c != ']') {return false;}
                if(bracketStack.top() == '{' && c != '}') {return false;}

                bracketStack.pop();
            }
        }

        if(!bracketStack.empty()) {return false;}

        return true;
    }
};
