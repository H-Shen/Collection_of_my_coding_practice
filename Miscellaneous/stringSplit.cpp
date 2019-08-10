/**
 * Python3 is used to interactively help code testing.
 */
#include <Python.h>
#include <bits/stdc++.h>

using namespace std;

#define DEBUG

/**
 * Split a string by using single character as the delimiter.
 * @return a vector of strings after splitting.
 */
vector<string> splitByChar(string s, const char &delim) {
    vector<string> res;
    istringstream f(s);
    string temp;
    while (getline(f, s, delim)) {
        res.emplace_back(s);
    }
    return res;
}

vector<string> splitByString(string s, const string &delim) {

    vector<string> result;
    if (delim.empty()) {
        result.emplace_back(s);
        return result;
    }

    size_t pos = 0;
    string token;
    while ((pos = s.find(delim)) != string::npos) {
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

#ifdef DEBUG

const static size_t MIN_STRING_LEN = 50;
const static size_t MAX_STRING_LEN = 100;
const static vector<char> charSet = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f',
                                     'g', 'h',
                                     'i',
                                     'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y',
                                     'z'};
static random_device dev;
static mt19937 random_generator(dev());
static uniform_int_distribution<std::mt19937::result_type> range(0, charSet.size() - 1);
static uniform_int_distribution<std::mt19937::result_type> length(MIN_STRING_LEN, MAX_STRING_LEN);

inline static
char getRandomAlnum() {
    return charSet.at(range(random_generator));
}

inline static
string generateRandomString() {
    size_t strLength = length(random_generator);
    string s;
    for (size_t i = 0; i != strLength; ++i) {
        s.push_back(getRandomAlnum());
    }
    return s;
}

inline static
string toString(const vector<string> &A) {
    string res = "[";
    bool firstItem = true;
    for (const string &i : A) {
        if (firstItem) {
            firstItem = false;
        } else {
            res.append(", ");
        }
        res.push_back('\'');
        res.append(i);
        res.push_back('\'');
    }

    res.push_back(']');
    return res;
}

inline static
void f(const string &s, const char &delimiter) {
    Py_Initialize();
    // TODO


    Py_Finalize();
}

#endif

int main() {

#ifdef DEBUG

    // TODO

#endif

    return 0;
}