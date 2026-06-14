class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> s_map;
        unordered_map<char, int> t_map;

        for(char c : s) {s_map[c]++;}
        for(char c : t) {t_map[c]++;}

        for(char c : "abcdefghijklmnopqrstuvwxyz") {
            if (s_map[c] != t_map[c]) {return false;}
        }

        return true;
    }
};
