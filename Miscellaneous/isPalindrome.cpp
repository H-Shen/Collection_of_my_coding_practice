#include <bits/stdc++.h>

// Judge if a string/ a vector of custom datatype/built-in type is a palindrome.

using namespace std;

bool isPalindrome(const string &A);

bool isPalindrome(const string &A) {
    if (!A.empty()) {
        size_t len = A.size();
        size_t half = (len - 1) / 2;
        for (size_t i = 0; i <= half; ++i) {
            if (A.at(i) != A.at(len - i - 1)) {
                return false;
            }
        }
    }
    return true;
}

template<typename T>
bool isPalindrome(const vector<T> &A) {
    if (!A.empty()) {
        size_t len = A.size();
        size_t half = (len - 1) / 2;
        for (size_t i = 0; i <= half; ++i) {
            if (A.at(i) != A.at(len - i - 1)) {
                return false;
            }
        }
    }
    return true;
}

template<typename T, typename BinaryPredicate>
bool isPalindrome(const vector<T> &A, const BinaryPredicate &comp) {
    if (!A.empty()) {
        size_t len = A.size();
        size_t half = (len - 1) / 2;
        for (size_t i = 0; i <= half; ++i) {
            if (!comp(A.at(i), A.at(len - i - 1))) {
                return false;
            }
        }
    }
    return true;
}

int main() {

    assert(isPalindrome(vector<int>{2}));
    assert(isPalindrome(vector<int>{2, 2}));
    assert(isPalindrome(vector<int>{2, 3, 2}));
    assert(!isPalindrome(vector<int>{2, 3, 4, 5, 2}));
    assert(isPalindrome(vector<int>{}));

    assert(isPalindrome(""));
    assert(isPalindrome("a"));
    assert(!isPalindrome("ab"));
    assert(isPalindrome("aba"));
    assert(isPalindrome("abcba"));
    assert(!isPalindrome("abcda"));
    assert(isPalindrome("abba"));

    auto cmp = [](const pair<int, int> &lhs, const pair<int, int> &rhs) -> bool {
        return (lhs.first == rhs.first);
    };
    assert(!isPalindrome(vector<pair<int, int>>{{1, 0},
                                                {3, 0}}, cmp));

    assert(!isPalindrome(vector<pair<int, int>>{{1, 0},
                                                {2, 0},
                                                {3, 1}}, cmp));

    assert(isPalindrome(vector<pair<int, int>>{{1, 0},
                                               {2, 0},
                                               {1, 1}}, cmp));

    assert(isPalindrome(vector<pair<int, int>>{{1, 0},
                                               {1, 1}}, cmp));
    assert(isPalindrome(vector<pair<int, int>>{{1, 0}}, cmp));

    assert(isPalindrome(vector<pair<int, int>>{}, cmp));

    class Widget {
    private:
        int first;
        char second;
    public:
        Widget(int first_, char second_) : first(first_), second(second_) {}

        bool operator!=(const Widget &rhs) const {
            return (second != rhs.second);
        }
    };
    assert(isPalindrome(vector<Widget>{Widget(12, 'a'), Widget(13, 'a')}));
    assert(isPalindrome(vector<Widget>{Widget(12, 'a')}));
    assert(isPalindrome(vector<Widget>{}));
    assert(isPalindrome(vector<Widget>{Widget(12, 'a'), Widget(13, 'b'), Widget(13, 'a')}));
    assert(isPalindrome(vector<Widget>{Widget(12, 'a'), Widget(13, 'c'), Widget(13, 'c'), Widget(13, 'a')}));
    assert(!isPalindrome(vector<Widget>{Widget(12, 'a'), Widget(13, 'C'), Widget(13, 'c'), Widget(13, 'a')}));

    return 0;
}