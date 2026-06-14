class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> ind_map;

        for(int i = 0; i < nums.size(); i++)
        {
            ind_map[nums[i]] = (i); // this is fine bc we will overwrite i with the larger value
        }

        for(int i = 0; i < nums.size(); i++) {
            int n = target - nums[i];
            if (ind_map.contains(n) && ind_map[n] != i) { // so if there's two inds with the same value of n, bc we iterate
            // from the lowest ind to highest ind, ind_map always contatins the HIGHER VALUE of the ind
            // so i must be less than ind_map[n]
                return {i, ind_map[n]};
            }
        }

        return {0,0};
    }
};
