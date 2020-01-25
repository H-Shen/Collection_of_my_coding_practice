// https://open.kattis.com/problems/sort
//
#include <bits/extc++.h>

using namespace std;

struct Stats {
    int number;
    int freq = 0;
    int indexOfFirstOccurrence;
};

unordered_map<int, Stats> A;

int main() {

    int N, C, val;
    scanf("%d %d", &N, &C);
    for (int i = 0; i < N; ++i) {
        scanf("%d", &val);
        if (A.find(val) != A.end()) {
            ++A[val].freq;
        } else {
            A[val].number = val;
            ++A[val].freq;
            A[val].indexOfFirstOccurrence = i;
        }
    }
    vector<Stats> output;
    for (const auto &it : A) {
        output.emplace_back(it.second);
    }
    sort(begin(output), end(output), [](const Stats& lhs, const Stats& rhs) {
        if (lhs.freq == rhs.freq) {
            return (lhs.indexOfFirstOccurrence < rhs.indexOfFirstOccurrence);
        }
        return (lhs.freq > rhs.freq);
    });
    bool firstItem = true;
    for (const auto &i : output) {
        for (int j = 0; j < i.freq; ++j) {
            if (firstItem) {
                firstItem = false;
            } else {
                printf(" ");
            }
            printf("%d", i.number);
        }
    }
    putchar('\n');

    return 0;
}
