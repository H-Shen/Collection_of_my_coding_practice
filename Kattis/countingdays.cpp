// https://open.kattis.com/problems/countingdays

#include "countingdays.h"

int day = 1;
int last = 0;

void lookAtClock(int hours, int minutes) {
    int temp = hours * 60 + minutes;
    if (temp < last) {
        ++day;
    }
    last = temp;
}

int getDay() {
    return day;
}
