#include <bits/stdc++.h>

using namespace std;
constexpr int N = 6;

int solve(const vector<vector<int>> &A) {
    int sum = numeric_limits<int>::min();
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            int current_sum = 0;
            try {
                current_sum += A.at(i).at(j);
                current_sum += A.at(i).at(j - 1);
                current_sum += A.at(i).at(j + 1);
                current_sum += A.at(i + 1).at(j);
                current_sum += A.at(i + 2).at(j);
                current_sum += A.at(i + 2).at(j - 1);
                current_sum += A.at(i + 2).at(j + 1);
                sum = max(sum, current_sum);
            } catch (...) {
                
            }
        }
    }
    return sum;
}

int main()
{
    vector<vector<int>> arr(N);
    for (int i = 0; i < N; i++) {
        arr[i].resize(N);

        for (int j = 0; j < N; j++) {
            cin >> arr[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cout << solve(arr) << endl;

    return 0;
}
