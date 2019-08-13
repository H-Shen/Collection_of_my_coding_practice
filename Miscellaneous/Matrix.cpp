#include <cassert>

#include <iostream>
#include <string>
#include <vector>
#include <random>

#define DEBUG

template<typename T>
class Matrix {
private:
    T **matrix = nullptr;
    size_t row = 0;
    size_t col = 0;
public:
    size_t getRow() const {
        return row;
    }

    size_t getCol() const {
        return col;
    }

    // Constructor with the value of rows and columns.
    Matrix(size_t row_, size_t col_) : row(row_), col(col_) {
        try {
            matrix = new T *[row];
            for (size_t i = 0; i != row; ++i) {
                matrix[i] = new T[col];
            }
        } catch (std::bad_alloc &) {
            assert(0); /* Memory allocation failure */
        }
    }

    Matrix(const std::initializer_list<std::initializer_list<T> > &rhs) {
        // Check if every row in A has the same size
        if (rhs.size() != 0) {
            size_t sizeOfLastRow = 0;
            bool firstRow = true;
            for (const auto &i : rhs) {
                if (firstRow) {
                    firstRow = false;
                    sizeOfLastRow = i.size();
                } else if (sizeOfLastRow != i.size()) {
                    // Throw an exception if it is not the case that every row in A has the same size
                    throw std::out_of_range("");
                }
            }
            row = rhs.size();
            col = sizeOfLastRow;
            try {
                matrix = new T *[row];
                for (size_t i = 0; i != row; ++i) {
                    matrix[i] = new T[col];
                }
            } catch (std::bad_alloc &) {
                assert(0); /* Memory allocation failure */
            }
            size_t currentRow = 0;
            size_t currentCol;
            for (const auto &i : rhs) {
                currentCol = 0;
                for (const auto &j : i) {
                    this->at(currentRow, currentCol) = j;
                    ++currentCol;
                }
                ++currentRow;
            }
        }
    }

    explicit Matrix(const std::vector<std::vector<T> > &rhs) {
        // Check if every row in A has the same size
        if (!rhs.empty()) {
            size_t sizeOfLastRow = 0;
            bool firstRow = true;
            for (const auto &i : rhs) {
                if (firstRow) {
                    firstRow = false;
                    sizeOfLastRow = i.size();
                } else if (sizeOfLastRow != i.size()) {
                    // Throw an exception if it is not the case that every row in A has the same size
                    throw std::out_of_range("");
                }
            }
            row = rhs.size();
            col = sizeOfLastRow;
            try {
                matrix = new T *[row];
                for (size_t i = 0; i != row; ++i) {
                    matrix[i] = new T[col];
                }
            } catch (std::bad_alloc &) {
                assert(0); /* Memory allocation failure */
            }
            size_t currentRow = 0;
            size_t currentCol;
            for (const auto &i : rhs) {
                currentCol = 0;
                for (const auto &j : i) {
                    this->at(currentRow, currentCol) = j;
                    ++currentCol;
                }
                ++currentRow;
            }
        }
    }

    // Copy constructor
    Matrix(const Matrix<T> &rhs) {
        if (row != 0) {
            clear();
        }
        row = rhs.row;
        col = rhs.col;
        try {
            matrix = new T *[row];
            for (size_t i = 0; i != row; ++i) {
                matrix[i] = new T[col];
            }

            // copy values
            for (size_t i = 0; i != row; ++i) {
                for (size_t j = 0; j != col; ++j) {
                    this->at(i, j) = rhs.at(i, j);
                }
            }

        } catch (std::bad_alloc &) {
            assert(0); /* Memory allocation failure */
        }
    }

    T &at(const size_t &i, const size_t &j) const {
        if (i >= row || j >= col) {
            throw std::out_of_range("");
        }
        return matrix[i][j];
    }

    Matrix &operator=(const Matrix<T> &rhs) {
        if (this != &rhs) {
            clear();
            row = rhs.row;
            col = rhs.col;
            try {
                matrix = new T *[row];
                for (size_t i = 0; i != row; ++i) {
                    matrix[i] = new T[col];
                }

                // copy values
                for (size_t i = 0; i != row; ++i) {
                    for (size_t j = 0; j != col; ++j) {
                        this->at(i, j) = rhs.at(i, j);
                    }
                }

            } catch (std::bad_alloc &) {
                assert(0); /* Memory allocation failure */
            }
        }
        return *this;
    }

    Matrix operator+(const Matrix &rhs) const {

        if (row != rhs.row || col != rhs.col) {
            throw std::out_of_range("");
        }

        Matrix result(rhs.row, rhs.col);
        for (size_t i = 0; i != row; ++i) {
            for (size_t j = 0; j != col; ++j) {
                result.at(i, j) = this->at(i, j) + rhs.at(i, j);
            }
        }
        return result;
    }

