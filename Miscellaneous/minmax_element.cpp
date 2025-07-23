#include <iostream>
#include <vector>
#include <span>
#include <optional>
#include <concepts>

template<typename T>
concept Comparable = std::totally_ordered<T>;

template<Comparable T>
constexpr std::optional<std::pair<T, T>> minmax(std::span<const T> arr) {
    const auto n = arr.size();

    if (n == 0) {
        return std::nullopt;
    }

    if (n == 1) {
        return std::pair{arr[0], arr[0]};
    }

    T min_val, max_val;
    std::size_t start;

    // 处理前两个元素
    if (arr[0] < arr[1]) {
        min_val = arr[0];
        max_val = arr[1];
    } else {
        min_val = arr[1];
        max_val = arr[0];
    }

    // 确定循环起始位置
    if (n & 1) {
        // 奇数长度：第一个元素单独处理
        if (arr[0] < min_val) min_val = arr[0];
        else if (arr[0] > max_val) max_val = arr[0];
        start = 1;
    } else {
        start = 2;
    }

    // 成对处理剩余元素
    for (auto i = start; i < n - 1; i += 2) {
        const auto &left = arr[i];
        const auto &right = arr[i + 1];

        // 处理相等情况：相等时保持现有的min/max不变
        if (left < right) {
            if (right > max_val) max_val = right;
            if (left < min_val) min_val = left;
        } else if (left > right) {
            if (left > max_val) max_val = left;
            if (right < min_val) min_val = right;
        }
        // left == right 时不需要更新任何值
    }

    return std::pair{min_val, max_val};
}

// 便捷重载：支持vector、数组等
template<Comparable T>
constexpr std::optional<std::pair<T, T>> minmax(const std::vector<T> &vec) {
    return minmax(std::span{vec});
}

template<Comparable T, std::size_t N>
constexpr std::optional<std::pair<T, T>> minmax(const T (&arr)[N]) {
    return minmax(std::span{arr, N});
}

template<Comparable T>
constexpr std::optional<std::pair<T, T>> minmax(std::initializer_list<T> list) {
    return minmax(std::span{list.begin(), list.size()});
}

int main() {
    // 测试用例
    std::vector<int> A1 = {1, 2, 3, 4, 1};
    if (auto result = minmax(A1)) {
        auto [min_val, max_val] = *result;
        std::cout << "[" << min_val << ", " << max_val << "]\n";
    }

    std::vector<int> A2 = {1, 2};
    if (auto result = minmax(A2)) {
        auto [min_val, max_val] = *result;
        std::cout << "[" << min_val << ", " << max_val << "]\n";
    }

    std::vector<int> A3 = {1, 1};
    if (auto result = minmax(A3)) {
        auto [min_val, max_val] = *result;
        std::cout << "[" << min_val << ", " << max_val << "]\n";
    }

    std::vector<int> A4 = {0};
    if (auto result = minmax(A4)) {
        auto [min_val, max_val] = *result;
        std::cout << "[" << min_val << ", " << max_val << "]\n";
    }

    // 测试初始化列表
    if (auto result = minmax({5, 2, 8, 1, 9})) {
        auto [min_val, max_val] = *result;
        std::cout << "[" << min_val << ", " << max_val << "]\n";
    }

    // 测试空数组
    std::vector<int> empty;
    if (auto result = minmax(empty)) {
        auto [min_val, max_val] = *result;
        std::cout << "[" << min_val << ", " << max_val << "]\n";
    } else {
        std::cout << "Empty array handled gracefully\n";
    }

    return 0;
}
