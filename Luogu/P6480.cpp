#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

namespace IO {
    template <typename T>
    inline
    void read(T& t) {
        int n = 0; int c = getchar_unlocked(); t = 0;
        while (!isdigit(c)) n |= c == '-', c = getchar_unlocked();
        while (isdigit(c)) t = t * 10 + c - 48, c = getchar_unlocked();
        if (n) t = -t;
    }
    template <typename T, typename... Args>
    inline
    void read(T& t, Args&... args) {
        read(t); read(args...);
    }
    template <typename T>
    inline void write(T x) {
        if (x < 0) x = -x, putchar_unlocked('-');
        if (x > 9) write(x / 10);
        putchar_unlocked(x % 10 + 48);
    }
    template <typename T>
    inline void writeln(T x) {
        write(x);
        putchar_unlocked('\n');
    }
}

int main() {

    int c, p;
    IO::read(c, p);
    vector<int> A(c);
    for (auto &i : A) {
        IO::read(i);
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
    IO::writeln(counter);
    return 0;
}