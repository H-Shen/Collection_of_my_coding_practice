#include <string>
#include <regex>
#include <cassert>
#include <iostream>
#include <random>
#include <limits>

/**
 * Checks if a string represents a valid integer
 * Rules:
 * - Leading zeros are not allowed (except for "0")
 * - Plus sign (+) is not allowed
 * - Minus sign (-) is allowed for negative numbers
 * - Empty strings and non-numeric characters are invalid
 *
 * Valid examples: "0", "123", "-456"
 * Invalid examples: "01", "+123", "-0", "12.3", "abc"
 *
 * @param s The string to validate
 * @return true if s represents a valid integer, false otherwise
 */
bool isInteger(const std::string& s) {
    // Use static to avoid recompiling regex on each call
    static const std::regex integerPattern(R"(^(-?[1-9]\d*|0)$)");
    return std::regex_match(s, integerPattern);
}

/**
 * Alternative implementation without regex (potentially faster)
 * Manual parsing approach for better performance
 */
bool isIntegerNoRegex(const std::string& s) {
    if (s.empty()) {
        return false;
    }

    size_t start = 0;
    bool isNegative = false;

    // Handle sign
    if (s[0] == '-') {
        isNegative = true;
        start = 1;
        if (s.length() == 1) { // Just "-"
            return false;
        }
    } else if (s[0] == '+') {
        return false; // Plus sign not allowed
    }

    // Check for leading zeros
    if (s.length() > start + 1 && s[start] == '0') {
        return false; // Leading zero not allowed
    }

    // Special case: "-0" is not allowed, but "0" is
    if (isNegative && s.length() == 2 && s[1] == '0') {
        return false;
    }

    // Check all remaining characters are digits
    for (size_t i = start; i < s.length(); ++i) {
        if (s[i] < '0' || s[i] > '9') {
            return false;
        }
    }

    return true;
}

/**
 * Runs comprehensive tests for the integer validation functions
 */
void runTests() {
    std::cout << "Running integer validation tests...\n";

    // Basic valid cases
    assert(isInteger("0"));
    assert(isInteger("1"));
    assert(isInteger("123"));
    assert(isInteger("-1"));
    assert(isInteger("-123"));
    assert(isInteger("2147483647"));
    assert(isInteger("-2147483648"));

    // Invalid cases
    assert(!isInteger(""));           // Empty string
    assert(!isInteger("-"));          // Just minus sign
    assert(!isInteger("+"));          // Just plus sign
    assert(!isInteger("+1"));         // Plus sign not allowed
    assert(!isInteger("01"));         // Leading zero
    assert(!isInteger("000"));        // Multiple leading zeros
    assert(!isInteger("-0"));         // Negative zero
    assert(!isInteger("12.3"));       // Decimal
    assert(!isInteger("12a"));        // Non-digit character
    assert(!isInteger("a12"));        // Non-digit at start
    assert(!isInteger(" 12"));        // Leading whitespace
    assert(!isInteger("12 "));        // Trailing whitespace
    assert(!isInteger("1 2"));        // Embedded space

    // Test both implementations produce same results
    const std::vector<std::string> testCases = {
            "0", "1", "-1", "123", "-123", "+1", "01", "-0", "000",
            "", "-", "+", "12.3", "abc", " 12", "12 ", "1a2"
    };

    for (const auto& testCase : testCases) {
        bool result1 = isInteger(testCase);
        bool result2 = isIntegerNoRegex(testCase);
        if (result1 != result2) {
            std::cout << "Mismatch for \"" << testCase << "\": regex="
                      << result1 << ", manual=" << result2 << std::endl;
        }
        assert(result1 == result2);
    }

    // Random number validation (using standard integers)
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(
            std::numeric_limits<int>::min(),
            std::numeric_limits<int>::max()
    );

    std::cout << "Testing with random integers...\n";
    for (int i = 0; i < 10000; ++i) {
        int randomInt = dist(gen);
        std::string intStr = std::to_string(randomInt);
        assert(isInteger(intStr));
        assert(isIntegerNoRegex(intStr));
    }

    std::cout << "All tests passed!\n";
}

int main() {
    runTests();
    return 0;
}
