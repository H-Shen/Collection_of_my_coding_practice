// https://www.nowcoder.com/practice/5973a31d58234b068fa1fe34f7290855

#include <cstdio>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

const int MAXN = 50;
const string quote = "\"";

int main() {

    int n, i;
    string str;

    while (~scanf("%d", &n)) {

        getchar();
        vector<string> res;

        while (n--) {

            char s[MAXN];
            scanf("%[^\n]", s);
            getchar();
            str = s;

            if (strstr(s, " ") || strstr(s, ",")) {
                str = quote + str + quote;
            }
            res.push_back(str);
        }
        int len = static_cast<int>(res.size());
        for (i = 0; i < len - 1; i++) {
            printf("%s, ", res[i].c_str());
        }
        printf("%s\n", res[len - 1].c_str());
    }
    return 0;
}
