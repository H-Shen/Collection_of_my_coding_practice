// https://open.kattis.com/problems/officespace
//
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
constexpr int MAXN = 30;
char name[MAXN];

struct Unit {
    vector<string> names;
};

int main() {

    int w, h, n, x1, x2, y1, y2;
    while (~scanf("%d %d", &w, &h)) {
        vector<vector<Unit> > A(h, vector<Unit>(w));
        scanf("%d", &n);
        vector<string> names(n);
        unordered_map<string, int> name2space;
        for (int i = 0; i < n; ++i) {
            scanf("%s %d %d %d %d", name, &x1, &y1, &x2, &y2);
            names.at(i) = name;
            name2space[name] = 0;
            for (int j = y1; j < y2; ++j) {
                for (int k = x1; k < x2; ++k) {
                    A.at(j).at(k).names.emplace_back(name);
                }
            }
        }
        // stats
        int unallocated = 0;
        int contested = 0;
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                if (A.at(i).at(j).names.empty()) {
                    ++unallocated;
                } else if (A.at(i).at(j).names.size() > 1) {
                    ++contested;
                } else {
                    ++name2space[A.at(i).at(j).names.front()];
                }
            }
        }
        // output
        printf("Total %d\n", w * h);
        printf("Unallocated %d\n", unallocated);
        printf("Contested %d\n", contested);
        for (const auto &i : names) {
            if (name2space.find(i) == name2space.end()) {
                printf("%s 0\n", i.c_str());
            } else {
                printf("%s %d\n", i.c_str(), name2space[i]);
            }
        }
        printf("\n");
    }

    return 0;
}
