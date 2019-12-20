// https://www.nowcoder.com/practice/6427b054e3a4415294b383beafc7532c

#include <bits/stdc++.h>

using namespace std;

int main() {

    int n, m, i, j, head, tail;

    string str;
    while (cin >> n >> m) {
        vector<string> area(static_cast<unsigned long>(n));
        for (i = 0; i < n; i++) {
            cin >> str;
            area[i] = str;
        }

        bool headFindOne, tailFindOne;
        for (i = 0; i < n; i++) {

            head = 0, tail = m - 1;
            headFindOne = false, tailFindOne = false;

            while (head <= tail) {

                if (headFindOne && tailFindOne)
                    break;

                if (!headFindOne && area[i][head] != '1') {
                    area[i][head] = '2';
                    head++;
                } else {
                    headFindOne = true;
                }

                if (!tailFindOne && area[i][tail] != '1') {
                    area[i][tail] = '2';
                    tail--;
                } else {
                    tailFindOne = true;
                }

            }
        }

        int boundary = -1;
        for (i = 0; i < n; i++) {
            for (j = 0; j < m; j++) {
                if (i == boundary && area[i][j] == '0')
                    area[i][j] = '2';

                if (boundary == -1 && area[i][j] == '1') {
                    if (j == 0)
                        break;
                    else
                        boundary = i;
                }
            }
        }

        int boundaryDown = -1;
        for (i = n - 1; i >= 0; i--) {
            for (j = m - 1; j >= 0; j--) {
                if (i == boundaryDown && area[i][j] == '0')
                    area[i][j] = '2';

                if (boundaryDown == -1 && area[i][j] == '1') {
                    if (j == 0)
                        break;
                    else
                        boundaryDown = i;
                }
            }
        }


        int counter = 0;
        for (i = 1; i < n - 1; i++) {
            for (j = 0; j < m; j++) {
                if (area[i][j] == '0') {
                    counter++;
                }
            }
        }
        printf("%d\n", counter);
    }
    return 0;
}