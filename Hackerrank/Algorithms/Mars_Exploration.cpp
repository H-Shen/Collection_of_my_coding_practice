#include <bits/stdc++.h>

using namespace std;

// Complete the marsExploration function below.
int marsExploration(string s) {
    int length = static_cast<int>(s.size());
    int repeat = length / 3;
    string origin;
    for (int i = 0; i < repeat; ++i) {
        origin += "SOS";
    }
    int counter = 0;
    for (int i = 0; i < length; ++i) {
        if (origin.at(i) == s.at(i)) {
            ++counter;
        }
    }
    return length - counter;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    int result = marsExploration(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
