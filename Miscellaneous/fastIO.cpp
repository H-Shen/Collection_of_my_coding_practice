/**
 * An implementation of optimization on reading (读入优化) an integer from stdin.
 * It has been tested in Linux csx.cs.ucalgary.ca (g++ -std=c++14 -Wall -O2),
 * but the strange thing is it is slower than scanf() in my macOS, (homebrew g++-7 -std=c++14 -Wall -O2)
 * So make sure to run the tests before using it.
 */
#include <bits/stdc++.h>

template<typename T>
inline static
void readInt(T &x) {

    x = 0;
    bool isNeg = false;
    char ch = static_cast<char>(getchar());                // Notice ch < '0' since '0' == 48

    // skip all non digit characters
    while (!isdigit(ch)) {      // go into the loop if ch is not a digit
        if (ch == '-') {
            isNeg = true;               // change isNeg if the number is negative
        }
        ch = static_cast<char>(getchar());                 // continue to get a character
    }

    while (isdigit(ch)) {    // go into the loop if ch is a digit
        x = x * 10 + static_cast<T>(ch ^ 48);        // append the new value of ch to the end of x
        ch = static_cast<char>(getchar());                 // continue to get a character
    }
    x = isNeg ? -x : x;
}

void testInt(const size_t &length) {

    auto arr0 = std::make_unique<int[]>(length);
    auto arr1 = std::make_unique<int[]>(length);
    const char *fileName("testData.in");

    /* createTestData */

    // Initialize a random number generator.
    std::random_device dev;
    std::mt19937 random_generator(dev());
    std::uniform_int_distribution<int> dist(INT_MIN, INT_MAX);

    // Create an empty file
    std::fstream file;
    file.open(fileName, std::ios::out);
    if (!file) {
        std::cerr << "Failed to create the test file!" << std::endl;
        exit(-1);
    }

    // Write into a file
    std::ofstream myFile;
    myFile.open(fileName);
    for (size_t i = 0; i != length; ++i) {
        myFile << dist(random_generator) << '\n';
    }
    myFile.close();

    /* Define some variables for the test */

    std::chrono::time_point<std::chrono::steady_clock> start, stop;
    std::chrono::duration<double> elapsed_in_seconds{};
    std::cout << "Test on " << length << " ints..." << std::endl;

    // Benchmark on scanf()
    freopen(fileName, "r", stdin);
    start = std::chrono::steady_clock::now();
    for (size_t i = 0; i != length; ++i) {
        scanf("%d", &arr0[i]);
    }
    stop = std::chrono::steady_clock::now();
    elapsed_in_seconds = stop - start;
    std::cout << "Scanf: " << elapsed_in_seconds.count() << " seconds" << std::endl;
    fclose(stdin);

    // Benchmark on readInt()
    freopen(fileName, "r", stdin);
    start = std::chrono::steady_clock::now();
    for (size_t i = 0; i != length; ++i) {
        readInt<int>(arr1[i]);
    }
    stop = std::chrono::steady_clock::now();
    elapsed_in_seconds = stop - start;
    std::cout << "ReadInt: " << elapsed_in_seconds.count() << " seconds" << std::endl;
    fclose(stdin);

    // Compare arr0 and arr1 just in case
    for (size_t i = 0; i != length; ++i) {
        assert(arr0[i] == arr1[i]);
    }

    /* remove TestData */
    std::remove(fileName);

}

void testLongLong(const size_t &length) {

    auto arr0 = std::make_unique<long long[]>(length);
    auto arr1 = std::make_unique<long long[]>(length);
    const char *fileName("testData.in");

    /* createTestData */

    // Initialize a random number generator.
    std::random_device dev;
    std::mt19937 random_generator(dev());
    std::uniform_int_distribution<long long> dist(LONG_LONG_MIN, LONG_LONG_MAX);

    // Create an empty file
    std::fstream file;
    file.open(fileName, std::ios::out);
    if (!file) {
        std::cerr << "Failed to create the test file!" << std::endl;
        exit(-1);
    }

    // Write into a file
    std::ofstream myFile;
    myFile.open(fileName);
    for (size_t i = 0; i != length; ++i) {
        myFile << dist(random_generator) << '\n';
    }
    myFile.close();

    /* Define some variables for the test */

    std::chrono::time_point<std::chrono::steady_clock> start, stop;
    std::chrono::duration<double> elapsed_in_seconds{};
    std::cout << "Test on " << length << " long long ints..." << std::endl;

    // Benchmark on scanf()
    freopen(fileName, "r", stdin);
    start = std::chrono::steady_clock::now();
    for (size_t i = 0; i != length; ++i) {
        scanf("%lld", &arr0[i]);
    }
    stop = std::chrono::steady_clock::now();
    elapsed_in_seconds = stop - start;
    std::cout << "Scanf: " << elapsed_in_seconds.count() << " seconds" << std::endl;
    fclose(stdin);

    // Benchmark on readInt()
    freopen(fileName, "r", stdin);
    start = std::chrono::steady_clock::now();
    for (size_t i = 0; i != length; ++i) {
        readInt<long long>(arr1[i]);
    }
    stop = std::chrono::steady_clock::now();
    elapsed_in_seconds = stop - start;
    std::cout << "ReadInt: " << elapsed_in_seconds.count() << " seconds" << std::endl;
    fclose(stdin);

    // Compare arr0 and arr1 just in case
    for (size_t i = 0; i != length; ++i) {
        assert(arr0[i] == arr1[i]);
    }

    /* remove TestData */
    std::remove(fileName);

}

int main() {

    constexpr size_t length = 5000000;
    testInt(length);
    testLongLong(length);

    return 0;
}
