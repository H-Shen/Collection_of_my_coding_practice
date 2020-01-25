// https://open.kattis.com/problems/fbiuniversal
//
#include <bits/extc++.h>

using namespace std;
constexpr int MAX_LENGTH = 9;
char s[MAX_LENGTH];

unordered_map<char, long long> char2index;
vector<long long> preCalc = {1LL};

inline static
long long convert(const string &str) {
    long long result = 0;
    size_t i = 0;
    for (auto it = str.crbegin(); it != str.crend(); ++it) {
        result = result + static_cast<long long>(char2index[*it]) * preCalc[i];
        ++i;
    }
    return result;
}

int main() {

    // pre
    string str = "0123456789ACDEFHJKLMNPRTVWX";
    for (size_t i = 0; i != str.size(); ++i) {
        char2index[str[i]] = static_cast<long long>(i);
    }

    for (int i = 0; i <= 10; ++i) {
        preCalc.emplace_back(preCalc.back() * 27LL);
    }

    // input
    int n, kase;
    string myStr;
    scanf("%d", &n);

    for (int i = 1; i <= n; ++i) {
        scanf("%d %s", &kase, s);
        myStr = "";
        for (int j = 0; j < MAX_LENGTH - 1; ++j) {
            // B->8, G->C, I->1, O->0, Q->0, S->5, U->V, Y->V, Z->2
            switch (s[j]) {
                case 'B':
                    s[j] = '8';
                    break;
                case 'G':
                    s[j] = 'C';
                    break;
                case 'I':
                    s[j] = '1';
                    break;
                case 'Q':
                    s[j] = '0';
                    break;
                case 'O':
                    s[j] = '0';
                    break;
                case 'S':
                    s[j] = '5';
                    break;
                case 'Y':
                    s[j] = 'V';
                    break;
                case 'U':
                    s[j] = 'V';
                    break;
                case 'Z':
                    s[j] = '2';
                    break;
                default:
                    break;
            }
            myStr.push_back(s[j]);
        }
        // calculate the checked
        // (2*D1 + 4*D2 + 5*D3 + 7*D4 + 8*D5 + 10*D6 + 11*D7 + 13*D8) mod 27
        long long a = (2*char2index[s[0]] + 4*char2index[s[1]] + 5*char2index[s[2]] + 7*char2index[s[3]] + 8*char2index[s[4]] +
                10*char2index[s[5]] +11*char2index[s[6]] +13*char2index[s[7]]) % 27;
        printf("%d ", kase);
        if (a != char2index[s[8]]) {
            printf("Invalid\n");
        } else {
            printf("%lld\n", convert(myStr));
        }
    }

    return 0;
}
