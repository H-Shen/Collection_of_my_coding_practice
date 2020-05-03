// https://open.kattis.com/problems/sumsets
//
#include <bits/extc++.h>

#include <sys/mman.h>
#include <sys/stat.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

constexpr int maxn = 4005;
constexpr ll minVal = -536870920;

namespace FasterIO {

    static constexpr int MAXSIZE = 1024 * 1024;
    static char* inputBuffer = nullptr;
    static char* ptr0;
    static char outputBuffer[MAXSIZE];
    static char *ptr = outputBuffer;
    int Size;

    inline static
    void init() {
        struct stat sb; // not initialize it to save time
        fstat(fileno_unlocked(stdin), &sb);
        Size = sb.st_size;
        inputBuffer = reinterpret_cast<char *>(mmap(nullptr, Size, PROT_READ, MAP_PRIVATE, fileno_unlocked(stdin), 0));
        ptr0 = inputBuffer;
    }
    inline static
    char getchar() {
        if (ptr0 == inputBuffer + Size || *ptr0 == EOF) return EOF;
        return *ptr0++;
    }
    template<typename T>
    inline static
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
    inline static
    void putchar(const char &ch) {
        if (ptr - outputBuffer == MAXSIZE) {
#ifdef __linux__
            fwrite_unlocked(outputBuffer, 1, MAXSIZE, stdout);
#else
            fwrite(outputBuffer, 1, MAXSIZE, stdout);
#endif
            ptr = outputBuffer;
        }
        *ptr++ = ch;
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
    inline
    void flush() {
#ifdef __linux__
        fwrite_unlocked(outputBuffer, 1, ptr - outputBuffer, stdout);
#else
        fwrite(outputBuffer, 1, ptr - outputBuffer, stdout);
#endif
    }
}

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

ll A[maxn];
gp_hash_table<ll, pair<ll, ll>, custom_hash> hashTable;

int main() {

    FasterIO::init();
    int n;
    FasterIO::read(n);
    for (int i = 0; i < n; ++i) {
        FasterIO::read(A[i]);
    }
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            hashTable[A[i] + A[j]] = make_pair(A[i], A[j]);
        }
    }
    ll max_d = minVal;
    ll c, d, a, b;
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            d = A[i];
            c = A[j];
            if (hashTable.find(d - c) != hashTable.end()) {
                a = hashTable[d - c].first;
                b = hashTable[d - c].second;
                if (d != a && d != b && c != a && c != b) {
                    max_d = max(max_d, d);
                }
            }
            d = A[j];
            c = A[i];
            if (hashTable.find(d - c) != hashTable.end()) {
                a = hashTable[d - c].first;
                b = hashTable[d - c].second;
                if (d != a && d != b && c != a && c != b) {
                    max_d = max(max_d, d);
                }
            }
        }
    }
    if (max_d == minVal) {
        FasterIO::putchar('n');
        FasterIO::putchar('o');
        FasterIO::putchar(' ');
        FasterIO::putchar('s');
        FasterIO::putchar('o');
        FasterIO::putchar('l');
        FasterIO::putchar('u');
        FasterIO::putchar('t');
        FasterIO::putchar('i');
        FasterIO::putchar('o');
        FasterIO::putchar('n');
    }
    else {
        FasterIO::write(max_d);
    }
    FasterIO::putchar('\n');
    FasterIO::flush();
    return 0;
}
