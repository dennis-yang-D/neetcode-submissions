class Solution {
public:
    unordered_map<int, string> digit_map;
    vector<string> ans;
    string curr;
    string digs;
    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0) {
            return {};
        }
        digit_map['2'] = "abc";
        digit_map['3'] = "def";
        digit_map['4'] = "ghi";
        digit_map['5'] = "jkl";
        digit_map['6'] = "mno";
        digit_map['7'] = "pqrs";
        digit_map['8'] = "tuv";
        digit_map['9'] = "wxyz";
        digs = digits;
        backtrack(0);
        return ans;
    }

    void backtrack(int i) {
        if(i > digs.size()) {
            return;
        }
        if(i == digs.size()) {
            ans.push_back(curr);
            return;
        }

        for(char c : digit_map[digs[i]]) {
            curr.push_back(c);
            backtrack(i+1);
            curr.pop_back();
        }
    }
};
