class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<bool> char_map(256);

        // Idea: increment right ptr if that character is not in the string
        // Since we want to maximize the potential length
        // Otherwise, increment left ptr so we start to remove duplicate characters.

        int left = 0;
        int right = 0;

        int len = 0;

        while(right < s.size()) {
            if(char_map[s[right]]) {
                // increment left
                char_map[s[left]] = false;
                left++;
            }
            else {
                char_map[s[right]] = true;
                right++;
            }
            len = max(len, right - left);
        }
        len = max(len, right - left);
        return len;
    }
};
