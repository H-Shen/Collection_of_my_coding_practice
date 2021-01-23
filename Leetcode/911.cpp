class TopVotedCandidate {
public:
    struct Node {
        int val, freq, updateTime;
        Node() = default;
        explicit Node(int val, int freq, int updateTime) : val(val), freq(freq), updateTime(updateTime) {}
        bool operator < (const Node &node) const {
            if (freq == node.freq) {
                return updateTime < node.updateTime;
            }
            return freq < node.freq;
        }
    };
    vector<int> times;
    vector<Node> leading;
    TopVotedCandidate(vector<int>& persons, vector<int>& times) : times(times) {
        constexpr int MAXN = 5005;
        int freqList[MAXN]{};
        priority_queue<Node, vector<Node>, less<> > pq;
        int n = (int)times.size();
        for (int i = 0; i < n; ++i) {
            ++freqList[persons.at(i)];
            pq.push(Node(persons.at(i), freqList[persons.at(i)], times.at(i)));
            leading.emplace_back(pq.top());
        }
    }
    
    int q(int t) {
        int index = -1;
        if (binary_search(times.begin(), times.end(), t)) {
            index = lower_bound(times.begin(), times.end(), t) - times.begin();
            return leading.at(index).val;
        }
        index = lower_bound(times.begin(), times.end(), t) - times.begin();
        return leading.at(index - 1).val;
    }
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */