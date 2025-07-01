// MPQHash.cpp
#include <array>
#include <cassert>
#include <cctype>
#include <cstdint>
#include <functional>
#include <iostream>
#include <optional>
#include <random>
#include <stdexcept>
#include <string>
#include <string_view>
#include <unordered_map>
#include <vector>

namespace MPQ {

// Fixed-width aliases
using HashType    = std::uint32_t;
using BucketIndex = std::size_t;

// MPQ constants
constexpr HashType HASH_OFFSET        = 0;
constexpr HashType HASH_A             = 1;
constexpr HashType HASH_B             = 2;
constexpr HashType CRYPT_TABLE_LENGTH = 0x500;

// Growth & load-factor policy
constexpr BucketIndex INITIAL_BUCKETS = 8;
constexpr double      MAX_LOAD_FACTOR = 0.7;

/**
 * @brief Compile-time generation of Blizzard's MPQ crypt table.
 */
consteval auto generate_crypt_table() -> std::array<HashType, CRYPT_TABLE_LENGTH> {
    std::array<HashType, CRYPT_TABLE_LENGTH> table{};
    HashType seed = 0x0010'0001;
    for (HashType i = 0; i < 0x100; ++i) {
        for (int j = 0; j < 5; ++j) {
            HashType idx = i + j * 0x100;
            seed = (seed * 125 + 3) % 0x2AAAAB;
            HashType tmp1 = (seed & 0xFFFF) << 16;
            seed = (seed * 125 + 3) % 0x2AAAAB;
            HashType tmp2 = (seed & 0xFFFF);
            table[idx] = tmp1 | tmp2;
        }
    }
    return table;
}
constexpr auto CRYPT_TABLE = generate_crypt_table();

/**
 * @brief Normalize and uppercase a char in a locale-independent way.
 */
static constexpr auto normalize_char(char c) noexcept -> unsigned char {
    return static_cast<unsigned char>(std::toupper(static_cast<unsigned char>(c)));
}

/**
 * @brief The core MPQ hash function (three hash types: OFFSET, A, B).
 */
constexpr auto mpq_hash(std::string_view s, HashType hash_type) noexcept -> HashType {
    HashType seed1 = 0x7FED7FED, seed2 = 0xD34D10CC;
    for (char c: s) {
        unsigned char uc = normalize_char(c);
        HashType idx = (hash_type << 8) + uc;
        seed1 = CRYPT_TABLE[idx] ^ (seed1 + seed2);
        seed2 = uc + seed1 + seed2 + (seed2 << 5) + 3;
    }
    return seed1;
}

/**
 * @brief A single bucket entry.
 */
template<typename T>
struct Node {
    HashType      h_a{};
    HashType      h_b{};
    bool          occupied{};
    std::string   key;    // store own copy
    T             value{};
};

/**
 * @brief Open-addressing hash table specialized for MPQ string keys.
 */
template<typename T>
class HashTable {
public:
    explicit HashTable(BucketIndex buckets = INITIAL_BUCKETS)
      : _size(buckets), _buckets(buckets) {}

    bool put(std::string_view key, T value) {
        if (_elements + 1 > _size * MAX_LOAD_FACTOR) {
            rehash(_size * 2);
        }
        return insert_no_rehash(key, std::move(value));
    }

    [[nodiscard]] auto get(std::string_view key) const noexcept -> std::optional<T> {
        auto pos = find_pos(key);
        if (pos == npos) return std::nullopt;
        return _buckets[pos].value;
    }

    [[nodiscard]] auto size()     const noexcept -> BucketIndex { return _elements; }
    [[nodiscard]] auto capacity() const noexcept -> BucketIndex { return _size; }

    template<typename Func>
    void for_each(Func func) const {
        for (auto const &n : _buckets)
            if (n.occupied)
                func(n.key, n.value);
    }

private:
    static constexpr BucketIndex npos = static_cast<BucketIndex>(-1);

    BucketIndex          _size{};
    BucketIndex          _elements{};
    std::vector<Node<T>> _buckets;

