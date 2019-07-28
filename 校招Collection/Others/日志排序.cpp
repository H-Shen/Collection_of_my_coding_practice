// https://www.nowcoder.com/practice/0f64518fea254c0187ccf0ea05019672

#include <algorithm>
#include <string>
#include <vector>
#include <cstdio>
#include <sstream>

using namespace std;

const int MAX = 100, MAXITEM = 10005;
char str[MAX];

struct Task {

    //LAP
    int lap0, lap1;

    //TIME
    int hour, minute, second;

    //DATE
    int year, month, day;

    //NAME
    string name;

    //STRINGSAVE
    string stringSave;
};

Task TaskList[MAXITEM];
int TaskListLen = 0;

bool cmp(const Task &A, const Task &B) {

    if (A.lap0 == B.lap0) {
        if (A.lap1 == B.lap1) {
            if (A.year == B.year) {
                if (A.month == B.month) {
                    if (A.day == B.day) {
                        if (A.hour == B.hour) {

                            if (A.minute == B.minute) {
                                return (A.second < B.second);
                            }
                            return (A.minute < B.minute);
                        }
                        return (A.hour < B.hour);
                    }
                    return (A.day < B.day);
                }
                return (A.month < B.month);
            }
            return (A.year < B.year);
        }
        return (A.lap1 < B.lap1);
    }
    return (A.lap0 < B.lap0);
}

int main() {

    while (~scanf("%[^\n]", str)) {

        //INITIALIZE
        string s, date, taskTime, lap, subStr;
        int i;

        //INPUT
        s = str;
        getchar();

        //SPLIT
        vector<string> res(4);
        istringstream f(s);
        subStr = "";
        i = 0;
        while (getline(f, subStr, ' ')) {
            if (subStr != "") {
                res[i++] = subStr;
            }
        }

        Task tmp;
        //NAME
        tmp.name = res[0];

        //STRINGSAVE
        tmp.stringSave = s;

        //DATE
        vector<int> res_date(3);
        istringstream f0(res[1]);
        subStr = "";
        i = 0;
        while (getline(f0, subStr, '-')) {
            res_date[i++] = stoi(subStr);
        }
        tmp.year = res_date[0];
        tmp.month = res_date[1];
        tmp.day = res_date[2];

        //TIME
        res[2].erase(res[2].find(","), 1);
        vector<int> res_time(3);
        istringstream f1(res[2]);
        subStr = "";
        i = 0;
        while (getline(f1, subStr, ':')) {
            res_time[i++] = stoi(subStr);
        }
        tmp.hour = res_time[0];
        tmp.minute = res_time[1];
        tmp.second = res_time[2];

        //LAP
        res[3].erase(res[3].find("("), 3);
        vector<int> res_lap(2);
        istringstream f2(res[3]);
        subStr = "";
        i = 0;
        while (getline(f2, subStr, '.')) {
            res_lap[i++] = stoi(subStr);
        }
        tmp.lap0 = res_lap[0];
        tmp.lap1 = res_lap[1];

        TaskList[TaskListLen++] = tmp;
    }

    //SORT
    sort(TaskList, TaskList + TaskListLen, cmp);

    //OUTPUT
    for (int i = 0; i < TaskListLen; i++) {
        printf("%s\n", TaskList[i].stringSave.c_str());
    }
    return 0;
}