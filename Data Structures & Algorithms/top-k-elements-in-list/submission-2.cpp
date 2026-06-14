class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq_count;
        for(int n : nums) {freq_count[n]++;}

        vector<vector<int>> buckets(nums.size() + 1);

        for(auto p : freq_count) {
            buckets[p.second].push_back(p.first);
        }

        vector<int> output;
        for(int i = buckets.size() - 1; i > -1; i--) {
            if(k == 0) {
                break;
            }
            if(buckets[i].size() > 0) {
                for(int n : buckets[i])
                {
                    output.push_back(n);
                    k--;
                }
            }
        }

        return output;
    }
};
