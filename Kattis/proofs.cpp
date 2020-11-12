// https://open.kattis.com/problems/proofs
//
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;
using pii = pair<int, int>;

vector<string> parse(const string &s) {
    istringstream iss(s);
    vector<string> result;
    string temp;
    do {
        iss >> temp;
        result.emplace_back(temp);
    } while (iss);
    result.pop_back();
    return result;
}

int main() {

    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int n;
    cin >> n;
    cin.get();
    string s;
    vector<string> temp;
    gp_hash_table<string, null_type> conclusions;
    for (int i = 1; i <= n; ++i) {
        getline(cin, s);
        temp = parse(s);
        if (temp.front() == "->") {
            for (size_t j = 1; j != temp.size(); ++j) {
                conclusions.insert(temp.at(j));
            }
        } else {
            auto iter = temp.cbegin();
            while (*iter != "->") {
                if (conclusions.find(*iter) == conclusions.end()) {
                    cout << i << '\n';
                    return 0;
                }
                ++iter;
            }
            ++iter;
            while (iter != temp.cend()) {
                conclusions.insert(*iter);
                ++iter;
            }
        }
    }
    cout << "correct" << '\n';

    return 0;
}
