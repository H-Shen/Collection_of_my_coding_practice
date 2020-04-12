#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
constexpr int MAXN = 10;

struct Person {
    int id;
    int D_id;
    int w;
};

int main() {

    int n, k;
    scanf("%d %d", &n, &k);
    vector<int> E(MAXN + 1);
    for (int i = 1; i <= MAXN; ++i) {
        scanf("%d", &E.at(i));
    }
    vector<Person> A(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &A.at(i).w);
        A.at(i).id = i + 1;
    }
    sort(A.begin(), A.end(), [](const Person &l, const Person &r){
        if (l.w == r.w) {
            return l.id < r.id;
        }
        return l.w > r.w;
    });
    for (int i = 0; i < n; ++i) {
        A.at(i).D_id = i + 1;
    }
    for (int i = 0; i < n; ++i) {
        A.at(i).w += E.at((A.at(i).D_id-1) % 10 + 1);
    }
    sort(A.begin(), A.end(), [](const Person &l, const Person &r){
        if (l.w == r.w) {
            return l.id < r.id;
        }
        return l.w > r.w;
    });
    bool first_item = true;
    for (int i = 0; i < k; ++i) {
        if (first_item) {
            first_item = false;
        } else {
            printf(" ");
        }
        printf("%d", A.at(i).id);
    }
    printf("\n");

    return 0;
}
