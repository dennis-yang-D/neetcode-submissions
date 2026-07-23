class Twitter {
public:
    vector<vector<pair<int, int>>> tweets; // first is tweetId. second is time
    vector<unordered_set<int>> is_following;
    int time = 0;
    struct pairComp {
        bool operator()(vector<int>& a, vector<int>& b) {
            return a[1] < b[1]; // min heap
        }
    };
    Twitter() {
        is_following.resize(101);
        tweets.resize(101);
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({tweetId, time});
        if(tweets[userId].size() > 10) {
            tweets[userId].erase(tweets[userId].begin());
        }
        time++;
        is_following[userId].insert(userId);
    }
    
    vector<int> getNewsFeed(int userId) {
        // use pq to sort this
        vector<int> feed;
        priority_queue<vector<int>, vector<vector<int>>, pairComp> pq;
        for(auto n : is_following[userId]) {
            pq.push({tweets[n].back().first, tweets[n].back().second, (int)tweets[n].size() - 1, n}); // only keep 1 tweet from each user at a time
        }

        while(!pq.empty()) {
            if(feed.size() >= 10) {break;} 
            feed.push_back(pq.top()[0]);
            //cout << pq.top()[1] << " ";
            auto v = pq.top();
            pq.pop();

            if(v[2] > 0) {
                pq.push({tweets[v[3]][v[2]-1].first, tweets[v[3]][v[2]-1].second, v[2] - 1, v[3]});
            }
        }

        //reverse(feed.begin(), feed.end());

        return feed;
    }
    
    void follow(int followerId, int followeeId) {
        is_following[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if(followerId != followeeId)
        {is_following[followerId].erase(followeeId);}
    }
};
