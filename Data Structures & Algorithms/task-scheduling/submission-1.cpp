class Solution {
public:
    // always get the most common element first
    // unless the time means we can't get it
    struct numComp {
        bool operator()(pair<char, int>& a, pair<char, int>& b) {
            return a.second < b.second;
        }
    };
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> times(26);

        priority_queue<pair<char, int>, vector<pair<char, int>>, numComp> pq;

        vector<int> counts(26);
        vector<bool> isUsed(26);
        for(auto c : tasks) {
            counts[c - 'A']++;
        }

        int time = 0;
        // constraint: pq will only have zero times
        int numTasks = tasks.size();
        while(numTasks > 0){
            // input all zero times into the pq
            for(int i = 0; i < counts.size(); i++) {
                if(!isUsed[i] && counts[i] > 0 && times[i] <= 0) {
                    pq.push({i, counts[i]});
                    isUsed[i] = true;
                }
            }

            // get top - only do one at a time
            if(!pq.empty()) {
                auto curr = pq.top();
                pq.pop();
                // complete task
                times[curr.first] = n + 1;
                counts[curr.first]--;
                isUsed[curr.first] = false;
                numTasks--;
            }

            //increase time by 1
            time++;
            for(int i = 0; i < counts.size(); i++) {
                times[i]--;
            }
        }

        return time;
    }
};
