#include <bits/stdc++.h>

using namespace std;

#define DEBUG

/**
 * An implementation of join in Cpp.
 */
inline static
string join(const vector<string> &v, const string &str) {
    string s;
    for (auto p = cbegin(v); p != cend(v); ++p) {
        s.append(*p);
        if (p != cend(v) - 1) {
            s.append(str);
        }
    }
    return s;
}

int main() {

#ifdef DEBUG
    assert(join({"ab", "mn","hj", "qw"}, "+-") == "ab+-mn+-hj+-qw");
    assert(join({"ab", "mn","hj", "qw"}, " t ") == "ab t mn t hj t qw");
    assert(join({}, "asd").empty());
    assert(join({"","",""}, "asd") == "asdasd");
    assert(join({"","",""},"").empty());
#endif

    return 0;
}
