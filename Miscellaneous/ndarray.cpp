#include <array>
#include <cstddef>
#include <iostream>

// ================= ndarray =================
namespace ndarray {

    namespace detail {
        template<typename T, std::size_t N, std::size_t... Ns>
        struct narray {
            using type = std::array<typename narray<T, Ns...>::type, N>;
        };
        template<typename T, std::size_t N>
        struct narray<T, N> {
            using type = std::array<T, N>;
        };
    } // namespace detail

    template<typename T, std::size_t... Ns>
    using array_t = typename detail::narray<T, Ns...>::type;

    template<typename T, std::size_t... Ns>
    constexpr array_t<T, Ns...> Array() {
        return {}; // default value
    }

// ---- length<Dim>(v) ----
    template<std::size_t Dim, class V>
    constexpr std::size_t length(const V &v) {
        if constexpr (Dim == 0) return v.size();
        else return length<Dim - 1>(v[0]);
    }

} // namespace ndarray
// ==========================================

int main() {

    // Compile-time usage
    constexpr auto a = ndarray::Array<int, 3, 4, 5>();
    static_assert(ndarray::length<0>(a) == 3);
    static_assert(ndarray::length<1>(a) == 4);
    static_assert(ndarray::length<2>(a) == 5);
    std::cout << a[0][0][0] << '\n';

    // Runtime usage
    auto b = ndarray::Array<int, 3, 4, 5>();
    for (std::size_t i = 0; i < ndarray::length<0>(b); ++i)
        for (std::size_t j = 0; j < ndarray::length<1>(b); ++j)
            for (std::size_t k = 0; k < ndarray::length<2>(b); ++k)
                b[i][j][k] = int(i + j + k);

    std::cout << b[1][2][3] << '\n'; // 1+2+3 = 6
}
