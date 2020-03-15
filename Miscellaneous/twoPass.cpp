/**
 * An implementation of the two-pass algorithm.
 */

#include <vector>
#include <random>

using namespace std;

namespace UnionFindSet {

    int MAXN = 0;
    vector<int> Father; // Father nodes
    vector<int> Rank; // Rank

    int find(int x) {
        if (x != Father.at(x))
            Father.at(x) = find(Father.at(x));
        return Father.at(x);
    }

    void merge(int x, int y) {

        x = find(x);
        y = find(y);

        if (Rank.at(x) > Rank.at(y)) {
            Father.at(y) = x;
        } else {
            Father.at(x) = y;
            if (Rank.at(x) == Rank.at(y))
                ++Rank.at(y);
        }
    }

    void reset() {
        for (int i = 0; i < MAXN; i++) {
            Father.at(i) = i;
            Rank.at(i) = 0;
        }
    }
}

// Description: ConnectedComponentLabeling collects
// all methods and data members I need to calculate the number of regions of '1'
// in a 2D array using two-pass algorithm
namespace ConnectedComponentLabeling {

    vector<vector<char> > A;

    int twoPass() {

        int numberOfRegions = 0;
        if (A.empty()) {
            return numberOfRegions;
        }
        int row = static_cast<int>(A.size());
        int col = static_cast<int>(A.front().size());
        int down;
        int right;

        // first pass
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (A.at(i).at(j) == '1') {
                    down = i + 1;
                    right = j + 1;
                    // merge the current pos and the south pos
                    if (down < row && A.at(down).at(j) == '1') {
                        UnionFindSet::merge(col * i + j, col * down + j);
                    }
                    // merge the current pos and the east pos
                    if (right < col && A.at(i).at(right) == '1') {
                        UnionFindSet::merge(col * i + j, col * i + right);
                    }
                }
            }
        }

        // second pass, we calculate the number of disjoint sets by counting
        // the number of roots in each disjoint set
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                int currentPosition = col * i + j;
                if (A.at(i).at(j) == '1' &&
                    UnionFindSet::Father.at(currentPosition) ==
                    currentPosition) {
                    ++numberOfRegions;
                }
            }
        }

        return numberOfRegions;
    }
}

int main() {

    int row = 50;
    int col = 50;

    // Resize A
    ConnectedComponentLabeling::A.resize(row);
    for (auto &&i : ConnectedComponentLabeling::A) {
        i.resize(col);
    }

    // Initialize UnionFindSet
    UnionFindSet::MAXN = row * col + 100;
    UnionFindSet::Father.resize(UnionFindSet::MAXN);
    UnionFindSet::Rank.resize(UnionFindSet::MAXN);
    UnionFindSet::reset();

    // Randomly fill A with '1' and '0'
    std::random_device dev;
    std::mt19937 random_generator(dev());
    std::uniform_int_distribution<int> dist(0, 1);
    for (auto &i : ConnectedComponentLabeling::A) {
        for (auto &j : i) {
            j = static_cast<char>(dist(random_generator)) + '0';
        }
    }

    // Print A
    for (const auto &i : ConnectedComponentLabeling::A) {
        for (const auto &j : i) {
            printf("%c", j);
        }
        putchar('\n');
    }
    // Print the number of regions of '1'
    printf("Number of regions: %d\n", ConnectedComponentLabeling::twoPass());

    return 0;
}
