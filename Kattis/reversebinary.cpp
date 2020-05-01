// https://open.kattis.com/problems/reversebinary
//
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

int main() {

    ll n;
    scanf("%lld", &n);
    bitset<64> A(n);
    string temp = A.to_string();
    deque<char> temp_deque(temp.begin(), temp.end());
    while (temp_deque.size() > 1 && temp_deque.front() == '0') {
        temp_deque.pop_front();
    }
    temp = string(temp_deque.begin(), temp_deque.end());
    reverse(temp.begin(), temp.end());
    printf("%lld\n", stoll(temp, nullptr, 2));

    return 0;
}
