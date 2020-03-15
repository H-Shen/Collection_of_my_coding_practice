#include <cassert>
#include <string>
#include <vector>

#define DEBUG

/**
 * An implementation of join in Cpp.
 */
inline static
std::string join(const std::vector<std::string> &v, const std::string &str) {
    std::string s;
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
