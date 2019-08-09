// https://ac.nowcoder.com/acm/problem/14742

#include <bits/stdc++.h>

using namespace std;

vector <pair<int, int>> A;

int main() {
    A.emplace_back(make_pair(2, 4));
    A.emplace_back(make_pair(0, 2));
    A.emplace_back(make_pair(3, 2));
    A.emplace_back(make_pair(3, 2));
    A.emplace_back(make_pair(1, 3));
    A.emplace_back(make_pair(3, 2));
    A.emplace_back(make_pair(3, 3));
    A.emplace_back(make_pair(1, 2));
    A.emplace_back(make_pair(3, 4));
    A.emplace_back(make_pair(3, 3));
    int T;
    cin >> T;
    while (T--) {
        getchar();
        string s;
        cin >> s;
        int hCnt = 0, vCnt = 0;
        for (const auto &p : s) {
            hCnt = hCnt + A[p - '0'].first;
            vCnt = vCnt + A[p - '0'].second;
        }
        cout << hCnt << ' ' << vCnt << endl;
    }
    return 0;
}