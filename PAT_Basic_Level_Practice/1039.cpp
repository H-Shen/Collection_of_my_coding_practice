#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    string a, b;
    getline(cin, a);
    getline(cin, b);

    unordered_map<char, int> aLog, bLog;
    for (const auto &i : a) {
        ++aLog[i];
    }
    for (const auto &i : b) {
        ++bLog[i];
    }

    bool canBuy = true;
    for (auto it = bLog.begin(); it != bLog.end(); ++it) {
        if (aLog.find(it->first) == aLog.end()) {
            canBuy = false;
            break;
        } else if (aLog[it->first] < it->second) {
            canBuy = false;
            break;
        }
    }

    int cnt0 = 0, cnt1 = 0;
    if (canBuy) {
        for (auto it = aLog.begin(); it != aLog.end(); ++it) {
            it->second = it->second - bLog[it->first];
        }
        for (auto it = aLog.begin(); it != aLog.end(); ++it) {
            cnt0 = cnt0 + it->second;
        }
    } else {
        for (auto it = bLog.begin(); it != bLog.end(); ++it) {
            if (aLog.find(it->first) == aLog.end()) {
                cnt1 = cnt1 + it->second;
            } else if (aLog[it->first] < it->second) {
                cnt1 = cnt1 + it->second - aLog[it->first];
            }
        }
    }

    if (canBuy) {
        cout << "Yes " << cnt0 << endl;
    } else {
        cout << "No " << cnt1 << endl;
    }

    return 0;
}