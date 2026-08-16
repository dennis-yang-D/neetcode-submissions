class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int max_length = 0;
        for(string st : wordDict) {
            max_length = max(max_length, (int)st.size());
        }

        vector<bool> dp(s.size()+1);
        dp[0] = true;

        unordered_set<string> dict(wordDict.begin(), wordDict.end());

        for(int i = 0; i < s.size(); i++) {
            bool dpval = dp[i+1];
            for(string& st : wordDict) {
                // this is the char to start looking at
                int begin = i - st.size() + 1 + 1; // add an additional 1 value due to dp size
                if(begin < 1) {
                }
                else {
                    //cout << s.substr(begin - 1, st.size()) << " ";
                    if(dict.contains(s.substr(begin - 1, st.size()))) {
                        dpval = dpval || (dp[begin - 1]);
                    }
                }
            }
            dp[i+1] = dpval;
        }

        return dp.back();
    }
};
