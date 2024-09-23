// https://ac.nowcoder.com/acm/contest/343/A
// NOI_1997_竞赛排名

#include <bits/stdc++.h>

using namespace std;
constexpr int MAX_SUBJECT = 8;
constexpr double eps = 1e-8;

inline static
int sgn(const double &a) {
    if (a > eps) {
        return 1;
    }
    if (a > -eps) {
        return 0;
    }
    return -1;
}

struct Student {
    int id;
    int grade[MAX_SUBJECT];
    int sum = 0;
    double positionGrade[MAX_SUBJECT];
    double sumPositionGrade = 0.0;
};

double avg[MAX_SUBJECT];
double m[MAX_SUBJECT];

int main() {

    // input
    int n;
    scanf("%d", &n);
    vector<Student> A(static_cast<size_t>(n));
    for (int i = 0; i < n; ++i) {
        Student student;
        student.id = i + 1;
        for (int j = 0; j < MAX_SUBJECT; ++j) {
            scanf("%d", &student.grade[j]);
            student.sum += student.grade[j];
        }
        A[i] = student;
    }

    // calculate the avg
    for (int i = 0; i < MAX_SUBJECT; ++i) {
        for (int j = 0; j < n; ++j) {
            avg[i] += A[j].grade[i];
        }
        avg[i] /= n;
    }

    // calculate the positionGrade
    for (int i = 0; i < MAX_SUBJECT; ++i) {
        for (int j = 0; j < n; ++j) {
            m[i] += abs(A[j].grade[i] * 1.0 - avg[i]);
        }
        m[i] /= n;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < MAX_SUBJECT; ++j) {
            if (sgn(m[j]) == 0) {
                A[i].positionGrade[j] = 0.0;
            } else {
                A[i].positionGrade[j] = (A[i].grade[j] * 1.0 - avg[j]) / m[j];
            }
        }
        for (int j = 0; j < 3; ++j) {
            A[i].sumPositionGrade += A[i].positionGrade[j];
        }
        for (int j = 3; j < 8; ++j) {
            A[i].sumPositionGrade += A[i].positionGrade[j] * 0.8;
        }
    }

    sort(begin(A), end(A), [](const Student &lhs, const Student &rhs) {
        int tempVal = sgn(lhs.sumPositionGrade - rhs.sumPositionGrade);
        if (tempVal == 0) {
            if (lhs.sum == rhs.sum) {
                return (lhs.id < rhs.id);
            }
            return (lhs.sum > rhs.sum);
        }
        return (tempVal == 1);
    });
    for (const auto &i : A) {
        printf("%d\n", i.id);
    }

    return 0;
}
