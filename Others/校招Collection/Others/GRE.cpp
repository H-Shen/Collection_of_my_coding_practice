// https://ac.nowcoder.com/acm/problem/15677

#include <bits/stdc++.h>

using namespace std;

int main() {
    unordered_map<string, string> A;
    A["zero"] = "ling";
    A["one"] = "yi";
    A["two"] = "er";
    A["three"] = "san";
    A["four"] = "si";
    A["five"] = "wu";
    A["six"] = "liu";
    A["seven"] = "qi";
    A["eight"] = "ba";
    A["nine"] = "jiu";
    A["ten"] = "shi";

    int n;
    string s;
    cin >> n;
    while (n--) {
        cin >> s;
        cout << A[s] << endl;
    }

    return 0;
}