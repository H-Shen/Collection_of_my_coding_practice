// https://open.kattis.com/problems/queens
//
#include <bits/extc++.h>

using namespace std;

vector<int> col;
vector<int> row;
unordered_set<int> mainDiagonal;
unordered_set<int> subDiagonal;

int main() {

    int t, x, y, temp;
    scanf("%d", &t);
    col.resize(t);
    row.resize(t);

    for (int i = 0; i < t; ++i) {
        scanf("%d %d", &x, &y);
        if (col.at(x) == 1) {
            printf("INCORRECT\n");
            return 0;
        } else {
            col.at(x) = 1;
        }
        if (row.at(y) == 1) {
            printf("INCORRECT\n");
            return 0;
        } else {
            row.at(y) = 1;
        }
        temp = y - x;
        if (mainDiagonal.find(temp) != mainDiagonal.end()) {
            printf("INCORRECT\n");
            return 0;
        } else {
            mainDiagonal.insert(temp);
        }
        temp = x + y;
        if (subDiagonal.find(temp) != subDiagonal.end()) {
            printf("INCORRECT\n");
            return 0;
        } else {
            subDiagonal.insert(temp);
        }
    }
    printf("CORRECT\n");
    return 0;
}
