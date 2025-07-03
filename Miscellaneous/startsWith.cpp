#include <algorithm>
#include <cctype>
#include <string>
#include <string_view>
#include <cassert>

// A small utility namespace for string algorithms
namespace Util {

    /**
     * Check if 'text' starts with 'prefix'.
     * @param text           The full string (or string_view) to test.
     * @param prefix         The starting sequence to look for.
     * @param case_sensitive If true, match exactly; if false, match case-insensitively.
     * @return true if 'text' begins with 'prefix', false otherwise.
     */
    inline bool starts_with(
        std::string_view text,
        std::string_view prefix,
        bool case_sensitive = true) noexcept
    {
        if (prefix.size() > text.size()) {
            return false;
        }

        if (case_sensitive) {
            // Direct comparison
            return std::equal(
                prefix.begin(), prefix.end(),
                text.begin());
        }

        // Case-insensitive comparison
        return std::equal(
            prefix.begin(), prefix.end(),
            text.begin(),
            [](const char a, const char b) {
                return std::toupper(static_cast<unsigned char>(a))
                     == std::toupper(static_cast<unsigned char>(b));
            });
    }

} // namespace util

int main() {
#ifndef NDEBUG
    using Util::starts_with;
    assert(starts_with("Abcdending", "abC", false));
    assert(!starts_with("abcdending", "ending"));
    assert(starts_with("We a abcdend inG ", "We a", false));
    assert(!starts_with("abcd", "abcdeeeee"));
    assert(starts_with("abcd ", "a"));
    assert(starts_with("abcd ", "A", false));
    assert(!starts_with("abcd ", "D"));
    assert(!starts_with("abcd", "acd"));
#endif
    return 0;
}
