constexpr int MAXN = 10;

class Twitter {
private:
    struct Comparator {
        bool operator()(const pair<int, int> &l, const pair<int, int> &r) const {
            return l.second > r.second;
        }
    };
    unordered_map<int, unordered_set<int> > follower2followees;
    unordered_map<int, deque<pair<int, int> > > tweets; // (userId,(tweetId,timestamp))
    unsigned int timestamp;
public:
    /** Initialize your data structure here. */
    Twitter() {
        timestamp = 0;
    }

    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_front({tweetId, timestamp});
        ++timestamp;
        while (tweets[userId].size() > MAXN) {
            tweets[userId].pop_back();
        }
    }

    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int, int>, vector<pair<int, int> >, Comparator> pq;
        // add self's tweets
        for (const auto &i : tweets[userId]) {
            if (pq.size() < MAXN) {
                pq.push(i);
            } else if (i.second > pq.top().second) {
                pq.pop();
                pq.push(i);
            }
        }
        // add all followees' tweets
        for (const auto &i : follower2followees[userId]) {
            for (const auto &j : tweets[i]) {
                if (pq.size() < MAXN) {
                    pq.push(j);
                } else if (j.second > pq.top().second) {
                    pq.pop();
                    pq.push(j);
                }
            }
        }
        vector<int> result;
        while (!pq.empty()) {
            result.emplace_back(pq.top().first);
            pq.pop();
        }
        reverse(result.begin(), result.end());
        return result;
    }

    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        if (followerId != followeeId) follower2followees[followerId].insert(followeeId);
    }

    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        if (followerId != followeeId) follower2followees[followerId].erase(followeeId);
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