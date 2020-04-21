#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

constexpr int MAX0 = 11;
constexpr int MAX1 = 21;

vector<pair<int, int> > solve(const string &s, int upper) {
    vector<pair<int, int> > output;
    pair<int, int> temp;
    for (const char &ch : s) {
        if (ch == 'W') {
            ++temp.first;
        } else {
            ++temp.second;
        }
        if ( (temp.first >= upper || temp.second >= upper) && abs(temp.first - temp.second) >= 2 ) {
            output.emplace_back(temp);
            temp.first = 0;
            temp.second = 0;
        }
    }
    output.emplace_back(temp);
    return output;
}

int main() {

    string result;
    string s;
    bool breakTheLoop = false;
    while (cin >> s) {
        for (const char &ch : s) {
            if (ch == 'E') {
                breakTheLoop = true;
                break;
            } else if (ch == 'W' || ch == 'L') {
                result.push_back(ch);

            }
        }
        if (breakTheLoop) {
            break;
        }
    }
    vector<pair<int, int> > output0 = solve(result, MAX0);
    for (const auto &[k, v] : output0) {
        printf("%d:%d\n", k, v);
    }
    putchar('\n');
    vector<pair<int, int> > output1 = solve(result, MAX1);
    for (const auto &[k, v] : output1) {
        printf("%d:%d\n", k, v);
    }

    return 0;
}
