class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        // to get to step i, you can go from i-1 or i-2
        // min cost to reach step i must be min(step from i - 1 + 1 step or step from i - 2 + 2 steps)

        vector<int> dp(cost.size() + 1);
        dp[0] = cost[0];
        dp[1] = cost[1];

        for(int i = 2; i < dp.size() - 1; i++) {
            // either come from i-1 or i - 2
            dp[i] = min(dp[i-1] + cost[i], dp[i-2] + cost[i]);
        }
        dp.back() = min(dp[dp.size() - 2], dp[dp.size() - 3]);

        return dp.back();
    }
};
