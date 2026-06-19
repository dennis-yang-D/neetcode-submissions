class Solution {
public:
    struct hashStruct {
        size_t operator()(const vector<int>& triplet) const {
            vector<int> t = {triplet[0], triplet[1], triplet[2]};
            sort(t.begin(), t.end());
            return hash<int>()(t[0]) ^ (hash<int>()(t[1]) << 1) ^ (hash<int>()(t[2]) << 2);
        }
    };
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        unordered_map<int, pair<int, int>> nums_map; // since nums is sorted, the pair represents the range
        // of i such that nums[i] = a value
        for(int i = 0; i < nums.size(); i++) {
            if(!nums_map.contains(nums[i])) {
                nums_map[nums[i]] = pair<int, int>(i, i);
            }
            else {
                nums_map[nums[i]].first = min(nums_map[nums[i]].first, i);
                nums_map[nums[i]].second = max(nums_map[nums[i]].second, i);
            }
        }

        unordered_set<vector<int>, hashStruct> dedupe;
        vector<vector<int>> ans;

        for(int left = 0; left < nums.size(); left++) {
            for(int right = 0; right < nums.size(); right++)
            {int diff = -1 * (nums[right] + nums[left]);
            // Goal: ensure that there always exists a left < ind of diff < right
            // Do this by forcing diff to be between nums[left] and nums[right]
            // Works bc of sorting
            //cout << nums[left] << " " << diff << " " << nums[right] << " | ";
            if(nums[left] <= diff && diff <= nums[right] && nums_map.contains(diff)) {
                // ensure diff != left and diff != right
                pair<int, int> range = nums_map[diff];

                // just check if possible for left != ind of diff != right
                bool check = nums[left] != diff && diff != nums[right];

                //cout << left << " " << range.first << " " << range.second << " " << right << " | ";

                if(nums[left] != diff && diff == nums[right]) {
                    check = check || (right > range.first);
                }
                else if (nums[left] == diff && diff != nums[right]) {
                    check = check || (left < range.second);
                }
                else { // all are equal
                    check = check || (left < right - 1);
                }

                if(check) {
                    if(!dedupe.contains({nums[left], nums[right], diff})) {
                        dedupe.insert({nums[left], nums[right], diff});
                        ans.push_back({nums[left], nums[right], diff});
                    }
                }
            }
            }
        }

        return ans;
    }
};
