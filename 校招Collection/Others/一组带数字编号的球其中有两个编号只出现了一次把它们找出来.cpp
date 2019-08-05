// https://www.nowcoder.com/practice/c3b49a12eb344ca3939f6a6232347397

#include <unordered_set>
#include <cstdio>

using namespace std;

unordered_set<int> occurOnce;

int main() {

    int val;
    while (~scanf("%d",&val)) {
        if (occurOnce.find(val) != occurOnce.end()) {
            occurOnce.erase(val);
        } else {
            occurOnce.insert(val);
        }
    }
    auto it = occurOnce.cbegin();
    int first = *(it++);
    int second = *it;
    if (first > second) {
        swap(first, second);
    }
    printf("%d %d\n", first, second);

    return 0;
}
