#include <cstdio>

using namespace std;
using ll = long long;

int counter;
int n;

int main() {

    int t;
    bool have_answer;
    scanf("%d", &t);
    while (t--) {
        int a = 1, b = 1; n = 1;
        scanf("%d", &counter);
        if (counter == 1) {
            printf("TERM 1 IS %d/%d\n", a, b);
            continue;
        }
        have_answer = false;
        ++b;
        for (; b >= 1; --b) {
            ++n;
            if (n == counter) {
                printf("TERM %d IS %d/%d\n", counter, a, b);
                have_answer = true;
                break;
            }
            ++a;
        }

        if (!have_answer) {
            while (true) {
                ++b;
                for (; a >= 1; --a) {
                    ++n;
                    if (n == counter) {
                        printf("TERM %d IS %d/%d\n", counter, a, b);
                        have_answer = true;
                        break;
                    }
                    ++b;
                }
                if (have_answer) {
                    break;
                }
                ++a;
                for (; b >= 1; --b) {
                    ++n;
                    if (n == counter) {
                        printf("TERM %d IS %d/%d\n", counter, a, b);
                        have_answer = true;
                        break;
                    }
                    ++a;
                }
                if (have_answer) {
                    break;
                }
            }
        }
    }

    return 0;
}