class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        map<int, int> largestNums;

        for(int i = 0; i < k; i++) {
            largestNums[nums[i]]++;
        }

        vector<int> ans;

        for(int i = k; i < nums.size(); i++) {
            ans.push_back(largestNums.rbegin()->first);

            largestNums[nums[i-k]]--;
            if(largestNums[nums[i-k]] == 0) {
                largestNums.erase(nums[i-k]);
            }
            largestNums[nums[i]]++;
        }
        ans.push_back(largestNums.rbegin()->first);

        return ans;
    }
};
