class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<bool> used(strs.size());
        vector<unordered_map<char, int>> num_chars;

        vector<vector<string>> groups;
        for(string s : strs) {
            num_chars.push_back(countCalc(s));
        }

        for(int i = 0; i < strs.size(); i++) {
            if(used[i]) {continue;}
            used[i] = true;
            vector<string> curr_group;
            curr_group.push_back(strs[i]);
            for(int j = i + 1; j < strs.size(); j++) {
                if(used[j]) {continue;}
                bool insert_flag = true;
                for(char c : "abcdefghijklmnopqrstuvwxyz") {
                    if(num_chars[i][c] != num_chars[j][c]) {
                        insert_flag = false;
                        break;
                    }
                }
                if(insert_flag) {
                    curr_group.push_back(strs[j]);
                    used[j] = true;
                }
            }

            groups.push_back(curr_group);

        }

        return groups;
    }

    unordered_map<char, int> countCalc(string& str) {
        unordered_map<char, int> count;

        for(char c : str) {
            count[c]++;
        }

        return count;
    }
};
