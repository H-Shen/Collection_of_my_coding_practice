/**
 * Print typename in g++ -std=c++17
 */

#include <cxxabi.h>
#include <cassert>
#include <memory>
#include <iostream>
#include <string>

template <typename T>
std::string printTypename(const T &t) {

    int status;
    const char* mangled(typeid(t).name());
    std::unique_ptr<char[], void (*)(void*)> result(
            abi::__cxa_demangle(mangled, nullptr, nullptr, &status), std::free);

    assert(result.get());
    return std::string(result.get());
}

struct S {};

int main() {

    std::tuple A(2, "3", "abcd", std::string("4"), S());
    const auto& [x, y, z, w, v]{A};
    std::cout << printTypename(x) << std::endl;
    std::cout << printTypename(y) << std::endl;
    std::cout << printTypename(z) << std::endl;
    std::cout << printTypename(w) << std::endl;
    std::cout << printTypename(v) << std::endl;
    return 0;
}