class RecentCounter {
private:
    vector<int> requests;
    int interval = 3000;
public:
    RecentCounter() {
        vector<int>().swap(requests);
    }
    
    int ping(int t) {
        requests.emplace_back(t);
        int min_t = t - interval;
        int index_min_t = lower_bound(requests.begin(), requests.end(), min_t) - requests.begin();
        int index_t = lower_bound(requests.begin(), requests.end(), t) - requests.begin();
        return (index_t - index_min_t + 1);
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */