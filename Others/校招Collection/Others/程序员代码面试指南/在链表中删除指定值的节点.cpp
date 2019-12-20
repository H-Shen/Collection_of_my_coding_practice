// https://www.nowcoder.com/practice/1a5fd679e31f4145a10d46bb8fd3d211

#include <bits/stdc++.h>

using namespace std;

forward_list<int> A;

int main() {

    int n, val;
    scanf("%d", &n);
    auto it = A.before_begin();
    for (int i = 0; i < n; ++i) {
        scanf("%d", &val);
        it = A.emplace_after(it, val);
    }
    scanf("%d", &val);
    A.remove(val);
    bool firstItem = true;
    for (const int &i : A) {
        if (firstItem) {
            firstItem = false;
        } else {
            printf(" ");
        }
        printf("%d", i);
    }
    return 0;
}