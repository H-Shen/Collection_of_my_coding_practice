#include <cmath>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

const int interval = 97, letters = 26;

int number_needed(const string &a, const string &b) {
    int res = 0, len_a = a.length(), len_b = b.length();
    int i;
    vector <int> aSave(letters), bSave(letters);
    for (i = 0; i < len_a; i++) {
        aSave[a[i] - interval]++;
    }
    for (i = 0; i < len_b; i++) {
        bSave[b[i] - interval]++;
    }
    for (i = 0; i < letters; i++) {
        res += abs(aSave[i] - bSave[i]);
    }
    return res;
}

int main(){
    string a;
    cin >> a;
    string b;
    cin >> b;
    cout << number_needed(a, b) << endl;
    return 0;
}
