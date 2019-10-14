// https://open.kattis.com/problems/musicyourway
//
#include <bits/stdc++.h>

using namespace std;

unordered_map<string, int> attributeToIndex;

inline static
void splitByChar(std::string s, const char &delim) {
    std::istringstream f(s);
    std::string temp;
    int index = 0;
    while (getline(f, s, delim)) {
        attributeToIndex[s] = index;
        ++index;
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    string s;
    getline(cin, s);
    splitByChar(s, ' ');

    int n;
    cin >> n;
    vector<vector<string> > A(n, vector<string>(attributeToIndex.size()));
    for (int i = 0; i < n; ++i) {
        vector<string> tempVec(attributeToIndex.size());
        for (auto &j : tempVec) {
            cin >> j;
        }
        A.at(i) = tempVec;
    }

    int query;
    string attribute;
    int attributeIndex;
    bool firstItem;
    bool firstCase = true;

    cin >> query;
    while (query--) {

        cin >> attribute;
        attributeIndex = attributeToIndex[attribute];

        // sort
        stable_sort(A.begin(), A.end(), [&](const vector<string> &lhs, const vector<string> &rhs) {
            return (lhs.at(attributeIndex) < rhs.at(attributeIndex));
        });

        if (firstCase) {
            firstCase = false;
        } else {
            cout << endl;
        }

        // output
        cout << s << endl;
        for (const auto &i : A) {
            firstItem = true;
            for (const auto &j : i) {
                if (firstItem) {
                    firstItem = false;
                } else {
                    cout << ' ';
                }
                cout << j;
            }
            cout << endl;
        }
    }

    return 0;
}
