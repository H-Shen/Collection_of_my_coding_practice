// write your code here cpp
// https://www.nowcoder.com/practice/8d5c073de9a54bc39adf363bbadb3cce

#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const vector<string> a = {"142857",
                          "0588235294117647",
                          "052631578947368421",
                          "0434782608695652173913",
                          "0344827586206896551724137931",
                          "0212765957446808510638297872340425531914893617",
                          "0169491525423728813559322033898305084745762711864406779661",
                          "016393442622950819672131147540983606557377049180327868852459"};

int main() {

    ios_base::sync_with_stdio(false);
    string s;
    while (cin >> s) {
        if (find(a.begin(), a.end(), s) != a.end())
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}
