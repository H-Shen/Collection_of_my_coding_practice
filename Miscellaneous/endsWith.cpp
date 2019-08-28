#include <bits/stdc++.h>

#define DEBUG

/**
 * Implementation of endsWith in Cpp.
 * @param original original string
 * @param ending the string to check
 * @param isCaseSensitive true if the case is sensitive, false otherwise
 * @return true if 'ending' is in the ending of 'original'
 */
inline static
bool endsWith(const std::string &original, const std::string &ending, const bool &isCaseSensitive) {
    if (ending.empty()) {
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

    if (original.length() >= ending.length()) {
        for (size_t i = original.length() - ending.length(), j = 0; i != original.length(); ++i, ++j) {
            if (!charIsEqual(original.at(i), ending.at(j))) {
                return false;
            }
        }
    } else {
        return false;
    }
    return true;
}

inline static
bool endsWith(const std::string &original, const std::string &ending) {
    return endsWith(original, ending, true);
}

int main() {

#ifdef DEBUG
    assert(!endsWith("abcd", "abcde"));
    assert(!endsWith("", "abcde"));
    assert(!endsWith("", "abcde", false));
    assert(endsWith("abcdending", "EndinG", false));
    assert(endsWith("abcdending", "ending"));
    assert(endsWith("abcdend inG ", "enD ing ", false));
    assert(endsWith("abcd", "cd"));
    assert(endsWith("abcd ", "d "));
    assert(endsWith("abcd ", ""));
    assert(!endsWith("abcd ", "D"));
    assert(!endsWith("abcd", "acd"));
#endif

    return 0;
}
