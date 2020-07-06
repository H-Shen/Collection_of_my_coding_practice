#include <bits/extc++.h>

using namespace std;

// OEIS: A006753
integer_sequence<int, 4, 22, 27, 58, 85, 94, 121, 166, 202, 265, 274, 319, 346, 355,
        378, 382, 391, 438, 454, 483, 517, 526, 535, 562, 576, 588,
        627, 634, 636, 645, 648, 654, 663, 666, 690, 706, 728, 729,
        762, 778, 825, 852, 861, 895, 913, 915, 922, 958, 985, 1086,
        1111, 1165> p;

template<typename T, T... elements>
constexpr T get(integer_sequence<T, elements...>, size_t i) {
    constexpr T temp_array[] = {elements...};
    return temp_array[i];
}

int main() {

    int n;
    cin >> n;
    cout << get(p, n - 1) << '\n';

    return 0;
}
