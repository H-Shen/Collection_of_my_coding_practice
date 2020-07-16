// https://open.kattis.com/problems/fantasydraft
//
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

constexpr int MAXN = 65005;

struct Owner {
    deque<int> pref_list;
    vector<int> players_taken;
};

bitset<MAXN> is_taken;
int n, p, global_id;
size_t k;
vector<string> id2name;
unordered_map<string, int> name2id;
vector<Owner> owners;
deque<int> pref_of_last_year;

int main(int argc, char *argv[]) {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> n >> k;
    owners.resize(n);
    int temp;
    string name;
    unordered_map<string, int>::const_iterator iter;
    for (int i = 0; i < n; ++i) {
        cin >> temp;
        for (int j = 0; j < temp; ++j) {
            cin >> name;
            iter = name2id.find(name);
            if (iter == name2id.end()) {
                name2id[name] = global_id;
                id2name.emplace_back(name);
                owners.at(i).pref_list.emplace_back(global_id);
                ++global_id;
            } else {
                owners.at(i).pref_list.emplace_back(iter->second);
            }
        }
    }
    cin >> p;
    pref_of_last_year.resize(p);
    for (auto &i : pref_of_last_year) {
        cin >> name;
        iter = name2id.find(name);
        if (iter == name2id.end()) {
            name2id[name] = global_id;
            id2name.emplace_back(name);
            i = global_id;
            ++global_id;
        } else {
            i = iter->second;
        }
    }
    bool need_to_scan = true;
    bool has_taken;
    while (need_to_scan) {
        need_to_scan = false;
        for (auto &i : owners) {
            if (i.players_taken.size() < k) {
                need_to_scan = true;
                has_taken = false;
                // add a player from the pref list at first
                while (!i.pref_list.empty()) {
                    if (is_taken[i.pref_list.front()]) {
                        i.pref_list.pop_front();
                    } else {
                        is_taken[i.pref_list.front()] = true;
                        i.players_taken.emplace_back(i.pref_list.front());
                        has_taken = true;
                        i.pref_list.pop_front();
                        break;
                    }
                }
                // otherwise, add a player from the last year's pref
                if (!has_taken) {
                    while (true) {
                        if (!is_taken[pref_of_last_year.front()]) {
                            is_taken[pref_of_last_year.front()] = true;
                            i.players_taken.emplace_back(pref_of_last_year.front());
                            pref_of_last_year.pop_front();
                            break;
                        } else {
                            pref_of_last_year.pop_front();
                        }
                    }
                }
            }
        }
    }
    // output
    bool first_item;
    for (const auto &[k, v] : owners) {
        first_item = true;
        for (const auto &i : v) {
            if (first_item) {
                first_item = false;
            } else {
                cout << ' ';
            }
            cout << id2name[i];
        }
        cout << '\n';
    }


    return 0;
}
