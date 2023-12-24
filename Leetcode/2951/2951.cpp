class Solution {
public:
    vector<int> findPeaks(vector<int>& mountain) {
        vector<int> vec;
        int n = (int)mountain.size();
        for (int i = 1; i < n-1; ++i) {
            if (mountain[i] > mountain[i-1] && mountain[i] > mountain[i+1]) {
                vec.emplace_back(i);
            }
        }
        return vec;
    }
};