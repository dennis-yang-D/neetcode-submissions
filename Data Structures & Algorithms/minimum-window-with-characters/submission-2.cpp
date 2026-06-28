class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> t_map;
        unordered_map<char, int> s_map;

        for(char c : t) {
            t_map[c]++;
        }

        int left = 0;
        int right = 0;
        int maxLength = 99999;
        int maxLeft = 0;

        // IDEA: similar to the substring permutation problem, if a substr doesn't have the permutation
        // inc right ptr bc you need to examine more characters. Otherwise, remove
        // extra characters from the left (potential to reduce length)
        while(right < s.size()) {
            //cout << left << " " << right << endl;
            if(containsSubstr(s_map, t_map)) {
                if(maxLength > right - left) {
                    maxLength = right - left;
                    maxLeft = left;
                }
                s_map[s[left]]--;
                left++;
            }
            else {
                s_map[s[right]]++;
                right++;
            }
        }

        // Needs one more post processing step at the end to get rid of left characters
        while(containsSubstr(s_map, t_map)) {
            if(maxLength > right - left) {
                maxLength = right - left;
                maxLeft = left;
            }
            s_map[s[left]]--;
            left++;
        }

        if(maxLength == 99999) {
            return "";
        }

        return s.substr(maxLeft, maxLength);
    }

    bool containsSubstr(unordered_map<char, int>& s_map, unordered_map<char, int>& t_map) {
        for(auto t : t_map) {
            if(t.second > s_map[t.first]) {
                return false;
            }
        }
        return true;
    }
};
