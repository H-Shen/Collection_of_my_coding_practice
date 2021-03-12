class Solution {
public:
    bool strictlyIncrease(const vector<int> &arr, int l, int r) {
        if (r - l == 0) return false;
        if (r - l == 1) return true;
        for (int i = l; i < r; ++i) {
            if (arr.at(i) >= arr.at(i + 1)) {
                return false;
            }
        }
        return true;
    }
    bool strictlyDecrease(const vector<int> &arr, int l, int r) {
        if (r - l == 0) return false;
        if (r - l == 1) return true;
        for (int i = l; i < r; ++i) {
            if (arr.at(i) <= arr.at(i + 1)) {
                return false;
            }
        }
        return true;
    }
    bool validMountainArray(vector<int>& arr) {
        if (arr.size() < 3) return false;
        auto iter = max_element(arr.begin(), arr.end());
        if (count(arr.begin(), arr.end(), *iter) != 1) return false;
        int indexOfMax = iter - arr.begin();
        return strictlyIncrease(arr, 0, indexOfMax) && strictlyDecrease(arr, indexOfMax, (int)arr.size()-1);
    }
};