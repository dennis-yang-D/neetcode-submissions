class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        // NOT POSSIBLE IN O(NLOGN) TIME !!!
        vector<vector<int>> ans;

        int n = INT_MIN;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] > 0) break;
            if(n == nums[i]) {continue;}
            int left = i + 1;
            int right = nums.size()-1;

            while(left < right) {
                if((nums[left] + nums[right] == -1 * nums[i])) {
                    ans.push_back({nums[left], nums[right], nums[i]});
                    int c = nums[left];
                    right--;
                    while(left < right && nums[left] == c) {
                        left++;
                    }
                }
                else if (nums[left] + nums[right] > -1 * nums[i]) {
                    right--;
                }
                else {
                    left++;
                }
            }
            n = nums[i];
        }

        return ans;
    }
};
