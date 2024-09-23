#include <bits/stdc++.h>

using namespace std;
constexpr int MAXN = 15;
char name[MAXN], id[MAXN];

struct Student {
    string name;
    string id;
    int grade;
};

bool cmp(const Student &a, const Student &b) {
    return (a.grade > b.grade);
}

int main() {
    int n, i, j;
    scanf("%d", &n);
    getchar();

    vector<Student> A(n);
    for (i = 0; i < n; ++i) {
        scanf("%s %s %d", name, id, &A[i].grade);
        A[i].name = name;
        A[i].id = id;
    }

    int minGrade, maxGrade;
    scanf("%d %d", &minGrade, &maxGrade);
    if (minGrade > maxGrade) {
        swap(minGrade, maxGrade);
    }

    vector<Student> filter(n);
    for (i = 0, j = 0; i < n; ++i) {
        if (A[i].grade >= minGrade && A[i].grade <= maxGrade) {
            filter[j++] = A[i];
        }
    }
    if (j != 0) {
        filter.resize(j);
        sort(filter.begin(), filter.end(), cmp);
        for (i = 0; i < j; ++i) {
            printf("%s %s\n", filter[i].name.c_str(), filter[i].id.c_str());
        }
    } else {
        printf("NONE\n");
    }
    return 0;
}