    auto insert_no_rehash(std::string_view key, T &&value) -> bool {
        const HashType hm = mpq_hash(key, HASH_OFFSET);
        HashType ha = mpq_hash(key, HASH_A);
        HashType hb = mpq_hash(key, HASH_B);
        auto idx = hm % _size;

        for (BucketIndex i = 0; i < _size; ++i, idx = (idx + 1) % _size) {
            auto &node = _buckets[idx];
            if (!node.occupied) {
                node.occupied = true;
                node.h_a      = ha;
                node.h_b      = hb;
                node.key      = std::string(key);
                node.value    = std::move(value);
                ++_elements;
                return true;
            }
            if (node.h_a == ha && node.h_b == hb && node.key == key) {
                node.value = std::move(value);
                return true;
            }
        }
        return false;
    }

    [[nodiscard]] auto find_pos(std::string_view key) const noexcept -> BucketIndex {
        const HashType hm = mpq_hash(key, HASH_OFFSET);
        HashType ha = mpq_hash(key, HASH_A);
        HashType hb = mpq_hash(key, HASH_B);
        auto idx = hm % _size;

        for (BucketIndex i = 0; i < _size; ++i, idx = (idx + 1) % _size) {
            auto const &node = _buckets[idx];
            if (!node.occupied) return npos;
            if (node.h_a == ha && node.h_b == hb && node.key == key) {
                return idx;
            }
        }
        return npos;
    }

    void rehash(BucketIndex new_size) {
        std::vector<Node<T>> old = std::move(_buckets);
        _size      = new_size;
        _buckets   = std::vector<Node<T>>(new_size);
        _elements  = 0;
        for (auto &n : old) {
            if (n.occupied)
                insert_no_rehash(n.key, std::move(n.value));
        }
    }
};

} // namespace MPQ

// ======================= Tests =======================
int main() {
    // --- Smoke tests ---
    {
        MPQ::HashTable<int> table;
        assert(table.size() == 0);
        assert(table.capacity() >= 8);

        assert(table.put("orc",   10));
        assert(table.put("elf",   20));
        assert(table.put("human", 30));
        assert(table.put("orc",   40));  // overwrite

        auto o = table.get("orc");
        assert(o && *o == 40);
        assert(!table.get("dwarf"));

        for (int i = 0; i < 100; ++i)
            assert(table.put("key" + std::to_string(i), i));

        assert(table.size() == 3 + 100);
        table.for_each([](std::string_view, const int v){
            assert(v >= 0);
        });
        std::cout << "[Smoke] all tests passed\n";
    }

    // --- Randomized consistency tests ---
    {
        std::mt19937_64 rng{std::random_device{}()};
        std::uniform_int_distribution len_dist(1, 16);
        // fix: use int distribution, then cast to char
        std::uniform_int_distribution<> char_dist('a', 'z');
        std::uniform_int_distribution val_dist(0, 1'000'000);

        constexpr int N = 50'000;
        MPQ::HashTable<int> mpq_table;
        std::unordered_map<std::string,int> ref;

        // generate and insert
        for (int i = 0; i < N; ++i) {
            const int len = len_dist(rng);
            std::string key;
            key.reserve(len);
            for (int j = 0; j < len; ++j)
                key += static_cast<char>(char_dist(rng));
            int v = val_dist(rng);

            ref[key] = v;
            if (!mpq_table.put(key, v)) {
                std::cerr << "MPQTable.put failed at insertion " << i << "\n";
                return 1;
            }
        }

        // verify all present keys
        for (auto const& [k, v] : ref) {
            if (auto o = mpq_table.get(k); !o || *o != v) {
                std::cerr << "Mismatch for key \"" << k
                          << "\": expected " << v
                          << ", got " << (o ? std::to_string(*o) : "none")
                          << "\n";
                return 1;
            }
        }

        // test lookups for some absent keys
        for (int i = 0; i < 1000; ++i) {
            std::string key = "zz_absent_" + std::to_string(i);
            if (ref.contains(key)) continue;
            if (mpq_table.get(key)) {
                std::cerr << "Unexpected hit for absent key \"" << key << "\"\n";
                return 1;
            }
        }

        std::cout << "[Random] all " << N << " insertions and lookups matched std::unordered_map\n";
    }

    std::cout << "All tests passed successfully.\n";
    return 0;
}
