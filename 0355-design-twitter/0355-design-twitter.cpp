class Twitter {
    map<int, set<int>> friends;
    vector<pair<int,int>> posts;

public:
    Twitter() {
    
    }

    void postTweet(int userId, int tweetId) {
        posts.push_back({userId,tweetId});
    }

    vector<int> getNewsFeed(int userId) {
        vector<int> ans;
        int n = 0;
        for(int i = posts.size()-1;i>=0 && n<10 ;i--){
            if(posts[i].first == userId || friends[userId].count(posts[i].first)){
                ans.push_back(posts[i].second);
                n++;
            }
        }
        return ans;
    }

    void follow(int followerId, int followeeId) {
        friends[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        friends[followerId].erase(followeeId);
    }
};