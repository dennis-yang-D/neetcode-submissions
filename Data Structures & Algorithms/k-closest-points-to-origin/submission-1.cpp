class Solution {
public:
    // keep a min heap! so we can get rid of the min element (since we only keep the max)
    struct comp {
        bool operator()(const vector<int>& a, const vector<int>& b) {
            return a[0] * a[0] + a[1] * a[1] <= b[0] * b[0] + b[1] * b[1];
        }
    };
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<vector<int>, vector<vector<int>>, comp> pq;

        for(auto v : points)
        {
            pq.push(v);
            if(pq.size() > k) {
                pq.pop();
            }
        }

        vector<vector<int>> ans;
        while(!pq.empty()) {
            ans.push_back(pq.top());
            pq.pop();
        }

        return ans;
    }
};
