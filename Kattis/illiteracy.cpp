// https://open.kattis.com/problems/illiteracy
//
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

constexpr int BASE = 6;

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

inline
void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

inline
void rotate(char &ch) {
    ++ch;
    if (ch > 'F') {
        ch = 'A';
    }
}

inline
int convert(string s) {
    for (char &ch : s) {
        ch = ch - 'A' + '0';
    }
    return stoi(s, nullptr, BASE);
}

inline
string convert(int n) {
    string result;
    while (n > 0) {
        result.push_back(n % BASE + 'A');
        n /= BASE;
    }
    while (result.size() < 8) {
        result.push_back('A');
    }
    reverse(result.begin(), result.end());
    return result;
}

inline
void effect(int x, string &s) {   // x is in [1, 8]
    char type = s.at(x - 1);
    switch (type) {
        case 'A':
            --x;
            if (x == 0) {
                rotate(s.at(x + 1));
            } else if (x == 7) {
                rotate(s.at(x - 1));
            } else {
                rotate(s.at(x - 1));
                rotate(s.at(x + 1));
            }
            break;
        case 'B':
            --x;
            if (!(x == 0 || x == 7)) {
                s.at(x + 1) = s.at(x - 1);
            }
            break;
        case 'C':
            rotate(s.at(9 - x - 1));
            break;
        case 'D':
            --x;
            if (x != 0 && x != 7) {
                if (x >= 0 && x <= 3) {
                    for (int i = 0; i <= x; ++i) {
                        if (i != x) {
                            rotate(s.at(i));
                        }
                    }
                } else {
                    for (int i = x; i <= 7; ++i) {
                        if (i != x) {
                            rotate(s.at(i));
                        }
                    }
                }
            }
            break;
        case 'E':
            --x;
            if (x != 0 && x != 7) {
                int y = 0;
                if (x >= 0 && x <= 3) {
                    for (int i = 0; i <= x; ++i) {
                        if (i != x) {
                            ++y;
                        }
                    }
                } else {
                    for (int i = x; i <= 7; ++i) {
                        if (i != x) {
                            ++y;
                        }
                    }
                }
                rotate(s.at(x - y));
                rotate(s.at(x + y));
            }
            break;
        case 'F':
            if (x % 2 == 0) {
                rotate(s.at(x / 2 - 1));
            } else {
                rotate(s.at((x + 9) / 2 - 1));
            }
            break;
        default:
            break;
    }
}

string original_s, dest_s;
gp_hash_table<int, int, custom_hash> dis;

void bfs(int original) {
    queue<int> q;
    q.push(original);
    dis[original] = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        string u_str = convert(u);
        string u_str_bak(u_str);
        int new_u;
        // iterate all 8 clicks from left to right
        for (int x = 1; x <= 8; ++x) {
            effect(x, u_str);
            new_u = convert(u_str);
            if (dis.find(new_u) == dis.end()) {
                q.push(new_u);
                dis[new_u] = dis[u] + 1;
            }
            // restore
            u_str = u_str_bak;
        }
    }
}

int main() {

    fast_io();
    cin >> original_s >> dest_s;
    bfs(convert(original_s));
    cout << dis[convert(dest_s)] << '\n';

    return 0;
}
