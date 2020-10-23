// https://open.kattis.com/problems/abandonedanimal
//
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

unordered_map<string, vector<int> > item2store;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, k, store;
    string item;
    cin >> n >> k;
    while (k--) {
        cin >> store >> item;
        item2store[item].emplace_back(store);
    }
    for (auto &[k, v] : item2store) {
        sort(v.begin(), v.end());
    }
    int m;
    cin >> m;
    vector<string> items(m);
    for (auto &i : items) {
        cin >> i;
    }
    vector<int> store_id(m);
    int index = 0;
    for (const auto &i : items) {
        if (index == 0) {
            store_id.at(index) = item2store[i].front();
            ++index;
            continue;
        }
        auto iter = lower_bound(item2store[i].begin(), item2store[i].end(), store_id.at(index - 1));
        if (iter == item2store[i].end()) {
            cout << "impossible" << '\n';
            return 0;
        }
        store_id.at(index) = *iter;
        ++index;
    }
    // reversely check
    vector<int> store_id_reverse(m);
    index = 0;
    for (auto it = items.crbegin(); it != items.crend(); ++it) {
        if (index == 0) {
            store_id_reverse.at(index) = item2store[*it].back();
            ++index;
            continue;
        }
        for (auto iter = item2store[*it].crbegin(); iter != item2store[*it].crend(); ++iter) {
            if (*iter <= store_id_reverse.at(index - 1)) {
                store_id_reverse.at(index) = *iter;
                ++index;
                break;
            }
        }
    }
    reverse(store_id_reverse.begin(), store_id_reverse.end());
    if (store_id == store_id_reverse) {
        cout << "unique" << '\n';
    } else {
        cout << "ambiguous" << '\n';
    }
    return 0;
}
