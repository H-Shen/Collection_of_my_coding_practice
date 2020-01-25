// https://open.kattis.com/problems/anewalphabet
#include <bits/extc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    unordered_map<string, string> A;

    A["a"] = "@";
    A["b"] = "8";
    A["c"] = "(";
    A["d"] = "|)";
    A["e"] = "3";
    A["f"] = "#";
    A["g"] = "6";
    A["h"] = "[-]";
    A["i"] = "|";
    A["j"] = "_|";
    A["k"] = "|<";
    A["l"] = "1";
    A["m"] = "[]\\/[]";
    A["n"] = "[]\\[]";
    A["o"] = "0";
    A["p"] = "|D";
    A["q"] = "(,)";
    A["r"] = "|Z";
    A["s"] = "$";
    A["t"] = "']['";
    A["u"] = "|_|";
    A["v"] = "\\/";
    A["w"] = "\\/\\/";
    A["x"] = "}{";
    A["y"] = "`/";
    A["z"] = "2";

    string s, res;
    getline(cin, s);
    char tmp = '\0';
    string tmpStr;

    for (auto &&ch : s) {
        if (ch >= 'A' && ch <= 'Z') {
            tmp = tolower(ch);
            tmpStr = tmp;
            res = res + A[tmpStr];
        } else if (ch >= 'a' && ch <= 'z') {
            tmpStr = ch;
            res = res + A[tmpStr];
        } else {
            res = res + ch;
        }
    }
    cout << res << endl;

    return 0;
}
