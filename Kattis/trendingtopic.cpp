// https://open.kattis.com/problems/trendingtopic
//
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

constexpr int MAXN = 30;
constexpr size_t LENGTH_LOWERBOUND = 4;
constexpr size_t MAXIMAL_HISTORY = 7;

char s[MAXN];

inline static
bool cmp(const pair<string, int> &lhs, const pair<string, int> &rhs) {
    if (lhs.second == rhs.second) {
        return (lhs.first < rhs.first);
    }
    return (lhs.second > rhs.second);
}

int main() {

    deque<unordered_map<string, int> > history;
    string str;
    size_t n;
    while (~scanf("%s", s)) {
        str = s;
        if (str == "<text>") {
            unordered_map<string, int> freq;
            while (true) {
                scanf("%s", s);
                str = s;
                if (str == "</text>") {
                    break;
                } else if (str.size() >= LENGTH_LOWERBOUND) {
                    ++freq[str];
                }
            }
            // Even cases like <text> </text>, we still need to add an empty hashmap
            if (history.size() == MAXIMAL_HISTORY) {
                history.pop_front();
            }
            history.push_back(freq);
        } else {
            scanf("%zd %s", &n, s);
            unordered_map<string, int> stats_for_seven_days;
            for (const auto &i : history) {
                for (const auto &[word, freq] : i) {
                    stats_for_seven_days[word] += freq;
                }
            }
            vector<pair<string, int> > output(stats_for_seven_days.begin(), stats_for_seven_days.end());
            sort(output.begin(), output.end(), cmp);
            // output
            int counter = 0;
            printf("<top %zd>\n", n);
            while (n < output.size() && output.at(n).second == output.at(n - 1).second) {
                ++n;
            }
            for (size_t i = 0; i < n && i < output.size(); ++i) {
                printf("%s %d\n", output.at(i).first.c_str(), output.at(i).second);
            }
            printf("</top>\n");
        }
    }


    return 0;
}
