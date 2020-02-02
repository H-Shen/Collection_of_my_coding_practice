// https://open.kattis.com/problems/averagespeed
//
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
constexpr int MAXN = 30;
char str[MAXN];

inline static
vector<string> splitByChar(string s, const char &delim) {
    vector<string> res;
    istringstream f(s);
    string temp;
    while (getline(f, s, delim)) {
        res.emplace_back(s);
    }
    return res;
}

inline static
int get_time(const string &s) {
    auto p = splitByChar(s, ':');
    return stoi(p.at(2)) + stoi(p.at(1)) * 60 + stoi(p.at(0)) * 3600;
}

int main() {

    string s;
    vector<string> query;
    unordered_map<int, int> history;
    int earliest_time = numeric_limits<int>::max();
    int latest_time = numeric_limits<int>::min();
    while (~scanf("%[^\n]", str)) {
        getchar();
        s = str;
        if (s.size() == 8) {
            int temp = get_time(s);
            query.emplace_back(s);
            earliest_time = min(earliest_time, temp);
            latest_time = max(latest_time, temp);
        } else {
            auto p = splitByChar(s, ' ');
            int temp = get_time(p.at(0));
            history.insert(make_pair(temp, stoi(p.at(1))));
            earliest_time = min(earliest_time, temp);
            latest_time = max(latest_time, temp);
        }
    }
    double distance = 0.0;
    unordered_map<int, double> time2distance;
    int current_speed = 0;
    for (int i = earliest_time; i <= latest_time; ++i) {
        distance += current_speed / 3600.0;
        if (history.find(i) != history.end()) {
            current_speed = history[i];
        }
        time2distance[i] = distance;
    }
    for (const auto &i : query) {
        printf("%s %.2lf km\n", i.c_str(), time2distance[get_time(i)]);
    }

    return 0;
}
