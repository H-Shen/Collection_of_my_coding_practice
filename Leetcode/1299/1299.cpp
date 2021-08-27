class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int n = (int)arr.size();
        for (int i = 0; i < n - 1; ++i) {
            arr.at(i) = arr.at(i + 1);
        }
        arr.at(n - 1) = -1;
        int maxValue = -1;
        for (int i = n - 1; i >= 0; --i) {
            maxValue = max(maxValue, arr.at(i));
            arr.at(i) = maxValue;
        }
        return arr;
    }
};