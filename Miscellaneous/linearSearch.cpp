/**
 * Modern C++20 implementation of linear search algorithm
 * Requires: C++20 compatible compiler
 * Compile examples:
 *   - GCC: g++ -std=c++20 -Wall -Wextra -O2 linearSearch.cpp -o linearSearch
 *   - Clang: clang++ -std=c++20 -Wall -Wextra -O2 linearSearch.cpp -o linearSearch
 *   - MSVC: cl /std:c++20 /W4 /O2 linearSearch.cpp
 *
 * @author Haohu Shen (modernized)
 * @date 2025/07/03
 */
#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
#include <ranges>
#include <optional>
#include <concepts>
#include <functional>

namespace linear_search {

    /**
     * @brief Performs linear search on a container
     * @tparam Container The container type (must be a range)
     * @tparam T The value type to search for
     * @param container The container to search in
     * @param key The value to search for
     * @return Optional index if found, std::nullopt otherwise
     *
     * @precondition container is a valid range
     * @postcondition container and key are unchanged
     */
    template<std::ranges::range Container, typename T>
    requires std::equality_comparable_with<std::ranges::range_value_t<Container>, T>
    [[nodiscard]] constexpr auto FindIndex(const Container& container, const T& key)
        -> std::optional<std::size_t> {

        if (std::ranges::empty(container)) {
            return std::nullopt;
        }

        auto it = std::ranges::find(container, key);
        if (it != std::ranges::end(container)) {
            return static_cast<std::size_t>(std::ranges::distance(std::ranges::begin(container), it));
        }

        return std::nullopt;
    }

    /**
     * @brief Performs linear search with custom comparator
     * @tparam Container The container type (must be a range)
     * @tparam T The value type to search for
     * @tparam Predicate The predicate type for comparison
     * @param container The container to search in
     * @param key The value to search for
     * @param predicate The predicate for comparison
     * @return Optional index if found, std::nullopt otherwise
     */
    template<std::ranges::range Container, typename T, typename Predicate>
    requires std::predicate<Predicate, std::ranges::range_value_t<Container>, T>
    [[nodiscard]] constexpr auto FindIndexIf(const Container& container, const T& key, Predicate predicate)
        -> std::optional<std::size_t> {

        if (std::ranges::empty(container)) {
            return std::nullopt;
        }

        auto it = std::ranges::find_if(container, [&](const auto& element) {
            return predicate(element, key);
        });

        if (it != std::ranges::end(container)) {
            return static_cast<std::size_t>(std::ranges::distance(std::ranges::begin(container), it));
        }

        return std::nullopt;
    }

    /**
     * @brief Legacy wrapper that returns -1 instead of std::nullopt for compatibility
     * @tparam Container The container type
     * @tparam T The value type to search for
     * @param container The container to search in
     * @param key The value to search for
     * @return Index if found, -1 otherwise
     */
    template<std::ranges::range Container, typename T>
    requires std::equality_comparable_with<std::ranges::range_value_t<Container>, T>
    [[nodiscard]] constexpr int FindIndexLegacy(const Container& container, const T& key) {
        auto result = FindIndex(container, key);
        return result.has_value() ? static_cast<int>(result.value()) : -1;
    }

    /**
     * @brief Returns iterator to found element or end iterator
     * @tparam Container The container type
     * @tparam T The value type to search for
     * @param container The container to search in
     * @param key The value to search for
     * @return Iterator to found element or end iterator
     */
    template<std::ranges::range Container, typename T>
    requires std::equality_comparable_with<std::ranges::range_value_t<Container>, T>
    [[nodiscard]] constexpr auto FindIterator(const Container& container, const T& key) {
        return std::ranges::find(container, key);
    }

} // namespace linear_search

// Example usage and demonstration
int main() {
    // Test with various container types
    const std::vector<int> kVec = {2, 3, 3, 4, 7, 7, 7, 9};

    std::cout << "=== Modern C++20 Linear Search Demo ===\n\n";

    // Test 1: Basic search with std::optional return
    std::cout << "Test 1: Modern approach with std::optional\n";
    for (const auto& val : {2, 7, 123}) {
        if (auto index = linear_search::FindIndex(kVec, val)) {
            std::cout << "Found " << val << " at index " << *index << '\n';
        } else {
            std::cout << "Value " << val << " not found\n";
        }
    }

    std::cout << "\nTest 2: Legacy approach (returns -1)\n";
    for (const auto& val : {2, 7, 123}) {
        int index = linear_search::FindIndexLegacy(kVec, val);
        if (index != -1) {
            std::cout << "Found " << val << " at index " << index << '\n';
        } else {
            std::cout << "Value " << val << " not found\n";
        }
    }

    std::cout << "\nTest 3: Custom comparator (find first element >= key)\n";
    for (const auto& val : {1, 5, 10}) {
        if (auto index = linear_search::FindIndexIf(kVec, val, std::greater_equal<>{})) {
            std::cout << "First element >= " << val << " found at index " << *index
                      << " (value: " << kVec[*index] << ")\n";
        } else {
            std::cout << "No element >= " << val << " found\n";
        }
    }

    std::cout << "\nTest 4: Working with different container types\n";
    const std::array<double, 5> kArr = {1.1, 2.2, 3.3, 4.4, 5.5};
    if (auto index = linear_search::FindIndex(kArr, 3.3)) {
        std::cout << "Found 3.3 in array at index " << *index << '\n';
    }

    std::cout << "\nTest 5: Using iterator-based approach\n";
    auto it = linear_search::FindIterator(kVec, 7);
    if (it != kVec.end()) {
        std::cout << "Found 7 at position " << std::distance(kVec.begin(), it) << '\n';
    }

    return 0;
}
