// https://ac.nowcoder.com/acm/problem/15051

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector <int> A(n);
    for (auto &&p : A)
    {
        cin >> p;
    }

    auto tmp0 = minmax_element(A.cbegin(), A.cend());

    vector <int> minValPosList;
    vector <int> maxValPosList;
    int minVal = *tmp0.first;
    int maxVal = *tmp0.second;
    int minValPos = 0;
    int maxValPos = 0;
    int len = static_cast<int>(A.size());

    for (int i = 0; i < len; ++i)
    {
        if (A[i] == minVal)
        {
            minValPos = i;
        }
        else if (A[i] == maxVal)
        {
            maxValPos = i;
        }
    }

    vector <int> res;
    res.push_back(abs(0 - minValPos));
    res.push_back(abs(0 - maxValPos));
    res.push_back(abs(len - 1 - minValPos));
    res.push_back(abs(len - 1 - maxValPos));


    cout << *max_element(res.begin(), res.end()) << endl;

    return 0;
}