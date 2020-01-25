// https://open.kattis.com/problems/judging
#include <bits/extc++.h>

using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    int n;
    string s;
    cin >> n;
    unordered_map<string, int> A;
    unordered_map<string, int> B;

    for (int i = 0; i < n; ++i) {
        cin >> s;
        ++A[s];
    }

    for (int i = 0; i < n; ++i) {
        cin >> s;
        ++B[s];
    }

    int cnt = 0;
    for (const auto &i : A) {
        if (B.find(i.first) != B.end()) {
            cnt += min(B[i.first], i.second);
        }
    }
    cout << cnt << endl;
    return 0;
}
