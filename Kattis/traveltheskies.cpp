// https://open.kattis.com/problems/traveltheskies

#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

namespace IO {
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
        putchar('\n');
    }
}

constexpr int DAYS = 10;
constexpr int MAXK = 15;
constexpr int COST = 1; // the number of days each flight cost
int FlightCapacity[MAXK][DAYS];  // capacities on flights
int Airports[MAXK][DAYS];  // stats on airports

int k,n,m,u,v,d,z,a,b,c;

int main() {
    IO::read(k,n,m);
    for (int i = 0; i < m; ++i) {
        IO::read(u,v,d,z);
        FlightCapacity[u][d] += z;
        Airports[v][d + COST] += z;
    }
    for (int i = 0; i < k*n; ++i) {
        IO::read(a,b,c);
        Airports[a][b] += c;
    }
    int people;
    // check each airport on n days
    for (int i = 1; i <= k; ++i) {
        people = 0;
        for (int j = 1; j <= n; ++j) {
            people += Airports[i][j];
            if (people < FlightCapacity[i][j]) {
                puts("suboptimal");
                return 0;
            }
            people -= FlightCapacity[i][j];
        }
    }
    puts("optimal");

    return 0;
}
