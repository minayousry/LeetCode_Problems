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

        priority_queue<tuple<int,int,int,int>> latest_posts;

        unordered_set<int> users = following_data[userId];
        users.insert(userId);


        for(auto it = users.begin();it != users.end();++it)
        {
            if(user_tweets.find(*it) != user_tweets.end() && !user_tweets[*it].empty())
            {
                int last_index = user_tweets[*it].size() - 1;
                int user_id = *it;
                int time = user_tweets[*it][last_index].first;
                int user_tweet_id = user_tweets[*it][last_index].second;

                latest_posts.emplace(make_tuple(time,user_tweet_id,user_id,last_index));
            }
        }

        int counter = 0;
        int latest_tweed_id;
        while(!latest_posts.empty() && counter < 10)
        {
            auto top_entry = latest_posts.top();
            latest_posts.pop();

            auto [time, user_tweet_id, user_id, index] = top_entry;

            news_feed.push_back(user_tweet_id);

            if(index > 0)
            {
                auto &[new_time_tweet,tweet_id] = user_tweets[user_id][index - 1];
                latest_posts.emplace(make_tuple(new_time_tweet,tweet_id,user_id,index - 1));
            }
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