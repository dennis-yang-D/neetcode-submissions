class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        // Once we merge two intervals, only future intervals need to be merged

        vector<vector<int>> merge;

        for(auto& v : intervals) {
            // if non overlapping
            if(v[1] < newInterval[0] || newInterval[1] < v[0]) {
                merge.push_back(v);
            }
            else {
                newInterval[0] = min(newInterval[0], v[0]);
                newInterval[1] = max(newInterval[1], v[1]);
            }
        }

        // insert new interval in
        if(merge.size() == 0) {
            merge.push_back(newInterval);
            return merge;
        }
        for(int i = 0; i < merge.size(); i++) {
            if(merge[i][0] >= newInterval[0]) {
                merge.insert(merge.begin() + i, newInterval);
                return merge;
            }
        }


        merge.push_back(newInterval);
        return merge;
    }
};
