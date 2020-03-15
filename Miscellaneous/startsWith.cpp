#include <bits/stdc++.h>

#define DEBUG

/**
 * Implementation of startsWith in Cpp.
 * @param original original string
 * @param starting the string to check
 * @param isCaseSensitive true if the case is sensitive, false otherwise
 * @return true if 'starting' is in the starting of 'original'
 */
inline static
bool startsWith(const std::string &original, const std::string &starting, const bool &isCaseSensitive) {
    if (starting.empty()) {
        return true;
    }

    std::function<bool(const char &lhs, const char &rhs)> charIsEqual;
    if (isCaseSensitive) {
        charIsEqual = [](const char &lhs, const char &rhs) -> bool {
            return (lhs == rhs);
        };
    } else {
        charIsEqual = [](const char &lhs, const char &rhs) -> bool {
            return (toupper(lhs) == toupper(rhs));
        };
    }

    if (original.length() >= starting.length()) {
        for (size_t i = 0, j = 0; i != starting.length(); ++i, ++j) {
            if (!charIsEqual(original.at(i), starting.at(j))) {
                return false;
            }
        }
    } else {
        return false;
    }
    return true;
}

inline static
bool startsWith(const std::string &original, const std::string &ending) {
    return startsWith(original, ending, true);
}

int main() {

#ifdef DEBUG
    assert(startsWith("Abcdending", "abC", false));
    assert(!startsWith("abcdending", "ending"));
    assert(startsWith("We a abcdend inG ", "We a", false));
    assert(!startsWith("abcd", "abcdeeeee"));
    assert(startsWith("abcd ", "a"));
    assert(startsWith("abcd ", "A", false));
    assert(!startsWith("abcd ", "D"));
    assert(!startsWith("abcd", "acd"));
#endif

    return 0;
}