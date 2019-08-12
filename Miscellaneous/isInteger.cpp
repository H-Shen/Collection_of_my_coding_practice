#include <bits/stdc++.h>

using namespace std;

#define DEBUG

/**
 * Check if a string is an integer by regex.
 * Leading zeroes, "+" are not allowed.
 * @param s string to check
 * @return true if s is an integer, false otherwise
 */
inline static
bool isInteger(const string &s) {
    const static string pattern("^(-?[1-9][0-9]*|0)$");
    const static regex r(pattern);
    return regex_match(begin(s), end(s), r);
}

int main() {

#ifdef DEBUG
    assert(!isInteger("-"));
    assert(!isInteger("+1"));
    assert(isInteger("1"));
    assert(!isInteger("01"));
    assert(!isInteger("000"));
    assert(!isInteger("-0"));
    random_device dev;
    mt19937 random_generator(dev());
    uniform_int_distribution<std::mt19937::result_type> dist(SHRT_MIN, SHRT_MAX);
    for (int i = 0; i < 1000; ++i) {
        assert(isInteger(to_string(dist(random_generator))));
    }
#endif

    return 0;
}