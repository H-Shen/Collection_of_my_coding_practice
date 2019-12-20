// https://www.nowcoder.com/practice/2a3dc06f337d4a2ba41d25c688f95e2f

#include <unordered_map>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

bool cmp(const pair<int, int> &a, const pair<int, int> &b) {
    return (a.second < b.second);
}

unordered_map<char, int> A;
vector<pair<char, int> > result;

int main() {

    ios_base::sync_with_stdio(false);
    int k;
    string s;
    while (cin >> k) {
        cin.get();
        getline(cin, s);
        int length = static_cast<int>(s.size());
        A.clear();
        for (int i = 0; i < length; ++i) {
            if (A.find(s[i]) != A.end()) {
                A[s[i]] = -1;
            } else {
                A[s[i]] = i;
            }
        }
        vector<pair<char, int> >().swap(result);
        for (const auto &it : A) {
            if (it.second != -1) {
                result.emplace_back(make_pair(it.first, it.second));
            }
        }
        sort(result.begin(), result.end(), cmp);
        if (k - 1 >= 0 && k - 1 < static_cast<int>(result.size())) {
            cout << "[" << result.at(k - 1).first << "]";
        } else {
            cout << "Myon~";
        }
        cout << endl;
    }
    return 0;
}
