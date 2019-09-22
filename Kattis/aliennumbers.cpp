// https://open.kattis.com/problems/aliennumbers
//
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

string convertFromDecimal(const string & represent, ll a) {
    int length = static_cast<int>(represent.size());
    deque<int> A;
    while (a > 0) {
        A.emplace_front(a % length);
        a /= length;
    }
    deque<char> convert(A.size());
    for (size_t i = 0; i != convert.size(); ++i) {
        convert[i] = represent[A[i]];
    }
    return string(convert.begin(), convert.end());
}

vector<ll> powerOfN;
ll convertToDecimal(const string & represent, const string &alien_number) {

    ll length = represent.size();
    vector<ll>().swap(powerOfN);
    powerOfN = {1};
    while (powerOfN.back() < 100000000000L) {
        powerOfN.emplace_back(powerOfN.back() * length);
    }

    unordered_map<char, size_t> A;
    for (size_t i = 0; i != represent.size(); ++i) {
        A[represent[i]] = i;
    }
    ll result = 0;
    ll counter = 0;
    for (auto it = alien_number.crbegin(); it != alien_number.crend(); ++it) {
        result += A[*it] * powerOfN[counter];
        ++counter;
    }
    return result;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    string alien_number;
    string source_language;
    string target_language;

    cin >> T;
    for (int i = 1; i <= T; ++i) {
        cin >> alien_number >> source_language >> target_language;
        cout << "Case #" << i << ": " << convertFromDecimal(target_language, convertToDecimal(source_language, alien_number)) << '\n';
    }

    return 0;
}
