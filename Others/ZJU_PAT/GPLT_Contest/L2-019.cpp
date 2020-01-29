#include <bits/stdc++.h>

using namespace std;

const double eps = 10e-6;

inline int sgn(double a, double b) {
    if (fabs(a - b) < eps) {
        return 0;
    }
    if (a - b > eps) {
        return 1;
    }
    return -1;
}

int main() {

    int n;
    cin >> n;

    unordered_set<string> nameList;
    string name;
    while (n--) {
        cin >> name;
        nameList.insert(name);
    }

    int m, i;
    cin >> m;

    string queryName;
    int cnt;
    int s = 0;

    vector<pair<string, int> > queryList(m);
    for (i = 0; i < m; ++i) {
        cin >> queryName >> cnt;
        pair<string, int> tmp(queryName, cnt);
        queryList[i] = tmp;
        s += cnt;
    }

    vector<string> result;
    double avg = (double) s / (double) m;

    bool haveAns = false;
    for (i = 0; i < m; ++i) {
        if (sgn((double) queryList[i].second, avg) == 1 && nameList.find(queryList[i].first) == nameList.end()) {
            result.push_back(queryList[i].first);
            haveAns = true;
        }
    }

    sort(result.begin(), result.end());

    for (auto &p : result) {
        cout << p << endl;
    }

    if (!haveAns) {
        cout << "Bing Mei You" << endl;
    }

    return 0;
}
