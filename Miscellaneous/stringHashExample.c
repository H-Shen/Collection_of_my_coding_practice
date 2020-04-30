// String hash example in Linux
// Insert n strings into the hashtable and count the number of unique strings
//
#include <stdio.h>
#include <search.h>
#include <string.h>

#define MAX_ELEMENTS 10005
#define MAX_STRING_LENGTH 1505

char s[MAX_STRING_LENGTH];

int main() {

    ENTRY item;
    ENTRY *found_item;
    hcreate(MAX_ELEMENTS);
    int counter = 0;
    int n;
    scanf("%d", &n);
    while (n--) {
        scanf("%s", s);
        item.key = s;
        item.data = NULL;
        if ((found_item = hsearch(item, FIND)) == NULL) {
            ++counter;
            hsearch(item, ENTER);
        }
    }
    printf("%d\n", counter);

    return 0;
}
