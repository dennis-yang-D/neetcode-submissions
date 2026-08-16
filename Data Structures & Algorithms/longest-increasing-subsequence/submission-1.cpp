class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        // each value keeps its length of the LIS ending there
        // using dp you can go back to each value and compare whether you can add to the seq
        // take the longest sequence of those values

        vector<int> dp(nums.size());

        dp[0] = 1; // a subsequence must have at least 1 length - the number itself
        int m = 1;

        for(int i = 1; i < nums.size(); i++) {
            int len = 1;
            for(int j = 0; j < i; j++) {
                if(nums[i] > nums[j]) {
                    len = max(len, 1 + dp[j]);
                }
            }
            dp[i] = len;
            m = max(m, len);
        }

        return m;
    }
};
