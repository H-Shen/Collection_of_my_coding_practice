// https://open.kattis.com/problems/tetris
//
#include <bits/stdc++.h>

using namespace std;

int main() {

    int c, p;
    scanf("%d %d", &c, &p);
    vector<int> A(c);
    for (auto &i : A) {
        scanf("%d", &i);
    }
    int counter = 0;
    switch (p) {
        case 1:
            // shape 1
            if (c >= 1) {
                // h
                counter += c;
            }
            // shape 2
            if (c >= 4) {
                // h h h h
                for (int i = 0; i < c - 3; ++i) {
                    if (A.at(i) == A.at(i + 1) && A.at(i + 1) == A.at(i + 2) &&
                        A.at(i + 2) == A.at(i + 3)) {
                        ++counter;
                    }
                }
            }
            break;
        case 2:
            // shape 1
            if (c >= 2) {
                // h h
                for (int i = 0; i < c - 1; ++i) {
                    if (A.at(i) == A.at(i + 1)) {
                        ++counter;
                    }
                }
            }
            break;
        case 3:
            // shape 1
            if (c >= 3) {
                // h h h+1
                for (int i = 0; i < c - 2; ++i) {
                    if (A.at(i) == A.at(i + 1) &&
                        A.at(i + 1) == A.at(i + 2) - 1) {
                        ++counter;
                    }
                }
            }
            // shape 2
            if (c >= 2) {
                // h+1 h
                for (int i = 0; i < c - 1; ++i) {
                    if (A.at(i) == A.at(i + 1) + 1) {
                        ++counter;
                    }
                }
            }
            break;
        case 4:
            // shape 1
            if (c >= 3) {
                // h+1 h h
                for (int i = 0; i < c - 2; ++i) {
                    if (A.at(i) == A.at(i + 1) + 1 &&
                        A.at(i + 1) == A.at(i + 2)) {
                        ++counter;
                    }
                }
            }
            // shape 2
            if (c >= 2) {
                // h h+1
                for (int i = 0; i < c - 1; ++i) {
                    if (A.at(i) == A.at(i + 1) - 1) {
                        ++counter;
                    }
                }
            }
            break;
        case 5:
            // shape 1
            if (c >= 3) {
                // h h h
                for (int i = 0; i < c - 2; ++i) {
                    if (A.at(i) == A.at(i + 1) && A.at(i + 1) == A.at(i + 2)) {
                        ++counter;
                    }
                }
            }
            // shape 2
            if (c >= 2) {
                // h h+1
                for (int i = 0; i < c - 1; ++i) {
                    if (A.at(i) == A.at(i + 1) - 1) {
                        ++counter;
                    }
                }
            }
            // shape 3
            if (c >= 3) {
                // h+1 h h+1
                for (int i = 0; i < c - 2; ++i) {
                    if (A.at(i) == A.at(i + 1) + 1 &&
                        A.at(i + 2) == A.at(i + 1) + 1) {
                        ++counter;
                    }
                }
            }
            // shape 4
            if (c >= 2) {
                // h+1 h
                for (int i = 0; i < c - 1; ++i) {
                    if (A.at(i) == A.at(i + 1) + 1) {
                        ++counter;
                    }
                }
            }
            break;
        case 6:
            // shape 1
            if (c >= 3) {
                // h h h
                for (int i = 0; i < c - 2; ++i) {
                    if (A.at(i) == A.at(i + 1) && A.at(i + 1) == A.at(i + 2)) {
                        ++counter;
                    }
                }
            }
            // shape 2
            if (c >= 2) {
                // h h
                for (int i = 0; i < c - 1; ++i) {
                    if (A.at(i) == A.at(i + 1)) {
                        ++counter;
                    }
                }
            }
            // shape 3
            if (c >= 3) {
                // h h+1 h+1
                for (int i = 0; i < c - 2; ++i) {
                    if (A.at(i) == A.at(i + 1) - 1 &&
                        A.at(i + 2) == A.at(i + 1)) {
                        ++counter;
                    }
                }
            }
            // shape 4
            if (c >= 2) {
                // h+2 h
                for (int i = 0; i < c - 1; ++i) {
                    if (A.at(i) == A.at(i + 1) + 2) {
                        ++counter;
                    }
                }
            }
            break;
        default:
            // shape 1
            if (c >= 3) {
                // h h h
                for (int i = 0; i < c - 2; ++i) {
                    if (A.at(i) == A.at(i + 1) && A.at(i + 1) == A.at(i + 2)) {
                        ++counter;
                    }
                }
            }
            // shape 2
            if (c >= 2) {
                // h h+2
                for (int i = 0; i < c - 1; ++i) {
                    if (A.at(i) + 2 == A.at(i + 1)) {
                        ++counter;
                    }
                }
            }
            // shape 3
            if (c >= 3) {
                // h+1 h+1 h
                for (int i = 0; i < c - 2; ++i) {
                    if (A.at(i) == A.at(i + 1) &&
                        A.at(i + 2) == A.at(i + 1) - 1) {
                        ++counter;
                    }
                }
            }
            // shape 4
            if (c >= 2) {
                // h h
                for (int i = 0; i < c - 1; ++i) {
                    if (A.at(i) == A.at(i + 1)) {
                        ++counter;
                    }
                }
            }
            break;
    }
    printf("%d\n", counter);

    return 0;
}
