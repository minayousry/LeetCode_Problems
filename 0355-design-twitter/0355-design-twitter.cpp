class Twitter {
public:
    unordered_map<int,unordered_set<int>> following_data;
    unordered_map< int,vector<pair<int,int>> > user_tweets;
    int timer;
    Twitter() {
        timer = 1;
    }
    
    void postTweet(int userId, int tweetId) {
        user_tweets[userId].push_back(make_pair(timer,tweetId));
        timer++;
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> news_feed;

        priority_queue<pair<int,int>> latest_posts;

        unordered_set<int> users = following_data[userId];
        users.insert(userId);

        for(auto it = users.begin();it != users.end();++it)
        {
            if(user_tweets.find(*it) != user_tweets.end())
            {
                for(const auto &user_tweet_data:user_tweets[*it])
                {
                    latest_posts.push(user_tweet_data);
                }
            }
        }

        int counter = 0;
        int latest_tweed_id;
        while(!latest_posts.empty() && counter < 10)
        {
            latest_tweed_id = latest_posts.top().second;
            latest_posts.pop();
            news_feed.emplace_back(latest_tweed_id);
            counter++;
        }

        return news_feed;



    }
    
    void follow(int followerId, int followeeId) {
        following_data[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if(following_data.find(followerId) !=  following_data.end() &&
         following_data[followerId].find(followeeId) != following_data[followerId].end())
        {
            following_data[followerId].erase(followeeId);
        }
        
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