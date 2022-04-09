#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

template<typename T>
using RBTree = __gnu_pbds::tree<T, __gnu_pbds::null_type, less<>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;

struct Node {
    int time;
    int id;
    Node() = default;
    Node(int time, int id) : time(time), id(id) {}
    bool operator < (const Node& node) const {
        if (time == node.time) {
            return id < node.id;
        }
        return time < node.time;
    }
};

class TweetCounts {
private:
    unordered_map<string, RBTree<Node>> tweet2timestamp;
    int id;
    int range_count(const string& tweetName, int startTime, int endTime) {
        auto iter = tweet2timestamp.find(tweetName);
        if (iter == tweet2timestamp.end()) {
            return 0;
        }
        auto& rbt = iter->second;
        if (startTime > (--rbt.end())->time || endTime < rbt.begin()->time ) {
            return 0;
        }
        int rank1 = rbt.order_of_key(Node(startTime, -1));
        int rank2 = rbt.order_of_key(Node(endTime, numeric_limits<int>::max()));
        return rank2 - rank1;
    }
public:
    TweetCounts() : id(0) {
        
    }
    
    void recordTweet(string tweetName, int time) {
        // Suppose we record the same tweet with the time by increasing order
        tweet2timestamp[tweetName].insert(Node(time, id));
        ++id;
    }
    
    vector<int> getTweetCountsPerFrequency(string freq, string tweetName, int startTime, int endTime) {
        vector<int> result;
        int l = -1;
        int r = -1;
        bool reachEnd = false;
        if (freq == "minute") {
            while (!reachEnd) {
                if (l == -1) {
                    l = startTime;
                    r = l + 59;
                    if (r >= endTime) {
                        r = endTime;
                        reachEnd = true;
                    }
                }
                else {
                    l = r + 1;
                    r = l + 59;
                    if (r >= endTime) {
                        r = endTime;
                        reachEnd = true;
                    }
                }
                result.emplace_back(range_count(tweetName, l, r));
            }
        }
        else if (freq == "hour") {
            while (!reachEnd) {
                if (l == -1) {
                    l = startTime;
                    r = l + 3599;
                    if (r >= endTime) {
                        r = endTime;
                        reachEnd = true;
                    }
                }
                else {
                    l = r + 1;
                    r = l + 3599;
                    if (r >= endTime) {
                        r = endTime;
                        reachEnd = true;
                    }
                }
                result.emplace_back(range_count(tweetName, l, r));
            }
        }
        else {
            while (!reachEnd) {
                if (l == -1) {
                    l = startTime;
                    r = l + 86399;
                    if (r >= endTime) {
                        r = endTime;
                        reachEnd = true;
                    }
                }
                else {
                    l = r + 1;
                    r = l + 86399;
                    if (r >= endTime) {
                        r = endTime;
                        reachEnd = true;
                    }
                }
                result.emplace_back(range_count(tweetName, l, r));
            }
        }
        return result;
    }
};

/**
 * Your TweetCounts object will be instantiated and called as such:
 * TweetCounts* obj = new TweetCounts();
 * obj->recordTweet(tweetName,time);
 * vector<int> param_2 = obj->getTweetCountsPerFrequency(freq,tweetName,startTime,endTime);
 */