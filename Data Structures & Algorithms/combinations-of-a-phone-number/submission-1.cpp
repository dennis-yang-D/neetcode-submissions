class Solution {
public:
// iterative solution
    unordered_map<int, string> digit_map;
    vector<string> layer;
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
        layer.push_back("");
        
        for(char c : digits) {
            vector<string> curr_layer = layer;
            layer.clear();

            for(string s : curr_layer) {
                for(char c1 : digit_map[c]) {
                    string s1 = s + c1;
                    layer.push_back(s1);
                }
            }
        }
        return layer;
    }
};
