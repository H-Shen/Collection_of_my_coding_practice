// https://open.kattis.com/problems/passwordrotation

#include <bits/extc++.h>

using namespace __gnu_pbds;
using namespace std;

int minimalRotation(string s) {
    s += s; // Concatenate string to it self to avoid modular arithmetic
    int length = (int)s.size();
    vector<int> f(length, -1);    // Failure function
    int k = 0;  // Least rotation of string found so far
    for (int j = 1, i; j < length; ++j) {
        char sj = s.at(j);
        i = f.at(j - k - 1);
        while (i != -1 && sj != s.at(k + i + 1)) {
            if (sj < s.at(k + i + 1)) {
                k = j - i - 1;
            }
            i = f.at(i);
        }
        if (sj != s.at(k + i + 1)) {
            if (sj < s.at(k)) {
                k = j;
            }
            f.at(j - k) = -1;
        } else {
            f.at(j - k) = i + 1;
        }
    }
    return k;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    string s;
    string rev_s;
    unordered_set<string> vis;
    while (n--) {
        cin >> s;
        rev_s = s;
        reverse(rev_s.begin(), rev_s.end());
        int temp1 = minimalRotation(s);
        rotate(s.begin(),s.begin()+temp1,s.end());
        int temp2 = minimalRotation(rev_s);
        rotate(rev_s.begin(), rev_s.begin()+temp2, rev_s.end());
        if (vis.count(s) > 0 || vis.count(rev_s) > 0) {
            cout << "Yes" << '\n';
            return 0;
        }
        vis.insert(s);
        vis.insert(rev_s);
    }
    cout << "No" << '\n';
    return 0;
}
