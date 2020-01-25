// https://open.kattis.com/problems/greatswercporto
//
#include <bits/extc++.h>

using namespace std;
using ll = long long;

constexpr int MAX_LENGTH = 15;

char cstr[MAX_LENGTH];
unordered_map<char, ll> leftDigits;
unordered_map<char, ll> rightDigits;
unordered_map<char, size_t> uniqueSymbols;
vector<int> uniqueSymbolsInDigits;
vector<ll> powerOfTen = {1};
vector<char> constraints; // all elements in this vector cannot be 0, may have duplicated elements

template<typename Iterator>
/* Credits: Mark Nelson http://marknelson.us */
inline bool
next_combination(const Iterator first, Iterator k, const Iterator last) {
    if ((first == last) || (first == k) || (last == k))
        return false;
    Iterator itr1 = first;
    Iterator itr2 = last;
    ++itr1;
    if (last == itr1)
        return false;
    itr1 = k;
    --itr2;
    while (first != itr1) {
        if (*--itr1 < *itr2) {
            Iterator j = k;
            while (!(*itr1 < *j)) ++j;
            iter_swap(itr1, j);
            ++itr1;
            ++j;
            itr2 = k;
            rotate(itr1, j, last);
            while (last != j) {
                ++j;
                ++itr2;
            }
            rotate(k, itr2, last);
            return true;
        }
    }
    rotate(first, k, last);
    return false;
}

int main() {

    // pre-calculation
    while (powerOfTen.size() < 11) {
        powerOfTen.emplace_back(powerOfTen.back() * 10);
    }

    int t;
    scanf("%d", &t);
    string s;
    for (int j = 0; j < t; ++j) {
        scanf("%s", cstr);
        s = cstr;
        int n = static_cast<int>(s.size());
        if (j == t - 1) {
            for (int i = 0; i < n; ++i) {
                rightDigits[s.at(i)] += powerOfTen[n - i - 1];
            }
        } else {
            for (int i = 0; i < n; ++i) {
                leftDigits[s.at(i)] += powerOfTen[n - i - 1];
            }
        }
        // the leftmost letter in a word cannot be zero
        constraints.emplace_back(s.front());
    }

    // Collect all unique symbols
    unordered_set<char> temp;
    for (const auto &i : leftDigits) {
        temp.insert(i.first);
    }
    for (const auto &i : rightDigits) {
        temp.insert(i.first);
    }
    // Write all unique symbols to 'uniqueSymbols'
    size_t index = 0;
    for (const auto &i : temp) {
        uniqueSymbols[i] = index;
        ++index;
    }
    // Resize 'uniqueSymbolsInDigits'
    uniqueSymbolsInDigits.resize(uniqueSymbols.size());
    string str = "0123456789";
    string_view sv(str);
    string substring;
    size_t comb_size = uniqueSymbolsInDigits.size();
    ll leftSum;
    ll rightSum;
    int counter = 0;
    bool pass;
    do {
        substring = sv.substr(0, comb_size);
        do {
            pass = false;
            // mapping substring to uniqueSymbolsInDigits
            for (size_t i = 0; i != substring.size(); ++i) {
                uniqueSymbolsInDigits.at(i) = static_cast<int>(substring.at(i) - '0');
            }
            // check constraints
            for (const auto &i : constraints) {
                if (uniqueSymbolsInDigits.at(uniqueSymbols[i]) == 0) {
                    pass = true;
                    break;
                }
            }
            if (pass) {
                continue;
            }
            // reset
            leftSum = 0;
            rightSum = 0;
            // calculate the left side of the expression
            for (const auto &i : leftDigits) {
                leftSum += uniqueSymbolsInDigits.at(uniqueSymbols[i.first]) * i.second;
            }
            // calculate the right side of the expression
            for (const auto &i : rightDigits) {
                rightSum += uniqueSymbolsInDigits.at(uniqueSymbols[i.first]) * i.second;
            }
            // compare
            if (leftSum == rightSum) {
                ++counter;
            }
        } while (next_permutation(substring.begin(), substring.end()));
    } while (next_combination(str.begin(), str.begin() + comb_size,
                              str.begin() + str.size()));
    printf("%d\n", counter);

    return 0;
}
