// https://open.kattis.com/problems/cheatingatwar
//
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

constexpr int MAXN = 26;

unordered_map<char, int> A;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // pre
    string s = "23456789TJQKA";
    int value = 1;
    for (const auto &i : s) {
        A[i] = value;
        ++value;
    }
    // input
    int t;
    cin >> t;
    while (t--) {
        string you_str, opponent_str;
        cin >> opponent_str >> you_str;
        vector<int> you;
        for (const char &ch : you_str) {
            you.emplace_back(A[ch]);
        }
        vector<int> opponent;
        for (const char &ch : opponent_str) {
            opponent.emplace_back(A[ch]);
        }
        // sort
        sort(you.begin(), you.end(), greater<>());
        sort(opponent.begin(), opponent.end(), greater<>());
        // compare
        int counter = 0;
        int temp;
        int the_cards_larger_than_opponent;
        for (int i = 0; i < MAXN; ++i) {
            the_cards_larger_than_opponent = 0;
            for (int j = 0; j < MAXN; ++j) {
                temp = you.at((j + i) % MAXN);
                if (temp == opponent.at(j)) {
                    ++the_cards_larger_than_opponent;
                } else if (temp > opponent.at(j)) {
                    the_cards_larger_than_opponent += 2;
                }
            }
            counter = max(counter, the_cards_larger_than_opponent);
        }
        cout << counter << '\n';
    }
    return 0;
}
