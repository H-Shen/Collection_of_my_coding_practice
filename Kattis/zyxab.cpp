// https://open.kattis.com/problems/zyxab

#include <bits/extc++.h>

using namespace std;
using ll = long long;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    vector<string> A;
    string s;
    while (n--) {
        cin >> s;
        if (s == "Zyxab") {
            continue;
        }
        if (s.size() < 5) {
            continue;
        }
        unordered_set<char> unset(s.begin(),s.end());
        if (unset.size() != s.size()) {
            continue;
        }
        A.emplace_back(s);
    }
    sort(A.begin(), A.end(), [](const string &l, const string &r){
        if (l.size() == r.size()) return l > r;
        return l.size() < r.size();
    });
    if (A.empty()) {
        cout << "neibb!";
    } else {
        cout << A.front();
    }
    cout << '\n';

    return 0;
}
