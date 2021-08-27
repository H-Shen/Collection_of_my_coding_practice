class Solution {
public:
    vector<int> transformArray(vector<int>& arr) {
        int n = (int)arr.size();
        vector<int> arrNext(n);
        while (true) {
            for (int i = 0; i < n; ++i) {
                if (i == 0 || i == n - 1) {
                    arrNext[i] = arr[i];
                } else if (arr[i] < arr[i-1] && arr[i] < arr[i+1]) {
                    arrNext[i] = arr[i] + 1;
                } else if (arr[i] > arr[i-1] && arr[i] > arr[i+1]) {
                    arrNext[i] = arr[i] - 1;
                } else {
                    arrNext[i] = arr[i];
                }
            }
            if (arrNext == arr) {
                break;
            } else {
                arr = arrNext;
            }
        }
        return arr;
    }
};