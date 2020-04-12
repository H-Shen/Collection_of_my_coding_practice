#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

namespace FastIO {

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
}

struct Node {
    int id;
    int score;
    int w;
};

bool cmp(const Node &l, const Node &r) {
    if (l.score == r.score) {
        return l.id < r.id;
    }
    return l.score > r.score;
}

int main() {

    int n, r, q;
    FastIO::readIntUsingFread(n);
    FastIO::readIntUsingFread(r);
    FastIO::readIntUsingFread(q);
    int length = 2 * n;
    vector<Node> A(length);
    for (int i = 0; i < length; ++i) {
        FastIO::readIntUsingFread(A.at(i).score);
        A.at(i).id = i + 1;
    }
    for (int i = 0; i < length; ++i) {
        FastIO::readIntUsingFread(A.at(i).w);
    }
    sort(A.begin(), A.end(), cmp);
    // after sorting, every elements in A are sorted
    // for all winners, their scores all += 1, thus the winners are also sorted
    // for all losers, their scores do not change, thus the losers are also sorted
    // thus we can merge winners and losers into A again, which cost O(n) at most
    vector<Node> winner(n);
    vector<Node> loser(n);
    int counter;
    for (int round = 0; round < r; ++round) {
        counter = 0;
        for (int i = 0; i < length; i += 2) {
            if (A.at(i).w > A.at(i + 1).w) {
                ++A.at(i).score;
                winner.at(counter) = A.at(i);
                loser.at(counter) = A.at(i + 1);
            } else {
                ++A.at(i + 1).score;
                winner.at(counter) = A.at(i + 1);
                loser.at(counter) = A.at(i);
            }
            ++counter;
        }
        merge(winner.begin(), winner.end(), loser.begin(), loser.end(), A.begin(), cmp);
    }
    FastIO::writeIntWithFwrite(A.at(q - 1).id);
    FastIO::putcharWithFwrite('\n');
    FastIO::flushAfterWriteIntWithFwrite();

    return 0;
}
