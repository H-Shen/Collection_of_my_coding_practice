class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& arr) {
        int n = (int)arr.size();
        vector<int> pre(n);
        pre[0] = arr[0];
        for (int i = 1; i < n; ++i) {
            pre[i] = pre[i-1] + arr[i];
        }
        int sum = pre.back();
        if (sum % 3 != 0) {
            return false;
        }
        vector<int> vec;
        int temp = sum / 3 * 2;
        for (int i = 0; i < n; ++i) {
            if (pre[i] == temp) {
                vec.emplace_back(i);
            }
        }
        for (int i = 0; i < n - 2; ++i) {
            if (pre[i] == sum / 3) {
                auto iter = upper_bound(vec.begin(), vec.end(), i);
                if (iter == vec.end()) {
                    continue;
                }
                if (*iter == n - 1) {
                    continue;
                }
                return true;
            }
        }
        return false;
    }
};