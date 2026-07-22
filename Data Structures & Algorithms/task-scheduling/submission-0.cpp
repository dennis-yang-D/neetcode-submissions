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
        for(auto c : tasks) {
            counts[c - 'A']++;
        }
        for(int i = 0; i < counts.size(); i++) {
            pq.push({'A' + i, counts[i]});
        }

        int time = 0;
        while(!pq.empty()) {
            if(pq.top().second <= 0) { // eliminate zeroes
                pq.pop();
                continue;
            }

            // get the top value with zero time left
            vector<pair<char, int>> store;
            while(!pq.empty()) {
                auto curr = pq.top();
                pq.pop();
                if(times[curr.first - 'A'] == 0) {
                    // simulate running it by setting time back up to n
                    //cout << curr.first << " ";
                    times[curr.first - 'A'] = n + 1;
                    curr.second = curr.second - 1;
                    //cout << curr.second << " ";
                    store.push_back(curr);
                    break;
                } else {
                    store.push_back(curr);
                }
            }

            // push curr back into pq to reset stack
            for(auto p : store) {
                pq.push(p);
            }

            // decrease times by 1
            for(int i = 0; i < counts.size(); i++) {
                if(times[i] > 0) {
                    times[i]--;
                }
            }
            time++;
        }

        return time;
    }
};
