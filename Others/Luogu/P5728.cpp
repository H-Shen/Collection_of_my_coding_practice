#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

struct Student {
    int chinese;
    int math;
    int english;
    int total;
};

int main() {
    
    int n;
    scanf("%d", &n);
    vector<Student> A(n);
    for (auto &i : A) {
        scanf("%d %d %d", &i.chinese, &i.math, &i.english);
        i.total = i.chinese + i.math + i.english;
    }
    int output = 0;
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (abs(A.at(i).chinese - A.at(j).chinese) <= 5 &&
                abs(A.at(i).math - A.at(j).math) <= 5 &&
                abs(A.at(i).english - A.at(j).english) <= 5 &&
                abs(A.at(i).total - A.at(j).total) <= 10) {
                ++output;
            }
        }
    }
    printf("%d\n", output);
    return 0;
}