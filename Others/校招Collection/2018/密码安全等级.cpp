// https://www.nowcoder.com/practice/9fa70c9d7d3040fb869fe21775f8f9fb

#include <cstring>
#include <iostream>
#include <string>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    string s;
    cin >> s;

    int total = 0;
    size_t len = s.size();

    // Length
    if (len <= 4) {
        total += 5;
    } else if (len <= 7) {
        total += 10;
    } else {
        total += 25;
    }

    // Letters
    bool hasLetter = false;
    bool hasUpperCase = false;
    bool hasLowerCase = false;
    for (const char &ch : s) {
        if (isupper(ch)) {
            hasLetter = true;
            hasUpperCase = true;
        } else if (islower(ch)) {
            hasLetter = true;
            hasLowerCase = true;
        }
    }
    if ((hasLowerCase && !hasUpperCase) || (!hasLowerCase && hasUpperCase)) {
        total += 10;
    } else if (hasUpperCase) {
        total += 20;
    }

    // Digits
    int digitCount = 0;
    for (const char &ch : s) {
        if (isdigit(ch)) {
            ++digitCount;
        }
    }
    if (digitCount == 1) {
        total += 10;
    } else if (digitCount > 1) {
        total += 20;
    }

    // Special Characters
    int specialCharCount = 0;
    for (const char &ch : s) {
        if (!isalnum(ch)) {
            ++specialCharCount;
        }
    }
    if (specialCharCount == 1) {
        total += 10;
    } else if (specialCharCount > 1) {
        total += 25;
    }

    // Bonus
    if (hasLowerCase && hasUpperCase && digitCount > 0 && specialCharCount > 0) {
        total += 5;
    } else if (hasLetter && digitCount > 0 && specialCharCount > 0) {
        total += 3;
    } else if (hasLetter && digitCount > 0) {
        total += 2;
    }


    // Conversion
    if (total >= 90) {
        cout << "VERY_SECURE";
    } else if (total >= 80) {
        cout << "SECURE";
    } else if (total >= 70) {
        cout << "VERY_STRONG";
    } else if (total >= 60) {
        cout << "STRONG";
    } else if (total >= 50) {
        cout << "AVERAGE";
    } else if (total >= 25) {
        cout << "WEAK";
    } else {
        cout << "VERY_WEAK";
    }
    cout << endl;


    return 0;
}