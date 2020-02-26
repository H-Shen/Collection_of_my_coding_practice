#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

struct Student {
    int chinese;
    int math;
    int english;
    int total;
    int id;
};

int main() {

    int n;
    scanf("%d", &n);
    vector<Student> A(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d %d %d", &A.at(i).chinese, &A.at(i).math, &A.at(i).english);
        A.at(i).id = i + 1;
        A.at(i).total = A.at(i).chinese + A.at(i).math + A.at(i).english;
    }
    sort(A.begin(), A.end(), [](const Student &l, const Student &r){
        if (l.total == r.total) {
            if (l.chinese == r.chinese) {
                return l.id < r.id;
            }
            return l.chinese > r.chinese;
        }
        return l.total > r.total;
    });
    try {
        for (int i = 0; i < 5; ++i) {
            printf("%d %d\n", A.at(i).id, A.at(i).total);
        }
    } catch (...) {}


    return 0;
}
