#include <string>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>

using namespace std;
using ll = long long;

bool cmp(const pair<string, int> &lhs, const pair<string, int> &rhs) {
    return lhs.first < rhs.first;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t, n;
    string number, a, b, c, d, e, f;
    cin >> t;
    bool first_case = true;
    while (t--) {
        if (first_case) {
            first_case = false;
        } else {
            cout << '\n';
        }
        cin >> n;
        unordered_map<string, int> A;
        while (n--) {
            cin >> a >> b >> c >> d >> e >> f;
            number = a.append(" ").append(b).append(" ").append(c).append(
                    " ").append(d).append(" ").append(e).append(" ").append(f);
            ++A[number];
        }
        vector<pair<string, int> > output;
        for (const auto &i : A) {
            output.emplace_back(make_pair(i.first, i.second));
        }
        sort(output.begin(), output.end(), cmp);
        for (const auto &i : output) {
            cout << i.first << ' ' << i.second << '\n';
        }
    }


    return 0;
}
