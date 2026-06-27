class Solution {
public:
    int characterReplacement(string s, int k) {
        // have a left ptr, and a right ptr
        // Change your replacement char to left ptr char

        // Ex for XYYX: left ptr at X, select X as replacement char
        // go as far as you can w/ right ptr while replacing with X
        // Once you exhausted that value, left jumps to right and we start again

        // XXYYYY, 2 - left ptr at X, select X as replacement char
        // right ptr gets to ind 3 (XXXXYY)

        int left = 0;
        int right = 0;
        int max_len = 0;

        int k_left = k;
        for(char replace_char : "QWERTYUIOPASDFGHJKLZXCVBNM")
        {   left = 0;
            right = 0;
            k_left = k;
            while(right < s.size()) {
            while(k_left > 0) {
                if(right >= s.size()) {
                    break;
                }
                if(s[right] != replace_char)
                {
                    k_left--;
                }
                right++;
                cout << left << " " << right << " " << k_left << " | ";
                max_len = max(max_len, right - left);
            }
            if(s[right] == replace_char) {
                right++;
                max_len = max(max_len, right - left);
                cout << left << " " << right << " " << k_left << " | ";
            }
            else {
                if(s[left] != replace_char) {
                    k_left++;
                }
                left++;
                max_len = max(max_len, right - left);
            }
        }}

        return max_len;
    }
};
