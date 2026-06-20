class Solution {
public:
    bool isValid(string s) {
        stack<char> bracketStack;
        unordered_map<char, char> bracketMap;
        bracketMap['('] = ')';
        bracketMap['['] = ']';
        bracketMap['{'] = '}';

        for(char c : s) {
            if(c == '(' || c == '[' || c == '{') {
                bracketStack.push(c);
            }
            else {
                if(bracketStack.empty()) {return false;}
                if(bracketMap[bracketStack.top()] != c) {return false;}
                bracketStack.pop();
            }
        }

        if(!bracketStack.empty()) {return false;}

        return true;
    }
};