    Matrix operator-(const Matrix &rhs) const {

        if (row != rhs.row || col != rhs.col) {
            throw std::out_of_range("");
        }

        Matrix result(rhs.row, rhs.col);
        for (size_t i = 0; i != row; ++i) {
            for (size_t j = 0; j != col; ++j) {
                result.at(i, j) = this->at(i, j) - rhs.at(i, j);
            }
        }
        return result;
    }

    Matrix operator*(const Matrix &rhs) const {
        if (row == 0 || rhs.row == 0 || col != rhs.row) {
            throw std::out_of_range("");
        }
        Matrix result(row, rhs.col);
        for (size_t i = 0; i != row; ++i) {
            for (size_t j = 0; j != col; ++j) {
                for (size_t k = 0; k != rhs.col; ++k) {
                    result.at(i, j) = result.at(i, j) + this->at(i, k) * rhs.at(k, j);
                }
            }
        }
        return result;
    }

    // Clear
    void clear() {
        if (row != 0) {
            for (size_t i = 0; i != row; ++i) {
                delete matrix[i];
                matrix[i] = nullptr;
            }
            delete matrix;
            matrix = nullptr;
            row = 0;
            col = 0;
        }
    }

    void fill(const T &val) {
        for (size_t i = 0; i != row; ++i) {
            for (size_t j = 0; j != col; ++j) {
                this->at(i, j) = val;
            }
        }
    }

    std::string toString() const {
        std::string result;
        bool firstItem;
        for (size_t i = 0; i != row; ++i) {
            firstItem = true;
            for (size_t j = 0; j != col; ++j) {
                if (firstItem) {
                    firstItem = false;
                } else {
                    result.push_back(' ');
                }
                result.append(std::to_string(this->at(i, j)));
            }
            if (i != row - 1) {
                result.push_back('\n');
            }
        }
        return result;
    }
};

template<typename T>
std::vector<std::vector<int> >
matrixMultiplication(const std::vector<std::vector<T> > &A, const std::vector<std::vector<T> > &B) {
    if (A.empty() || B.empty() || A.at(0).empty() || B.at(0).empty() || A.at(0).size() != B.size()) {
        throw std::out_of_range("");
    }
    int m = static_cast<int>(A.size());
    int n = static_cast<int>(A.at(0).size());
    int q = static_cast<int>(B.at(0).size());

    std::vector<std::vector<T> > C(static_cast<unsigned long>(m), std::vector<T>(static_cast<unsigned long>(q)));
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
auto toString(const std::vector<std::vector<T> > &C) {

    std::string result;
    if (!C.empty()) {
        size_t row = C.size();
        size_t col = C.at(0).size();
        bool firstItem;
        for (size_t i = 0; i != row; ++i) {
            firstItem = true;
            for (size_t j = 0; j != col; ++j) {
                if (firstItem) {
                    firstItem = false;
                } else {
                    result.push_back(' ');
                }
                result.append(std::to_string(C.at(i).at(j)));
            }
            if (i != row - 1) {
                result.push_back('\n');
            }
        }
    }
    return result;
}

std::string exec(const char *cmd) {
    char buffer[128];
    std::string result;
    auto pipe = popen(cmd, "r");
    if (!pipe) {
        throw std::runtime_error("popen() failed!");
    }
    try {
        while (fgets(buffer, sizeof(buffer), pipe) != nullptr) {
            result += buffer;
        }
    } catch (std::exception &ex) {
        pclose(pipe);
        std::cout << ex.what() << std::endl;
        exit(0);
    }
    pclose(pipe);
    return result;
}

int main() {

#ifdef DEBUG

    std::mt19937 random_generator((std::random_device()()));
    std::uniform_int_distribution<std::mt19937::result_type> random_size_range(1, 15);
    std::uniform_int_distribution<std::mt19937::result_type> random_value_range(static_cast<unsigned int>(-500), 500);

    int m = random_size_range(random_generator);
    int n = random_size_range(random_generator);
    int q = random_size_range(random_generator);
    std::vector<std::vector<int> > A(static_cast<unsigned long>(m), std::vector<int>(static_cast<unsigned long>(n)));
    for (auto &&i : A) {
        for (auto &&j : i) {
            j = random_value_range(random_generator);
        }
    }

    std::vector<std::vector<int> > B(static_cast<unsigned long>(n), std::vector<int>(static_cast<unsigned long>(q)));
    for (auto &&i : B) {
        for (auto &&j : i) {
            j = random_value_range(random_generator);
        }
    }

    for (int i = 0; i < 100; ++i) {
        Matrix<int> obj(matrixMultiplication(A, B));
        std::vector<std::vector<int> > obj2(matrixMultiplication(A, B));
        assert(obj.toString() == toString(obj2));
    }

#endif
    return 0;
}

