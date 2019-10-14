// https://open.kattis.com/problems/okviri
//
#include <bits/stdc++.h>

using namespace std;
constexpr int maxn = 20;
char s[maxn];

int main() {

    scanf("%s", s);
    vector<string> output;
    bool useWendyFrame = false;
    int counter = 1;
    for (int i = 0; s[i] != '\0'; ++i) {
        if (counter == 3) {
            useWendyFrame = true;
            counter = 1;
        } else {
            useWendyFrame = false;
        }
        if (useWendyFrame) {
            output.emplace_back("..*..");
            output.emplace_back(".*.*.");
            output.emplace_back(string("*.") + s[i] + string(".*"));
            output.emplace_back(".*.*.");
        } else {
            output.emplace_back("..#..");
            output.emplace_back(".#.#.");
            output.emplace_back(string("#.") + s[i] + string(".#"));
            output.emplace_back(".#.#.");
            ++counter;
        }
    }
    if (useWendyFrame) {
        output.emplace_back("..*..");
    } else {
        output.emplace_back("..#..");
    }

    try {
        for (size_t i = 8; i < output.size(); i += 12) {
            if (i != output.size() - 1) {
                output.at(i).at(2) = '*';
            }
            if (i + 4 != output.size() - 1) {
                output.at(i + 4).at(2) = '*';
            }
        }
    } catch (...) {

    }

    // output
    int col = static_cast<int>(output.front().size());
    int row = static_cast<int>(output.size());
    for (int i = col - 1; i >= 0; --i) {
        for (int j = 0; j < row; ++j) {
            printf("%c", output.at(j).at(i));
        }
        putchar('\n');
    }

    return 0;
}
