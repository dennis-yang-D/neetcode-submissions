class Solution {
public:
    int maxProduct(vector<int>& nums) {
        // solution with Kadane's algo
        int currMax = 1;
        int currMin = 1; // can flip to max whenever
        int bestMax = nums[0];

        for(int i = 0; i < nums.size(); i++) {
            int prevMax = currMax;
            currMax = max(currMin * nums[i], max(currMax * nums[i], nums[i]));
            currMin = min(currMin * nums[i], min(prevMax * nums[i], nums[i]));

            bestMax = max(bestMax, currMax);
        }

        return bestMax;
    }
};
