// https://open.kattis.com/problems/greedilyincreasing
//
#include <bits/stdc++.h>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    size_t n;
    cin >> n;
    vector<int> A(n);
    for (auto &&i : A) {
        cin >> i;
    }
    vector<int> result{A.front()};
    int maxVal = A.front();
    for (const auto &i : A) {
        if (i > maxVal) {
            maxVal = i;
            result.emplace_back(i);
        }
    }
    cout << result.size() << '\n';
    bool firstItem = true;
    for (const auto &i : result) {
        if (firstItem) {
            firstItem = false;
        } else {
            cout << " ";
        }
        cout << i;
    }
    cout << '\n';

    return 0;
}
