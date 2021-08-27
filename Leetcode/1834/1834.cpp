class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        using ll = long long;
        struct Node {
            ll enqueueTime, processingTime, idx;
            Node(int e, int p, int idx_) : enqueueTime(e), processingTime(p), idx(idx_) {}
            bool operator < (const Node &other) const {
                if (enqueueTime == other.enqueueTime) {
                    if (processingTime == other.processingTime) {
                        return idx > other.idx;
                    }
                    return processingTime > other.processingTime;
                }
                return (enqueueTime > other.enqueueTime);
            }
        };
        auto comp = [&](const Node& a, const Node &b) {
            if (a.processingTime == b.processingTime) {
                return a.idx > b.idx;
            }
            return a.processingTime > b.processingTime;
        };
        
        int n = (int)tasks.size();
        ll currentTime = 0;
        vector<int> result;
        std::priority_queue<Node, vector<Node>, less<> > pq;
        std::priority_queue<Node, vector<Node>, decltype(comp) > pq2(comp);
        for (int i = 0; i < n; ++i) {
            pq.push(Node(tasks[i][0], tasks[i][1], i));
        }
        while (result.size() < tasks.size()) {
            while (!pq.empty() && pq.top().enqueueTime <= currentTime) {
                pq2.push(pq.top());
                pq.pop();
            }
            if (pq2.empty()) {
                if (pq.empty()) {
                    break;
                }
                else {
                    currentTime = pq.top().enqueueTime;
                }
            }
            else {
                Node cur = pq2.top();
                pq2.pop();
                result.emplace_back(cur.idx);
                currentTime = currentTime + cur.processingTime;  
            }
        }
        return result;
    }
};