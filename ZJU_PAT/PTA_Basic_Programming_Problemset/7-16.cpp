#include <iostream>
#include <algorithm>
#include <set>
#include <vector>

using namespace std;
const int MAX_ELEMENT = 6;
const int LENGTH = 4;

int main() {

    ios_base::sync_with_stdio(false);
    set<string> result;
    int n;
    cin >> n;
    vector<int> allPossibles(LENGTH);
    allPossibles[0] = 100 * n + 10 * (n + 1) + (n + 2);
    allPossibles[1] = 100 * n + 10 * (n + 1) + (n + 3);
    allPossibles[2] = 100 * n + 10 * (n + 2) + (n + 3);
    allPossibles[3] = 100 * (n + 1) + 10 * (n + 2) + (n + 3);

    for (const int &i : allPossibles) {
        string s = to_string(i);
        do {
            result.insert(s);
        } while (next_permutation(s.begin(), s.end()));
    }

    int count = 1;
    for (const auto &it : result) {
        cout << it;
        if (count == MAX_ELEMENT) {
            cout << endl;
            count = 1;
        } else {
            cout << ' ';
            ++count;
        }
    }
    return 0;
}