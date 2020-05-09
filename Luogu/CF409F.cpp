#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

using result_type =
std::integer_sequence<int,
        0, 1, 1, 1, 2, 1, 2, 1, 5, 2, 2, 1, 5, 1, 2, 1, 14, 1, 5, 1, 5, 2, 2, 1,
        15, 2, 2, 5, 4, 1, 4, 1, 51, 1, 2, 1, 14, 1, 2, 2, 14, 1, 6, 1, 4, 2, 2,
        1, 52, 2, 5, 1, 5, 1, 15, 2, 13, 2, 2, 1, 13, 1, 2, 4, 267>;

template<typename T, T... elements>
constexpr T get(integer_sequence<T, elements...>, size_t i) {
    constexpr T temp_array[] = {elements...};
    return temp_array[i];
}

int main() {
    int n;
    scanf("%d", &n);
    printf("%d\n", get(result_type(), n));
    return 0;
}