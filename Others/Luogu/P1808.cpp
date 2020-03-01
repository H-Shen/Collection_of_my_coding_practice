#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

constexpr int MAXN = 26;
constexpr int MAX_STRING_LENGTH = 105;
char cstr[MAX_STRING_LENGTH];

struct myHashFunc {
    std::size_t operator()(const array<int, MAXN>& A) const {
        std::size_t h = 0;
        for (const auto &i : A) {
            h ^= std::hash<int>{}(i)  + 0x9e3779b9 + (h << 6) + (h >> 2);
        }
        return h;
    }
};

unordered_map<array<int, MAXN>, int, myHashFunc> unmap;

int main() {

    int n;
    scanf("%d", &n);
    while (n--) {
        scanf("%s", cstr);
        array<int, MAXN> temp_array{};
        for (int i = 0; cstr[i] != '\0'; ++i) {
            ++temp_array.at(cstr[i] - 'A');
        }
        ++unmap[temp_array];
    }
    printf("%zu\n", unmap.size());

    return 0;
}