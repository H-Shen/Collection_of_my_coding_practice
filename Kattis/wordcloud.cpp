// https://open.kattis.com/problems/wordcloud
//
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

constexpr int GAP = 10;

struct Word {
    string content;
    int freq;
    int height;
    int width;
};

inline static
int get_height(const Word &word, int max_occurrence) {
    int a = 40 * (word.freq - 4);
    int b = max_occurrence - 4;
    if (a % b == 0) {
        return 8 + a / b;
    }
    return 8 + (int)(a * 1.0 / b) + 1;
}

inline static
int get_width(const Word &word, int p) {
    int a = 9 * static_cast<int>(word.content.size()) * p;
    int b = 16;
    if (a % b == 0) {
        return a / b;
    }
    return (int)(a * 1.0 / b) + 1;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int w, n;
    int t = 1;
    int max_occurrence;
    while (cin >> w >> n) {
        max_occurrence = -1;
        if (w == 0 && n == 0) {
            break;
        }
        vector<Word> A(n);
        for (auto &i : A) {
            cin >> i.content >> i.freq;
            max_occurrence = max(max_occurrence, i.freq);
        }
        for (auto &i : A) {
            i.height = get_height(i, max_occurrence);
            i.width = get_width(i, i.height);
        }
        int current_width = 0;
        int current_height = -1;
        int total_height = 0;
        bool first_item = true;

        for (const auto &i : A) {
            if (first_item) {
                if (current_width + i.width > w) {
                    // Ignore
                } else {
                    first_item = false;
                    current_width += i.width;
                    current_height = max(current_height, i.height);
                }
            } else {
                if (current_width + GAP + i.width > w) {
                    // Jump to the next line
                    total_height += current_height;
                    current_width = i.width;
                    current_height = i.height;
                } else {
                    current_width += GAP + i.width;
                    current_height = max(current_height, i.height);
                }
            }
        }
        // Update the last row
        if (current_height > 0) {
            total_height += current_height;
        }
        cout << "CLOUD " << t << ": " << total_height << '\n';
        ++t;
    }

    return 0;
}
