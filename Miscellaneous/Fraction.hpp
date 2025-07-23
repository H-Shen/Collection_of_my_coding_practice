#include <iostream>
#include <numeric>
#include <compare>
#include <stdexcept>
#include <cstdint>
#include <limits>
#include <cassert>

class Fraction {
public:
    int64_t num, den;  // den > 0, gcd(|num|, den) == 1

    // 0/1
    constexpr Fraction() noexcept : num(0), den(1) {}

    // val/1
    constexpr explicit Fraction(int64_t val) noexcept : num(val), den(1) {}

    // a/b (auto reduce)
    constexpr Fraction(int64_t a, int64_t b) : num(a), den(b) {
        if (b == 0) throw std::invalid_argument("Zero denominator");
        normalize();
    }

    // <=> strong ordering, overflow-safe without 128-bit or FP
    constexpr std::strong_ordering operator<=>(const Fraction& other) const noexcept {
        // Different signs? (den > 0 is invariant)
        bool s1 = num < 0;
        bool s2 = other.num < 0;
        if (s1 != s2) return s1 ? std::strong_ordering::less
                                : std::strong_ordering::greater;

        // Same sign -> compare absolute values; if both negative, invert result at the end.
        bool flip = s1;  // both negative => result should be inverted
        int64_t a = num < 0 ? -num : num;
        int64_t b = den;                 // > 0
        int64_t c = other.num < 0 ? -other.num : other.num;
        int64_t d = other.den;           // > 0

        std::strong_ordering r = cmp_abs(a, b, c, d);
        if (flip) r = invert(r);
        return r;
    }

    constexpr bool operator==(const Fraction& other) const noexcept = default;

    // +
    constexpr Fraction operator+(const Fraction& other) const {
        return add_sub(other, true);
    }

    // -
    constexpr Fraction operator-(const Fraction& other) const {
        return add_sub(other, false);
    }

    // *
    constexpr Fraction operator*(const Fraction& other) const {
        check_mul_overflow(num, other.num);
        check_mul_overflow(den, other.den);
        return {num * other.num, den * other.den};
    }

    // /
    constexpr Fraction operator/(const Fraction& other) const {
        if (other.num == 0) throw std::invalid_argument("Division by zero");
        check_mul_overflow(num, other.den);
        check_mul_overflow(den, other.num);
        return {num * other.den, den * other.num};
    }

    // abs
    constexpr Fraction abs() const {
        if (num == std::numeric_limits<int64_t>::min())
            throw std::overflow_error("abs(INT64_MIN) overflow");
        return {num < 0 ? -num : num, den};
    }

    // stream
    friend std::ostream& operator<<(std::ostream& os, const Fraction& f) {
        return os << f.num << '/' << f.den;
    }

private:
    // Reduce and make denominator positive
    constexpr void normalize() {
        if (den < 0) {
            if (den == std::numeric_limits<int64_t>::min() ||
                num == std::numeric_limits<int64_t>::min()) {
                throw std::overflow_error("INT64_MIN normalization");
            }
            num = -num;
            den = -den;
        }
        int64_t g = std::gcd(num < 0 ? -num : num, den);
        num /= g;
        den /= g;
    }

    // Shared add/sub core
    constexpr Fraction add_sub(const Fraction& other, bool add) const {
        int64_t cross1 = num, cross2 = other.num;
        int64_t new_den = den;

        if (den != other.den) {
            check_mul_overflow(num, other.den);
            check_mul_overflow(other.num, den);
            check_mul_overflow(den, other.den);
            cross1 = num * other.den;
            cross2 = other.num * den;
            new_den = den * other.den;
        }

        int64_t new_num = add ? (cross1 + cross2) : (cross1 - cross2);
        check_add_overflow(cross1, add ? cross2 : -cross2);
        return {new_num, new_den};
    }

    // Overflow guards
    static constexpr void check_mul_overflow(int64_t a, int64_t b) {
        if (a == 0 || b == 0) return;
        const int64_t maxv = std::numeric_limits<int64_t>::max();
        const int64_t minv = std::numeric_limits<int64_t>::min();

        if ((a > 0 && b > 0 && a > maxv / b) ||
            (a < 0 && b < 0 && a < maxv / b) ||
            (a > 0 && b < 0 && b < minv / a) ||
            (a < 0 && b > 0 && a < minv / b)) {
            throw std::overflow_error("Multiplication overflow");
        }
    }

    static constexpr void check_add_overflow(int64_t a, int64_t b) {
        const int64_t maxv = std::numeric_limits<int64_t>::max();
        const int64_t minv = std::numeric_limits<int64_t>::min();
        if ((b > 0 && a > maxv - b) || (b < 0 && a < minv - b)) {
            throw std::overflow_error("Addition overflow");
        }
    }

