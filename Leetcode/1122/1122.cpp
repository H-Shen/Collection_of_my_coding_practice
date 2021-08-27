class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int, int> unmap;
        int id = 0;
        for (const auto &i : arr2) unmap[i] = id++;
        auto iter = partition(arr1.begin(), arr1.end(), [&](const auto &i){
            return unmap.find(i) != unmap.end();
        });
        sort(arr1.begin(), iter, [&](const auto &l, const auto &r) {
            return unmap[l] < unmap[r];
        });
        sort(iter, arr1.end());
        return arr1;
    }
};