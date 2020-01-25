// https://open.kattis.com/problems/lindenmayorsystem
//
#include <bits/extc++.h>

using namespace std;
unordered_map<char, string> Table;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, iteration;
    string a, b, c, original;
    cin >> n >> iteration;
    while (n--) {
        cin >> a >> b >> c;
        Table[a.front()] = c;
    }
    cin >> original;
    for (int i = 0; i < iteration; ++i) {
        string newString;
        for (const char &ch : original) {
            if (Table.find(ch) != Table.end()) {
                newString += Table[ch];
            } else {
                newString.push_back(ch);
            }
        }
        original = newString;
    }
    cout << original << '\n';

    return 0;
}
