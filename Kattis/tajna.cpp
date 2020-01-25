// https://open.kattis.com/problems/tajna
//
#include <bits/extc++.h>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    string s;
    cin >> s;
    int rows = -1;
    int cols;
    int length = static_cast<int>(s.size());
    for (int i = 1; i < length; ++i) {
        if (length % i == 0) {
            cols = length / i;
            if (i <= cols) {
                rows = max(rows, i);
            }
        }
    }
    cols = length / rows;
    vector<vector<char> > A(rows, vector<char>(cols));
    for (int i = 0; i < length; ++i) {
        A.at(i % rows).at(i / rows) = s.at(i);
    }


    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << A.at(i).at(j);
        }
    }
    cout << endl;

    return 0;
}
