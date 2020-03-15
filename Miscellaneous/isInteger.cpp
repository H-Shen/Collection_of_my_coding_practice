#include <bits/stdc++.h>

#define DEBUG

/**
 * Check if a string is an integer by regex.
 * Leading zeroes, "+" are not allowed.
 * @param s string to check
 * @return true if s is an integer, false otherwise
 */
inline static
bool isInteger(const std::string &s) {
    const static std::string pattern("^(-?[1-9][0-9]*|0)$");
    const static std::regex r(pattern);
    return std::regex_match(begin(s), end(s), r);
}

int main() {

#ifdef DEBUG
    assert(!isInteger("-"));
    assert(!isInteger("+1"));
    assert(isInteger("1"));
    assert(!isInteger("01"));
    assert(!isInteger("000"));
    assert(!isInteger("-0"));
    std::random_device dev;
    std::mt19937 random_generator(dev());
    std::uniform_int_distribution<int> dist(std::numeric_limits<int>::min(), std::numeric_limits<int>::max());
    for (int i = 0; i < 100000; i += 2) {
        assert(isInteger(std::to_string(dist(random_generator))));
        assert(isInteger(std::to_string(dist(random_generator))));
    }
#endif

    return 0;
}