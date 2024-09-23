#include <bits/stdc++.h>

using namespace std;

vector<string> hand, mouth, eye;

void parse(string s, vector<string> &List) {
    string tmp;
    bool inBracket = false;

    for (string::size_type i = 0; i < s.size(); ++i) {
        if (inBracket && s[i] != ']') {
            tmp += s[i];
        } else if (inBracket && s[i] == ']') {
            inBracket = false;
            List.push_back(tmp);
        } else if (!inBracket && s[i] == '[') {
            inBracket = true;
            tmp = "";
        }
    }

}

int main() {
    string input;
    getline(cin, input);
    parse(input, hand);
    getline(cin, input);
    parse(input, eye);
    getline(cin, input);
    parse(input, mouth);

    int n;
    vector<string>::size_type leftHand, leftEye, Mouth, rightEye, rightHand;
    cin >> n;

    while (n--) {

        cin >> leftHand >> leftEye >> Mouth >> rightEye >> rightHand;
        leftHand--;
        leftEye--;
        Mouth--;
        rightEye--;
        rightHand--;

        if (leftHand >= hand.size() || leftEye >= eye.size() ||
            Mouth >= mouth.size() || rightEye >= eye.size() ||
            rightHand >= hand.size()) {
            cout << "Are you kidding me? @\\/@" << endl;
        } else {
            cout << hand[leftHand] << "(" << eye[leftEye] << mouth[Mouth]
                 << eye[rightEye] << ")" << hand[rightHand] << endl;
        }
    }
    return 0;
}