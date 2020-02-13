// https://open.kattis.com/problems/goodmorning
//
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
constexpr int R = 4;
constexpr int C = 3;

vector<vector<char> > A = {{'1','2','3'},{'4','5','6'},{'7','8','9'},{'#','0','#'}};
vector<int> powerOfTwo = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768};

unordered_set<string> B;
unordered_set<string> B_;

void go(string s, int i, int j) {
    try {
        char temp = A.at(i).at(j);
        if (temp == '#') {
            B.insert(s);
        } else {
            s += temp;
            go(s, i + 1, j);
            go(s, i, j + 1);
        }
    } catch (...) { B.insert(s); }
}

void process(const string &s) {

    string temp_s;
    int n = static_cast<int>(s.size());
    for (int i = 0; i <= powerOfTwo.at(n) - 1; ++i) {
        deque<char> temp(s.begin(), s.end());

        if (n == 1) {
            bitset<1> temp_bitset(i);
            temp_s = temp_bitset.to_string();
            for (size_t index = 0; index != temp_s.size(); ++index) {
                if (temp_s.at(index) == '0') {
                    temp.at(index) = '\0';
                }
            }
        } else if (n == 2) {
            bitset<2> temp_bitset(i);
            temp_s = temp_bitset.to_string();
            for (size_t index = 0; index != temp_s.size(); ++index) {
                if (temp_s.at(index) == '0') {
                    temp.at(index) = '\0';
                }
            }
        } else if (n == 3) {
            bitset<3> temp_bitset(i);
            temp_s = temp_bitset.to_string();
            for (size_t index = 0; index != temp_s.size(); ++index) {
                if (temp_s.at(index) == '0') {
                    temp.at(index) = '\0';
                }
            }
        } else if (n == 4) {
            bitset<4> temp_bitset(i);
            temp_s = temp_bitset.to_string();
            for (size_t index = 0; index != temp_s.size(); ++index) {
                if (temp_s.at(index) == '0') {
                    temp.at(index) = '\0';
                }
            }
        } else if (n == 5) {
            bitset<5> temp_bitset(i);
            temp_s = temp_bitset.to_string();
            for (size_t index = 0; index != temp_s.size(); ++index) {
                if (temp_s.at(index) == '0') {
                    temp.at(index) = '\0';
                }
            }
        } else if (n == 6) {
            bitset<6> temp_bitset(i);
            temp_s = temp_bitset.to_string();
            for (size_t index = 0; index != temp_s.size(); ++index) {
                if (temp_s.at(index) == '0') {
                    temp.at(index) = '\0';
                }
            }
        } else if (n == 7) {
            bitset<7> temp_bitset(i);
            temp_s = temp_bitset.to_string();
            for (size_t index = 0; index != temp_s.size(); ++index) {
                if (temp_s.at(index) == '0') {
                    temp.at(index) = '\0';
                }
            }
        } else if (n == 8) {
            bitset<8> temp_bitset(i);
            temp_s = temp_bitset.to_string();
            for (size_t index = 0; index != temp_s.size(); ++index) {
                if (temp_s.at(index) == '0') {
                    temp.at(index) = '\0';
                }
            }
        } else if (n == 9) {
            bitset<9> temp_bitset(i);
            temp_s = temp_bitset.to_string();
            for (size_t index = 0; index != temp_s.size(); ++index) {
                if (temp_s.at(index) == '0') {
                    temp.at(index) = '\0';
                }
            }
        } else if (n == 10) {
            bitset<10> temp_bitset(i);
            temp_s = temp_bitset.to_string();
            for (size_t index = 0; index != temp_s.size(); ++index) {
                if (temp_s.at(index) == '0') {
                    temp.at(index) = '\0';
                }
            }
        } else if (n == 11) {
            bitset<11> temp_bitset(i);
            temp_s = temp_bitset.to_string();
            for (size_t index = 0; index != temp_s.size(); ++index) {
                if (temp_s.at(index) == '0') {
                    temp.at(index) = '\0';
                }
            }
        } else if (n == 12) {
            bitset<12> temp_bitset(i);
            temp_s = temp_bitset.to_string();
            for (size_t index = 0; index != temp_s.size(); ++index) {
                if (temp_s.at(index) == '0') {
                    temp.at(index) = '\0';
                }
            }
        } else if (n == 13) {
            bitset<13> temp_bitset(i);
            temp_s = temp_bitset.to_string();
            for (size_t index = 0; index != temp_s.size(); ++index) {
                if (temp_s.at(index) == '0') {
                    temp.at(index) = '\0';
                }
            }
        } else if (n == 14) {
            bitset<14> temp_bitset(i);
            temp_s = temp_bitset.to_string();
            for (size_t index = 0; index != temp_s.size(); ++index) {
                if (temp_s.at(index) == '0') {
                    temp.at(index) = '\0';
                }
            }
        } else if (n == 15) {
            bitset<15> temp_bitset(i);
            temp_s = temp_bitset.to_string();
            for (size_t index = 0; index != temp_s.size(); ++index) {
                if (temp_s.at(index) == '0') {
                    temp.at(index) = '\0';
                }
            }
        }

        string out;
        for (const char &j : temp) {
            if (j != '\0') {
                out.push_back(j);
            }
        }
        if (!out.empty()) {
            B_.insert(out);
        }
    }
}

int main() {

    // pre
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            if (A.at(i).at(j) != '#') {
                string s;
                go(s, i, j);
            }
        }
    }

    for (const auto &i : B) {
        string temp_str;
        for (const auto &ch : i) {
            for (int rep = 0; rep < 3; ++rep) {
                temp_str.push_back(ch);
            }
        }
        process(temp_str);
    }

    vector<long long> temp_vec;
    for (const auto &i : B_) {
        temp_vec.emplace_back(stoll(i));
    }
    sort(temp_vec.begin(), temp_vec.end());
    int t;
    long long k;
    scanf("%d", &t);
    while (t--) {
        scanf("%lld", &k);
        if (k < temp_vec.front()) {
            printf("%lld\n", temp_vec.front());
        } else if (k > temp_vec.back()) {
            printf("%lld\n", temp_vec.back());
        } else {
            auto iter = lower_bound(temp_vec.begin(), temp_vec.end(), k);
            long long b = *iter;
            long long a = *(--iter);
            if (abs(a - k) <= abs(b - k)) {
                printf("%lld\n", a);
            } else {
                printf("%lld\n", b);
            }
        }
    }
    return 0;
}
