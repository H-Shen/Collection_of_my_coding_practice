class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        sort(arr.begin(), arr.end(), [&](const int &a, const int &b)
        {
            int diff_a(abs(a - x));
            int diff_b(abs(b - x));
            if (diff_a == diff_b) {
                return (a < b);
            }
            return (diff_a < diff_b);
        });
        vector<int> res(arr.begin(), arr.begin() + k);
        sort(res.begin(), res.end());
        return res;
    }
};