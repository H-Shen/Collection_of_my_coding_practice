class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    }
    int maxEvents(vector<vector<int>>& events) {
        // greedy
        constexpr int TIME_LENGTH = 1e5+5;
        vector<int> groupByStartDays[TIME_LENGTH]{};
        int n = (int)events.size();
        // group by start days
        for (int i = 0; i < n; ++i) {
            groupByStartDays[events[i][0]].emplace_back(i);
        }
        int counter = 0;
        int currentTimePoint = 1;
        priority_queue<int, vector<int>, greater<> > pq;    // store endDay only
        while (currentTimePoint < TIME_LENGTH) {
            // Step1: Add all tasks that starts from the current time point
            for (const auto &i : groupByStartDays[currentTimePoint]) {
                pq.push(events[i][1]);
            }
            // Step2: Pop out all tasks whose endDay < currentTimePoint
            while (!pq.empty() && pq.top() < currentTimePoint) {
                pq.pop();
            }
            if (!pq.empty()) {
                ++counter;
                pq.pop();
            }
            ++currentTimePoint;
        }
        return counter;
    }
};