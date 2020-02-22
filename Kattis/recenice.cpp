// https://open.kattis.com/problems/recenice
//
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

constexpr int MAXN = 60;
char cstr[MAXN];

unordered_map<int, string> number2string;

void pre() {
    number2string[0] = "zero";
    number2string[1] = "one";
    number2string[2] = "two";
    number2string[3] = "three";
    number2string[4] = "four";
    number2string[5] = "five";
    number2string[6] = "six";
    number2string[7] = "seven";
    number2string[8] = "eight";
    number2string[9] = "nine";
    number2string[10] = "ten";
    number2string[11] = "eleven";
    number2string[12] = "twelve";
    number2string[13] = "thirteen";
    number2string[14] = "fourteen";
    number2string[15] = "fifteen";
    number2string[16] = "sixteen";
    number2string[17] = "seventeen";
    number2string[18] = "eighteen";
    number2string[19] = "nineteen";
    number2string[20] = "twenty";
    number2string[30] = "thirty";
    number2string[40] = "forty";
    number2string[50] = "fifty";
    number2string[60] = "sixty";
    number2string[70] = "seventy";
    number2string[80] = "eighty";
    number2string[90] = "ninety";

    for (int i = 1; i <= 99; ++i) {
        if (number2string.find(i) == number2string.end()) {
            if (i >= 10) {
                int a = (i / 10) * 10;
                int b = i % 10;
                number2string[i] = number2string[a] + number2string[b];
            }
        }
    }
    for (int i = 100; i <= 999; ++i) {
        int a = i / 100;
        int b = i - a * 100;
        if (b == 0) {
            number2string[i] = number2string[a] + "hundred";
        } else {
            number2string[i] = number2string[a] + "hundred" + number2string[b];
        }
    }

}

int main() {

    pre();
    int n;
    scanf("%d", &n);
    int sum = 0;
    int pos = -1;
    vector<string> output(n);
    for (int i = 0; i < n; ++i) {
        scanf("%s", cstr);
        output.at(i) = cstr;
        if (strcmp(cstr, "$") != 0) {
            sum += strlen(cstr);
        } else {
            pos = i;
        }
    }

    // test
    for (int i = 1; i <= 999; ++i) {
        if (sum + static_cast<int>(number2string[i].size()) == i) {
            output.at(pos) = number2string[i];
            break;
        }
    }

    // output
    bool first_item = true;
    for (int i = 0; i < n; ++i) {
        if (first_item) {
            first_item = false;
        } else {
            printf(" ");
        }
        printf("%s", output.at(i).c_str());
    }
    printf("\n");

    return 0;
}
