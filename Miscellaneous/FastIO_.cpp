/**
 * An implementation of optimization on reading (读入优化) an integer from stdin and writing (输出优化) an integer to stdout.
 * It has been tested in Linux csx.cs.ucalgary.ca (g++ -std=c++14 -Wall -O2),
 * but the strange thing is it is slower than scanf() in my macOS, (homebrew g++-7 -std=c++14 -Wall -O2)
 * So make sure to run the tests before using it.
 */

//Time used (Smaller is faster):
//Input : fread < putchar < scanf < cin(without sync, tie(0)) < cin
//Output: getchar < printf < cout(without sync, tie(0)) < cout

/**
 * I have packed all the code about reading and writing on namespace fastIO and you can just use it directly.
 * Remaining functions are for benchmark only.
 */

#include <bits/stdc++.h>
#include <unistd.h>

namespace FastIO {

    static constexpr int MAXSIZE = 1024 * 1024;
    static char inputBuffer[MAXSIZE];
    static char *ptr1 = inputBuffer + MAXSIZE;
    static char *ptr2 = inputBuffer + MAXSIZE;

    inline static
    char getcharUsingFread() {
        if (ptr1 == ptr2) {
            ptr1 = inputBuffer;
            ptr2 = inputBuffer + fread(inputBuffer, 1, MAXSIZE, stdin);
            if (ptr1 == ptr2) {
                return EOF;
            }
        }
        return *ptr1++;
    }

    template<typename T>
    inline static
    void readIntUsingFread(T &x) {
        x = 0;
        bool isNeg = false;
        char ch = getcharUsingFread();             // Notice ch < '0' since '0' == 48

        // skip all non digit characters
        while (!isdigit(ch)) {                                  // go into the loop if ch is not a digit
            if (ch == '-') {
                isNeg = true;                                   // change isNeg if the number is negative
            }
            ch = getcharUsingFread();                 // continue to get a character
        }

        while (isdigit(ch)) {                       // go into the loop if ch is a digit
            x = x * 10 + static_cast<T>(ch ^ 48);               // append the new value of ch to the end of x
            ch = getcharUsingFread();                      // continue to get a character
        }
        x = isNeg ? -x : x;
    }

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

    static char outputBuffer[MAXSIZE];
    static char *ptr = outputBuffer;

