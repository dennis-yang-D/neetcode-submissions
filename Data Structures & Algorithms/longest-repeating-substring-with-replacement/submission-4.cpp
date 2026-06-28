class Solution {
public:
    int characterReplacement(string s, int k) {
        int left = 0;
        int right = 0;
        int max_len = 0;

        int k_left = k;
        unordered_map<char, int> freq_map;

        while(right < s.size()) {
            int most_freq = mostFrequent(freq_map);
            int num_replace = right - left - most_freq;
            //cout << left << " " << right << " " << num_replace;
            //max_len = max(max_len, right - left);

            // Base sliding window on the # of most frequent characters - which is correlated
            // to the mininum # of characters you have to replace in the sliding window
            if(num_replace > k) {
                // increase left
                //cout << "i";
                freq_map[s[left]]--;
                left++;
            }
            else {
                freq_map[s[right]]++;
                max_len = max(max_len, right - left);
                right++;
            }
            //cout << endl;
        }
        int most_freq = mostFrequent(freq_map);
            int num_replace = right - left - most_freq;
        
        if(num_replace <= k)
        {max_len = max(max_len, right - left);}

        return max_len;
    }

    int mostFrequent(unordered_map<char, int>& freq_map) {
        int most = 0;
        for(char c : "ABCDEFGHIJKLMNOPQRSTUVWXYZ") {
            if(most < freq_map[c]) {
                most = freq_map[c];
            }
        }

        return most;
    }
};
