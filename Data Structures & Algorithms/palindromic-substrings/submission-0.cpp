class Solution {
public:
    int countSubstrings(string s) {
        vector<vector<int>> pals(s.size(), vector<int>(s.size()));

        for(int i = 0; i < s.size(); i++) {
            for(int j = i; j < s.size(); j++) {
                if(pals[i][j] == 0)
                {helper(s, pals, i, j);}
            }
        }

        int count = 0;
        for(int i = 0; i < s.size(); i++) {
            for(int j = i; j < s.size(); j++) {
                if(pals[i][j] == 2) {
                    count++;
                }
            }
        }

        return count;
    }

    int helper(const string& s, vector<vector<int>>& v, int i, int j) {
        if(v[i][j] != 0) {
            return v[i][j];
        }
        if(i > j) {
            return 2;
        }
        if(i == j) {
            v[i][j] = 2;
            return 2;
        }
        if(s[i] == s[j] && helper(s, v, i+1, j-1) == 2) {
            v[i][j] = 2;
            return 2;
        }
        else {
            v[i][j] = 1;
            return 1;
        }
    }
};
