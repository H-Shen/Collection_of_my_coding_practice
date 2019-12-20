// https://ac.nowcoder.com/acm/problem/15660

#include <bits/stdc++.h>

using ll = long long;
using namespace std;

struct Time {
    ll day;
    ll hour;
    ll minute;
    ll second;
};

inline
Time convert(const string &s) {

    string day_str;
    string hour_str;
    string minute_str;
    string second_str;

    int len = s.size();
    int i;
    for (i = 0; s[i] != 'd'; ++i) {
        day_str += s[i];
    }
    i += 3;
    for (; s[i] != ':'; ++i) {
        hour_str += s[i];
    }
    i += 1;
    for (; s[i] != ':'; ++i) {
        minute_str += s[i];
    }
    i += 1;
    for (; i < len; ++i) {
        second_str += s[i];
    }

    Time res{};
    res.day = stol(day_str);
    res.hour = stol(hour_str);
    res.minute = stol(minute_str);
    res.second = stol(second_str);

    return res;
}

inline
ll secondCnt(const Time &a) {
    ll res = 0;
    res = res + a.day * 24 * 60 * 60 + a.hour * 60 * 60 + a.minute * 60 + a.second;
    return res;
}

inline
ll diff(const Time &a, const Time &b) {
    return secondCnt(b) - secondCnt(a);
}

int main() {
    int n;
    string a, b;
    cin >> n;
    while (n--) {
        cin >> a >> b;
        cout << diff(convert(a), convert(b)) << endl;
    }
    return 0;
}