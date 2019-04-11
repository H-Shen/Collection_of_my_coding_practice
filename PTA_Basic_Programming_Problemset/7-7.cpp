#include <cstdio>

const int convert = 12;

int main() {
    char *s = nullptr;
    int hour, minute;
    scanf("%d:%d", &hour, &minute);

    if (hour > 12) {
        hour %= convert;
        s = "PM";
    } else if (hour == 12) {
        s = "PM";
    } else {
        s = "AM";
    }

    printf("%d:%d %s\n", hour, minute, s);

    return 0;
}