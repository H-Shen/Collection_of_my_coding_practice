class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> unmap; 
        // O(n)
        for (const auto &i : words) {
            ++unmap[i];
        }
        // O(n)
        vector<string> uniqueWords(unmap.size());
        auto iter = uniqueWords.begin();
        for (const auto &[k, v] : unmap) {
            *iter = k;
            ++iter;
        }
        auto cmp = [&](const string &l, const string &r){
            int temp = unmap[l] - unmap[r];
            if (temp == 0) return l < r;
            return temp > 0;
        };
        nth_element(uniqueWords.begin(), uniqueWords.begin() + k - 1, uniqueWords.end(), cmp);  // O(n)
        sort(uniqueWords.begin(), uniqueWords.begin() + k, cmp); // O(klogk)
        return vector<string>(uniqueWords.begin(), uniqueWords.begin() + k);  // O(k)
    }
};