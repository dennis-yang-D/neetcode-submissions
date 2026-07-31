class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n + 1);
        
        dp[0] = 1; // 1 way to climb 0 stairs
        dp[1] = 1; // 1 way to climb 1 stairs
        // i = 2 case ends up being the same as dp[0] + dp[1]

        for(int i = 2; i < dp.size(); i++) {
            dp[i] = dp[i-1] + dp[i - 2]; // can climb from i-1, or i-2. Climbing 1 + 1 steps is included under i-1 case
        }

        return dp.back();
    }
};
