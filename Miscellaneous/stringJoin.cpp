#include <cassert>
#include <string>
#include <string_view>
#include <vector>

// A simple join utility: concatenate parts with a separator in between.
inline std::string join(
    const std::vector<std::string_view> &parts,
    const std::string_view sep) {
    if (parts.empty()) {
        return {};
    }

    // Precompute total length to reserve capacity
    size_t total = (parts.size() - 1) * sep.size();
    for (auto sv: parts) {
        total += sv.size();
    }

    std::string out;
    out.reserve(total);

    // Append first part without a leading separator
    out.append(parts[0]);

    // Append remaining parts prefixed by the separator
    for (size_t i = 1; i < parts.size(); ++i) {
        out.append(sep);
        out.append(parts[i]);
    }

    return out;
}

int main() {
    // Test cases (asserts are active unless NDEBUG is defined)
    assert(join({"ab", "mn", "hj", "qw"}, "+-") == "ab+-mn+-hj+-qw");
    assert(join({"ab", "mn", "hj", "qw"}, " t ") == "ab t mn t hj t qw");
    assert(join({}, "asd").empty());
    assert(join({"", "", ""}, "asd") == "asdasd");
    assert(join({"", "", ""}, "").empty());

    return 0;
}
