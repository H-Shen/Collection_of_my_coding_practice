#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

int n;
ll p;
unordered_map<string, pair<ll, ll> > word_value_freq;

inline static
void parse(const string &s) {
    istringstream iss(s);
    vector<string> temp;
    string str;
    do {
        iss >> str;
        temp.emplace_back(str);
    } while (iss);
    temp.pop_back();
    for (const auto &i : temp) {
        if (word_value_freq.find(i) != word_value_freq.end()) {
            ++word_value_freq[i].second;
        }
    }
}

int main() {

    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr); 
    cout.tie(nullptr);

    cin >> n >> p;
    string s;
    ll value;
    while (n--) {
        cin >> s >> value;
        word_value_freq[s].first = value;
    }
    cin.get();
    while (getline(cin, s)) {
        for (auto &ch : s) {
            if (ch == ',' || ch == '.' || ch == '!' || ch == '?') {
                ch = ' ';
            }
        }
        parse(s);
    }
    ll sum = 0;
    for (const auto &[k, v] : word_value_freq) {
        sum += v.first * v.second % p;
    }
    cout << (sum % p) << endl;

    return 0;
}