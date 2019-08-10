#include <string>
#include <cassert>

using namespace std;

#define DEBUG

/**
 * A function that three-way compares two integers as strings.
 * @return -1 if lhs < rhs, 0 if lhs == rhs, 1 if lhs > rhs
 */
inline static
int threeWayComparator(const string &lhs, const string &rhs) {

    // Case 1: lhs < 0 and rhs >= 0
    if (lhs.front() == '-' && rhs.front() != '-')
        return -1;
    // Case 2: lhs >= 0 and rhs < 0
    if (lhs.front() != '-' && rhs.front() == '-')
        return 1;
    // Case 3: lhs < 0 and rhs < 0
    if (lhs.front() == '-' && rhs.front() == '-') {
        return threeWayComparator(string(rhs, 1), string(lhs, 1));
    }

    // Case 4: lhs >= 0 and rhs >= 0
    // Sub-case 1: lhs = rhs
    if (lhs == rhs)
        return 0;
    // Sub-case 2-1: lhs != rhs and length(lhs) > length(rhs)
    if (lhs.size() > rhs.size())
        return 1;
    // Sub-case 2-2: lhs != rhs and length(lhs) < length(rhs)
    if (lhs.size() < rhs.size())
        return -1;
    // Sub-case 2-3: lhs != rhs and length(lhs) == length(rhs)
    for (size_t i = 0; i < lhs.size(); i++) {
        if (lhs.at(i) == rhs.at(i))
            continue;
        if (lhs.at(i) > rhs.at(i))
            return 1;
        else
            return -1;
    }
    return 0;
}

int main() {

#ifdef DEBUG
    assert(threeWayComparator("1", "192379123") == -1);
    assert(threeWayComparator("1123123", "192379123") == -1);
    assert(threeWayComparator("0", "0") == 0);
    assert(threeWayComparator("-12", "-13") == 1);
    assert(threeWayComparator("-12", "13") == -1);
    assert(threeWayComparator("-1", "-1312398123") == 1);
    assert(threeWayComparator("1238812739871923790127031121213", "-1238812739871923790127031121213") == 1);
#endif

    return 0;
}