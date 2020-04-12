#include <bits/extc++.h>

using namespace std;

int main() {

    int n;
    vector<int> input;
    while (~scanf("%d", &n)) {
        input.emplace_back(n);
    }
    vector<char> A(input.front() * input.front());
    int counter;
    auto iter_A = A.begin();
    bool zero = true;
    for (size_t index = 1; index != input.size(); ++index) {
        counter = input.at(index);
        if (zero) {
            for (int i = 0; i < counter; ++i) {
                *iter_A = '0';
                ++iter_A;
            }
            zero = false;
        } else {
            for (int i = 0; i < counter; ++i) {
                *iter_A = '1';
                ++iter_A;
            }
            zero = true;
        }
    }

    vector<vector<char> > output(input.front(), vector<char>(input.front()));
    auto iter_c = A.cbegin();
    for (auto &i : output) {
        for (auto &j : i) {
            j = *iter_c;
            ++iter_c;
        }
    }

    // output
    for (const auto &i : output) {
        for (const auto &j : i) {
            printf("%c", j);
        }
        printf("\n");
    }
    return 0;
}