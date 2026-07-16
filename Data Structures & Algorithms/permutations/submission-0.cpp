class Solution {
public:
    vector<vector<int>> ans;
    unordered_map<int, bool> used;
    vector<int> curr;
    vector<vector<int>> permute(vector<int>& nums) {
        backtrack(nums);
        return ans;
    }

    void backtrack(vector<int>& nums) {
        if(curr.size() == nums.size()) {
            ans.push_back(curr);
            return;
        }
        for(int i = 0; i < nums.size(); i++) {
            if(!used[nums[i]]) {
                curr.push_back(nums[i]);
                used[nums[i]] = true;
                backtrack(nums);
                used[nums[i]] = false;
                curr.pop_back();
            }
        }
    }
};
