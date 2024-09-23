// https://ac.nowcoder.com/acm/problem/21659

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

unordered_map<string, string> A;

inline static
vector<string> parse(const string &s) {
    istringstream iss(s);
    string temp;
    vector<string> temp_vec;
    do {
        iss >> temp;
        temp_vec.emplace_back(temp);
    } while (iss);
    temp_vec.pop_back();
    return temp_vec;
}

inline static
ll convert(const vector<string> &L) {
    string temp;
    for (const auto &i : L) {
        temp += A[i];
    }
    return stol(temp, nullptr, 16);
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    // pre
    string s =
    "zero - 0\n"
    "one - 1\n"
    "two - 2\n"
    "three - 3\n"
    "four - 4\n"
    "five - 5\n"
    "six - 6\n"
    "seven - 7\n"
    "eight - 8\n"
    "nine - 9\n"
    "ten - 10\n"
    "eleven - 11\n"
    "twelve - 12\n"
    "thirteen - 13\n"
    "fourteen - 14\n"
    "fifteen - 15";

    auto temp_vec = parse(s);
    for (ll i = 0; i < 16; ++i) {
        A[temp_vec.at(i * 3)] = temp_vec.at(i * 3 + 2);
    }
    A["ten"] = "A";
    A["eleven"] = "B";
    A["twelve"] = "C";
    A["thirteen"] = "D";
    A["fourteen"] = "E";
    A["fifteen"] = "F";

    // input
    ll a, b;
    while (true) {
        if (!getline(cin, s)) {
            break;
        }
        a = convert(parse(s));
        getline(cin, s);
        b = convert(parse(s));
        cout << a * b << '\n';
    }

    return 0;
}