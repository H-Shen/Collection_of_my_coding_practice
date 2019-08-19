// https://open.kattis.com/problems/deduplicatingfiles
#include<bits/stdc++.h>

using namespace std;

int hashGet(string s) {
    int sum = 0;
    if (s.empty()) return sum;
    sum = s[0];
    for (size_t i = 1; i < s.size(); ++i) {
        sum = sum ^ s[i];
    }
    return sum;
}

int main() {
    int n;
    string s;
    while (true) {
        cin >> n;
        getchar();
        if (n == 0) {
            break;
        }
        unordered_set<string> A;
        unordered_map<int, vector<string> > collision;
        while (n--) {
            getline(cin, s);
            A.insert(s);
            collision[hashGet(s)].push_back(s);
        }
        int collisionCnt = 0;
        for (auto &&it : collision) {
            collisionCnt = collisionCnt + it.second.size() * (it.second.size() - 1) / 2;
            unordered_map<string, int> freq;
            for (auto &&it0 : it.second) {
                ++freq[it0];
            }
            for (auto &&it0 : freq) {
                if (it0.second >= 2) {
                    collisionCnt = collisionCnt - it0.second * (it0.second - 1) / 2;
                }
            }
        }

        /*
        for (auto &it : collision)
        {
            if (it.second > 1)
            {
                collisionCnt += it.second * (it.second - 1) / 2;
            }
        }*/
        cout << A.size() << ' ' << collisionCnt << endl;
    }
    return 0;
}
