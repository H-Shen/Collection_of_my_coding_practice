class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for (auto&i : nums) ++freq[i];
        int n = (int)freq.size();
        vector<int> result(n);
        auto iter = freq.begin();
        for (int i = 0; i < n; ++i, ++iter) {
            result[i] = iter->first;
        }
        // O(n)
        nth_element(result.begin(), result.begin()+k-1, result.end(), [&](const int&l , const int& r) {
            return freq[l] > freq[r];
        });
        while (result.size() > k) {
            result.pop_back();
        }
        return result;
    }
};