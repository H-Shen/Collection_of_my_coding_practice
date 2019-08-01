// https://open.kattis.com/problems/thinkingofanumber

#include<bits/stdc++.h>

using namespace std;
const int MAX = 50005;
const int MIN = 1;

vector<string> split(const string &a) {
    vector<string> res;
    istringstream f(a);
    string s;
    while (getline(f, s, ' ')) {
        res.push_back(s);
    }
    return res;
}

int lcm(int a, int b) {
    return a * b / __gcd(a, b);
}

int multi_lcm(const vector<int> &a) {
    int result = 0;
    if (a.size() == 1) {
        result = a[0];
    } else if (a.size() > 1) {
        result = a[0];
        for (size_t i = 1; i != a.size(); ++i) {
            result = lcm(result, a[i]);
        }
    }
    return result;
}

int main() {

    ios_base::sync_with_stdio(false);

    int n;
    string s, n_str;
    bool isInfinite;

    while (true) {

        getline(cin, n_str);
        n = stoi(n_str);
        if (n == 0) {
            break;
        }

        int lower, upper;
        tie(lower, upper) = make_tuple(MIN, MAX);
        vector<int> divisible;
        vector<int> ans;
        isInfinite = false;

        for (int i = 0; i < n; ++i) {
            getline(cin, s);
            vector<string> temp = split(s);
            if (temp[0] == "less") {
                upper = min(upper, stoi(temp[2]) - 1);
            } else if (temp[0] == "greater") {
                lower = max(lower, stoi(temp[2]) + 1);
            } else {
                divisible.push_back(stoi(temp[2]));
            }
        }

        int lcm = 1;
        if (!divisible.empty()) {
            lcm = multi_lcm(divisible);
        }

        // filter the range
        if (upper == MAX) {
            isInfinite = true;
        } else if (lower <= upper) {
            ans.resize(upper - lower + 1);
            iota(ans.begin(), ans.end(), lower);
        }

        // filter all divisors
        if (!isInfinite) {
            for (auto &&i : ans) {
                if (i % lcm != 0) {
                    i = -1;
                }
            }
        }

        // output
        if (isInfinite) {
            cout << "infinite";
        } else {
            bool isFirst = true;
            bool isNone = true;
            for (const int &i : ans) {
                if (i != -1) {
                    isNone = false;
                    if (isFirst) {
                        isFirst = false;
                        cout << i;
                    } else {
                        cout << " " << i;
                    }
                }
            }
            if (isNone) {
                cout << "none";
            }
        }
        cout << endl;
    }

    return 0;
}
