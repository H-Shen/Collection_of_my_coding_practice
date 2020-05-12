#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

constexpr int MAXN = 260;
char str[MAXN];

bool all_zeros(const string &s) {
    for (const char &ch : s) {
        if (ch != '0') {
            return false;
        }
    }
    return true;
}
bool all_ones(const string &s) {
    for (const char &ch : s) {
        if (ch != '1') {
            return false;
        }
    }
    return true;
}
bool has_zero_or_one(const string &s) {
    for (const char &ch : s) {
        if (ch != '1' && ch != '0') {
            return false;
        }
    }
    return true;
}

int main() {

    scanf("%s", str);
    string temp, a, b;
    list<string> A;
    A.emplace_back(str);
    bool check_again;

    while (true) {
        check_again = false;
        for (auto iter = A.begin(); iter != A.end(); ++iter) {
            //cout << *iter << endl;
            if (all_zeros(*iter)) {
                *iter = "A";
            } else if (all_ones(*iter)) {
                *iter = "B";
            } else if (has_zero_or_one(*iter)) {
                temp = *iter;
                a = temp.substr(0, temp.size() / 2);
                b = temp.substr(temp.size() / 2);
                *iter = b;
                iter = A.insert(iter, a);
                iter = A.insert(iter, "C");
                check_again = true;
            }
        }
        if (!check_again) {
            break;
        }
    }
    for (const auto &i : A) {
        printf("%s", i.c_str());
    }
    putchar_unlocked('\n');
    return 0;
}
