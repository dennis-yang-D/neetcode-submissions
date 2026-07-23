class Twitter {
public:
    vector<pair<int, int>> tweets; // first is userId, second is tweetId. Later values are more recent
    vector<unordered_set<int>> is_following;
    Twitter() {
        is_following.resize(101);
    }
    
    void postTweet(int userId, int tweetId) {
        tweets.push_back({userId, tweetId});
        is_following[userId].insert(userId);
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> feed;
        for(int i = tweets.size() - 1; i > -1; i--) {
            if(feed.size() >= 10) {break;}
            if(is_following[userId].contains(tweets[i].first)) {
                feed.push_back(tweets[i].second);
            }
        }

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
