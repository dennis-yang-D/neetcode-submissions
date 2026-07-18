class Solution {
public:
    vector<vector<string>> ans;
    vector<string> curr;
    string s1;
    vector<vector<string>> partition(string s) {
        s1 = s;
        backtrack(0);

        return ans;
    }

    // I represents the start of a new palindrome
    void backtrack(int i) {
        if(i >= s1.size()) {
            ans.push_back(curr);
            return;
        }

        string palindrome = "";
        for(; i < s1.size(); i++) {
            palindrome.push_back(s1[i]);
            if(isPal(palindrome)) {
                curr.push_back(palindrome);
                backtrack(i+1);
                curr.pop_back();
            }
        }
    }

    bool isPal(string s) {
        for(int i = 0; i < s.size()/2; i++) {
            if(s[i] != s[s.size() - 1 - i]) {
                return false;
            }
        }
        return true;
    }
};
