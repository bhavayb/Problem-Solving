class Twitter {
public:
    int timer;

    unordered_map<int, unordered_set<int>> following;
    unordered_map<int, vector<pair<int,int>>> tweets;

    Twitter() {
        timer = 0;
    }

    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({timer++, tweetId});
    }

    vector<int> getNewsFeed(int userId) {
        priority_queue<vector<int>> pq;
        following[userId].insert(userId);
        for(auto followee : following[userId]) {
            auto &userTweets = tweets[followee];
            if(!userTweets.empty()) {
                int idx = userTweets.size() - 1;
                pq.push({
                    userTweets[idx].first,  
                    userTweets[idx].second, 
                    followee,
                    idx
                });
            }
        }

        vector<int> ans;

        while(!pq.empty() && ans.size() < 10) {

            auto cur = pq.top();
            pq.pop();

            int tweetId = cur[1];
            int user = cur[2];
            int idx = cur[3];

            ans.push_back(tweetId);

            idx--;

            if(idx >= 0) {
                pq.push({
                    tweets[user][idx].first,
                    tweets[user][idx].second,
                    user,
                    idx
                });
            }
        }

        return ans;
    }

    void follow(int followerId, int followeeId) {
        if(followerId == followeeId) return;
        following[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        if(followerId == followeeId) return;
        following[followerId].erase(followeeId);
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