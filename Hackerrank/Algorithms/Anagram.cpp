#include <cstdio>
#include <string>
#include <unordered_map>

using namespace std;

const int MAXN = 10005;
char s[MAXN];

unordered_map <char, int> stats(string &s, int len) {
    unordered_map <char, int> res;
    for (int i = 0; i < len; i++) {
        res[s[i]]++;
    }
    return res;
}

int main() {

    int n, len, len_half, cnt, tmp;
    string str;

    scanf("%d", &n);
    while (n--) {

        scanf("%s", s);
        str = s;
        len = str.size();

        if (len % 2 != 0) {
            printf("-1\n");
        }
        else {

            len_half = len / 2;
            cnt = 0;

            string str_a (str, 0, len_half);
            string str_b (str, len_half);
            unordered_map <char, int> str_a_stats = stats(str_a, len_half);
            unordered_map <char, int> str_b_stats = stats(str_b, len_half);

            for (auto it = str_b_stats.begin(); it != str_b_stats.end(); ++it) {

                if (str_a_stats.find(it->first) != str_a_stats.end()) {
                    tmp = min(str_a_stats[it->first], it->second);
                    str_a_stats[it->first] -= tmp;
                }
            }

            for (auto it = str_a_stats.begin(); it != str_a_stats.end(); ++it) {
                cnt += it->second;
            }
            printf("%d\n", cnt);
        }
    }

    return 0;
}
