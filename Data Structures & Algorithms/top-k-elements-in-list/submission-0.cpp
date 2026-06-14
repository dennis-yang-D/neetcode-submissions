class Solution {
public:
    struct pairComp {
        bool operator()(pair<int, int>& a, pair<int, int>& b)
        {
            return a.second > b.second;
        }
    };
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq_count;
        for(int n : nums) {freq_count[n]++;}

        vector<pair<int, int>> pairVec;

        for(auto p : freq_count) {
            pairVec.push_back(p);
        }

        sort(pairVec.begin(), pairVec.end(), pairComp());

        vector<int> output;
        for(int i = 0; i < k; i++) {
            output.push_back(pairVec[i].first);
        }
        return output;
    }
};
