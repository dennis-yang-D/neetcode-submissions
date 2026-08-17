class Solution {
public:
    bool canPartition(vector<int>& nums) {
        // at each point, build a subset w/ half the sum of the total
        // knapsack with weight of half of total sum

        int numItems = nums.size();
        int sum = 0;
        for(int n : nums) {
            sum += n;
        }
        if(sum % 2 == 1) {return false;}
        sum /= 2;

        vector<vector<int>> dp(numItems + 1, vector<int>(sum + 1));
        // maximum value that can be obtained with the first i items with weight less than w
        
        // initial will be 0
        for(int i = 1; i < numItems+1; i++) { // item
            for(int j = 1; j < sum + 1; j++) { // weight
                if(nums[i-1] > j) {
                    dp[i][j] = dp[i-1][j]; // can't add the new weight so its the previous weight
                }
                else {
                    // max of not adding the new weight, or adding the new weight
                    dp[i][j] = max(dp[i-1][j], nums[i-1] + dp[i - 1][j - nums[i-1]]);
                }
            }
        }

        //cout << dp.back().back();

        return dp.back().back() == sum;
    }
};
