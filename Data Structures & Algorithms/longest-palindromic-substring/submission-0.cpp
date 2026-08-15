class Solution {
public:
    string longestPalindrome(string s) {
        string longest_pal;
        int longest_length = 0;
        vector<vector<bool>> dp(s.size(), vector<bool>(s.size()));

        for(int i = s.size() - 1; i >= 0; i--) {
            for(int j = i; j < s.size(); j++) {
                if(s[i] == s[j] && (i + 1 >= j - 1 || dp[i+1][j-1])) {
                    int curr = j - i + 1;
                    if(longest_length < curr) {
                        longest_length = curr;
                        longest_pal = s.substr(i, longest_length);
                    }
                    dp[i][j] = true;
                }
            }
        }

        return longest_pal;
    }
};
