// https://www.nowcoder.com/practice/5cb47b86911c4aa48722e531a51ec823

#include <bits/stdc++.h>

using namespace std;

int main() {

    int m, n, val;
    scanf("%d", &m);
    while (m--) {
        scanf("%d", &n);
        vector<int> A(static_cast<unsigned long>(n));
        for (auto &&i : A) {
            scanf("%d", &i);
        }
        unordered_set<int> allUniqElements(A.begin(), A.end());
        map<int, map<int, int> > B;
        for (int i = 0; i < n; ++i) {
            scanf("%d", &val);
            ++B[val][A[i]];
        }

        for (const auto &it : B) {
            for (const int &element : allUniqElements) {
                if (it.second.find(element) == it.second.end()) {
                    B[it.first][element] = 0;
                }
            }
        }

        // output
        bool firstItem;
        for (const auto &it : B) {
            printf("%d={", it.first);
            firstItem = true;
            for (const auto &it1 : it.second) {
                if (firstItem) {
                    firstItem = false;
                } else {
                    printf(",");
                }
                printf("%d=%d", it1.first, it1.second);
            }
            printf("}\n");
        }
    }
    return 0;
}