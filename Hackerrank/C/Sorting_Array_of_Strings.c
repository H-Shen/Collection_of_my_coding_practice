#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define maxn 300
int freq[maxn];

int count_distinct(const char *s) {

    int count = 0;
    memset(freq, 0, sizeof(freq));


    for (int i = 0; s[i] != '\0'; ++i) {
        if (freq[(size_t) s[i]] == 0) {
            freq[(size_t) s[i]] = 1;
        }
    }

    for (int i = 0; i < maxn; ++i) {
        if (freq[i] != 0) {
            ++count;
        }
    }

    return count;
}

int count_len(const char *s) {
    int i = 0;
    for (; s[i] != '\0'; ++i);
    return i;
}

int lexicographic_sort(const char *a, const char *b) {
    return strcmp(a, b);
}

int lexicographic_sort_reverse(const char *a, const char *b) {
    return -lexicographic_sort(a, b);
}

int sort_by_number_of_distinct_characters(const char *a, const char *b) {
    int num_a = count_distinct(a);
    int num_b = count_distinct(b);
    if (num_a == num_b) {
        return lexicographic_sort(a, b);
    } else if (num_a < num_b) {
        return -1;
    }
    return 1;
}

int sort_by_length(const char *a, const char *b) {
    int len_a = count_len(a);
    int len_b = count_len(b);
    if (len_a == len_b) {
        return lexicographic_sort(a, b);
    } else if (len_a > len_b) {
        return 1;
    }
    return -1;
}

void string_sort(char **arr, const int len, int (*cmp_func)(const char *a, const char *b)) {
    int i, j;
    char *temp = NULL;
    for (i = 0; i < len - 1; ++i) {
        for (j = 0; j < len - 1 - i; ++j) {
            if (cmp_func(arr[j], arr[j + 1]) > 0) {
                // swap(arr[j], arr[j+1]
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);

    char **arr;
    arr = (char **) malloc(n * sizeof(char *));

    for (int i = 0; i < n; i++) {
        *(arr + i) = malloc(1024 * sizeof(char));
        scanf("%s", *(arr + i));
        *(arr + i) = realloc(*(arr + i), strlen(*(arr + i)) + 1);
    }

    string_sort(arr, n, lexicographic_sort);
    for (int i = 0; i < n; i++)
        printf("%s\n", arr[i]);
    printf("\n");

    string_sort(arr, n, lexicographic_sort_reverse);
    for (int i = 0; i < n; i++)
        printf("%s\n", arr[i]);
    printf("\n");

    string_sort(arr, n, sort_by_length);
    for (int i = 0; i < n; i++)
        printf("%s\n", arr[i]);
    printf("\n");

    string_sort(arr, n, sort_by_number_of_distinct_characters);
    for (int i = 0; i < n; i++)
        printf("%s\n", arr[i]);
    printf("\n");
}