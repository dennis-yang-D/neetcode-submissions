class Solution {
public:

    string encode(vector<string>& strs) {
        string result = "";
        for(string str : strs) {
            int len = str.size();
            result += char(len) + str;
        }

        return result;
    }

    vector<string> decode(string s) {
        vector<string> result;

        int next_len = 0;
        for(int i = 0; i < s.size(); i++) {
            next_len = s[i];
            if(next_len < 0) {
                next_len += 256;
            }
            string curr;
            int curr_ind = i;
            i++;
            for(; i <= curr_ind + next_len && i < s.size(); i++) {
                curr += s[i];
            }
            i--;
            result.push_back(curr);
        }

        return result;
    }
};
