// https://www.nowcoder.com/practice/2bd6542951ba48b0b49178f090e1e22f

#include <stdio.h>

float list[7];
char name[30];

int main(void) {
    while (scanf("%f %f %f %f %f %f %f %s", &list[0], &list[1], &list[2], &list[3], &list[4], &list[5], &list[6],
                 name) != EOF) {
        float min = list[0], max = list[0];
        float sum = 0.0;
        int i;
        for (i = 0; i < 7; ++i) {
            sum += list[i];
            if (min > list[i])
                min = list[i];
            if (max < list[i])
                max = list[i];
        }
        sum = sum - min - max;
        printf("%s %.2f\n", name, sum / 5);

    }
    return 0;
}
