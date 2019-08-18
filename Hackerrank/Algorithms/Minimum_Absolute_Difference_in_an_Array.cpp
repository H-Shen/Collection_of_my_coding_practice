#include <bits/stdc++.h>

using namespace std;

int minimumAbsoluteDifference(int n, vector <int> arr) {
    // Complete this function
    sort(arr.begin(), arr.end());
    int minVal = numeric_limits<int>::max();
    int i;
    for (i = 0; i < n - 1; ++i) {
        minVal = min(minVal, abs(arr[i + 1] - arr[i]));
    }
    return minVal;
}

int main() {

    int n;
    cin >> n;
    vector<int> arr(static_cast<size_t>(n));
    for(int arr_i = 0; arr_i < n; arr_i++){
        cin >> arr[arr_i];
    }
    int result = minimumAbsoluteDifference(n, arr);
    cout << result << endl;
    return 0;
}
