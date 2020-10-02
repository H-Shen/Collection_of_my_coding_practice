#include <bits/stdc++.h>

using namespace std;

vector<int> factorial{1};

int solve(int sum) {
    int counter = 0;
    int temp;
    for (size_t i = 0; i != factorial.size();) {
        if (factorial.at(i) > sum) {
            ++i;
        } else {
            temp = sum / factorial.at(i);
            counter += temp;
            sum -= temp * factorial.at(i);
        }
    }
    return counter;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // pre
    for (int i = 1; factorial.size() != 9; ++i) {
        factorial.emplace_back(factorial.back() * i);
    }
    reverse(factorial.begin(), factorial.end());
    int n;
    while (cin >> n) {
        cout << solve(n) << '\n';
    }

    return 0;
}