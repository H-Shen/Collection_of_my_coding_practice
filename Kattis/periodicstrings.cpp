// https://open.kattis.com/problems/periodicstrings
//
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
constexpr int MAXN = 105;
char cstr[MAXN];

inline static
vector<deque<char> > split(const string &s, int length) {
    vector<deque<char> > ret;
    int n = static_cast<int>(s.size());
    string str;
    int counter = 0;
    for (int i = 0; i < n; ++i) {
        str.push_back(s.at(i));
        ++counter;
        if (counter == length) {
            ret.emplace_back(deque<char>(str.begin(), str.end()));
            str = "";
            counter = 0;
        }
    }
    return ret;
}

inline static
bool check(const vector<deque<char> > &A) {
    if (A.size() <= 1) {
        return true;
    }
    int n = static_cast<int>(A.size());
    for (int i = 1; i < n; ++i) {
        deque<char> current = A.at(i);
        deque<char> previous = A.at(i - 1);
        previous.push_front(previous.back());
        previous.pop_back();
        if (previous != current) {
            return false;
        }
    }
    return true;
}

int main() {

    scanf("%s", cstr);
    string s(cstr);
    int n = static_cast<int>(s.size());
    for (int i = 1; i <= n; ++i) {
        if (n % i == 0 && check(split(s, i))) {
            printf("%d\n", i);
            break;
        }
    }

    return 0;
}
