class Solution {
public:
    int findPairs(vector<int> &nums, int k) {
        if (k < 0) {
            return 0;
        }
        unordered_map<int, int> freq;
        for (const auto &i : nums) {
            ++freq[i];
        }
        int cnt = 0;

        if (k == 0) {
            for (auto it = freq.cbegin(); it != freq.cend(); ++it) {
                if (it->second > 1) {
                    ++cnt;
                }
            }
            return cnt;
        } else {
            unordered_set<string> res;
            int tmpMax, tmpMin;
            string tmpStr;
            for (auto it = freq.begin(); it != freq.end(); ++it) {
                if (freq.find(it->first + k) != freq.end()) {
                    tmpMin = min(it->first, it->first + k);
                    tmpMax = max(it->first, it->first + k);
                    tmpStr = to_string(tmpMin) + ' ' + to_string(tmpMax);
                    res.insert(tmpStr);
                }
                if (freq.find(it->first - k) != freq.end()) {
                    tmpMin = min(it->first, it->first - k);
                    tmpMax = max(it->first, it->first - k);
                    tmpStr = to_string(tmpMin) + ' ' + to_string(tmpMax);
                    res.insert(tmpStr);
                }
            }
            cnt = static_cast<int>(res.size());
        }
        return cnt;
    }
};