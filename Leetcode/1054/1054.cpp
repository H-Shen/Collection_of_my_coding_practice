class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        unordered_map<int, int> unmap;
        for (const auto &i : barcodes) ++unmap[i];
        struct Node {
            int val, freq;
            Node(int val, int freq) : val(val), freq(freq) {}
            bool operator < (const Node &node) const {
                if (freq == node.freq) return val < node.val;
                return freq < node.freq;
            }
        };
        priority_queue<Node> pq;
        for (const auto &[k, v] : unmap) pq.push(Node(k, v));
        vector<int> result;
        while (pq.size() >= 2) {
            Node cur1 = pq.top();
            pq.pop();
            Node cur2 = pq.top();
            pq.pop();
            result.emplace_back(cur1.val);
            result.emplace_back(cur2.val);
            --cur1.freq;
            --cur2.freq;
            if (cur1.freq > 0) {
                pq.push(cur1);
            }
            if (cur2.freq > 0) {
                pq.push(cur2);
            }
        }
        if (!pq.empty()) {
            result.emplace_back(pq.top().val);
        }
        return result;
    }
};