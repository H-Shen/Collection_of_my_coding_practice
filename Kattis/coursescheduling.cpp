// https://open.kattis.com/problems/coursescheduling

#include <bits/extc++.h>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    string first, second, course, name;
    cin >> n;
    unordered_map<string, unordered_set<string> > unmap;
    while (n--) {
        cin >> first >> second >> course;
        name = first + ' ' + second;
        unmap[course].insert(name);
    }
    vector<pair<string, int> > output;
    for (const auto &[k, v] : unmap) {
        output.emplace_back(k, (int)v.size());
    }
    sort(output.begin(), output.end(), [](const auto &l, const auto &r) {
        return l.first < r.first;
    });
    for (const auto &[k, v] : output) {
        cout << k << ' ' << v << '\n';
    }

    return 0;
}
