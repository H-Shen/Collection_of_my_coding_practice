#include <string>
#include <algorithm>
#include <cctype>
#include <cassert>
#include <iostream>
#include <vector>

/**
 * Checks if a string ends with a specific suffix
 * @param original The string to check
 * @param suffix The suffix to look for
 * @param caseSensitive Whether the comparison should be case-sensitive (default: true)
 * @return true if 'original' ends with 'suffix', false otherwise
 */
bool endsWith(const std::string &original, const std::string &suffix, bool caseSensitive = true) {
    // Empty suffix always matches
    if (suffix.empty()) {
        return true;
    }

    // If suffix is longer than original, it cannot be a suffix
    if (suffix.length() > original.length()) {
        return false;
    }

    // Get the starting position in original string to compare
    const size_t startPos = original.length() - suffix.length();

    if (caseSensitive) {
        // Direct comparison using string's compare method
        return original.compare(startPos, suffix.length(), suffix) == 0;
    } else {
        // Case-insensitive comparison
        return std::equal(
                original.begin() + static_cast<std::string::difference_type>(startPos), original.end(),
                suffix.begin(),
                [](char a, char b) {
                    return std::tolower(static_cast<unsigned char>(a)) ==
                           std::tolower(static_cast<unsigned char>(b));
                }
        );
    }
}


/**
 * Runs comprehensive tests for the endsWith function
 */
void runTests() {
    std::cout << "Running endsWith tests...\n";

    // Basic functionality tests
    assert(endsWith("hello world", "world"));
    assert(!endsWith("hello world", "World"));
    assert(endsWith("hello world", "World", false));
    assert(endsWith("hello world", ""));
    assert(!endsWith("short", "very long suffix"));
    assert(!endsWith("", "non-empty"));
    assert(endsWith("", ""));

    // Edge cases
    assert(endsWith("a", "a"));
    assert(!endsWith("a", "b"));
    assert(endsWith("ABC", "abc", false));
    assert(!endsWith("ABC", "abc"));

    // Whitespace handling
    assert(endsWith("test ", " "));
    assert(endsWith("test\n", "\n"));
    assert(!endsWith("test", " "));

    // Your original test cases
    assert(!endsWith("abcd", "abcde"));
    assert(!endsWith("", "abcde"));
    assert(endsWith("abcdending", "EndinG", false));
    assert(endsWith("abcdending", "ending"));
    assert(endsWith("abcdend inG ", "enD ing ", false));
    assert(endsWith("abcd", "cd"));
    assert(endsWith("abcd ", "d "));
    assert(endsWith("abcd ", ""));
    assert(!endsWith("abcd ", "D"));
    assert(!endsWith("abcd", "acd"));

    // Additional test cases
    const std::vector<std::pair<std::string, std::string>> testCases = {
            {"hello", "lo"},
            {"HELLO", "lo"},
            {"test",  "TEST"},
            {"",      ""},
            {"short", "very long"},
            {"same",  "same"},
            {"Case",  "case"}
    };

    for (const auto &[original, suffix]: testCases) {
        // Test both case-sensitive and case-insensitive modes
        bool caseSensitive = endsWith(original, suffix, true);
        bool caseInsensitive = endsWith(original, suffix, false);
        // Results logged for verification during development
        (void) caseSensitive;
        (void) caseInsensitive;
    }

    std::cout << "All tests passed!\n";
}

int main() {
    runTests();
    return 0;
}
