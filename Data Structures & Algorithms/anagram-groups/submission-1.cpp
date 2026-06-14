class Solution {
public:
    struct vectorHasher {
        size_t operator()(const vector<int>& p) const
        {
            int hashVal = 0;
            for(int i = 0; i < p.size(); i++) {
                hashVal ^= (hash<int>()(p[i]) << i);
            }
            return hashVal;
        }
    };
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<vector<int>, vector<string>, vectorHasher> groups;
        
        for(string s : strs) {
            groups[countCalc(s)].push_back(s);
        }

        vector<vector<string>> output;
        for(auto p : groups) {
            output.push_back(p.second);
        }

        return output;
    }

    vector<int> countCalc(string& str) {
        vector<int> count(26);

        for(char c : str) {
            count[c - 'a']++;
        }

        return count;
    }
};
