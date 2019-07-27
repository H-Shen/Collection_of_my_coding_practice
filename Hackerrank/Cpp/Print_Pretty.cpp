#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int T;
    cin >> T;
    cout << setiosflags(ios::uppercase);
    cout << setw(0xf) << internal;
    while (T--) {
        double A;
        cin >> A;
        double B;
        cin >> B;
        double C;
        cin >> C;

#include <string>
#include <cstdio>

        printf("0x%llx\n", (long long) A);

        char strB[100];
        sprintf(strB, "%.2f", B);
        string cstrB = strB;
        int gap = 15 - cstrB.size() - 1;
        for (int i = 0; i < gap; i++)
            printf("_");
        if (B < 0)
            printf("-%s\n", strB);
        else
            printf("+%s\n", strB);

        printf("%.9E\n", C);
    }
    return 0;

}