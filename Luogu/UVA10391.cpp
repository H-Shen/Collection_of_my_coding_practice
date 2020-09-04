#include <vector>
#include <string>
#include <iostream>
#include <unordered_set>
#include <set>

using namespace std;
using ll = long long;

unordered_set<string> unset;
vector<string> vec;

auto fast_io = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
};

int main() {

    fast_io();
    string s;
    while (cin >> s) {
        unset.insert(s);
        vec.emplace_back(s);
    }
    set<string> output;
    for (const auto &i : vec) {
        if (i.size() > 1) {
            for (size_t j = 1; j != i.size(); ++j) {
                if (unset.find(i.substr(0, j)) != unset.end() && unset.find(i.substr(j)) != unset.end()) {
                    output.insert(i);
                }
            }
        }
    }
    for (const auto &i : output) {
        cout << i << '\n';
    }
    return 0;
}