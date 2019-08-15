#include <bits/stdc++.h>

#define DEBUG
// Judge if a string/ a vector of custom datatype/built-in type is a palindrome.

using namespace std;

inline static
bool isPalindrome(long long A) {
    if (A < 0) {
        return false;
    }
    if (A % 10 == 0 && A != 0) {
        return false;
    }
    long long A_rev{0};
    while (A > A_rev) {
        A_rev = A_rev * 10 + A % 10;
        A /= 10;
    }
    return (A == A_rev || A == A_rev / 10);
}

inline static
bool isPalindrome(int A) {
    return isPalindrome(static_cast<long long>(A));
}

inline static
bool isPalindrome(unsigned long long A) {
    if (A % 10 == 0 && A != 0) {
        return false;
    }
    unsigned long long A_rev{0};
    while (A > A_rev) {
        A_rev = A_rev * 10 + A % 10;
        A /= 10;
    }
    return (A == A_rev || A == A_rev / 10);
}

inline static
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

#ifdef DEBUG
class Widget {
private:
    int first;
    char second;
public:
    Widget(int first, char second) : first(first), second(second) {}

    bool operator!=(const Widget &rhs) const {
        return (second != rhs.second);
    }
};
#endif

int main() {

#ifdef DEBUG
    assert(isPalindrome(0));
    assert(isPalindrome(1));
    assert(isPalindrome(121));
    assert(isPalindrome(11));
    assert(isPalindrome(12321));
    assert(isPalindrome(1221));
    assert(!isPalindrome(-1));
    assert(!isPalindrome(12341));
    assert(!isPalindrome(12381991113311ULL));
    assert(isPalindrome(1234567890987654321ULL));
    assert(!isPalindrome(-12381991113311LL));

    assert(isPalindrome(""));
    assert(isPalindrome("a"));
    assert(!isPalindrome("ab"));
    assert(isPalindrome("aba"));
    assert(isPalindrome("abcba"));
    assert(!isPalindrome("abcda"));
    assert(isPalindrome("abba"));

    assert(isPalindrome(vector<int>{2}));
    assert(isPalindrome(vector<int>{2, 2}));
    assert(isPalindrome(vector<int>{2, 3, 2}));
    assert(!isPalindrome(vector<int>{2, 3, 4, 5, 2}));
    assert(isPalindrome(vector<int>{}));

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

    assert(isPalindrome(vector<Widget>{Widget(12, 'a'), Widget(13, 'a')}));
    assert(isPalindrome(vector<Widget>{Widget(12, 'a')}));
    assert(isPalindrome(vector<Widget>{}));
    assert(isPalindrome(vector<Widget>{Widget(12, 'a'), Widget(13, 'b'), Widget(13, 'a')}));
    assert(isPalindrome(vector<Widget>{Widget(12, 'a'), Widget(13, 'c'), Widget(13, 'c'), Widget(13, 'a')}));
    assert(!isPalindrome(vector<Widget>{Widget(12, 'a'), Widget(13, 'C'), Widget(13, 'c'), Widget(13, 'a')}));
#endif

    return 0;
}