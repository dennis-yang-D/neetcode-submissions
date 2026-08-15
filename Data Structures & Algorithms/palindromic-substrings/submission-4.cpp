class Solution {
public:
    int countSubstrings(string s) {
        vector<vector<bool>> pals(s.size(), vector<bool>(s.size()));

        int count = 0;

        for(int i = s.size()-1; i >= 0; i--) {
            for(int j = i; j < s.size(); j++) {
                if(s[i] == s[j] && (i+1 >= j-1 || pals[i+1][j-1])) {
                    count++;
                    pals[i][j] = true;
                }
            }
        }

        return count;
    }
};

