#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

template <typename T>
inline
void read(T& t) {
    int n = 0; int c = getchar(); t = 0;
    while (!isdigit(c)) n |= c == '-', c = getchar();
    while (isdigit(c)) t = t * 10 + c - 48, c = getchar();
    if (n) t = -t;
}
template <typename T, typename... Args>
inline
void read(T& t, Args&... args) {
    read(t); read(args...);
}

template <typename T>
inline void write(T x) {
    if (x < 0) x = -x, putchar('-');
    if (x > 9) write(x / 10);
    putchar(x % 10 + 48);
}
template <typename T>
inline void writeln(T x) {
    write(x);
    puts("");
}

using ll = long long;
constexpr int N = 7;

int main() {

    vector<pair<int, int> > A(N);
    int x, y;
    for (int i = 0; i < N; ++i) {
        scanf("%d %d", &x, &y);
        A.at(i).first = x + y;
        A.at(i).second = i;
    }
    sort(A.begin(), A.end(), [](const pair<int, int> &lhs, const pair<int, int> &rhs) {
        if (lhs.first == rhs.first) {
            return (lhs.second < rhs.second);
        }
        return (lhs.first > rhs.first);
    });
    printf("%d\n", A.front().second + 1);


    return 0;
}