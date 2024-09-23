// https://www.nowcoder.com/practice/72d0910e837a4a6e95c7f4d60e6d0e68

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int, int> > A(n);
    for (auto &&i : A) {
        cin >> i.first >> i.second;
    }
    sort(A.begin(), A.end(), [](const pair<int, int> &a, const pair<int, int> &b) {
        if (a.first == b.first) {
            return (a.second < b.second);
        }
        return (a.first < b.first);
    });
    cout << A[0].first << ' ' << A[0].second << endl;

    return 0;
}