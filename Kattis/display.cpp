// https://open.kattis.com/problems/display
//
#include <bits/stdc++.h>

using namespace std;
constexpr int MAXN = 10;
inline const vector<char> delimiter(7, ' ');
char input[MAXN];

unordered_map<char, vector<vector<char> > > number2Pixel;

inline static
vector<vector<char> > rotateRight(const vector<vector<char> > &s) {
    if (s.empty() || s.front().empty()) {
        return vector<vector<char> >();
    }
    vector<vector<char> > result(s.front().size(), vector<char>(s.size()));
    for (size_t i = 0; i != result.size(); ++i) {
        for (size_t j = 0; j != result.at(i).size(); ++j) {
            result.at(i).at(j) = s.at(s.size() - 1 - j).at(i);
        }
    }
    return result;
}

inline static
vector<vector<char> > rotateLeft(const vector<vector<char> > &s) {
    return rotateRight(rotateRight(rotateRight(s)));
}

inline static
vector<vector<char> > handle(const string &s) {
    vector<vector<char> > result;
    vector<char> line;
    for (const char &ch : s) {
        if (ch == '\n') {
            result.emplace_back(line);
            vector<char>().swap(line);
        } else {
            line.emplace_back(ch);
        }
    }
    result.emplace_back(line);
    result = rotateRight(result);
    return result;
}

inline static
void pre() {
    string s;
    vector<vector<char> > p;
    // zero
    s = "+---+\n"
        "|   |\n"
        "|   |\n"
        "+   +\n"
        "|   |\n"
        "|   |\n"
        "+---+";
    number2Pixel['0'] = handle(s);
    // one
    s = "    +\n"
        "    |\n"
        "    |\n"
        "    +\n"
        "    |\n"
        "    |\n"
        "    +";
    number2Pixel['1'] = handle(s);
    // two
    s = "+---+\n"
        "    |\n"
        "    |\n"
        "+---+\n"
        "|    \n"
        "|    \n"
        "+---+";
    number2Pixel['2'] = handle(s);
    // three
    s = "+---+\n"
        "    |\n"
        "    |\n"
        "+---+\n"
        "    |\n"
        "    |\n"
        "+---+";
    number2Pixel['3'] = handle(s);
    // four
    s = "+   +\n"
        "|   |\n"
        "|   |\n"
        "+---+\n"
        "    |\n"
        "    |\n"
        "    +";
    number2Pixel['4'] = handle(s);
    // five
    s = "+---+\n"
        "|    \n"
        "|    \n"
        "+---+\n"
        "    |\n"
        "    |\n"
        "+---+";
    number2Pixel['5'] = handle(s);
    // six
    s = "+---+\n"
        "|    \n"
        "|    \n"
        "+---+\n"
        "|   |\n"
        "|   |\n"
        "+---+";
    number2Pixel['6'] = handle(s);
    // seven
    s = "+---+\n"
        "    |\n"
        "    |\n"
        "    +\n"
        "    |\n"
        "    |\n"
        "    +";
    number2Pixel['7'] = handle(s);
    // eight
    s = "+---+\n"
        "|   |\n"
        "|   |\n"
        "+---+\n"
        "|   |\n"
        "|   |\n"
        "+---+";
    number2Pixel['8'] = handle(s);
    // nine
    s = "+---+\n"
        "|   |\n"
        "|   |\n"
        "+---+\n"
        "    |\n"
        "    |\n"
        "+---+";
    number2Pixel['9'] = handle(s);
    // the sign of delimiter
    s = "     \n"
        "     \n"
        "  o  \n"
        "     \n"
        "  o  \n"
        "     \n"
        "     ";
    number2Pixel[':'] = handle(s);
}

int main() {

    // pre
    pre();

    // input
    bool firstCase = true;
    while (true) {
        scanf("%s", input);

        if (firstCase) {
            firstCase = false;
        } else {
            printf("\n\n");
        }

        if (strcmp(input, "end") == 0) {
            printf("end\n");
            break;
        }
        vector<vector<char> > A;
        for (int i = 0; input[i] != '\0'; ++i) {
            auto p = number2Pixel[input[i]];
            A.insert(end(A), begin(p), end(p));
            if (isdigit(input[i]) && i != 1 && i != 4) {
                A.emplace_back(delimiter);
                A.emplace_back(delimiter);
            }
        }
        A = rotateLeft(A);

        // output
        for (const auto &i : A) {
            for (const auto &j : i) {
                printf("%c", j);
            }
            putchar('\n');
        }
    }

    return 0;
}
