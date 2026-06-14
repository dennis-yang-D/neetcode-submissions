class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, vector<int>> ind_map;

        for(int i = 0; i < nums.size(); i++)
        {
            ind_map[nums[i]].push_back(i);
        }

        for(int i = 0; i < nums.size(); i++) {
            int n = target - nums[i];
            if (ind_map[n].size() > 0) {
                if(ind_map[n].size() == 2) {
                    return {ind_map[n][0], ind_map[n][1]};
                }
                if(i == ind_map[n][0]) {continue;}
                else if(i < ind_map[n][0]) {return {i, ind_map[n][0]};}
                else {return {ind_map[n][0], i};}
            }
        }

        return {0,0};
    }
};
