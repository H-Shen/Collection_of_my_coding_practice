// https://open.kattis.com/problems/conformity
//
#include <bits/extc++.h>

using namespace std;
constexpr int MAXN = 5;

int main() {

    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    unordered_map<string, int> freq;
    vector<int> A(MAXN);
    while (n--) {
        for (auto &i : A) {
            cin >> i;
        }
        sort(A.begin(), A.end());
        string s;
        for (const auto &i : A) {
            s.append(to_string(i));
            s.push_back(' ');
        }
        ++freq[s];
    }

    int maxVal = std::max_element(freq.begin(), freq.end(),
            [](const pair<string, int>& p1, const pair<string, int>& p2) {
                return p1.second < p2.second; }
        )->second;

    int counter = 0;
    for (const auto &i : freq) {
        if (i.second == maxVal) {
            counter += maxVal;
        }
    }
    cout << counter << endl;

    return 0;
}
