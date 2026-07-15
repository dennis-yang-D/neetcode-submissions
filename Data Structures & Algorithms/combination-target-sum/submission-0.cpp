class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> curr;
        backtrack(nums, curr, target, 0, 0);
        return ans;
    }

    void backtrack(vector<int>& nums, vector<int>& curr, int target, int curr_sum, int i) {
        if(curr_sum > target) {return;}
        if(curr_sum == target) {
            ans.push_back(curr);
            return;
        }
        if(i >= nums.size()) {
            return;
        }
        int num_added = 0;
        backtrack(nums, curr, target, curr_sum, i+1);
        while(curr_sum <= target) {
            curr_sum += nums[i];
            curr.push_back(nums[i]);
            backtrack(nums, curr, target, curr_sum, i+1);
            num_added++;
        }
        for(int i = 0; i < num_added; i++) {
            curr.pop_back();
        }
    }
};
