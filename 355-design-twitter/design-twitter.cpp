class Twitter {
public:
    Twitter() : timer(0) {}

    void postTweet(int userId, int tweetId) {
        ensureSelfFollow(userId);
        tweets[userId].push_back({++timer, tweetId});
    }

    vector<int> getNewsFeed(int userId) {
        ensureSelfFollow(userId);
        vector<int> feed;
        // max-heap of (time, tweetId, userId, index in that user's tweet list)
        using T = tuple<int,int,int,int>;
        priority_queue<T> pq;

        for (int f : follows[userId]) {
            auto &tw = tweets[f];
            if (!tw.empty()) {
                int idx = (int)tw.size() - 1;
                pq.emplace(tw[idx].first, tw[idx].second, f, idx);
            }
        }

        while (!pq.empty() && (int)feed.size() < 10) {
            auto [t, id, u, idx] = pq.top(); pq.pop();
            feed.push_back(id);
            if (idx - 1 >= 0) {
                auto &tw = tweets[u];
                pq.emplace(tw[idx - 1].first, tw[idx - 1].second, u, idx - 1);
            }
        }
        return feed;
    }

    void follow(int followerId, int followeeId) {
        if (followerId == followeeId) return;
        ensureSelfFollow(followerId);
        ensureSelfFollow(followeeId);
        follows[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        if (followerId == followeeId) return; // cannot unfollow self
        auto it = follows.find(followerId);
        if (it != follows.end()) it->second.erase(followeeId);
    }

private:
    int timer;
    unordered_map<int, vector<pair<int,int>>> tweets;     // userId -> [(time, tweetId)]
    unordered_map<int, unordered_set<int>> follows;       // userId -> set of followees

    void ensureSelfFollow(int userId) {
        auto &s = follows[userId];
        if (s.find(userId) == s.end()) s.insert(userId);
    }
};
