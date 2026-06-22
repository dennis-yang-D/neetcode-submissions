class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int, int>> temps;
        vector<int> days(temperatures.size());

        for(int i = 0; i < temperatures.size(); i++) {
            if(temps.empty()) {temps.push({temperatures[i], i}); continue;}
            if(temps.top().first >= temperatures[i]) {
                temps.push({temperatures[i], i});
            }
            else {
                while(!temps.empty() && temps.top().first < temperatures[i]) {
                    pair<int, int> t = temps.top();
                    temps.pop();
                    days[t.second] = i - t.second; // you have access to the indices, just use them
                }
                temps.push({temperatures[i], i});
            }
        }

        return days;
    }
};
