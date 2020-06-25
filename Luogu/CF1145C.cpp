#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

std::integer_sequence<int,
        15, 14, 12, 13, 8, 9, 10, 11, 0, 1, 2, 3, 4, 5, 6, 7> p;

template<typename T, T... elements>
constexpr T get(integer_sequence<T, elements...>, size_t i) {
    constexpr T temp_array[] = {elements...};
    return temp_array[i];
}

int main() {

    int n;
    cin >> n;
    cout << get(p, n) << endl;

    return 0;
}