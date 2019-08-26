/**
 * Print typename in g++ -std=c++17
 */

#include <cxxabi.h>
#include <cassert>
#include <memory>
#include <iostream>
#include <string>

template <typename T>
inline static
std::string getTypename(const T &t) {

    int status;
    std::unique_ptr<char[], void (*)(void*)> result(
            abi::__cxa_demangle(typeid(t).name(), nullptr, nullptr, &status), std::free);

    assert(result.get());
    return std::string(result.get());
}

struct S {};
inline S o{};

int main() {

    std::tuple A(2, "3", "abcd", std::string("4"), o);
    const auto& [x, y, z, w, v] = A;
    std::cout << getTypename(x) << std::endl;
    std::cout << getTypename(y) << std::endl;
    std::cout << getTypename(z) << std::endl;
    std::cout << getTypename(w) << std::endl;
    std::cout << getTypename(v) << std::endl;
    return 0;
}