// An example that uses std::boyer_moore_horspool_searcher
//
#include <bits/extc++.h>

using namespace std;

constexpr int MAX_NAME_LEN = 25;
constexpr int MAX_STR_LEN = 205;
char name[MAX_NAME_LEN];
char s[MAX_STR_LEN];

inline const string needle = "sos";
inline const auto searcher = std::boyer_moore_horspool_searcher(
        needle.begin(), needle.end());

struct Node {
    Node(string name, string str, int time) : name(std::move(name)),
                                              str(std::move(str)),
                                              occurrence(time) {}

    friend ostream &operator<<(ostream &os, const Node &node) {
        os << "name: " << node.name << " str: " << node.str << " occurrence: "
           << node.occurrence;
        return os;
    }

    string name;
    string str;
    int occurrence;
};

int get_occurrences(const string &str) {
    int occurrence = 0;
    for (auto it = search(str.begin(), str.end(), searcher); it != str.end();) {
        ++occurrence;
        ++it;
        it = search(it, str.end(), searcher);
    }
    return occurrence;
}

int main() {

    int n;
    vector<Node> A;
    scanf("%d", &n);
    while (n--) {
        scanf("%s %s", name, s);
        A.emplace_back(Node(name, s, get_occurrences(s)));
    }
    int maximal_occurrence = max_element(A.begin(), A.end(),
                                         [](const Node &lhs, const Node &rhs) {
                                             return lhs.occurrence < rhs.occurrence;
                                         })->occurrence;
    bool first_item = true;
    for (const auto &[i, j, k] : A) {
        if (k == maximal_occurrence) {
            if (first_item) {
                first_item = false;
            } else {
                putchar_unlocked(' ');
            }
            printf("%s", i.c_str());
        }
    }
    if (!first_item) {
        putchar_unlocked('\n');
    }
    printf("%d\n", maximal_occurrence);

    return 0;
}
