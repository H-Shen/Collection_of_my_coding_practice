#include <bits/stdc++.h>

using namespace std;

// Complete the alternatingCharacters function below.
int alternatingCharacters(string s) {

    int len = static_cast<int>(s.size());
    unordered_set<char> set_s(s.begin(), s.end());
    vector<char> list_s(s.begin(), s.end());
    int result = 0;

    if (set_s.size() == 1) {
        return len - 1;
    }

    try {
        for (int i = 0; i < len; ++i) {
            if (list_s.at(i) == list_s.at(i + 1)) {
                ++result;
            }
        }
    } catch (...) {}

    return result;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s;
        getline(cin, s);

        int result = alternatingCharacters(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
