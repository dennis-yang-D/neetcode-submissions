class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<int, int> char_map;

        // Idea: increment right ptr if that character is not in the string
        // Since we want to maximize the potential length
        // Otherwise, increment left ptr so we start to remove duplicate characters.

        int left = 0;
        int right = 0;

        int len = 0;

        while(right < s.size()) {
            if(char_map[s[right]] >= left + 1) {
                // jump to left and increment (more optimal solution instead of incrementing left to the dup pos)
                int jump_to = char_map[s[right]] - 1;
                char_map[s[left]] = 0;
                left = jump_to + 1;
            }
            else {
                char_map[s[right]] = right + 1;
                right++;
            }
            len = max(len, right - left);
        }
        len = max(len, right - left);
        return len;
    }
};
