#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
constexpr int MAXN = 30;
char cstr[MAXN];

struct Student {
    string name;
    int final;
    int assessment;
    string isOfficial;
    string west;
    int countOfEssay;
    int price = 0;
    int id;
};

int main() {

    int n;
    scanf("%d", &n);
    vector<Student> A(n);
    for (int i = 0; i < n; ++i) {
        scanf("%s", cstr);
        A.at(i).name = cstr;
        scanf("%d %d", &A.at(i).final, &A.at(i).assessment);
        scanf("%s", cstr);
        A.at(i).isOfficial = cstr;
        scanf("%s", cstr);
        A.at(i).west = cstr;
        scanf("%d", &A.at(i).countOfEssay);
        A.at(i).id = i;
    }
    int total = 0;
    for (auto &i : A) {
        if (i.final > 80 && i.countOfEssay > 0) {
            i.price += 8000;
        }
        if (i.final > 85 && i.assessment > 80) {
            i.price += 4000;
        }
        if (i.final > 90) {
            i.price += 2000;
        }
        if (i.final > 85 && i.west == "Y") {
            i.price += 1000;
        }
        if (i.assessment > 80 && i.isOfficial == "Y") {
            i.price += 850;
        }
        total += i.price;
    }
    auto max_val = *min_element(A.begin(), A.end(), [](const Student &l, const Student &r){
        if (l.price == r.price) {
            return l.id < r.id;
        }
        return l.price > r.price;
    });
    printf("%s\n%d\n%d\n", max_val.name.c_str(), max_val.price, total);


    return 0;
}
