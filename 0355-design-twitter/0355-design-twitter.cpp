class Twitter {
public:
    map<int, vector<pair<int, int>>> mp; // userId -> {timestamp, tweetId}
    map<int, set<int>> flw;              // follower -> followees
    map<int, vector<int>> feed;
    int timer;

    Twitter() {
        timer = 0;
    }

    void refreshFeed(int userId) {
        priority_queue<pair<int, int>> pq;

        // User's own tweets
        for (auto tweet : mp[userId]) {
            pq.push(tweet);
        }

        // Tweets from followees
        for (auto followeeId : flw[userId]) {
            for (auto tweet : mp[followeeId]) {
                pq.push(tweet);
            }
        }

        vector<int> finalFeed;
        int sz = 10;

        while (!pq.empty() && sz--) {
            finalFeed.push_back(pq.top().second);
            pq.pop();
        }

        feed[userId] = finalFeed;
    }

    void postTweet(int userId, int tweetId) {
        timer++;
        mp[userId].push_back({timer, tweetId});

        // Refresh own feed
        refreshFeed(userId);

        // Refresh feeds of followers who follow this user
        for (auto &[follower, followees] : flw) {
            if (followees.count(userId)) {
                refreshFeed(follower);
            }
        }
    }

    vector<int> getNewsFeed(int userId) {
        refreshFeed(userId);   // ensure latest feed
        return feed[userId];
    }

    void follow(int followerId, int followeeId) {
        if (followerId == followeeId) return;

        flw[followerId].insert(followeeId);
        refreshFeed(followerId);
    }

    void unfollow(int followerId, int followeeId) {
        if (followerId == followeeId) return;

        flw[followerId].erase(followeeId);
        refreshFeed(followerId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */