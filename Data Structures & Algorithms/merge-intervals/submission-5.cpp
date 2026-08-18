class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // greedy solution

        vector<int> line(1001);

        for(auto& v : intervals) {
            line[v[0]] = max(line[v[0]], v[1] - v[0] + 1); // represents size of the interval starting at v[0]
        }

        vector<vector<int>> ans;

        int counter = 0;

        // Ex for [1,3] [1,5] [6,7]
        // We get 0 5 0 0 0 0 2 0 0
        // We get 0,1,2,3,4,5,6,7,8
        // first decrease counter value
        // if counter == 0, then make new interval
        // then set counter value to the new value

        // Ex for [1,2] [2,3]
        // 0 1 1 0 0
        // 0 1 2 3 4

        vector<int> inter;
        for(int i = 0; i < line.size(); i++) {
            if(line[i] > 0) {
                counter = max(counter, line[i]); // take max remaining size of the interval to merge
                if(inter.size() == 0) {
                    inter.push_back(i);
                }
            }

            counter--;

            if(counter == 0 && inter.size() > 0) {
                inter.push_back(i);
                ans.push_back(inter);
                inter.clear();
            }

            //cout << counter << " " << i << endl;
        }

        return ans;
    }
};
