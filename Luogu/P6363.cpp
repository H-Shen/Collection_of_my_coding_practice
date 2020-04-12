#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

constexpr int GAP = 15;
constexpr int MAXN = 3;
char team_name[MAXN];

inline static
int sgn(const double &x) {
    constexpr double EPS = 1e-7;
    if (x > EPS) return 1;
    if (x > -EPS) return 0;
    return -1;
}

struct Student {
    char team;
    int individual_grade;
    int team_grade;
    int final_grade;
};
unordered_map<char, vector<int> > Grades;
unordered_map<char, int> Avg;

int main() {

    int n, k, grade;
    scanf("%d %d", &n, &k);
    vector<Student> A(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d %s", &A.at(i).individual_grade, team_name);
        A.at(i).team = team_name[0];
    }
    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < k; ++j) {
            scanf("%d", &grade);
            Grades['A' + j].emplace_back(grade);
        }
    }
    for (const auto &[k, v] : Grades) {
        double avg = 0.0;
        for (const auto &i : v) {
            avg += i;
        }
        int length = static_cast<int>(v.size());
        avg /= length;
        double avg_ = 0.0;
        int counter = 0;
        for (const auto &i : v) {
            if ( sgn( abs(i - avg) - GAP ) <= 0 ) {
                avg_ += i;
                ++counter;
            }
        }
        avg_ /= counter;
        Avg[k] = static_cast<int>(lround(avg_));
    }
    double temp;
    for (auto &i : A) {
        i.team_grade = Avg[i.team];
        temp = i.individual_grade * 0.6 + i.team_grade * 0.4;
        i.final_grade = static_cast<int>(lround(temp));
    }
    sort(A.begin(), A.end(), [](const Student &l, const Student &r){
        if (l.final_grade == r.final_grade) {
            return (l.team < r.team);
        }
        return (l.final_grade > r.final_grade);
    });
    for (const auto &i : A) {
        printf("%d %c\n", i.final_grade, i.team);
    }

    return 0;
}