class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        //Idea 1: sort the array, then run through it and find the duplicate
        sort(nums.begin(), nums.end());
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] == nums[i-1]) {
                return nums[i];
            }
        }
        return nums[0];
        // Idea: treat the nums vector like a graph, and make this a cycle detection problem?

        // [1,3,2,4,5,6,3]
    }
};
