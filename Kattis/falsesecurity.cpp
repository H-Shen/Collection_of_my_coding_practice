// https://open.kattis.com/problems/falsesecurity
//

#include <bits/stdc++.h>

using namespace std;

unordered_map<char, string> A;
unordered_map<string, char> A_rev;

void myInsert(const string &a, const string& b) {
    A[a.front()] = b;
    A_rev[b] = a.front();
}

void myParse(const string &s) {
    istringstream iss(s);
    string a, b;
    iss >> a >> b;
    myInsert(a, b);
}

int main() {

    ios_base::sync_with_stdio(false);

    myParse("A .-");
    myParse("B -...");
    myParse("C -.-.");
    myParse("D -..");
    myParse("E .");
    myParse("F ..-.");
    myParse("G --.");
    myParse("H ....");
    myParse("I ..");
    myParse("J .---");
    myParse("K -.-");
    myParse("L .-..");
    myParse("M --");
    myParse("N -.");
    myParse("O ---");
    myParse("P .--.");
    myParse("Q --.-");
    myParse("R .-.");
    myParse("S ...");
    myParse("T -");
    myParse("U ..-");
    myParse("V ...-");
    myParse("W .--");
    myParse("X -..-");
    myParse("Y -.--");
    myParse("Z --..");
    myParse("_ ..--");
    myParse(", .-.-");
    myParse(". ---.");
    myParse("? ----");

    string s;
    while (cin >> s) {
        string morse_code;
        string code_length;
        for (const auto &i : s) {
            morse_code += A[i];
            code_length += to_string(A[i].size());
        }
        reverse(code_length.begin(), code_length.end());

        string message;
        auto it = code_length.cbegin();
        int counter;
        string temp_message;
        for (size_t i = 0; i != morse_code.size(); ++it) {
            counter = static_cast<int>(*it - '0');
            temp_message = "";
            while (counter > 0) {
                temp_message.push_back(morse_code.at(i));
                ++i;
                --counter;
            }
            message += A_rev[temp_message];
        }
        cout << message << endl;
    }

    return 0;
}
