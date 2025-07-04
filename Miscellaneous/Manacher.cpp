// Finds the first longest palindromic substring in O(n) using Manacher's algorithm.
// C++20 version, leveraging std::string_view for zero-copy slicing.

#include <algorithm>
#include <iostream>
#include <string>
#include <string_view>
#include <vector>

namespace Util {

    // Preprocess input by inserting sentinels and separators to handle even-length palindromes uniformly.
    inline std::string preprocess(std::string_view s) {
        if (s.empty()) return "^$";
        std::string t;
        t.reserve(s.size() * 2 + 3);
        t.push_back('^');
        for (char c : s) {
            t.push_back('#');
            t.push_back(c);
        }
        t += "#$";
        return t;
    }

    // Manacher's algorithm: returns a string_view into the original s.
    inline std::string_view longest_palindrome(std::string_view s) {
        auto t = preprocess(s);
        int n = static_cast<int>(t.size());
        std::vector<int> p(n);
        int center = 0, right = 0;

        for (int i = 1; i < n - 1; ++i) {
            int mirror = 2 * center - i;
            if (i < right) {
                p[i] = std::min(right - i, p[mirror]);
            }
            // Expand around i
            while (t[i + 1 + p[i]] == t[i - 1 - p[i]]) ++p[i];

            // Update center and right boundary
            if (i + p[i] > right) {
                center = i;
                right = i + p[i];
            }
        }

        // Find iterator to maximum palindrome radius in range [1, n-1)
        auto it = std::ranges::max_element(p.begin() + 1, p.begin() + n - 1);
        int max_center = static_cast<int>(std::distance(p.begin(), it));
        int max_len = *it;

        // Calculate start index in original string
        int start = (max_center - 1 - max_len) / 2;
        return s.substr(start, max_len);
    }

} // namespace util

int main() {
    std::string input;
    std::getline(std::cin, input);

    auto result = Util::longest_palindrome(input);
    std::cout << result << '\n';
    return 0;
}
