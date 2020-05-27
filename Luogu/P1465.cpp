#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

namespace IO {
    template<typename T>
    inline
    void read(T &t) {
        int n = 0;
        int c = getchar();
        t = 0;
        while (!isdigit(c)) n |= c == '-', c = getchar();
        while (isdigit(c)) t = t * 10 + c - 48, c = getchar();
        if (n) t = -t;
    }

    template<typename T, typename... Args>
    inline
    void read(T &t, Args &... args) {
        read(t);
        read(args...);
    }

    template<typename T>
    inline void write(T x) {
        if (x < 0) x = -x, putchar('-');
        if (x > 9) write(x / 10);
        putchar(x % 10 + 48);
    }

    template<typename T>
    inline void writeln(T x) {
        write(x);
        putchar('\n');
    }
}

namespace Roman {

    const vector<vector<string> > NumDic = {{"I", "IV", "V", "IX"},
                                            {"X", "XL", "L", "XC"},
                                            {"C", "CD", "D", "CM"},
                                            {"M"}};
    constexpr int NumDicLength = 4;
    constexpr int MAXN = 3550;
    unordered_map<string, int> roman2int;
    unordered_map<int, string> int2roman;

    inline static
    string intToRoman(int Num) {
        string retstr;
        int i, modNum;
        for (i = 0; i < NumDicLength; i++) {
            string str;
            modNum = Num % 10;
            Num = Num / 10;
            if (modNum != 0) {
                if (i != 3) {
                    if (modNum <= 3) {
                        while (modNum > 0) {
                            str = str + NumDic[i][0];
                            modNum--;
                        }
                    } else if (modNum < 5)
                        str = NumDic[i][1];
                    else if (modNum == 5)
                        str = NumDic[i][2];
                    else if (modNum < 9) {
                        str = NumDic[i][2];
                        while (modNum > 5) {
                            str += NumDic[i][0];
                            modNum--;
                        }
                    } else
                        str = NumDic[i][3];
                } else {
                    while (modNum > 0) {
                        str += NumDic[i][0];
                        modNum--;
                    }
                }
                retstr = str + retstr;
            }
        }
        return retstr;
    }

    inline static
    void init() {
        for (int i = 1; i <= MAXN; i++) {
            auto temp = intToRoman(i);
            roman2int[temp] = i;
            int2roman[i] = temp;
        }
    }
}

constexpr int MAX_CHAR = 7;

unordered_map<char, int> RomanChar2Index = {
        {'I', 0},
        {'V', 1},
        {'X', 2},
        {'L', 3},
        {'C', 4},
        {'D', 5},
        {'M', 6}
};
unordered_map<int, char> RomanChar2IndexInv;
array<int, MAX_CHAR> A;

int main() {

    Roman::init();
    for (const auto &[k, v] : RomanChar2Index) {
        RomanChar2IndexInv[v] = k;
    }
    int n;
    IO::read(n);
    for (int i = 1; i <= n; ++i) {
        for (const char &ch : Roman::intToRoman(i)) {
            ++A.at(RomanChar2Index[ch]);
        }
    }
    for (int i = 0; i < MAX_CHAR; ++i) {
        if (A.at(i) != 0) {
            printf("%c %d\n", RomanChar2IndexInv[i], A.at(i));
        }
    }

    return 0;
}
