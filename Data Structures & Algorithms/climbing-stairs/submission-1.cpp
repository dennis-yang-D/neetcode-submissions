class Solution {
public:
    int climbStairs(int n) {        
        int low_dp = 1; // 1 way to climb 0 stairs
        int high_dp = 1; // 1 way to climb 1 stairs
        // i = 2 case ends up being the same as dp[0] + dp[1]

        for(int i = 0; i < n - 1; i++) {
            if(low_dp <= high_dp) {
                low_dp += high_dp;
            } else {
                high_dp += low_dp;
            }
        }

        return max(low_dp, high_dp);
    }
};
