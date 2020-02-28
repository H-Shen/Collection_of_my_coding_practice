// Get the longest palindrome substring's first instance. (Manacher Algorithm)
// In Cpp17, std::string_view will be used for using substring to reduce space and time complexity.

// https://www.nowcoder.com/practice/93f6c5b032bf473696373ab0d834b0fc

#include <bits/stdc++.h>

// #define USE_STRING_VIEW

#ifdef USE_STRING_VIEW

inline static
std::string preProcess(const std::string_view &s) {
    if (s.empty()) {
        return "^$";
    }
    std::string ret{"^"};
    for (size_t i = 0; i != s.length(); i++) {
        ret.push_back('#');
        ret.append(s.substr(i, 1));
    }
    ret.append("#$");
    return ret;
}

inline static
std::string_view longestPalindrome(const std::string_view &s) {

    std::string T{preProcess(s)};
    auto P {std::make_unique<int[]>(T.length())};
    int n {static_cast<int>(T.length())};
    int C{0};
    int R{0};

    for (int i = 1; i < n - 1; i++) {
        int i_mirror = 2 * C - i; // equals to i' = C - (i-C)

        if (R > i) {
            P[i] = std::min(R - i, P[i_mirror]);
        } else {
            P[i] = 0;
        }

        // Attempt to expand palindrome centered at i
        while ( T[i + 1 + P[i]] == T[i - 1 - P[i]] ) {
            ++P[i];
        }
        // If palindrome centered at i expand past R,
        // adjust center based on expanded palindrome.
        if (i + P[i] > R) {
            C = i;
            R = i + P[i];
        }
    }

    // Find the maximum element in P.
    int maxLength{0};
    int indexOfCenter{0};
    for (int i = 1; i < n - 1; i++) {
        if (P[i] > maxLength) {
            maxLength = P[i];
            indexOfCenter = i;
        }
    }

    // maxLength: the length of the longest palindrome substring
    return s.substr((indexOfCenter - 1 - maxLength) / 2, maxLength);
}

#endif

#ifndef USE_STRING_VIEW

inline static
std::string preProcess(const std::string &s) {
    if (s.empty()) {
        return "^$";
    }
    std::string ret{"^"};
    for (size_t i = 0; i != s.length(); i++) {
        ret.push_back('#');
        ret.append(s.substr(i, 1));
    }
    ret.append("#$");
    return ret;
}

inline static
std::string longestPalindrome(const std::string &s) {

    std::string T{preProcess(s)};
    auto P{std::make_unique<int[]>(T.length())};
    int n{static_cast<int>(T.length())};
    int C{0};
    int R{0};

    for (int i = 1; i < n - 1; i++) {
        int i_mirror = 2 * C - i; // equals to i' = C - (i-C)

        if (R > i) {
            P[i] = std::min(R - i, P[i_mirror]);
        } else {
            P[i] = 0;
        }

        // Attempt to expand palindrome centered at i
        while (T[i + 1 + P[i]] == T[i - 1 - P[i]]) {
            ++P[i];
        }
        // If palindrome centered at i expand past R,
        // adjust center based on expanded palindrome.
        if (i + P[i] > R) {
            C = i;
            R = i + P[i];
        }
    }

    // Find the maximum element in P.
    int maxLength{0};
    int indexOfCenter{0};
    for (int i = 1; i < n - 1; i++) {
        if (P[i] > maxLength) {
            maxLength = P[i];
            indexOfCenter = i;
        }
    }

    // maxLength: the length of the longest palindrome substring
    return s.substr((indexOfCenter - 1 - maxLength) / 2, maxLength);
}

#endif

int main() {

    std::string s;
    std::getline(std::cin, s);
    std::cout << longestPalindrome(s) << std::endl;

    return 0;
}
