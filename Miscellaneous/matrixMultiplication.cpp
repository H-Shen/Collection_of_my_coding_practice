// Matrix multiplication by the definition

#include <bits/stdc++.h>

#define DEBUG

using namespace std;

template<typename T>
vector<vector<int> > matrixMultiplication(const vector<vector<T> > &A, const vector<vector<T> > &B) {
    if (A.empty() || B.empty() || A.at(0).empty() || B.at(0).empty() || A.at(0).size() != B.size()) {
        throw out_of_range("");
    }
    int m = static_cast<int>(A.size());
    int n = static_cast<int>(A.at(0).size());
    int q = static_cast<int>(B.at(0).size());

    vector<vector<T> > C(static_cast<unsigned long>(m), vector<T>(static_cast<unsigned long>(q)));
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < q; ++j) {
            for (int k = 0; k < n; ++k) {
                C.at(i).at(j) += A.at(i).at(k) * B.at(k).at(j);
            }
        }
    }
    return C;
}

template<typename T>
void print2DArray(const vector<vector<T> > &C) {
    int m = static_cast<int>(C.size());
    for (int i = 0; i < m; ++i) {
        int q = static_cast<int>(C.at(i).size());
        for (int j = 0; j < q - 1; ++j) {
            cout << C.at(i).at(j) << " ";
        }
        cout << C.at(i).at(q - 1) << endl;
    }
}

string exec(const char *cmd) {
    char buffer[128];
    string result;
    auto pipe = popen(cmd, "r");
    if (!pipe) {
        throw runtime_error("popen() failed!");
    }
    try {
        while (fgets(buffer, sizeof(buffer), pipe) != nullptr) {
            result += buffer;
        }
    } catch (exception &ex) {
        pclose(pipe);
        cout << ex.what() << endl;
        exit(0);
    }
    pclose(pipe);
    return result;
}

int main() {

#ifdef DEBUG

    mt19937 random_generator((random_device()()));
    uniform_int_distribution<std::mt19937::result_type> random_size_range(1, 15);
    uniform_int_distribution<std::mt19937::result_type> random_value_range(static_cast<unsigned int>(-500), 500);

    int m = random_size_range(random_generator);
    int n = random_size_range(random_generator);
    int q = random_size_range(random_generator);
    vector<vector<int> > A(static_cast<unsigned long>(m), vector<int>(static_cast<unsigned long>(n)));
    for (auto &&i : A) {
        for (auto &&j : i) {
            j = random_value_range(random_generator);
        }
    }

    vector<vector<int> > B(static_cast<unsigned long>(n), vector<int>(static_cast<unsigned long>(q)));
    for (auto &&i : B) {
        for (auto &&j : i) {
            j = random_value_range(random_generator);
        }
    }

    print2DArray(matrixMultiplication(A, B));

#endif
    return 0;
}

