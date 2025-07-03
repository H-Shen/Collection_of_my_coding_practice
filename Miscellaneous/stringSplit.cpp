#include <algorithm>
#include <array>
#include <iostream>
#include <iterator>
#include <random>
#include <sstream>
#include <string>
#include <string_view>
#include <vector>

// A small utility namespace for string splitting, joining, and random string generation
namespace Util {

// ——— Splitting ——————————————————————————————————————————————————————

// Split a string_view by a single character delimiter.
// Returns a vector of std::string (each substring owns its data).
inline std::vector<std::string> split(std::string_view s, char delim) {
    std::vector<std::string> result;
    size_t start = 0;
    while (true) {
        auto pos = s.find(delim, start);
        // Extract substring [start, pos)
        result.emplace_back(s.substr(start, pos - start));
        if (pos == std::string_view::npos)
            break;  // no more delimiters
        start = pos + 1;
    }
    return result;
}

// Split a string_view by a string delimiter.
// Skips empty tokens except when delim is empty.
inline std::vector<std::string> split(std::string_view s, std::string_view delim) {
    std::vector<std::string> result;
    if (delim.empty()) {
        // Edge case: no delimiter specified
        result.emplace_back(s);
        return result;
    }
    size_t start = 0;
    while (true) {
        auto pos = s.find(delim, start);
        if (pos == std::string_view::npos) {
            // Last token after final delimiter
            result.emplace_back(s.substr(start));
            break;
        }
        if (pos > start) {
            // Non-empty token before delimiter
            result.emplace_back(s.substr(start, pos - start));
        }
        start = pos + delim.size();
    }
    return result;
}

// Split a string_view on any whitespace sequence.
// Uses an istringstream to handle varying amounts of spaces/tabs/newlines.
inline std::vector<std::string> splitWhitespace(std::string_view s) {
    // We need a std::string for istringstream, so copy the view into a string
    std::istringstream iss{std::string{s}};
    return { std::istream_iterator<std::string>(iss),
             std::istream_iterator<std::string>() };
}

// ——— Joining ——————————————————————————————————————————————————————

// Join a vector of strings using 'sep' between elements.
// Precomputes total length for a single allocation.
inline std::string join(
    const std::vector<std::string>& parts,
    std::string_view sep = " ")
{
    if (parts.empty()) return {};
    // Calculate total characters needed
    size_t total = (parts.size() - 1) * sep.size();
    for (auto const& p : parts) total += p.size();

    std::string out;
    out.reserve(total);
    auto it = parts.begin();
    out += *it++;  // first element
    for (; it != parts.end(); ++it) {
        out += sep; // separator
        out += *it; // next element
    }
    return out;
}

// ——— Random string generation —————————————————————————————————————

// Min/max lengths for the default random-string generator
constexpr size_t MIN_STRING_LEN = 50;
constexpr size_t MAX_STRING_LEN = 100;

// A compile-time char set of digits + lowercase letters
constexpr std::array<char, 36> CHARSET = [] {
    std::array<char, 36> arr{};
    std::string_view chars{"0123456789abcdefghijklmnopqrstuvwxyz"};
    std::copy_n(chars.begin(), arr.size(), arr.begin());
    return arr;
}();

// Returns a reference to a single RNG instance (thread-unsafe / single-threaded context)
inline std::mt19937& rng() {
    static std::random_device rd;
    static std::mt19937 gen{rd()};
    return gen;
}

// Pick one random alphanumeric character from CHARSET
inline char getRandomAlnum() {
    std::uniform_int_distribution<size_t> dist(0, CHARSET.size() - 1);
    return CHARSET[dist(rng())];
}

// Generate a random string of specified length
inline std::string generateRandomString(size_t length) {
    std::string s;
    s.reserve(length);  // avoid reallocations
    for (size_t i = 0; i < length; ++i) {
        s.push_back(getRandomAlnum());
    }
    return s;
}

// Generate a random string with length in [MIN_STRING_LEN, MAX_STRING_LEN]
inline std::string generateRandomString() {
    std::uniform_int_distribution<size_t> dist(MIN_STRING_LEN, MAX_STRING_LEN);
    return generateRandomString(dist(rng()));
}

} // namespace Util

// ——— Main driver demonstrating usage —————————————————————————————————
int main() {
    constexpr int testCount = 10;
    for (int i = 0; i < testCount; ++i) {
        // Build a random line with 5-char tokens separated by tabs
        std::string temp;
        for (int j = 0; j < testCount; ++j) {
            temp += Util::generateRandomString(5);
            temp += '\t';
        }
        // Print the raw line
        std::cout << temp << '\n';

        // Split on whitespace (tabs/spaces), then re-join with single spaces
        auto tokens = Util::splitWhitespace(temp);
        std::cout << Util::join(tokens) << "\n\n";
    }
    return 0;
}
