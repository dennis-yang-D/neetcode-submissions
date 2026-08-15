class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1);

        dp[0] = 0;

        for(int i = 1; i < amount+1; i++) {
            int num_coins = INT_MAX / 2;
            for(int c : coins) {
                if(i - c >= 0) {
                    num_coins = min(num_coins, dp[i - c]);
                }
            }
            dp[i] = num_coins+1;
        }

        if(dp.back() > amount) {
            return -1;
        }
        return dp.back();
    }
};
