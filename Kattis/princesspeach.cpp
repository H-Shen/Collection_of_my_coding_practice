// https://open.kattis.com/problems/princesspeach
//
#include <bits/extc++.h>

using namespace std;

int main() {

    unordered_set<int> uniqObstacles;
    int N, Y, temp;
    scanf("%d %d", &N, &Y);
    for (int i = 0; i < Y; ++i) {
        scanf("%d", &temp);
        uniqObstacles.insert(temp);
    }
    for (int i = 0; i < N; ++i) {
        if (uniqObstacles.find(i) == uniqObstacles.end()) {
            printf("%d\n", i);
        }
    }
    printf("Mario got %lu of the dangerous obstacles.\n", uniqObstacles.size());

    return 0;
}
