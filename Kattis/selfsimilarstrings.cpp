// https://open.kattis.com/problems/selfsimilarstrings
//
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

constexpr int MAXN = 90;
char cstr[MAXN];

int main() {

    while (~scanf("%s", cstr)) {
        string s(cstr);
        int n = static_cast<int>(s.size());
        bool haveAns = false;
        for (size_t i = n; i >= 1; --i) {
            haveAns = true;
            unordered_map<string, int> temp_unmap;
            deque<char> temp(s.begin(), s.begin() + i);
            int j = i;
            while (true) {
                ++temp_unmap[string(temp.begin(), temp.end())];
                if (j == n) {
                    break;
                }
                temp.push_back(s.at(j));
                temp.pop_front();
                ++j;
            }
            for (const auto &[k, v] : temp_unmap) {
                if (v == 1) {
                    haveAns = false;
                    break;
                }
            }
            if (haveAns) {
                printf("%zu\n", i);
                break;
            }
        }
        if (!haveAns) {
            printf("0\n");
        }
    }

    return 0;
}
