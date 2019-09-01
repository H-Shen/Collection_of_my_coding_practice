// https://open.kattis.com/problems/touchscreenkeyboard
//
#include <bits/stdc++.h>

using namespace std;

inline static
int distance(const vector<vector<char> > &arr, const char &a, const char &b) {

    int a_i = 0;
    int a_j = 0;
    int b_i = 0;
    int b_j = 0;

    for (size_t i = 0; i != arr.size(); ++i) {
        for (size_t j = 0; j != arr.at(i).size(); ++j) {
            if (arr.at(i).at(j) == a) {
                a_i = static_cast<int>(i);
                a_j = static_cast<int>(j);
                break;
            }
        }
    }
    for (size_t i = 0; i != arr.size(); ++i) {
        for (size_t j = 0; j != arr.at(i).size(); ++j) {
            if (arr.at(i).at(j) == b) {
                b_i = static_cast<int>(i);
                b_j = static_cast<int>(j);
                break;
            }
        }
    }
    return abs(a_i - b_i) + abs(a_j - b_j);
}

inline static
int distanceOfTwoWords(const vector<vector<char> > &arr, const string &a, const string &b) {
    int result = 0;
    for (size_t i = 0; i != a.size(); ++i) {
        result += distance(arr, a.at(i), b.at(i));
    }
    return result;
}

int main() {

    // qwertyuiop
    // asdfghjklX
    // zxcvbnmXXX
    vector<vector<char> > A;
    vector<char> oneLine;
    string s = "qwertyuiop";
    for (const char &i : s) {
        oneLine.emplace_back(i);
    }
    A.emplace_back(oneLine);
    vector<char>().swap(oneLine);
    s = "asdfghjklX";
    for (const char &i : s) {
        oneLine.emplace_back(i);
    }
    A.emplace_back(oneLine);
    vector<char>().swap(oneLine);
    s = "zxcvbnmXXX";
    for (const char &i : s) {
        oneLine.emplace_back(i);
    }
    A.emplace_back(oneLine);
    vector<char>().swap(oneLine);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    int l;
    string tempStr;
    cin >> t;
    while (t--) {
        cin >> s >> l;
        vector<pair<string, int> > tempVec(l);
        for (int i = 0; i < l; ++i) {
            cin >> tempStr;
            tempVec.at(i) = {tempStr, distanceOfTwoWords(A, s, tempStr)};
        }
        sort(tempVec.begin(), tempVec.end(), [](const pair<string, int> &lhs, const pair<string, int> &rhs) {
           if (lhs.second == rhs.second) {
               return (lhs.first < rhs.first);
           }
           return (lhs.second < rhs.second);
        });
        for (const auto &i : tempVec) {
            cout << i.first << ' ' << i.second << '\n';
        }
    }

    return 0;
}
