#include <bits/stdc++.h>

#define DEBUG

/**
 * Implementation of endWith in Cpp.
 * @param original original string
 * @param ending the string to check
 * @return true if 'ending' is in the ending of 'original'
 */
inline static
bool endsWith(const std::string &original, const std::string &ending) {
    if (ending.empty()) {
        return true;
    }
    if (original.length() >= ending.length()) {
        return (0 == original.compare(original.length() - ending.length(), ending.length(), ending));
    }
    return false;
}

int main() {

#ifdef DEBUG
    assert(endsWith("abcd", "d"));
    assert(endsWith("abcd ", "d "));
    assert(endsWith("abcd ", ""));
    assert(!endsWith("abcd ", "D"));
#endif

    return 0;
}