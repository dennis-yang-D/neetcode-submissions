class Solution {
public:
    int rob(vector<int>& nums) {
        // keep 2 vector, one where you start w/ house 1 and one where you start w/ house 2
        // unless ur nums size is 2
        if(nums.size() == 1) {return nums[0];}
        if(nums.size() == 2) {return max(nums[0], nums[1]);}

        vector<int> dp1(nums.size()); // rob 1
        vector<int> dp2(nums.size()); // rob 2

        dp1[0] = nums[0];
        dp1[1] = nums[0];
        for(int i = 2; i < nums.size() - 1; i++) { // can't include last house
            dp1[i] = max(dp1[i-1], dp1[i-2] + nums[i]);
            //cout << dp1[i] << " ";
        }
        dp1.back() = dp1[dp1.size() - 2];

        //cout << endl;

        dp2[0] = 0;
        dp2[1] = nums[1];
        for(int i = 2; i < nums.size(); i++) { // can include last house
            dp2[i] = max(dp2[i-1], dp2[i-2] + nums[i]);
            //cout << dp2[i] << " ";
        }

        return max(dp2.back(), dp1.back());
    }
};
