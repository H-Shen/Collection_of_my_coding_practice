#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

void f(const string &a, int &a_score, const string &b, int &b_score) {
    if (a == b) {
        return;
    }
    if (a == "rock") {
        if (b == "scissors") {
            ++a_score;
        } else {
            ++b_score;
        }
    } else if (a == "scissors") {
        if (b == "paper") {
            ++a_score;
        } else {
            ++b_score;
        }
    } else {
        if (b == "rock") {
            ++a_score;
        } else {
            ++b_score;
        }
    }
}

int main() {

    string a, b, c;
    cin >> a >> b >> c;
    int a_score = 0;
    int b_score = 0;
    int c_score = 0;
    f(a, a_score, b, b_score);
    f(a, a_score, c, c_score);
    f(b, b_score, c, c_score);
    int max_val =  max(a_score, max(b_score, c_score));
    vector<int> p = {a_score, b_score, c_score};
    int count_of_max_val = count(p.begin(), p.end(), max_val);
    if (count_of_max_val == 1) {
        if (a_score == max_val) {
            cout << "F\n";
        } else if (b_score == max_val) {
            cout << "M\n";
        } else {
            cout << "S\n";
        }
    } else {
        cout << "?" << '\n';
    }

    return 0;
}