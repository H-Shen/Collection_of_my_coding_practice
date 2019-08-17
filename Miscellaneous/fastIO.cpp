/**
 * An implementation of optimization on reading (读入优化) an integer from stdin and writing (输出优化) an integer to stdout.
 * It has been tested in Linux csx.cs.ucalgary.ca (g++ -std=c++14 -Wall -O2),
 * but the strange thing is it is slower than scanf() in my macOS, (homebrew g++-7 -std=c++14 -Wall -O2)
 * So make sure to run the tests before using it.
 */
#include <bits/stdc++.h>
#include <unistd.h>

template<typename T>
inline static
void readInt(T &x) {

    x = 0;
    bool isNeg = false;
    char ch = static_cast<char>(getchar());                // Notice ch < '0' since '0' == 48

    // skip all non digit characters
    while (!isdigit(ch)) {                                  // go into the loop if ch is not a digit
        if (ch == '-') {
            isNeg = true;                                   // change isNeg if the number is negative
        }
        ch = static_cast<char>(getchar());                 // continue to get a character
    }

    while (isdigit(ch)) {                       // go into the loop if ch is a digit
        x = x * 10 + static_cast<T>(ch ^ 48);               // append the new value of ch to the end of x
        ch = static_cast<char>(getchar());                      // continue to get a character
    }
    x = isNeg ? -x : x;
}

template<typename T>
inline static
void writeInt(T x) {
    if (x < 0) {
        x = -x;
        putchar('-');
    }
    static int storeDigits[40];
    int top = 0;
    do {
        storeDigits[top++] = x % 10;
        x /= 10;
    } while (x);
    while (top) {
        putchar(storeDigits[--top] + 48);
    }
}

void testReadInt(const size_t &length) {

    auto arr0 = std::make_unique<int[]>(length);
    auto arr1 = std::make_unique<int[]>(length);
    const char *fileName("testData.in");

    /* create TestData */

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
    std::cout << "Test on reading " << length << " ints..." << std::endl;

    // Benchmark on scanf()
    freopen(fileName, "r", stdin);
    start = std::chrono::steady_clock::now();
    for (size_t i = 0; i != length; ++i) {
        scanf("%d", &arr0[i]);
    }
    stop = std::chrono::steady_clock::now();
    elapsed_in_seconds = stop - start;
    std::cout << "scanf: " << elapsed_in_seconds.count() << " seconds" << std::endl;
    fclose(stdin);

    // Benchmark on readInt()
    freopen(fileName, "r", stdin);
    start = std::chrono::steady_clock::now();
    for (size_t i = 0; i != length; ++i) {
        readInt<int>(arr1[i]);
    }
    stop = std::chrono::steady_clock::now();
    elapsed_in_seconds = stop - start;
    std::cout << "readInt: " << elapsed_in_seconds.count() << " seconds" << std::endl;
    fclose(stdin);

    // Compare arr0 and arr1 just in case
    for (size_t i = 0; i != length; ++i) {
        assert(arr0[i] == arr1[i]);
    }

    /* remove TestData */
    std::remove(fileName);

}

void testReadLongLong(const size_t &length) {

    auto arr0 = std::make_unique<long long[]>(length);
    auto arr1 = std::make_unique<long long[]>(length);
    const char *fileName("testData.in");

    /* create TestData */

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
    std::cout << "Test on reading " << length << " long long ints..." << std::endl;

    // Benchmark on scanf()
    freopen(fileName, "r", stdin);
    start = std::chrono::steady_clock::now();
    for (size_t i = 0; i != length; ++i) {
        scanf("%lld", &arr0[i]);
    }
    stop = std::chrono::steady_clock::now();
    elapsed_in_seconds = stop - start;
    std::cout << "scanf: " << elapsed_in_seconds.count() << " seconds" << std::endl;
    fclose(stdin);

    // Benchmark on readInt()
    freopen(fileName, "r", stdin);
    start = std::chrono::steady_clock::now();
    for (size_t i = 0; i != length; ++i) {
        readInt<long long>(arr1[i]);
    }
    stop = std::chrono::steady_clock::now();
    elapsed_in_seconds = stop - start;
    std::cout << "readInt: " << elapsed_in_seconds.count() << " seconds" << std::endl;
    fclose(stdin);

    // Compare arr0 and arr1 just in case
    for (size_t i = 0; i != length; ++i) {
        assert(arr0[i] == arr1[i]);
    }

    /* remove TestData */
    std::remove(fileName);

}

void testWriteInt(const size_t &length) {

    const char *fileName0("testData0.out");
    const char *fileName1("testData1.out");

    // Initialize a random number generator.
    std::random_device dev;
    std::mt19937 random_generator(dev());
    std::uniform_int_distribution<int> dist(INT_MIN, INT_MAX);

    // Initialize an array with given size of random numbers.
    auto arr = std::make_unique<int[]>(length);
    for (size_t i = 0; i != length; ++i) {
        arr[i] = dist(random_generator);
    }

    /* Define some variables for the test */
    std::chrono::time_point<std::chrono::steady_clock> start, stop;
    std::chrono::duration<double> elapsed_in_seconds0{};
    std::chrono::duration<double> elapsed_in_seconds1{};
    std::cout << "Test on writing " << length << " ints..." << std::endl;

    // Benchmark on printf()
    freopen(fileName0, "w", stdout);
    start = std::chrono::steady_clock::now();
    for (size_t i = 0; i != length; ++i) {
        printf("%d\n", arr[i]);
    }
    stop = std::chrono::steady_clock::now();
    elapsed_in_seconds0 = stop - start;

    // Benchmark on writeInt()
    freopen(fileName1, "w", stdout);
    start = std::chrono::steady_clock::now();
    for (size_t i = 0; i != length; ++i) {
        writeInt<int>(arr[i]);
        putchar('\n');
    }
    stop = std::chrono::steady_clock::now();
    elapsed_in_seconds1 = stop - start;

    fclose(stdout);
    std::cerr << "printf  : " << elapsed_in_seconds0.count() << " seconds" << std::endl;
    std::cerr << "writeInt: " << elapsed_in_seconds1.count() << " seconds" << std::endl;

    /* remove TestData */
    std::remove(fileName0);
    std::remove(fileName1);
}

int main() {

    constexpr size_t length = 5000000;
    testReadInt(length);
    testReadLongLong(length);
    testWriteInt(length);

    return 0;
}
