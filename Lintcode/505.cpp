class WebLogger {
private:
    static const int FIVE_MINUTES = 5*60;
    // The call to the function is in chronological order, that is to say, timestamp is in ascending order.
    vector<int> timestamps;    // timestamp to accumulated hits from the earliest timestamp
public:
    WebLogger() {
        // do intialization if necessary
    }

    /*
     * @param timestamp: An integer
     * @return: nothing
     */
    void hit(int timestamp) {
        // write your code here
        timestamps.emplace_back(timestamp);
    }

    /*
     * @param timestamp: An integer
     * @return: An integer
     */
    int get_hit_count_in_last_5_minutes(int timestamp) {
        // write your code here
        if (timestamps.empty()) {
            return 0;
        }
        int start = timestamp - FIVE_MINUTES + 1;
        auto iter = lower_bound(timestamps.begin(),timestamps.end(),start);
        if (iter == timestamps.end()) {
            return 0;
        }
        return (int)timestamps.size() - (int)(iter - timestamps.begin());
    }
};