    // Compare |a/b| and |c/d| without overflow, assuming b,d > 0
    static constexpr std::strong_ordering cmp_abs(int64_t a, int64_t b,
                                                  int64_t c, int64_t d) noexcept {
        while (true) {
            int64_t q1 = a / b;
            int64_t q2 = c / d;
            if (q1 != q2) {
                return (q1 < q2) ? std::strong_ordering::less
                                 : std::strong_ordering::greater;
            }
            int64_t r1 = a % b;
            int64_t r2 = c % d;
            if (r1 == 0 || r2 == 0) {
                if (r1 == r2) return std::strong_ordering::equal;
                // One is exact integer, the other still has fractional part
                return (r1 == 0) ? std::strong_ordering::less
                                 : std::strong_ordering::greater;
            }
            a = b; b = r1;
            c = d; d = r2;
        }
    }

    static constexpr std::strong_ordering invert(std::strong_ordering s) noexcept {
        if (s == std::strong_ordering::less)    return std::strong_ordering::greater;
        if (s == std::strong_ordering::greater) return std::strong_ordering::less;
        return std::strong_ordering::equal;
    }
};

// ------------------------------ tests ------------------------------

void test_addition_edge_cases() {
    std::cout << "=== Addition edge cases ===\n";
    Fraction f1(1, 2), f2(1, 3);
    std::cout << f1 << " + " << f2 << " = " << f1 + f2 << '\n';

    Fraction zero(0), one(1);
    std::cout << zero << " + " << one << " = " << zero + one << '\n';

    Fraction neg(-1, 2), pos(3, 4);
    std::cout << neg << " + " << pos << " = " << neg + pos << '\n';

    Fraction a(1, 2), b(-1, 2);
    std::cout << a << " + " << b << " = " << a + b << '\n';

    Fraction c(1, 7), d(2, 7);
    std::cout << c << " + " << d << " = " << c + d << '\n';

    try {
        constexpr int64_t max_val = std::numeric_limits<int64_t>::max();
        Fraction large1(max_val - 1, 2);
        Fraction large2(max_val - 1, 3);
        auto overflow = large1 + large2;
        std::cout << "Unexpected: no overflow " << overflow << '\n';
    } catch (const std::exception& e) {
        std::cout << "Addition overflow caught: " << e.what() << '\n';
    }

    try {
        constexpr int64_t max_val = std::numeric_limits<int64_t>::max();
        Fraction huge1(1, max_val / 2 + 1);
        Fraction huge2(1, max_val / 2 + 1);
        auto overflow = huge1 + huge2;
        std::cout << "Unexpected: denom product no overflow " << overflow << '\n';
    } catch (const std::exception& e) {
        std::cout << "Denominator product overflow caught: " << e.what() << '\n';
    }
}

void test_subtraction_edge_cases() {
    std::cout << "\n=== Subtraction edge cases ===\n";
    Fraction f1(3, 4), f2(1, 4);
    std::cout << f1 << " - " << f2 << " = " << f1 - f2 << '\n';

    Fraction small(1, 4), big(3, 4);
    std::cout << small << " - " << big << " = " << small - big << '\n';

    Fraction self(5, 7);
    auto diff = self - self;
    std::cout << self << " - " << self << " = " << diff << '\n';
    assert(diff == Fraction{0});

    try {
        constexpr int64_t min_val = std::numeric_limits<int64_t>::min();
        Fraction neg_large(min_val / 2, 3);
        Fraction pos_small(1, 4);
        auto underflow = neg_large - pos_small;
        std::cout << "Result: " << underflow << '\n';
    } catch (const std::exception& e) {
        std::cout << "Subtraction underflow caught: " << e.what() << '\n';
    }
}

void test_multiplication_edge_cases() {
    std::cout << "\n=== Multiplication edge cases ===\n";
    Fraction f1(2, 3), f2(3, 5);
    std::cout << f1 << " * " << f2 << " = " << f1 * f2 << '\n';

    Fraction zero(0), nonzero(7, 11);
    std::cout << zero << " * " << nonzero << " = " << zero * nonzero << '\n';

    Fraction one(1), value(5, 7);
    std::cout << one << " * " << value << " = " << one * value << '\n';

    Fraction neg(-2, 3), pos(4, 5);
    std::cout << neg << " * " << pos << " = " << neg * pos << '\n';

    Fraction neg1(-1, 2), neg2(-3, 4);
    std::cout << neg1 << " * " << neg2 << " = " << neg1 * neg2 << '\n';

    try {
        constexpr int64_t max_val = std::numeric_limits<int64_t>::max();
        constexpr int64_t sqrt_max = 3037000499LL;
        Fraction big1(sqrt_max + 1, 1);
        Fraction big2(sqrt_max + 1, 1);
        auto overflow = big1 * big2;
        std::cout << "Unexpected: num product no overflow " << overflow << '\n';
    } catch (const std::exception& e) {
        std::cout << "Numerator product overflow caught: " << e.what() << '\n';
    }

    try {
        constexpr int64_t max_val = std::numeric_limits<int64_t>::max();
        constexpr int64_t sqrt_max = 3037000499LL;
        Fraction big1(1, sqrt_max + 1);
        Fraction big2(1, sqrt_max + 1);
        auto overflow = big1 * big2;
        std::cout << "Unexpected: denom product no overflow " << overflow << '\n';
    } catch (const std::exception& e) {
        std::cout << "Denominator product overflow caught: " << e.what() << '\n';
    }

    try {
        constexpr int64_t min_val = std::numeric_limits<int64_t>::min();
        Fraction min_frac(min_val, 1);
        Fraction two(2, 1);
        auto overflow = min_frac * two;
        std::cout << "Unexpected: INT64_MIN mul no overflow " << overflow << '\n';
    } catch (const std::exception& e) {
        std::cout << "INT64_MIN mul overflow caught: " << e.what() << '\n';
    }
}

