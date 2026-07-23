class Twitter {
public:
    vector<vector<pair<int, int>>> tweets; // first is tweetId. second is time
    vector<unordered_set<int>> is_following;
    int time = 0;
    struct pairComp {
        bool operator()(pair<int, int>& a, pair<int, int>& b) {
            return a.second > b.second; // min heap
        }
    };
    Twitter() {
        is_following.resize(101);
        tweets.resize(101);
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({tweetId, time});
        time++;
        is_following[userId].insert(userId);
    }
    
    vector<int> getNewsFeed(int userId) {
        // use pq to sort this
        vector<int> feed;
        priority_queue<pair<int, int>, vector<pair<int, int>>, pairComp> pq;
        for(auto n : is_following[userId]) {
            for(auto p : tweets[n]) {
                pq.push(p);
                if(pq.size() > 10) {pq.pop();}
            }
        }

        while(!pq.empty()) {
            feed.push_back(pq.top().first);
            pq.pop();
        }

        reverse(feed.begin(), feed.end());

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
