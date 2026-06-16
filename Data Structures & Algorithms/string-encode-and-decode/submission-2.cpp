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
                next_len += 256; // correct if s[i] ends up being a negative int value
            }
            string curr;
            int curr_ind = i;
            i++; // i refers to the length char, so increase by 1 to start reading the string
            for(; i <= curr_ind + next_len && i < s.size(); i++) {
                curr += s[i];
            }
            i--; // The loop will add 1 to i, so to get to the length char instead of skipping, sub 1
            result.push_back(curr);
        }

        return result;
    }
};
