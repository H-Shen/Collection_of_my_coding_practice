#include <bits/stdc++.h>

using namespace std;

// Complete the minimumNumber function below.
int minimumNumber(int n, string password) {
    // Return the minimum number of characters to make the password strong

    string special_characters = "!@#$%^&*()-+";
    unordered_set<char> special_characters_set(special_characters.begin(), special_characters.end());

    int length = static_cast<int>(password.size());
    int digits = 0;
    int lower = 0;
    int upper = 0;
    int special = 0;

    for (const char &ch : password) {
        if (isdigit(ch)) {
            ++digits;
        } else if (isupper(ch)) {
            ++upper;
        } else if (islower(ch)) {
            ++lower;
        } else if (special_characters_set.find(ch) != special_characters_set.end()) {
            ++special;
        }
    }

    int result = 0;
    if (digits == 0) {
        ++result;
        ++length;
    }
    if (lower == 0) {
        ++result;
        ++length;
    }
    if (upper == 0) {
        ++result;
        ++length;
    }
    if (special == 0) {
        ++result;
        ++length;
    }
    while (length < 6) {
        ++result;
        ++length;
    }
    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string password;
    getline(cin, password);

    int answer = minimumNumber(n, password);

    fout << answer << "\n";

    fout.close();

    return 0;
}
