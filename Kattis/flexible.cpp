// https://open.kattis.com/problems/flexible
//
#include <bits/extc++.h>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int w, p, val;
    cin >> w >> p;
    vector<int> A = {0};
    while (p--) {
        cin >> val;
        A.emplace_back(val);
    }
    A.emplace_back(w);
    unordered_set<int> dist;
    int length = static_cast<int>(A.size());
    for (int i = 0; i < length - 1; ++i) {
        for (int j = i + 1; j < length; ++j) {
            dist.insert(abs(A.at(i) - A.at(j)));
        }
    }
    vector<int> output(dist.begin(), dist.end());
    sort(output.begin(), output.end());
    bool firstItem = true;
    for (const auto &i : output) {
        if (firstItem) {
            firstItem = false;
        } else {
            cout << ' ';
        }
        cout << i;
    }
    cout << '\n';

    return 0;
}
