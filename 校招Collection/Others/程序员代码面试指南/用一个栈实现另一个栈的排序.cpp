// https://www.nowcoder.com/practice/ff8cba64e7894c5582deafa54cca8ff2

#include <bits/stdc++.h>

using namespace std;

int main() {

    stack<int> start;
    stack<int> helper;
    int n, val;

    // input
    scanf("%d", &n);
    while (n--) {
        scanf("%d", &val);
        start.push(val);
    }
    while (!start.empty()) {
        val = start.top();
        start.pop();
        while (!helper.empty() && val > helper.top()) {
            start.push(helper.top());
            helper.pop();
        }
        helper.push(val);
    }
    while (!helper.empty()) {
        start.push(helper.top());
        helper.pop();
    }
    // output
    bool firstItem = true;
    while (!start.empty()) {
        if (firstItem) {
            firstItem = false;
        } else {
            printf(" ");
        }
        printf("%d", start.top());
        start.pop();
    }
    printf("\n");
    return 0;
}