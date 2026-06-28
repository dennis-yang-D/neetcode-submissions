class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> s1_map;
        unordered_map<char, int> s2_map;

        for(char c : s1) {s1_map[c]++;}

        if(s1.size() > s2.size()) {return false;}
        int left = 0;
        int right = 0;
        
        for(int i = 0; i < s1.size(); i++) {
            s2_map[s2[i]]++;
            right++;
        }

        while(right < s2.size()) {
            if(maps_equal(s1_map, s2_map)) {return true;}
            s2_map[s2[left]]--;
            left++;
            s2_map[s2[right]]++;
            right++;
        }
        if(maps_equal(s1_map, s2_map)) {return true;}
        return false;
    }

    bool maps_equal(unordered_map<char, int>& s1_map, unordered_map<char, int>& s2_map) {
        for(auto p : s1_map) {
            if(p.second != s2_map[p.first]) {
                return false;
            }
        }

        for(auto p : s2_map) {
            if(p.second != s1_map[p.first]) {
                return false;
            }
        }

        return true;
    }
};