    inline static
    void putcharWithFwrite(const char &ch) {
        if (ptr == outputBuffer + MAXSIZE) {
            fwrite(outputBuffer, 1, MAXSIZE, stdout);
            ptr = outputBuffer;
        }
        *ptr++ = ch;
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
}

inline static
void createData(const size_t &dataSize, const std::string &fileName) {

    // Initialize a random number generator.
    std::random_device dev;
    std::mt19937 random_generator(dev());
    std::uniform_int_distribution<int> dist(std::numeric_limits<int>::min(), std::numeric_limits<int>::max());

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
    for (size_t i = 0; i != dataSize; ++i) {
        myFile << dist(random_generator) << '\n';
    }
    myFile.close();
}

inline static
void readByFread(const size_t &dataSize, const std::string &fileName) {

    // Define some variables for the test
    std::chrono::time_point<std::chrono::steady_clock> start, stop;
    std::chrono::duration<double> elapsed_in_seconds{};
    auto arr0 = std::make_unique<int[]>(dataSize);

    // Use getchar read from fileName
    freopen(fileName.c_str(), "r", stdin);
    start = std::chrono::steady_clock::now();
    for (size_t i = 0; i != dataSize; ++i) {
        FastIO::readIntUsingFread<int>(arr0[i]);
    }
    stop = std::chrono::steady_clock::now();
    elapsed_in_seconds = stop - start;
    std::cout << "fread: " << elapsed_in_seconds.count() << " seconds" << std::endl;
}

inline static
void readByGetchar(const size_t &dataSize, const std::string &fileName) {

    // Define some variables for the test
    std::chrono::time_point<std::chrono::steady_clock> start, stop;
    std::chrono::duration<double> elapsed_in_seconds{};
    auto arr0 = std::make_unique<int[]>(dataSize);

    // Use getchar read from fileName
    freopen(fileName.c_str(), "r", stdin);
    start = std::chrono::steady_clock::now();
    for (size_t i = 0; i != dataSize; ++i) {
        FastIO::readInt<int>(arr0[i]);
    }
    stop = std::chrono::steady_clock::now();
    elapsed_in_seconds = stop - start;
    std::cout << "readInt: " << elapsed_in_seconds.count() << " seconds" << std::endl;

}

inline static
void readByScanf(const size_t &dataSize, const std::string &fileName) {

    // Define some variables for the test
    std::chrono::time_point<std::chrono::steady_clock> start, stop;
    std::chrono::duration<double> elapsed_in_seconds{};
    auto arr0 = std::make_unique<int[]>(dataSize);

    // Use scanf read from fileName
    freopen(fileName.c_str(), "r", stdin);
    start = std::chrono::steady_clock::now();
    for (size_t i = 0; i != dataSize; ++i) {
        scanf("%d", &arr0[i]);
    }
    stop = std::chrono::steady_clock::now();
    elapsed_in_seconds = stop - start;
    std::cout << "scanf: " << elapsed_in_seconds.count() << " seconds" << std::endl;
}

inline static
void readByCin(const size_t &dataSize, const std::string &fileName) {

    // Define some variables for the test
    std::chrono::time_point<std::chrono::steady_clock> start, stop;
    std::chrono::duration<double> elapsed_in_seconds{};
    auto arr0 = std::make_unique<int[]>(dataSize);

    // Use cin read from fileName
    freopen(fileName.c_str(), "r", stdin);
    start = std::chrono::steady_clock::now();
    for (size_t i = 0; i != dataSize; ++i) {
        std::cin >> arr0[i];
    }
    stop = std::chrono::steady_clock::now();
    elapsed_in_seconds = stop - start;
    std::cout << "cin: " << elapsed_in_seconds.count() << " seconds" << std::endl;
}

inline static
void readByCinWithoutSync(const size_t &dataSize, const std::string &fileName) {

    // Define some variables for the test
    std::chrono::time_point<std::chrono::steady_clock> start, stop;
    std::chrono::duration<double> elapsed_in_seconds{};
    auto arr0 = std::make_unique<int[]>(dataSize);

    // Use cin without sync read from fileName
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    freopen(fileName.c_str(), "r", stdin);
    start = std::chrono::steady_clock::now();
    for (size_t i = 0; i != dataSize; ++i) {
        std::cin >> arr0[i];
    }
    stop = std::chrono::steady_clock::now();
    elapsed_in_seconds = stop - start;
    std::cout << "cin without sync: " << elapsed_in_seconds.count() << " seconds" << std::endl;
}

inline static
void writeByFwrite(const size_t &dataSize, const std::string &fileName) {
    // TODO
}

inline static
void writeByPutchar(const size_t &dataSize, const std::string &fileName) {

    // Define some variables for the test
    std::chrono::time_point<std::chrono::steady_clock> start, stop;
    std::chrono::duration<double> elapsed_in_seconds{};
    auto arr0 = std::make_unique<int[]>(dataSize);

    // Fill arr0 with the data from fileName
    freopen(fileName.c_str(), "r", stdin);
    for (size_t i = 0; i != dataSize; ++i) {
        scanf("%d", &arr0[i]);
    }
    fclose(stdin);

    // Create an empty file for output
    const char *outputFile("testData.out");

    // Use cout write to outputFile
    freopen(outputFile, "w", stdout);
    start = std::chrono::steady_clock::now();
    for (size_t i = 0; i != dataSize; ++i) {
        FastIO::writeInt<int>(arr0[i]);
    }
    stop = std::chrono::steady_clock::now();
    elapsed_in_seconds = stop - start;
    fclose(stdout);

    // Since stdout is closed, we use stderr to print the result
    std::cerr << "putchar: " << elapsed_in_seconds.count() << " seconds" << std::endl;

    // Cleaning
    std::remove(outputFile);
}

inline static
void writeByPrintf(const size_t &dataSize, const std::string &fileName) {

    // Define some variables for the test
    std::chrono::time_point<std::chrono::steady_clock> start, stop;
    std::chrono::duration<double> elapsed_in_seconds{};
    auto arr0 = std::make_unique<int[]>(dataSize);

    // Fill arr0 with the data from fileName
    freopen(fileName.c_str(), "r", stdin);
    for (size_t i = 0; i != dataSize; ++i) {
        scanf("%d", &arr0[i]);
    }
    fclose(stdin);

    // Create an empty file for output
    const char *outputFile("testData.out");

    // Use cout write to outputFile
    freopen(outputFile, "w", stdout);
    start = std::chrono::steady_clock::now();
    for (size_t i = 0; i != dataSize; ++i) {
        printf("%d\n", arr0[i]);
    }
    stop = std::chrono::steady_clock::now();
    elapsed_in_seconds = stop - start;
    fclose(stdout);

    // Since stdout is closed, we use stderr to print the result
    std::cerr << "printf: " << elapsed_in_seconds.count() << " seconds" << std::endl;

    // Cleaning
    std::remove(outputFile);
}

inline static
void writeByCout(const size_t &dataSize, const std::string &fileName) {

    // Define some variables for the test
    std::chrono::time_point<std::chrono::steady_clock> start, stop;
    std::chrono::duration<double> elapsed_in_seconds{};
    auto arr0 = std::make_unique<int[]>(dataSize);

    // Fill arr0 with the data from fileName
    freopen(fileName.c_str(), "r", stdin);
    for (size_t i = 0; i != dataSize; ++i) {
        scanf("%d", &arr0[i]);
    }
    fclose(stdin);

    // Create an empty file for output
    const char *outputFile("testData.out");

    // Use cout write to outputFile
    freopen(outputFile, "w", stdout);
    start = std::chrono::steady_clock::now();
    for (size_t i = 0; i != dataSize; ++i) {
        std::cout << arr0[i] << std::endl;
    }
    stop = std::chrono::steady_clock::now();
    elapsed_in_seconds = stop - start;
    fclose(stdout);

    // Since stdout is closed, we use stderr to print the result
    std::cerr << "cout: " << elapsed_in_seconds.count() << " seconds" << std::endl;

    // Cleaning
    std::remove(outputFile);
}

inline static
void writeByCoutWithoutSync(const size_t &dataSize, const std::string &fileName) {

    // Define some variables for the test
    std::chrono::time_point<std::chrono::steady_clock> start, stop;
    std::chrono::duration<double> elapsed_in_seconds{};
    auto arr0 = std::make_unique<int[]>(dataSize);

    // Fill arr0 with the data from fileName
    freopen(fileName.c_str(), "r", stdin);
    for (size_t i = 0; i != dataSize; ++i) {
        scanf("%d", &arr0[i]);
    }
    fclose(stdin);

    // Create an empty file for output
    const char *outputFile("testData.out");

    // Use cout write to outputFile
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    freopen(outputFile, "w", stdout);
    start = std::chrono::steady_clock::now();
    for (size_t i = 0; i != dataSize; ++i) {
        std::cout << arr0[i] << '\n';
    }
    stop = std::chrono::steady_clock::now();
    elapsed_in_seconds = stop - start;
    fclose(stdout);

    // Since stdout is closed, we use stderr to print the result
    std::cerr << "cout without sync: " << elapsed_in_seconds.count() << " seconds" << std::endl;

    // Cleaning
    std::remove(outputFile);
}

inline static
void checkArguments(int argc, char *argv[]) {

    // Show usage if argc or argv are not correct.
    const std::string usage = "\nUsage: ./FastIO in/out 1/2/3/4/5 dataSize\n\n"
                              "in: read input test\n"
                              " 1: fread\n"
                              " 2: getchar\n"
                              " 3: scanf\n"
                              " 4: cin\n"
                              " 5: cin + sync(false) + tie(nullptr)\n\n"
                              "out: print output test\n"
                              " 1: fwrite\n"
                              " 2: putchar\n"
                              " 3: printf\n"
                              " 4: cout\n"
                              " 5: cout + sync(false) + tie(nullptr)\n\n"
                              "* dataSize is the number of integers for the read input test, and it must be >= 1000 and <= 10000000\n\n";

    // Parsing
    // Incorrect number of arguments.
    if (argc != 4) {
        std::cout << usage;
        exit(-1);
    }
    // The second option is invalid.
    if (strcmp(argv[1], "in") != 0 && strcmp(argv[1], "out") != 0) {
        std::cout << usage;
        exit(-1);
    }
    // The third option is invalid.
    bool thirdOptionIsValid = false;
    for (int i = 1; i <= 5; ++i) {
        if (strcmp(argv[2], std::to_string(i).c_str()) == 0) {
            thirdOptionIsValid = true;
            break;
        }
    }
    if (!thirdOptionIsValid) {
        std::cout << usage;
        exit(-1);
    }
    // The fourth option is invalid.
    std::string dataSize = argv[3];
    std::string pattern("^(-?[1-9][0-9]*|0)$");
    std::regex r(pattern);
    if (!std::regex_match(begin(dataSize), end(dataSize), r)) {
        // Case 1: The fourth option is not an integer.
        std::cout << usage;
        exit(-1);
    }
    auto dataSizeInt = static_cast<size_t>(stoi(dataSize));
    if (dataSizeInt < 10000 || dataSizeInt > 10000000) {
        // Case 1: The size of data is out of valid range.
        std::cout << usage;
        exit(-1);
    }
}

int main(int argc, char *argv[]) {

    // Check arguments, exit if any argument is invalid.
    checkArguments(argc, argv);

    // Initialization
    int choiceNumber = stoi(std::string(argv[2]));
    const size_t dataSizeInt = static_cast<size_t>(stoi(std::string(argv[3])));
    const std::string fileName = "testData.in";

    createData(dataSizeInt, fileName);
    if (strcmp(argv[1], "in") == 0) {
        switch (choiceNumber) {
            case 1:
                readByFread(dataSizeInt, fileName);
                break;
            case 2:
                readByGetchar(dataSizeInt, fileName);
                break;
            case 3:
                readByScanf(dataSizeInt, fileName);
                break;
            case 4:
                readByCin(dataSizeInt, fileName);
                break;
            default:
                readByCinWithoutSync(dataSizeInt, fileName);
                break;
        }
    } else {
        switch (choiceNumber) {
            case 1:
                writeByFwrite(dataSizeInt, fileName);
                break;
            case 2:
                writeByPutchar(dataSizeInt, fileName);
                break;
            case 3:
                writeByPrintf(dataSizeInt, fileName);
                break;
            case 4:
                writeByCout(dataSizeInt, fileName);
                break;
            default:
                writeByCoutWithoutSync(dataSizeInt, fileName);
                break;
        }
    }
    std::remove(fileName.c_str());
    return 0;
}
