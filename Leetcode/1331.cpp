class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> arrCopy(arr);
        sort(arrCopy.begin(), arrCopy.end());
        arrCopy.erase(unique(arrCopy.begin(), arrCopy.end()), arrCopy.end());
        unordered_map<int, int> unmap;
        int id = 1;
        for (const auto &i : arrCopy) {
            unmap[i] = id++;
        }
        for (auto &i : arr) {
            i = unmap[i];
        }
        return arr;
    }
};