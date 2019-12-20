#include <bits/stdc++.h>

using namespace std;

vector<string> weekdays = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};

int main() {
    ios_base::sync_with_stdio(false);
    string a0, a1, b0, b1;
    cin >> a0 >> a1 >> b0 >> b1;

    int len0 = min(a0.size(), a1.size());
    int len1 = min(b0.size(), b1.size());

    string res;
    int pos;
    int i;

    for (i = 0; i < len0; ++i) {
        if (a0[i] == a1[i] && a0[i] >= 'A' && a0[i] <= 'G') {
            res = res + a0[i];
            ++i;
            break;
        }
    }
    for (; i < len0; ++i) {
        if (a0[i] == a1[i] && ((isdigit(a0[i]) || (a0[i] >= 'A' && a0[i] <= 'N')))) {
            res = res + a0[i];
            break;
        }
    }

    for (i = 0; i < len1; ++i) {
        if (b0[i] == b1[i] && isalpha(b0[i])) {
            pos = i;
            break;
        }
    }

    string resOutput;
    resOutput = resOutput + weekdays[res[0] - 'A'] + " ";

    if (isdigit(res[1])) {
        resOutput = resOutput + string("0") + res[1] + string(":");
    } else {
        resOutput = resOutput + to_string(res[1] - 'A' + 10) + string(":");
    }

    if (pos < 10) {
        resOutput = resOutput + "0" + to_string(pos);
    } else {
        resOutput = resOutput + to_string(pos);
    }
    cout << resOutput << endl;

    return 0;
}