class Solution {
public:
    unordered_map<int, int> count;
    vector<vector<int>> ans;
    vector<int> curr;
    vector<int> singles;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        singles.push_back(nums[0]);
        for(int n : nums) {
            count[n]++;
            if(n != singles.back()) {singles.push_back(n);}
        }
        backtrack(0);
        return ans;
    }

    void backtrack(int i) {
        ans.push_back(curr);

        for(; i < singles.size(); i++) {
            for(int j = 0; j < count[singles[i]]; j++) {
                curr.push_back(singles[i]);
                backtrack(i+1);
            }
            for(int j = 0; j < count[singles[i]]; j++) {
                curr.pop_back();
            }
        }
    }
};
