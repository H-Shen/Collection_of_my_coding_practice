#include <bits/stdc++.h>

/**
 * Split a string by using single character as the delimiter.
 * @return a vector of strings after splitting.
 */
inline static
std::vector<std::string> splitByChar(std::string s, const char &delim) {
    std::vector<std::string> res;
    std::istringstream f(s);
    while (getline(f, s, delim)) {
        res.emplace_back(s);
    }
    return res;
}

inline static
std::vector<std::string> splitByString(std::string s, const std::string &delim) {

    std::vector<std::string> result;
    if (delim.empty()) {
        result.emplace_back(s);
        return result;
    }

    size_t pos{0};
    std::string token;
    while ((pos = s.find(delim)) != std::string::npos) {
        token = s.substr(0, pos);
        if (!token.empty()) {
            result.emplace_back(token);
        }
        s.erase(0, pos + delim.length());
    }
    if (!s.empty()) {
        result.emplace_back(s);
    }
    return result;
}

/**
 * Split a string by whitespaces with unknown length.
 */
inline static
std::vector<std::string> splitByWhitespaces(const std::string &s) {
    std::istringstream iss(s);
    return std::vector<std::string>{std::istream_iterator<std::string>(iss),
                                    std::istream_iterator<std::string>()};
}

constexpr static size_t MIN_STRING_LEN = 50;
constexpr static size_t MAX_STRING_LEN = 100;
const static std::vector<char> charSet = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e',
                                          'f',
                                          'g', 'h',
                                          'i',
                                          'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x',
                                          'y',
                                          'z'};
static std::random_device dev;
static std::mt19937 random_generator(dev());
static std::uniform_int_distribution<size_t> range(0, charSet.size() - 1);
static std::uniform_int_distribution<size_t> length(MIN_STRING_LEN, MAX_STRING_LEN);

inline static
char getRandomAlnum() {
    return charSet.at(range(random_generator));
}

inline static
std::string generateRandomString() {
    size_t strLength = length(random_generator);
    std::string s;
    for (size_t i = 0; i != strLength; ++i) {
        s.push_back(getRandomAlnum());
    }
    return s;
}

inline static
std::string generateRandomString(size_t strlength) {
    std::string s;
    for (size_t i = 0; i != strlength; ++i) {
        s.push_back(getRandomAlnum());
    }
    return s;
}

inline static
std::string toString(const std::vector<std::string> &A) {
    std::string res;
    bool firstItem = true;
    for (const std::string &i : A) {
        if (firstItem) {
            firstItem = false;
        } else {
            res.append(" ");
        }
        res.append(i);
    }
    return res;
}

int main() {

    // splitByWhitespaces
    int testNumber = 10;
    for (int i = 0; i < testNumber; ++i) {
        std::string tempString;
        for (int gap = 0; gap < testNumber; ++gap) {
            tempString.append(generateRandomString(5));
            tempString.append("\t   ");
        }
        std::cout << tempString << std::endl;
        std::cout << toString(splitByWhitespaces(tempString)) << std::endl;
    }

    return 0;
}
