// https://open.kattis.com/problems/epigdanceoff
#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

vector<vector<char> > rotate(const vector<vector<char> > & A, int n, int m) {
    vector<vector<char> > result(m, vector<char>(n));
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            result[i][j] = A[j][i];
        }
    }
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    int n, m;
    string s;
    cin >> n >> m;
    vector<vector<char> > A(n, vector<char>(m));
    for (int i = 0; i < n; ++i) {
        cin >> s;
        for (int j = 0; j < m; ++j) {
            A[i][j] = s[j];
        }
    }
    vector<vector<char> > A_rotate = rotate(A, n, m);
    vector<string> A_rotate_string(m);
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            A_rotate_string[i] += A_rotate[i][j];
        }
    }

    string delimiter = string(n, '_');
    int count = 0;
    for (const auto & i : A_rotate_string) {
        if (i == delimiter) {
            ++count;
        }
    }
    ++count;
    cout << count << endl;
}
