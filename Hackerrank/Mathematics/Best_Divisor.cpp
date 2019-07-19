#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

const int maxn = 100005, gap = 48;

struct save {
  vector <int> A;
};

save sum[maxn];

int digitSum(const int &n) {
    string s = to_string(n);
    int res = 0;
    for (auto i : s) {
        res = res + (int)(i - gap);
    }
    return res;
}

bool cmpDigitSum(const int &a, const int &b) {
    return (digitSum(a) < digitSum(b));
}

int main() {

    for(int i = 1; i < maxn; i++)
        for(int j = 1; i * j < maxn; j++)
            sum[i * j].A.emplace_back(i);

    int a;
    scanf("%d", &a);
    printf("%d\n", *max_element(sum[a].A.begin(), sum[a].A.end(), cmpDigitSum));
    return 0;
}
