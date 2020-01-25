// https://open.kattis.com/problems/teque
//
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
constexpr int MAXN = 20;
char op[MAXN];

struct Teque {
    deque<int> A;
    deque<int> B;
    int get(int i) {
        int length_A = static_cast<int>(A.size());
        if (i < length_A) {
            return A.at(i);
        }
        return B.at(i - length_A);
    }
    void push_front(int x) {
        A.push_front(x);
        balance();
    }
    void push_back(int x) {
        B.push_back(x);
        balance();
    }
    void push_middle(int x) {
        B.push_front(x);
        balance();
    }
    void balance() {
        int length_A = static_cast<int>(A.size());
        int length_B = static_cast<int>(B.size());
        if ((length_A + length_B) % 2 == 0) {
            // a | a
            while (length_A != length_B) {
                if (length_A > length_B) {
                    B.push_front(A.back());
                    A.pop_back();
                    ++length_B;
                    --length_A;
                }
                else {
                    A.push_back(B.front());
                    B.pop_front();
                    ++length_A;
                    --length_B;
                }
            }
        } else {
            // a | a-1
            while (length_A != length_B + 1) {
                if (length_A > length_B + 1) {
                    B.push_front(A.back());
                    A.pop_back();
                    ++length_B;
                    --length_A;
                } else {
                    A.push_back(B.front());
                    B.pop_front();
                    ++length_A;
                    --length_B;
                }
            }
        }
    }
};

int main() {

    int n, val;
    Teque T;
    scanf("%d", &n);
    while (n--) {
        scanf("%s %d", op, &val);
        if (strcmp(op, "push_back") == 0) {
            T.push_back(val);
        } else if (strcmp(op, "push_front") == 0) {
            T.push_front(val);
        } else if (strcmp(op, "push_middle") == 0) {
            T.push_middle(val);
        } else {
            printf("%d\n", T.get(val));
        }
    }


    return 0;
}
