class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        int n = (int)arr.size();
        if (n == 1) return 1;
        unordered_set<int> vis;
        for (int i = 0; i < n; ++i) {
            vis.insert(arr[i]);
            for (int j = i-1; j >= 0; --j) {
                if ((arr[i] | arr[j]) == arr[j]) {
                    // 结果不变 接下来不用算了
                    break;
                }
                arr[j] |= arr[i];
                vis.insert(arr[j]);
            }
        }
        return (int)vis.size();
    }
};