// https://open.kattis.com/problems/chartingprogress
//
#include <bits/extc++.h>

using namespace std;

inline static
vector<vector<char> > rotate(const vector<vector<char> > &A) {
    int row = static_cast<int>(A.size());
    int col = static_cast<int>(A.front().size());
    vector<vector<char> > temp(col, vector<char>(row));
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            temp.at(j).at(i) = A.at(i).at(j);
        }
    }
    return temp;
}

inline static
vector<vector<char> > process(const vector<vector<char> > &A) {
    int row = static_cast<int>(A.size());
    int col = static_cast<int>(A.front().size());
    auto temp = rotate(A);
    vector<int> ret;
    for (int i = 0; i < col; ++i) {
        for (int j = 0; j < row; ++j) {
            if (temp.at(i).at(j) == '*') {
                ret.emplace_back(j);
            }
        }
    }
    sort(ret.begin(), ret.end(), greater<>());

    // reset all elements to '.'
    for (int i = 0; i < col; ++i) {
        for (int j = 0; j < row; ++j) {
            temp.at(i).at(j) = '.';
        }
    }

    auto iter = ret.cbegin();
    for (int i = 0; i < col; ++i) {
        temp.at(i).at(*iter) = '*';
        ++iter;
    }

    return rotate(temp);
}


int main() {

    ios_base::sync_with_stdio(false);
    string s;
    vector<vector<char> > L;
    bool firstItem = true;
    while (getline(cin, s)) {
        if (!s.empty()) {
            vector<char> temp;
            for (const auto &i : s) {
                temp.emplace_back(i);
            }
            L.emplace_back(temp);
        } else {
            if (firstItem) {
                firstItem = false;
            } else {
                cout << endl;
            }
            L = process(L);
            for (const auto &i : L) {
                for (const auto &j : i) {
                    cout << j;
                }
                cout << endl;
            }
            vector<vector<char> >().swap(L);
        }
    }
    if (!firstItem) {
        cout << endl;
    }
    L = process(L);
    for (const auto &i : L) {
        for (const auto &j : i) {
            cout << j;
        }
        cout << endl;
    }
    cout << endl;
    return 0;
}
