/**
 * Definition of Tweet:
 * class Tweet {
 * public:
 *     int id;
 *     int user_id;
 *     String text;
 *     static Tweet create(int user_id, string tweet_text) {
 *         // This will create a new tweet object,
 *         // and auto fill id
 *     }
 * }
 */


class MiniTwitter {
private:
    static const int NUMBER_OF_TWEETS = 10;
    struct Pair {
        int timestamp;
        Tweet tweet;
        Pair () = default;
        Pair (int timestamp, Tweet tweet) : timestamp(timestamp), tweet(tweet) {}
    };
    struct TweetComparator {
        bool operator ()(const Pair& l, const Pair& r) const {
            return l.timestamp > r.timestamp;
        }
    };
    int currentTimestamp;
    unordered_map<int, set<Pair, TweetComparator>> userId2tweets;
    unordered_map<int, unordered_set<int>> userId2FollowId;
public:
    MiniTwitter() {
        // do intialization if necessary
        currentTimestamp = 0;
    }

    /*
     * @param user_id: An integer
     * @param tweet_text: a string
     * @return: a tweet
     */
     Tweet postTweet(int user_id, string &tweet_text) {
        // write your code here
        if (userId2FollowId.count(user_id) == 0) {
            userId2FollowId[user_id].clear();
        }
        Tweet tweet = Tweet::create(user_id, tweet_text);
        userId2tweets[user_id].insert(Pair(currentTimestamp, tweet));
        ++currentTimestamp;
        return tweet;
    }

    /*
     * @param user_id: An integer
     * @return: a list of 10 new feeds recently and sort by timeline
     */
    vector<Tweet> getNewsFeed(int user_id) {
        // write your code here
        vector<Tweet> result;
        if (userId2FollowId.count(user_id) == 0) {
            return result;
        }
        // minimal heap (k-way merge)
        struct Node {
            int userId;
            set<Pair, TweetComparator>::iterator iter;
            Node() = default;
            Node(int userId, const set<Pair, TweetComparator>::iterator& iter) : userId(userId), iter(iter) {}
            bool operator < (const Node& other) const {
                return iter->timestamp < (other.iter)->timestamp;
            }
        };
        priority_queue<Node> pq;
        // add self
        if (!userId2tweets[user_id].empty()) {
            pq.push(Node(user_id, userId2tweets[user_id].begin()));
        }
        // add friends the user follows
        for (const auto &friendId : userId2FollowId[user_id]) {
            if (!userId2tweets[friendId].empty()) {
                pq.push(Node(friendId, userId2tweets[friendId].begin()));
            }
        }
        while ((int)result.size() < NUMBER_OF_TWEETS) {
            if (pq.empty()) {
                break;
            }
            Node node = pq.top();
            pq.pop();
            result.emplace_back((node.iter)->tweet);
            node.iter++;
            if (node.iter != userId2tweets[node.userId].end()) {
                pq.push(node);
            }
        }
        return result;
    }

    /*
     * @param user_id: An integer
     * @return: a list of 10 new posts recently and sort by timeline
     */
    vector<Tweet> getTimeline(int user_id) {
        // write your code here
        vector<Tweet> result;
        if (userId2FollowId.count(user_id) == 0) {
            return result;
        }
        auto& history = userId2tweets[user_id];
        auto iter = history.begin();
        while ((int)result.size() < NUMBER_OF_TWEETS && iter != history.end()) {
            result.emplace_back(iter->tweet);
            ++iter;
        }
        return result;
    }

    /*
     * @param from_user_id: An integer
     * @param to_user_id: An integer
     * @return: nothing
     */
    void follow(int from_user_id, int to_user_id) {
        // write your code here
        userId2FollowId[from_user_id].insert(to_user_id);
    }

    /*
     * @param from_user_id: An integer
     * @param to_user_id: An integer
     * @return: nothing
     */
    void unfollow(int from_user_id, int to_user_id) {
        // write your code here
        userId2FollowId[from_user_id].erase(to_user_id);
    }
};
