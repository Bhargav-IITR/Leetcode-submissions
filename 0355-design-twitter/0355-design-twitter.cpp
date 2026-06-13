class Twitter {
public:
    map <int, vector <pair<int, int>>> mp; // userId - vector of tweetIds of that userId
    vector <vector <int>> flw;
    map <int, vector <int>> feed;
    int timer;
    Twitter(){
        this->timer = 0;
        this->flw  = vector(501, vector <int> (501, 0));
        for(int i = 0; i < 501 ; i++) flw[i][i] = 1;
    }

    void refreshFeed(int userId){
        vector <int> followeeIds;
        for(int i = 0 ; i < 501 ; i++) if(flw[userId][i]) followeeIds.push_back(i);
        priority_queue <pair<int, int>> pq;
        for(auto followeeId : followeeIds){
            for(int i = mp[followeeId].size()-1 ; i >= 0 ; i--){
                auto tweet = mp[followeeId][i];
                pq.push(tweet);
            }
        }
        vector <int> finalFeed;
        int size = 10;
        while(!pq.empty() && (size > 0)){
            finalFeed.push_back(pq.top().second);
            pq.pop();
            size--;
        }
        feed[userId] = finalFeed;
    }
    
    void postTweet(int userId, int tweetId) {
        timer++;
        mp[userId].push_back({timer, tweetId});
        for(int flwrId = 0 ; flwrId < 501 ; flwrId++){
            if(flw[flwrId][userId]) refreshFeed(flwrId);
        }
    }
    
    vector<int> getNewsFeed(int userId) {
        return feed[userId];
    }
    
    void follow(int followerId, int followeeId) {
        flw[followerId][followeeId] = 1;
        refreshFeed(followerId);
    }
    
    void unfollow(int followerId, int followeeId) {
        flw[followerId][followeeId] = 0;
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