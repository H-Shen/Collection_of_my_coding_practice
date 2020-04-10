// https://open.kattis.com/problems/doubleplusgood
//
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

int number_of_plus = 0;

inline static
ll get_sum(const string &s) {
    ll sum = 0;
    bool in_digits = false;
    string temp_digits;
    for (const auto &ch : s) {
        if (in_digits) {
            if (ch == '+') {
                sum += stoll(temp_digits);
                temp_digits = "";
                in_digits = false;
            } else {
                temp_digits += ch;
            }
        } else {
            temp_digits += ch;
            in_digits = true;
        }
    }
    if (!temp_digits.empty()) {
        sum += stoll(temp_digits);
    }
    return sum;
}

inline static
ll get_sum(const vector<string> &s) {
    string str;
    for (const auto &i : s) {
        str += i;
    }
    return get_sum(str);
}

inline static
vector<string> splitByChar(string s, const char &delim) {
    vector<string> res;
    istringstream f(s);
    string temp;
    string delim_str;
    delim_str.push_back(delim);
    while (getline(f, s, delim)) {
        res.emplace_back(s);
        res.emplace_back(delim_str);
        ++number_of_plus;
    }
    res.pop_back();
    --number_of_plus;
    return res;
}

inline static
string dec_to_bin(int x, int length) {
    string s;
    if (x == 0) {
        s = "0";
        while (s.length() < length) {
            s.push_back('0');
        }
    } else {
        while (x > 0) {
            if (x % 2 == 0) {
                s += "0";
            } else {
                s += "1";
            }
            x /= 2;
        }
        while (s.length() < length) {
            s.push_back('0');
        }
        reverse(s.begin(), s.end());
    }
    return s;
}

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
gp_hash_table<ll, null_type, custom_hash> uniq;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    string s;
    cin >> s;
    vector<string> A = splitByChar(s, '+');
    int total_status = 1;
    for (int i = 0; i < number_of_plus; ++i) {
        total_status *= 2;
    }
    string current_status;
    for (int i = 0; i < total_status; ++i) {
        current_status = dec_to_bin(i, number_of_plus);
        auto iter = current_status.cbegin();
        for (auto &item : A) {
            if (item == "+" || item.empty()) {
                if (*iter == '0') {
                    item = "";
                } else {
                    item = "+";
                }
                uniq.insert(get_sum(A));
                ++iter;
            }
        }
    }
    cout << uniq.size() << '\n';

    return 0;
}
