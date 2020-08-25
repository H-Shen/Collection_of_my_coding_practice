// https://open.kattis.com/problems/bokforing
//
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

inline
void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int global_counter;
int restart_balance;

struct Account {
    int counter = 0;
    int balance = 0;
    void set(const int &x) {
        balance = x;
        counter = global_counter + 1;
    }
    void print() const {
        cout << balance << '\n';
    }
    void upd() {
        if (counter <= global_counter) {
            counter = global_counter;
            balance = restart_balance;
        }
    }
};

vector<Account> A;

int main() {

    fast_io();
    int n, q;
    string s;
    int i, x;
    cin >> n >> q;
    A.resize(n + 5);
    while (q--) {
        cin >> s;
        if (s == "PRINT") {
            cin >> i;
            A.at(i).upd();
            A.at(i).print();
        }
        else if (s == "SET") {
            cin >> i >> x;
            A.at(i).set(x);
        }
        else {
            cin >> x;
            ++global_counter;
            restart_balance = x;
        }
    }
    return 0;
}
