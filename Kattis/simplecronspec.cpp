// https://open.kattis.com/problems/simplecronspec
#include <bits/extc++.h>

using namespace std;
using ll = long long;

constexpr int MAXN = 24*60*60;

int n;
string s;
int vis[MAXN+5];

inline static
std::vector<std::string> splitByChar(std::string str, const char &delim) {
    std::vector<std::string> res;
    std::istringstream f(str);
    while (getline(f, str, delim)) {
        res.emplace_back(str);
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    cin.get();
    while (n--) {
        getline(cin, s);
        vector<int> hour, minute, second;
        vector<string> temp = splitByChar(s, ' ');
        // hour
        if (temp[0] == "*") {
            for (int i = 0; i <= 23; ++i) {
                hour.emplace_back(i);
            }
        }
        else {
            vector<string> tempVec = splitByChar(temp[0], ',');
            for (auto& str : tempVec) {
                if (str.find('-') == string::npos) {
                    hour.emplace_back(stoi(str));
                }
                else {
                    int a, b;
                    sscanf(str.c_str(), "%d-%d", &a,&b);
                    for (int i = a; i <= b; ++i) {
                        hour.emplace_back(i);
                    }
                }
            }
        }
        // minute
        if (temp[1] == "*") {
            for (int i = 0; i <= 59; ++i) {
                minute.emplace_back(i);
            }
        }
        else {
            vector<string> tempVec = splitByChar(temp[1], ',');
            for (auto& str : tempVec) {
                if (str.find('-') == string::npos) {
                    minute.emplace_back(stoi(str));
                }
                else {
                    int a, b;
                    sscanf(str.c_str(), "%d-%d", &a,&b);
                    for (int i = a; i <= b; ++i) {
                        minute.emplace_back(i);
                    }
                }
            }
        }
        // second
        if (temp[2] == "*") {
            for (int i = 0; i <= 59; ++i) {
                second.emplace_back(i);
            }
        }
        else {
            vector<string> tempVec = splitByChar(temp[2], ',');
            for (auto& str : tempVec) {
                if (str.find('-') == string::npos) {
                    second.emplace_back(stoi(str));
                }
                else {
                    int a, b;
                    sscanf(str.c_str(), "%d-%d", &a,&b);
                    for (int i = a; i <= b; ++i) {
                        second.emplace_back(i);
                    }
                }
            }
        }
        for (const auto &i : hour) {
            for (const auto &j : minute) {
                for (const auto &k : second) {
                    vis[i*60*60+j*60+k]++;
                }
            }
        }
    }
    int counter1 = 0;
    int counter2 = 0;
    for (int i = 0; i < MAXN+5; ++i) {
        if (vis[i] > 0) {
            ++counter1;
            counter2 += vis[i];
        }
    }
    cout << counter1 << ' ' << counter2 << '\n';
    return 0;
}
