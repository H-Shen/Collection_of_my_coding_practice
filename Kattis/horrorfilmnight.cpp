// https://open.kattis.com/problems/horrorfilmnight
//
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

static constexpr int MAXSIZE = 1024 * 1024;
static char inputBuffer[MAXSIZE];
static char *ptr1 = inputBuffer + MAXSIZE;
static char *ptr2 = inputBuffer + MAXSIZE;
static char outputBuffer[MAXSIZE];
static char *ptr = outputBuffer;

inline static
char getcharUsingFread() {
    if (ptr1 == ptr2) {
        ptr1 = inputBuffer;
        ptr2 = inputBuffer + fread(inputBuffer, 1, MAXSIZE, stdin);
        if (ptr1 == ptr2) {
            return EOF;
        }
    }
    return *ptr1++;
}

inline static
void putcharWithFwrite(const char &ch) {
    if (ptr - outputBuffer == MAXSIZE) {
        fwrite(outputBuffer, 1, MAXSIZE, stdout);
        ptr = outputBuffer;
    }
    *ptr++ = ch;
}

template<class T>
inline static
void writeIntWithFwrite(T x) {
    if (x < 0) {
        x = -x;
        putcharWithFwrite('-');
    }
    static int storeDigits[40];
    int top = 0;
    do {
        storeDigits[top++] = x % 10;
        x /= 10;
    } while (x);
    while (top) {
        putcharWithFwrite(static_cast<T>(storeDigits[--top]) + 48);
    }
}

void flushAfterWriteIntWithFwrite() {
    fwrite(outputBuffer, 1, ptr - outputBuffer, stdout);
}

template<typename T>
inline static
void readIntUsingFread(T &x) {
    x = 0;
    bool isNeg = false;
    char ch = getcharUsingFread();

    // skip all non digit characters
    while (!isdigit(ch)) {
        if (ch == '-') {
            isNeg = true;
        }
        ch = getcharUsingFread();
    }

    while (isdigit(ch)) {
        x = x * 10 + static_cast<T>(ch ^ 48);
        ch = getcharUsingFread();
    }
    x = isNeg ? -x : x;
}

constexpr int MAXN = 1000005;
int a[MAXN];
int b[MAXN];

int main() {

    int n, movie;
    readIntUsingFread<int>(n);
    for (int i = 0; i < n; ++i) {
        readIntUsingFread<int>(movie);
        a[movie] = 1;
    }
    readIntUsingFread<int>(n);
    for (int i = 0; i < n; ++i) {
        readIntUsingFread<int>(movie);
        b[movie] = 1;
    }
    int previous_a = 1;
    int previous_b = 1;
    int counter = 0;
    for (int i = 0; i < MAXN; ++i) {
        if (a[i] && b[i]) {
            previous_a = 1;
            previous_b = 1;
            ++counter;
        } else if (a[i] && previous_b) {
            previous_a = 1;
            previous_b = 0;
            ++counter;
        } else if (b[i] && previous_a) {
            previous_b = 1;
            previous_a = 0;
            ++counter;
        }
    }
    writeIntWithFwrite<int>(counter);
    putcharWithFwrite('\n');
    flushAfterWriteIntWithFwrite();
    return 0;
}
