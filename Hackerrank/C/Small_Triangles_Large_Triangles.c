#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct triangle
{
	int a;
	int b;
	int c;
};

typedef struct triangle triangle;

int cmp(const void *s1, const void *s2) {
    triangle *e1 = (triangle *) s1;
    triangle *e2 = (triangle *) s2;

    int e1_area = (e1->a + e1->b + e1->c) *
                  (e1->a + e1->b - e1->c) *
                  (e1->a + e1->c - e1->b) *
                  (e1->b + e1->c - e1->a);

    int e2_area = (e2->a + e2->b + e2->c) *
                  (e2->a + e2->b - e2->c) *
                  (e2->a + e2->c - e2->b) *
                  (e2->b + e2->c - e2->a);

    if (e1_area > e2_area) {
        return 1;
    } else if (e1_area == e2_area) {
        return 0;
    }
    return -1;
}

void sort_by_area(triangle* tr, int n) {
	/**
	* Sort an array a of the length n
	*/
    qsort(tr, n, sizeof(triangle), cmp);
}

int main()