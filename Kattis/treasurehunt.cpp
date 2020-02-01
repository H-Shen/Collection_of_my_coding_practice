// https://open.kattis.com/problems/treasurehunt
//
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

unordered_set<int> positions;
int r;
int c;
int convert(int i, int j) {
    return i * c + j;
}

int main() {

    scanf("%d %d", &r, &c);
    vector<vector<char> > A(r, vector<char>(c));
    getchar();
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            scanf("%c", &A.at(i).at(j));
        }
        getchar();
    }
    int current_r = 0;
    int current_c = 0;
    int counter = 0;
    int temp;
    char ch;
    try {
        while (true) {
            ch = A.at(current_r).at(current_c);
            temp = convert(current_r, current_c);
            if (positions.find(temp) != positions.end()) {
                printf("Lost\n");
                return 0;
            } else {
                positions.insert(temp);
            }
            if (ch == 'N') {
                --current_r;
            } else if (ch == 'S') {
                ++current_r;
            } else if (ch == 'W') {
                --current_c;
            } else if (ch == 'E') {
                ++current_c;
            } else {
                break;
            }
            ++counter;
        }
    } catch (...) {
        printf("Out\n");
        return 0;
    }
    printf("%d\n", counter);
    return 0;
}
