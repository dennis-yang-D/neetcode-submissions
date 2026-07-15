class Solution {
public:
    vector<vector<int>> ans;
    vector<int> curr;
    unordered_map<int, int> copies;
    vector<int> unique_cands;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        for(int i = 0; i < candidates.size(); i++) {
            copies[candidates[i]]++;
        }
        unique_cands.push_back(candidates[0]);
        for(int i = 1; i < candidates.size(); i++) {
            if(candidates[i] != unique_cands.back()) {
                unique_cands.push_back(candidates[i]);
            }
        }
        backtrack(unique_cands, target, 0, 0);
        return ans;
    }

    void backtrack(vector<int>& candidates, int target, int i, int curr_sum) {
        if(curr_sum > target) {return;}
        if(curr_sum == target) {
            ans.push_back(curr);
            return;
        }
        if(i >= candidates.size()) {return;}

        backtrack(candidates, target, i+1, curr_sum); // backtrack with no copies
        for(int c = 0; c < copies[candidates[i]]; c++) {
            curr.push_back(candidates[i]);
            curr_sum += candidates[i];
            backtrack(candidates, target, i+1, curr_sum);
        }
        for(int c = 0; c < copies[candidates[i]]; c++) {
            curr.pop_back();
        }
    }
};
