// https://www.nowcoder.com/practice/f459f298ca814040bf601004734129a9

#include <unordered_set>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

unordered_set<string> A;

int main() {

    ios_base::sync_with_stdio(false);
    int n;
    string s;
    cin >> n;
    while (n--) {
        cin >> s;
        A.insert(s);
    }
    int m;
    cin >> m;
    while (m--) {
        cin >> s;
        A.erase(s);
    }
    vector<string> result(A.size());
    auto it0 = A.cbegin();
    for (auto &&i : result) {
        i = *it0;
        ++it0;
    }
    sort(result.begin(), result.end());
    for (const auto &i : result) {
        cout << i << endl;
    }

    return 0;
}