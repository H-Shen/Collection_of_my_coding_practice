// https://open.kattis.com/problems/asciiaddition
//
#include <bits/extc++.h>

using namespace std;
constexpr int MAX_LINE = 7;
constexpr int GAP = 5;

unordered_map<string, char> pixel2Number;
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
string convertToString(const vector<vector<char> > &s) {
    string result;
    for (size_t i = 0; i != s.size(); ++i) {
        for (size_t j = 0; j != s.at(i).size(); ++j) {
            result.push_back(s.at(i).at(j));
        }
        result.push_back('\n');
    }
    return result;
}

inline static
vector<vector<char> > handle(const string& s) {
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
    s = "xxxxx\n"
        "x...x\n"
        "x...x\n"
        "x...x\n"
        "x...x\n"
        "x...x\n"
        "xxxxx";
    pixel2Number[convertToString(handle(s))] = '0';
    number2Pixel['0'] = handle(s);
    // one
    s = "....x\n"
        "....x\n"
        "....x\n"
        "....x\n"
        "....x\n"
        "....x\n"
        "....x";
    pixel2Number[convertToString(handle(s))] = '1';
    number2Pixel['1'] = handle(s);
    // two
    s = "xxxxx\n"
        "....x\n"
        "....x\n"
        "xxxxx\n"
        "x....\n"
        "x....\n"
        "xxxxx";
    pixel2Number[convertToString(handle(s))] = '2';
    number2Pixel['2'] = handle(s);
    // three
    s = "xxxxx\n"
        "....x\n"
        "....x\n"
        "xxxxx\n"
        "....x\n"
        "....x\n"
        "xxxxx";
    pixel2Number[convertToString(handle(s))] = '3';
    number2Pixel['3'] = handle(s);
    // four
    s = "x...x\n"
        "x...x\n"
        "x...x\n"
        "xxxxx\n"
        "....x\n"
        "....x\n"
        "....x";
    pixel2Number[convertToString(handle(s))] = '4';
    number2Pixel['4'] = handle(s);
    // five
    s = "xxxxx\n"
        "x....\n"
        "x....\n"
        "xxxxx\n"
        "....x\n"
        "....x\n"
        "xxxxx";
    pixel2Number[convertToString(handle(s))] = '5';
    number2Pixel['5'] = handle(s);
    // six
    s = "xxxxx\n"
        "x....\n"
        "x....\n"
        "xxxxx\n"
        "x...x\n"
        "x...x\n"
        "xxxxx";
    pixel2Number[convertToString(handle(s))] = '6';
    number2Pixel['6'] = handle(s);
    // seven
    s = "xxxxx\n"
        "....x\n"
        "....x\n"
        "....x\n"
        "....x\n"
        "....x\n"
        "....x";
    pixel2Number[convertToString(handle(s))] = '7';
    number2Pixel['7'] = handle(s);
    // eight
    s = "xxxxx\n"
        "x...x\n"
        "x...x\n"
        "xxxxx\n"
        "x...x\n"
        "x...x\n"
        "xxxxx";
    pixel2Number[convertToString(handle(s))] = '8';
    number2Pixel['8'] = handle(s);
    // nine
    s = "xxxxx\n"
        "x...x\n"
        "x...x\n"
        "xxxxx\n"
        "....x\n"
        "....x\n"
        "xxxxx";
    pixel2Number[convertToString(handle(s))] = '9';
    number2Pixel['9'] = handle(s);
    // the sign of addition
    s = ".....\n"
        "..x..\n"
        "..x..\n"
        "xxxxx\n"
        "..x..\n"
        "..x..\n"
        ".....";
    pixel2Number[convertToString(handle(s))] = '+';
}

int main() {

    ios_base::sync_with_stdio(false);

    // pre
    pre();

    // input
    vector<vector<char> > input;
    string s;
    for (int i = 0; i < MAX_LINE; ++i) {
        cin >> s;
        vector<char> inputALine;
        for (const char &ch : s) {
            inputALine.emplace_back(ch);
        }
        input.emplace_back(inputALine);
    }
    input = rotateRight(input);

    int counter = 0;
    string parse;
    bool ignoreThisLine = false;
    bool changeOperator = false;
    string a;
    string b;

    for (const auto &i : input) {
        if (ignoreThisLine) {
            ignoreThisLine = false;
            continue;
        }
        for (const auto &j : i) {
            parse.push_back(j);
        }
        parse.push_back('\n');
        ++counter;
        if (counter == GAP) {

            if (pixel2Number[parse] == '+') {
                changeOperator = true;
            } else if (changeOperator)  {
                b.push_back(pixel2Number[parse]);
            } else {
                a.push_back(pixel2Number[parse]);
            }

            counter = 0;
            parse = "";
            ignoreThisLine = true;
        }
    }

    string sum = to_string(stol(a) + stol(b));

    // output
    counter = 0;
    vector<vector<char> > output;
    vector<char> delim(7, '.');
    for (const auto &ch : sum) {
        auto p = number2Pixel[ch];
        for (const auto &i : p) {
            output.emplace_back(i);
        }
        output.emplace_back(delim);
    }
    output.pop_back();
    output = rotateLeft(output);
    for (const auto &i : output) {
        for (const auto &j : i) {
            cout << j;
        }
        cout << endl;
    }

    return 0;
}
