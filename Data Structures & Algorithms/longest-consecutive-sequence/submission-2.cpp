class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> next_set;
        unordered_map<int, bool> visited;

        for(int n : nums) {
            next_set.insert(n);
        }

        int longest_sequence = 0;

        for(int n : nums) {
            int length = 0;
            if(!next_set.contains(n-1)) { // denotes start of a sequence
                int curr = n;
                while(next_set.contains(curr)) {
                    length++;
                    curr++;
                }
            }
            
            longest_sequence = max(length, longest_sequence);
        }
        
        return longest_sequence;
    }
};
