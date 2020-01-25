// https://open.kattis.com/problems/rimski
//
#include <bits/extc++.h>

using namespace std;

namespace Roman {

    const vector<vector<string> > NumDic = {{"I", "IV", "V", "IX"},
                                            {"X", "XL", "L", "XC"},
                                            {"C", "CD", "D", "CM"},
                                            {"M"}};
    constexpr int NumDicLength = 4;
    constexpr int MAXN = 3999;
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

    inline static
    int romanToInt(const string &s) {
        return roman2int[s];
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    Roman::init();
    string a;
    cin >> a;
    sort(begin(a), end(a));
    int minVal = numeric_limits<int>::max();
    do {
        if (Roman::roman2int.find(a) != Roman::roman2int.end()) {
            minVal = min(minVal, Roman::romanToInt(a));
        }
    } while (next_permutation(begin(a), end(a)));
    cout << Roman::int2roman[minVal] << endl;


    return 0;
}
