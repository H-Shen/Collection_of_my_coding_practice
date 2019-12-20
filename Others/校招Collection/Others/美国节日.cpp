// https://www.nowcoder.com/practice/d95d98a2f96e49078cd7df84ba0c9d79

#include <cstdio>

int zellerFormula(int year, int month, int day) {

    if (month == 1 || month == 2) {
        year--;
        month += 12;
    }
    int c = year / 100;
    int y = year - c * 100;
    int week = 0;

    week = c / 4 - 2 * c + y + y / 4 + 13 * (month + 1) / 5 + day - 1;
    while (week < 0)
        week += 7;
    week %= 7;

    return week;
}

int main() {

    int year, counter, day;
    while (scanf("%d", &year) != EOF) {

        printf("%d-01-01\n", year);

        day = 1;
        counter = 0;
        while (counter != 3) {
            if (zellerFormula(year, 1, day) == 1)
                counter++;
            day++;
        }
        printf("%d-01-%02d\n", year, day - 1);

        day = 1;
        counter = 0;
        while (counter != 3) {
            if (zellerFormula(year, 2, day) == 1)
                counter++;
            day++;
        }
        printf("%d-02-%02d\n", year, day - 1);

        day = 31;
        counter = 0;
        while (counter != 1) {
            if (zellerFormula(year, 5, day) == 1)
                counter++;
            day--;
        }
        printf("%d-05-%02d\n", year, day + 1);

        printf("%d-07-04\n", year);

        day = 1;
        counter = 0;
        while (counter != 1) {
            if (zellerFormula(year, 9, day) == 1)
                counter++;
            day++;
        }
        printf("%d-09-%02d\n", year, day - 1);

        day = 1;
        counter = 0;
        while (counter != 4) {
            if (zellerFormula(year, 11, day) == 4)
                counter++;
            day++;
        }
        printf("%d-11-%02d\n", year, day - 1);

        printf("%d-12-25\n\n", year);
    }
    return 0;
}