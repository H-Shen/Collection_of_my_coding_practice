#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

int A[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};

bool check(const string &s) {
    string temp = s[0] + string() + s[1];
    int month = stoi(temp);
    if (month > 12) {
        return false;
    }
    temp = s[3] + string() + s[4];
    int day = stoi(temp);
    return day <= A[month];
}

string convert(int n) {
    if (n < 10) {
       return "0" + to_string(n);
    }
    return to_string(n);
}

int count_adjust(const string &a, const string &b) {
    int counter = 0;
    for (size_t i = 0; i != a.size(); ++i) {
        if (a[i] != b[i]) {
            ++counter;
        }
    }
    return counter;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string s, temp;
    cin >> s;

    int minimal_adjust = numeric_limits<int>::max();
    for (int i = 1; i <= 99; ++i) {
        for (int j = 1; j <= 32; ++j) {
            temp = convert(i) + "-" + convert(j);
            if (check(temp)) {
                minimal_adjust = min(minimal_adjust, count_adjust(s, temp));
            }
        }
    }
    cout << minimal_adjust << '\n';

    return 0;
}
