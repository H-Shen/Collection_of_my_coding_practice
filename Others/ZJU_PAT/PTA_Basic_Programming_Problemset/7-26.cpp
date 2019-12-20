#include <cstdio>
#include <vector>

using namespace std;

const char DOT = '.';
const char SPACE = ' ';

int main() {

    vector<int> A;
    int length = 0;
    char ch;
    while (true) {
        scanf("%c", &ch);
        if (ch == DOT) {
            if (length != 0) {
                A.push_back(length);
            }
            break;
        } else if (ch == SPACE) {
            if (length != 0) {
                A.push_back(length);
                length = 0;
            }
        } else {
            ++length;
        }
    }

    bool firstItem = true;
    for (const auto &i : A) {
        if (firstItem) {
            printf("%d", i);
            firstItem = false;
        } else {
            printf(" %d", i);
        }
    }
    printf("\n");
    return 0;
}