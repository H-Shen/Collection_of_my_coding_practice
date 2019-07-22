#include <cmath>
#include <string>
#include <vector>
#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

const int MAX = 100;
const char CHAR_NOT_USED = '\n';

int main() {

    char s[MAX];
    scanf("%s", s);

    string str = s;
    int L = static_cast<int>(str.size());
    int lowerBound = static_cast<int>(sqrt(static_cast<double>(L)));
    int upperBound = lowerBound + 1;
    int i, j, row = 0, column = 0, crnArea;
    int minArea = (upperBound + 1) * (upperBound + 1);

    for (i = lowerBound; i <= upperBound; i++) {
        for (j = i; j <= upperBound; j++) {
            crnArea = i * j;
            if (crnArea >= L && crnArea < minArea) {
                minArea = crnArea;
                row = i;
                column = j;
            }
        }
    }

    vector<vector<char> > A(static_cast<unsigned long>(row));
    for (i = 0; i < row; i++) {
        A[i].resize(static_cast<unsigned long>(column));
    }
    int pos = 0;
    for (i = 0; i < row; i++) {
        for (j = 0; j < column; j++) {
            if (pos == L) {
                A[i][j] = CHAR_NOT_USED;
            } else {
                A[i][j] = str[pos];
                pos++;
            }
        }
    }

    for (i = 0; i < column; i++) {
        for (j = 0; j < row; j++) {
            if (A[j][i] != CHAR_NOT_USED)
                cout << A[j][i];
        }
        if (i != column - 1) {
            cout << ' ';
        } else {
            cout << endl;
        }
    }
    return 0;
}
