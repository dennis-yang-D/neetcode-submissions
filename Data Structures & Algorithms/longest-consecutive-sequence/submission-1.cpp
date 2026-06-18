class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> next_set;
        unordered_map<int, bool> visited;

        for(int n : nums) {
            next_set.insert(n);
        }

        int longest_sequence = 0;
        int i = 0;

        while(true) {
            int curr_longest = 0;
            while(i < nums.size() && visited[nums[i]]) {
                i++;
            }
            if(i == nums.size()) {
                break;
            }
            int start_val = nums[i];
            int curr = start_val;
            while(next_set.contains(curr) && !visited[curr]) {
                visited[curr] = true;
                curr_longest++;
                curr++;
            }
            curr = start_val - 1; // go downwards too
            while(next_set.contains(curr) && !visited[curr]) {
                visited[curr] = true;
                curr_longest++;
                curr--;
            }
            longest_sequence = max(curr_longest, longest_sequence);
        }
        
        return longest_sequence;
    }
};
