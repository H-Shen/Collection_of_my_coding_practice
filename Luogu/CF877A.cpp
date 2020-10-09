#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

int get_occurrences(const string &str, const string &needle) {
    auto searcher = boyer_moore_horspool_searcher(needle.begin(), needle.end());
    int occurrence = 0;
    for (auto it = search(str.begin(), str.end(), searcher); it != str.end();) {
        ++occurrence;
        ++it;
        it = search(it, str.end(), searcher);
    }
    return occurrence;
}

int main() {

    vector<string> needles = {"Danil", "Olya", "Slava", "Ann", "Nikita"};
    string s;
    cin >> s;
    int stats = 0;
    int temp;
    for (const auto &i : needles) {
        temp = get_occurrences(s, i);
        if (temp > 1) {
            cout << "NO" << '\n';
            return 0;
        }
        if (temp == 1) {
            ++stats;
        }
    }
    if (stats == 1) {
        cout << "YES";
    } else {
        cout << "NO";
    }
    cout << '\n';
    return 0;
}