void test_division_edge_cases() {
    std::cout << "\n=== Division edge cases ===\n";
    Fraction f1(2, 3), f2(4, 5);
    std::cout << f1 << " / " << f2 << " = " << f1 / f2 << '\n';

    Fraction one(1), value(7, 11);
    std::cout << value << " / " << one << " = " << value / one << '\n';

    Fraction neg(-3, 4), pos(2, 5);
    std::cout << neg << " / " << pos << " = " << neg / pos << '\n';

    Fraction zero(0), nonzero(5, 7);
    std::cout << zero << " / " << nonzero << " = " << zero / nonzero << '\n';

    try {
        Fraction zero_div(0), dividend(1, 2);
        auto error = dividend / zero_div;
        std::cout << "Unexpected: divide-by-zero no exception " << error << '\n';
    } catch (const std::exception& e) {
        std::cout << "Divide-by-zero caught: " << e.what() << '\n';
    }

    try {
        constexpr int64_t max_val = std::numeric_limits<int64_t>::max();
        Fraction small(1, max_val);
        Fraction large(max_val, 1);
        auto overflow = large / small;
        std::cout << "Unexpected: reciprocal mul no overflow " << overflow << '\n';
    } catch (const std::exception& e) {
        std::cout << "Reciprocal overflow caught: " << e.what() << '\n';
    }

    try {
        constexpr int64_t min_val = std::numeric_limits<int64_t>::min();
        Fraction dividend(1, 1);
        Fraction divisor(1, min_val);
        auto overflow = dividend / divisor;
        std::cout << "Result: " << overflow << '\n';
    } catch (const std::exception& e) {
        std::cout << "Denominator INT64_MIN caught: " << e.what() << '\n';
    }
}

void test_construction_edge_cases() {
    std::cout << "\n=== Construction edge cases ===\n";

    try {
        Fraction invalid(1, 0);
        std::cout << "Unexpected: zero denom no exception " << invalid << '\n';
    } catch (const std::exception& e) {
        std::cout << "Zero denom caught: " << e.what() << '\n';
    }

    try {
        constexpr int64_t min_val = std::numeric_limits<int64_t>::min();
        Fraction min_den(1, min_val);
        std::cout << "Unexpected: INT64_MIN denom no exception " << min_den << '\n';
    } catch (const std::exception& e) {
        std::cout << "INT64_MIN denom caught: " << e.what() << '\n';
    }

    try {
        constexpr int64_t min_val = std::numeric_limits<int64_t>::min();
        Fraction min_num_neg_den(min_val, -2);
        std::cout << "Unexpected: INT64_MIN num & neg den no exception " << min_num_neg_den << '\n';
    } catch (const std::exception& e) {
        std::cout << "INT64_MIN num & neg den caught: " << e.what() << '\n';
    }

    constexpr int64_t max_val = std::numeric_limits<int64_t>::max();
    Fraction large_normal(max_val - 1, max_val);
    std::cout << "Large normal: " << large_normal << '\n';
}

void test_abs_edge_cases() {
    std::cout << "\n=== Abs edge cases ===\n";
    Fraction pos(3, 4);
    std::cout << "abs(" << pos << ") = " << pos.abs() << '\n';

    Fraction neg(-5, 7);
    std::cout << "abs(" << neg << ") = " << neg.abs() << '\n';

    Fraction zero(0);
    std::cout << "abs(" << zero << ") = " << zero.abs() << '\n';

    try {
        constexpr int64_t min_val = std::numeric_limits<int64_t>::min();
        Fraction min_frac(min_val, 1);
        auto error = min_frac.abs();
        std::cout << "Unexpected: abs(INT64_MIN) no exception " << error << '\n';
    } catch (const std::exception& e) {
        std::cout << "abs(INT64_MIN) caught: " << e.what() << '\n';
    }
}

void run_test() {
    std::cout << "Fraction exhaustive edge tests\n" << std::string(50, '=') << '\n';
    test_construction_edge_cases();
    test_addition_edge_cases();
    test_subtraction_edge_cases();
    test_multiplication_edge_cases();
    test_division_edge_cases();
    test_abs_edge_cases();
    std::cout << "\nAll tests done!\n";
    return 0;
}
