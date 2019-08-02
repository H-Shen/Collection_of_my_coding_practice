/**
 * Some tricks of Cpp.
 *
 * @author Haohu Shen
 * @date 2019/08/02
 */

#include <bits/stdc++.h>

using namespace std;

#define joinTest

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

/**
 * A demo shows how to detect the failure of memory allocation.
 */
inline static
void allocateFailure() {
    int *A;
    try {
        A = new int (12);
        delete A;
    } catch (bad_alloc& e) {
        cout << "ALLOCATION FAILED." << endl;
    }
    // Do not forget make A point to null after release.
    A = nullptr;
}

#define showValueAfterSizeofTest

/**
 * A demo shows the value of sizeof(i++)
 */
inline static
void showValueAfterSizeof() {
    int i{1};
    sizeof(i++);
    assert(i == 1);
    i++;
    assert(i == 2);
}

#define showSizeofEmptyStructClassUnionTest
/**
 * A demo shows the size of any empty struct, class and union is 1;
 */
inline static
void showSizeofEmptyStructClassUnion() {
    struct Struct{};
    class Class{};
    union Union{};
    static_assert(sizeof(Struct) == 1, "The size should be 1.");
    static_assert(sizeof(Class) == 1, "The size should be 1.");
    static_assert(sizeof(Union) == 1, "The size should be 1.");
}

int main() {

#ifdef joinTest
    assert(join({"ab", "mn","hj", "qw"}, "+-") == "ab+-mn+-hj+-qw");
    assert(join({"ab", "mn","hj", "qw"}, " t ") == "ab t mn t hj t qw");
    assert(join({}, "asd").empty());
    assert(join({"","",""}, "asd") == "asdasd");
    assert(join({"","",""},"").empty());
#endif

#ifdef showValueAfterSizeofTest
    showValueAfterSizeof();
#endif

#ifdef showSizeofEmptyStructClassUnionTest
    showSizeofEmptyStructClassUnion();
#endif

    return 0;
}
