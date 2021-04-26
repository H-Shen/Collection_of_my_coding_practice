class Solution {
public:
    vector<int> getStrongest(vector<int>& arr, int k) {
        int n = (int)arr.size();
        nth_element(arr.begin(), arr.begin() + (n-1)/2, arr.end());
        int median = arr.at((n-1)/2);
        nth_element(arr.begin(), arr.begin() + (k-1), arr.end(), [&](const auto &l, const auto &r) {
            int temp_l = abs(l - median);
            int temp_r = abs(r - median);
            if (temp_l == temp_r) {
                return l > r;
            }
            return temp_l > temp_r;
        });
        return vector<int>(arr.begin(), arr.begin() + k);         
    }
};