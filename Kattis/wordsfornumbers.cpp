// https://open.kattis.com/problems/wordsfornumbers
//
#include <bits/extc++.h>

using namespace std;

unordered_map<int, string> A = {
        {1,   "one"},
        {2,   "two"},
        {3,   "three"},
        {4,   "four"},
        {5,   "five"},
        {6,   "six"},
        {7,   "seven"},
        {8,   "eight"},
        {9,   "nine"},
        {10,  "ten"},
        {11,  "eleven"},
        {12,  "twelve"},
        {13,  "thirteen"},
        {14,  "fourteen"},
        {15,  "fifteen"},
        {16,  "sixteen"},
        {17,  "seventeen"},
        {18,  "eighteen"},
        {19,  "nineteen"},
        {20,  "twenty"},
        {30,  "thirty"},
        {40,  "forty"},
        {50,  "fifty"},
        {60,  "sixty"},
        {70,  "seventy"},
        {80,  "eighty"},
        {90,  "ninety"},
        {100, "hundred"}
};

inline static
string handle(const int &n) {
    if (n == 0) {
        return "zero";
    }
    if (n <= 20 || (n <= 100 && n % 10 == 0)) {
        return A[n];
    }
    return A[n / 10 * 10] + string("-") + A[n - n / 10 * 10];
}


int main() {

    ios_base::sync_with_stdio(false);
    string s;

    while (getline(cin, s)) {

        while (true) {

            size_t startPos = 0;
            bool encounterADecimal = false;
            string decimal;
            string newSubstring;

            for (size_t i = 0; i != s.size(); ++i) {
                if (isdigit(s.at(i))) {
                    if (encounterADecimal) {
                    } else {
                        encounterADecimal = true;
                        startPos = i;
                    }
                    decimal.push_back(s.at(i));
                } else if (encounterADecimal) {
                    break;
                }
            }

            if (encounterADecimal) {
                newSubstring = handle(stoi(decimal));
                if (startPos == 0) {
                    newSubstring.front() = toupper(newSubstring.front());
                }
                s.replace(startPos, decimal.size(), newSubstring);
            } else {
                break;
            }
        }
        cout << s << endl;
    }
    return 0;
}
