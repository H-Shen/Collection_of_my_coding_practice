#include <bits/stdc++.h>
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
constexpr int MAXN = 10;
char cstr[MAXN];

struct Student {
    string name;
    int a;
    int b;
    int c;
    int total;
    int idx;
};

int main() {
    
    int n;
    scanf("%d", &n);
    vector<Student> A(n);
    for (int i = 0; i < n; ++i) {
        scanf("%s %d %d %d", cstr, &A.at(i).a, &A.at(i).b, &A.at(i).c);
        A.at(i).name = cstr;
        A.at(i).total = A.at(i).a + A.at(i).b + A.at(i).c;
        A.at(i).idx = i;
    }
    auto temp = min_element(A.begin(), A.end(), [](const Student &lhs, const Student &rhs) {
        if (lhs.total == rhs.total) {
            return lhs.idx < rhs.idx;
        }
        return lhs.total > rhs.total;
    });
    printf("%s %d %d %d\n", temp->name.c_str(), temp->a, temp->b, temp->c);

    return 0;
}