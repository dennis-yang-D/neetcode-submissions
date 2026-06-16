class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> leftPref(nums.size());
        vector<int> rightPref(nums.size());

        leftPref[0] = nums[0];
        for(int i = 1; i < nums.size(); i++) {
            leftPref[i] = leftPref[i-1] * nums[i];
        }

        rightPref[nums.size()-1] = nums[nums.size()-1];
        for(int i = nums.size() - 2; i > -1; i--) {
            rightPref[i] = rightPref[i+1] * nums[i];
        }

        vector<int> val(nums.size());

        for(int i = 0; i < nums.size(); i++) {
            if(i == 0) {
                val[i] = rightPref[i+1];
                continue;
            }
            if(i ==nums.size() - 1) {
                val[i] = leftPref[nums.size() - 2];
                continue;
            }
            val[i] = leftPref[i-1] * rightPref[i+1];
        }

        return val;
    }
};
