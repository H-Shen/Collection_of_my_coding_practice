// https://open.kattis.com/problems/codetosavelives

#include <bits/extc++.h>

using namespace __gnu_pbds;
using namespace std;
using ll = long long;

int t;
string s;

void parse(const string&str, ll& number) {
    istringstream iss(str);
    string temp;
    string num;
    do {
        iss >> temp;
        num += temp;
    } while (iss);
    num.pop_back();
    number = stol(num);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> t;
    cin.get();
    while (t--) {
        ll a, b;
        getline(cin, s);
        parse(s, a);
        getline(cin, s);
        parse(s, b);
        ll c = a + b;
        string strC = to_string(c);
        bool firstItem = true;
        for (auto &i : strC) {
            if (firstItem) {
                firstItem = false;
            } else {
                cout << ' ';
            }
            cout << i;
        }
        cout << '\n';
    }
    return 0;
}
