// https://www.nowcoder.com/practice/839f681bf36c486fbcc5fcb977ffe432

#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

const int MAXN = 105;
char s[MAXN];

vector<string> List, List_copy;
vector<int> lenList, lenList_copy;

int main() {

    int n, i;
    string str;
    scanf("%d", &n);
    List.resize(n);
    lenList.resize(n);

    for (i = 0; i < n; i++) {
        scanf("%s", s);
        str = s;
        List[i] = str;
        lenList[i] = str.size();
    }

    List_copy = List;
    lenList_copy = lenList;

    sort(List.begin(), List.end());
    sort(lenList.begin(), lenList.end());

    bool b1 = false, b2 = false;
    if (List == List_copy)
        b1 = true;
    if (lenList == lenList_copy)
        b2 = true;

    if (b1 && b2)
        printf("both\n");
    else if (b1)
        printf("lexicographically\n");
    else if (b2)
        printf("lengths\n");
    else
        printf("none\n");

    return 0;
}