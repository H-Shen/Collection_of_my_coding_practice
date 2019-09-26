// https://open.kattis.com/problems/jollyjumpers
//
#include <bits/stdc++.h>

using namespace std;

vector<int> vis;

int main() {

    int n, currentAbs, currentVal, lastVal;
    while (~scanf("%d", &n)) {
        if (n == 1) {
            printf("Jolly\n");
            scanf("%d", &currentVal);
        } else {
            vector<int>().swap(vis);
            vis.resize(n);
            bool noJolly = false;
            scanf("%d", &lastVal);
            for (int i = 1; i < n; ++i) {
                scanf("%d", &currentVal);
                currentAbs = abs(currentVal - lastVal);

                // if the abs not in the valid range
                if (currentAbs == 0 || currentAbs > n - 1) {
                    noJolly = true;
                }
                // if the abs is in the valid range
                else {
                    // if the abs occurred before
                    if (vis[currentAbs] == -1) {
                        noJolly = true;;
                    }
                        // if the abs didnt occur before
                    else {
                        vis[currentAbs] = -1;
                    }
                }
                lastVal = currentVal;
            }
            if (!noJolly) {
                // re-check if all numbers from 1 to n-1 is visited
                for (int i = 1; i <= n - 1; ++i) {
                    if (vis[i] != -1) {
                        noJolly = true;
                        break;
                    }
                }
            }
            if (noJolly) {
                printf("Not jolly\n");
            } else {
                printf("Jolly\n");
            }
        }
    }

    return 0;
}
