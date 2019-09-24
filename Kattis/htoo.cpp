// https://open.kattis.com/problems/htoo
//
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

inline static
unordered_map<char, ll> stats(const string &s, ll times) {

    unordered_map<char, ll> result;
    static string pattern ("[A-Z]{1}[0-9]*");
    static regex r(pattern);
    string temp;
    for (sregex_iterator it(s.begin(), s.end(), r), end_it; it != end_it; ++it) {
        temp = it->str();
        if (temp.size() == 1) {
            ++result[temp.front()];
        } else {
            result[temp.front()] += stol(temp.substr(1));
        }
    }
    for (auto &it : result) {
        it.second *= times;
    }

    return result;
}

int main() {

    ios_base::sync_with_stdio(false);
    string input;
    string output;
    ll countOfInput;

    cin >> input >> countOfInput;
    cin >> output;
    auto stats0 = stats(input, countOfInput);
    auto stats1 = stats(output, 1);

    ll minVal = numeric_limits<ll>::max();
    for (const auto &i : stats1) {
        if (stats0.find(i.first) == stats0.end()) {
            minVal = 0;
            break;
        }
        minVal = min(minVal, stats0[i.first] / i.second);
    }
    cout << minVal << endl;

    return 0;
}
