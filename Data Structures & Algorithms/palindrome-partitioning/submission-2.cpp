class Solution {
public:
    vector<vector<string>> ans;
    vector<string> curr;
    string s1;
    unordered_map<string, bool> palindrome_dp;
    vector<vector<string>> partition(string s) {
        s1 = s;
        compute_dp(s);
        backtrack(0);

        return ans;
    }

    void compute_dp(string s) {
        for(int i = 0; i < s.size(); i++) {
            string sub = "";
            for(int j = i; j < s.size(); j++) {
                sub += s[j];
                palindrome_dp[sub] = isPal(sub);
            }
        }
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
            if(palindrome_dp[palindrome]) {
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
