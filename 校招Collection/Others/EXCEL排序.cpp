// https://www.nowcoder.com/practice/bf3ec474bb7d410dbb9d5bbcd07a93e5

#include <bits/stdc++.h>

using namespace std;

struct student {
    char id[10];
    char name[10];
    int grade;
    int id_num;
};

int convert(char id[]) {
    int result = stoi(string(id));
    return result;
}

inline
bool cmp1(const student &a, const student &b) {
    return a.id_num < b.id_num;
}

inline
bool cmp2(const student &a, const student &b) {
    if (strcmp(a.name, b.name) != 0)
        return strcmp(a.name, b.name) < 0;
    return a.id_num < b.id_num;
}

inline
bool cmp3(const student &a, const student &b) {
    if (a.grade != b.grade)
        return a.grade < b.grade;
    return a.id_num < b.id_num;
}

student a[100005];

int main() {

    int n, c;

    while (~scanf("%d %d", &n, &c)) {

        if (n == 0) {
            break;
        }

        for (int i = 0; i < n; i++) {

            char id[10];
            char name[10];
            int grade;

            scanf("%s %s %d", id, name, &grade);
            strcpy(a[i].id, id);
            strcpy(a[i].name, name);
            a[i].grade = grade;
            a[i].id_num = convert(id);
        }

        if (c == 1)
            sort(a, a + n, cmp1);
        else if (c == 2)
            sort(a, a + n, cmp2);
        else
            sort(a, a + n, cmp3);

        printf("Case:\n");
        for (int i = 0; i < n; i++)
            printf("%s %s %d\n", a[i].id, a[i].name, a[i].grade);

        memset(a, 0, sizeof(student) * n);
    }
    return 0;
}