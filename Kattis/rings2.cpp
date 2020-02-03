// https://open.kattis.com/problems/rings2
//
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

int main() {

    int r, c;
    scanf("%d %d", &r, &c);
    deque<deque<char> > A(r, deque<char>(c));
    getchar();
    int counter_of_grid_square = 0;
    for (auto &i : A) {
        for (auto &j : i) {
            scanf("%c", &j);
            if (j == 'T') {
                ++counter_of_grid_square;
            }
        }
        getchar();
    }
    // add boundaries
    for (auto &i : A) {
        i.push_front('.');
        i.push_back('.');
    }
    A.push_front(deque<char>(c + 2, '.'));
    A.emplace_back(deque<char>(c + 2, '.'));

    char current = '1';
    for (int i = 0; i < r + 2; ++i) {
        for (int j = 0; j < c + 2; ++j) {
            if (A.at(i).at(j) == '.') {
                try {
                    if (A.at(i - 1).at(j) == 'T') {
                        A.at(i - 1).at(j) = current;
                        --counter_of_grid_square;
                    }
                } catch (...) {}
                try {
                    if (A.at(i + 1).at(j) == 'T') {
                        A.at(i + 1).at(j) = current;
                        --counter_of_grid_square;
                    }
                } catch (...) {}
                try {
                    if (A.at(i).at(j - 1) == 'T') {
                        A.at(i).at(j - 1) = current;
                        --counter_of_grid_square;
                    }
                } catch (...) {}
                try {
                    if (A.at(i).at(j + 1) == 'T') {
                        A.at(i).at(j + 1) = current;
                        --counter_of_grid_square;
                    }
                } catch (...) {}
            }
        }
    }

    int max_current = static_cast<int>(current);
    while (counter_of_grid_square > 0) {
        for (int i = 0; i < r + 2; ++i) {
            for (int j = 0; j < c + 2; ++j) {
                if (A.at(i).at(j) == current) {
                    try {
                        if (A.at(i - 1).at(j) == 'T') {
                            A.at(i - 1).at(j) = current + 1;
                            --counter_of_grid_square;
                        }
                    } catch (...) {}
                    try {
                        if (A.at(i + 1).at(j) == 'T') {
                            A.at(i + 1).at(j) = current + 1;
                            --counter_of_grid_square;
                        }
                    } catch (...) {}
                    try {
                        if (A.at(i).at(j - 1) == 'T') {
                            A.at(i).at(j - 1) = current + 1;
                            --counter_of_grid_square;
                        }
                    } catch (...) {}
                    try {
                        if (A.at(i).at(j + 1) == 'T') {
                            A.at(i).at(j + 1) = current + 1;
                            --counter_of_grid_square;
                        }
                    } catch (...) {}
                }
            }
        }
        ++current;
        max_current = max(max_current, static_cast<int>(current));
    }

    // shrink
    A.pop_front();
    A.pop_back();
    for (auto &i : A) {
        i.pop_front();
        i.pop_back();
    }

    int space = 0;
    if (max_current <= 57) {
        space = 1;
    } else {
        space = 2;
    }

    auto convert = [&](const char &ch)->string {
        if (ch == '.') {
            if (space == 1) {
                return "..";
            } else {
                return "...";
            }
        }
        int temp = static_cast<int>(ch - 48);
        string s = to_string(temp);
        if (space == 1) {
            while (s.size() < 2) {
                s = "." + s;
            }
        } else {
            while (s.size() < 3) {
                s = "." + s;
            }
        }
        return s;
    };

    deque<deque<string> > output(r, deque<string>(c));
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            output.at(i).at(j) = convert(A.at(i).at(j));
        }
    }
    // output
    for (const auto &i : output) {
        for (const auto &j : i) {
            printf("%s", j.c_str());
        }
        printf("\n");
    }
    printf("\n");

    return 0;
}
