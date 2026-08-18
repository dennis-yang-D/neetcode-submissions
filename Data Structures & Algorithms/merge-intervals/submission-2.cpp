class Solution {
public:
    struct comp {
        bool operator()(const vector<int>& a, const vector<int>& b) {
            if(a[0] == b[0]) {
                return a[1] < b[1];
            }
            return a[0] < b[0];
        }
    };

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // start by sorting intervals by 1st number

        sort(intervals.begin(), intervals.end(), comp());

        vector<vector<int>> ans;

        for(int i = 0; i < intervals.size(); i++) {
            if(ans.size() == 0) {
                ans.push_back(intervals[i]);
            }
            if(ans.back()[1] >= intervals[i][0]) {
                ans.back()[1] = max(ans.back()[1], intervals[i][1]);
            }
            else {
                ans.push_back(intervals[i]);
            }
        }

        return ans;
    }
};
