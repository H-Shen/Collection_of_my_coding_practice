#include <bits/stdc++.h>

using namespace std;

struct Student {
    string Id;
    int grade;

    Student(const string &studentId, const int &studentGrade) :
            Id(studentId), grade(studentGrade) {}
};

// stats of students with the lecture number
struct Stats0 {
    int studentNumber = 0;
    int totalGrade = 0;
};

const int MAXN = 20;
const char NOT_EXIST[] = "NA";
char s[MAXN];

vector<Student> LevelA;
vector<Student> LevelB;
vector<Student> LevelT;
bool isLevelASorted = false;
bool isLevelBSorted = false;
bool isLevelTSorted = false;
unordered_map<string, Stats0> lectureNumberStats;

// compare func for command1
bool cmp1(const Student &a, const Student &b) {
    if (a.grade == b.grade) {
        return (a.Id < b.Id);
    }
    return (a.grade > b.grade);
}

void command1(char level) {
    bool haveAns = false;
    switch (level) {
        case 'A':
            if (!isLevelASorted) {
                sort(LevelA.begin(), LevelA.end(), cmp1);
                isLevelASorted = true;
            }
            for (const Student &i : LevelA) {
                haveAns = true;
                printf("%s %d\n", i.Id.c_str(), i.grade);
            }
            break;
        case 'B':
            if (!isLevelBSorted) {
                sort(LevelB.begin(), LevelB.end(), cmp1);
                isLevelBSorted = true;
            }
            for (const Student &i : LevelB) {
                haveAns = true;
                printf("%s %d\n", i.Id.c_str(), i.grade);
            }
            break;
        case 'T':
            if (!isLevelTSorted) {
                sort(LevelT.begin(), LevelT.end(), cmp1);
                isLevelTSorted = true;
            }
            for (const Student &i : LevelT) {
                haveAns = true;
                printf("%s %d\n", i.Id.c_str(), i.grade);
            }
            break;
        default:
            break;
    }
    if (!haveAns) {
        printf("%s\n", NOT_EXIST);
    }
}

void command2(const string &lectureNumber) {
    if (lectureNumberStats.find(lectureNumber) != lectureNumberStats.end()) {
        printf("%d %d\n",
               lectureNumberStats[lectureNumber].studentNumber,
               lectureNumberStats[lectureNumber].totalGrade);
    } else {
        printf("%s\n", NOT_EXIST);
    }
}

struct myPair {
    string lectureNumber;
    int studentNumber = 0;
};

// stats of students with the same date of the exam
unordered_map<string, unordered_map<string, int> > examDateStats;
unordered_map<string, bool> examDateStatsSortedFlag;
unordered_map<string, vector<myPair> > examDateSortList;

// compare func for command3
bool cmp2(const myPair &a, const myPair &b) {
    if (a.studentNumber == b.studentNumber) {
        return (a.lectureNumber < b.lectureNumber);
    }
    return (a.studentNumber > b.studentNumber);
}

void command3(const string &examDate) {
    if (examDateStats.find(examDate) != examDateStats.end()) {
        if (!examDateStatsSortedFlag[examDate]) {

            // add elements to examDateSortList
            examDateSortList[examDate].resize(examDateStats[examDate].size());
            size_t index = 0;
            for (const auto &it : examDateStats[examDate]) {
                examDateSortList[examDate][index].lectureNumber = it.first;
                examDateSortList[examDate][index].studentNumber = it.second;
                ++index;
            }

            sort(examDateSortList[examDate].begin(), examDateSortList[examDate].end(), cmp2);
            examDateStatsSortedFlag[examDate] = true;
        }
        for (const myPair &i : examDateSortList[examDate]) {
            printf("%s %d\n", i.lectureNumber.c_str(), i.studentNumber);
        }
    } else {
        printf("%s\n", NOT_EXIST);
    }
}

int main() {

    int N, M, grade;
    string examDate;
    string lectureNumber;
    scanf("%d %d", &N, &M);

    for (int i = 0; i < N; ++i) {

        // input
        scanf("%s %d", s, &grade);
        Student temp(s, grade);

        // stats of 3 levels
        switch (s[0]) {
            case 'A':
                LevelA.push_back(temp);
                break;
            case 'B':
                LevelB.push_back(temp);
                break;
            default:
                LevelT.push_back(temp);
                break;
        }

        // stats of lectureNumberStats
        lectureNumber = temp.Id.substr(1, 3);
        ++lectureNumberStats[lectureNumber].studentNumber;
        lectureNumberStats[lectureNumber].totalGrade += grade;

        // stats of examDate
        examDate = temp.Id.substr(4, 6);
        examDateStatsSortedFlag[examDate] = false;
        ++examDateStats[examDate][lectureNumber];
    }

    int query;
    for (int i = 1; i <= M; ++i) {
        scanf("%d %s", &query, s);
        printf("Case %d: %d %s\n", i, query, s);

        switch (query) {
            case 1:
                command1(s[0]);
                break;
            case 2:
                command2(s);
                break;
            case 3:
                command3(s);
                break;
            default:
                printf("%s\n", NOT_EXIST);
        }
    }

    return 0;
}
