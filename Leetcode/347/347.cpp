class Solution {
public:
    vector<int> topKFrequent(const vector<int> &nums, int k) {
        unordered_map<int, int> freq;
        for (const auto &p : nums) {
            ++freq[p];
        }
        vector<pair<int, int> > A(freq.size());
        int i = 0;
        for (const auto it : freq) {
            A[i++] = it;
        }
        sort(A.begin(), A.end(), [](const pair<int, int> &a, const pair<int, int> &b) -> bool {
            return (a.second > b.second);
        });
        vector<int> res(static_cast<unsigned long>(k));
        auto it = A.cbegin();
        for (auto &p : res) {
            p = (*it).first;
            ++it;
        }
        return res;
    }
};