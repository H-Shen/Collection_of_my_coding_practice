// https://open.kattis.com/problems/weightofwords
//
#include <bits/stdc++.h>

using namespace std;

int main() {

    int l, w;
    scanf("%d %d", &l, &w);
    int currentValue = l;
    if (l > w || 26 * l < w) {
        printf("impossible\n");
    } else {
        string s(static_cast<size_t>(l), 'a');
        for (int i = 0; i < l; ++i) {
            while (s.at(i) < 'z') {
                if (currentValue == w) {
                    printf("%s\n", s.c_str());
                    return 0;
                }
                ++s.at(i);
                ++currentValue;
                if (currentValue == w) {
                    printf("%s\n", s.c_str());
                    return 0;
                }
            }
        }
    }
    return 0;
}
