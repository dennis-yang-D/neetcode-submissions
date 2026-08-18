class Solution {
public:
    struct sorter {
        bool operator()(const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        }
    };
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        // greedy: order by last value of each interval

        sort(intervals.begin(), intervals.end(), sorter());

        int num_intervals = 0;
        vector<int> curr_int;

        for(auto& v : intervals) {
            if(curr_int.size() == 0) {
                curr_int = v;
                num_intervals++;
                continue;
            }

            if(v[0] < curr_int[1]) {
                // overlapping
            }
            else {
                num_intervals++;
                curr_int = v;
            }
        }

        return intervals.size() - num_intervals;
    }
};
