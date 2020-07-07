/**
 * An implementation of optimization on reading an integer
 * from stdin and writing an integer to stdout.
 * It has been tested in Linux csx.cs.ucalgary.ca (g++ -std=c++17 -Wall -O2).
 * Make sure to run the test before using it.
 */

//Time used (Smaller is faster):
//Input : mmap < fread < putchar_unlocked < putchar < scanf < cin(without sync, tie(0)) < cin
//Output: fwrite < getchar_unlocked < getchar < printf < cout(without sync, tie(0)) < cout

//Notice: getchar_unlocked()/putchar_unlocked() is compiler and OS specific and
// Windows user can replace them with _getchar_nolock()/_putchar_nolock()
// These two pairs of macros are not thread-safe.

/**
 * All the code about reading and writing have been packed separately in
 * namespaces(IO/FastIO/FasterIO).
 * Remaining functions are for benchmark only.
 */

#include <bits/extc++.h>

// For FasterIO, Linux/Unix specific
#include <sys/mman.h>
#include <sys/stat.h>

namespace IO {
    template<typename T>
    inline
    void read(T &t) {
        int n = 0;
        int c = getchar_unlocked();
        t = 0;
        while (!isdigit(c)) n |= c == '-', c = getchar_unlocked();
        while (isdigit(c)) t = t * 10 + c - 48, c = getchar_unlocked();
        if (n) t = -t;
    }

    template<typename T, typename... Args>
    inline
    void read(T &t, Args &... args) {
        read(t);
        read(args...);
    }

    template<typename T>
    inline void write(T x) {
        if (x < 0) x = -x, putchar_unlocked('-');
        if (x > 9) write(x / 10);
        putchar_unlocked(x % 10 + 48);
    }

    template<typename T>
    inline void writeln(T x) {
        write(x);
        putchar_unlocked('\n');
    }
}

// Use getchar()/putchar() instead
// For test only
namespace Temp {
    template<typename T>
    inline
    void read(T &t) {
        int n = 0;
        int c = getchar();
        t = 0;
        while (!isdigit(c)) n |= c == '-', c = getchar();
        while (isdigit(c)) t = t * 10 + c - 48, c = getchar();
        if (n) t = -t;
    }

    template<typename T, typename... Args>
    inline
    void read(T &t, Args &... args) {
        read(t);
        read(args...);
    }

    template<typename T>
    inline void write(T x) {
        if (x < 0) x = -x, putchar('-');
        if (x > 9) write(x / 10);
        putchar(x % 10 + 48);
    }

    template<typename T>
    inline void writeln(T x) {
        write(x);
        putchar('\n');
    }
}

namespace FastIO {

    static constexpr int MAXSIZE = 1024 * 1024;
    static char input_buffer[MAXSIZE];
    static char *ptr1 = input_buffer + MAXSIZE;
    static char *ptr2 = input_buffer + MAXSIZE;
    static char output_buffer[MAXSIZE];
    static char *ptr = output_buffer;

    inline static
    char getchar() {
        if (ptr1 == ptr2) {
            ptr1 = input_buffer;
            ptr2 = input_buffer + fread(input_buffer, 1, MAXSIZE, stdin);
            if (ptr1 == ptr2) {
                return EOF;
            }
        }
        return *ptr1++;
    }

    template<typename T>
    inline
    void read(T &t) {
        int n = 0;
        int c = getchar();
        t = 0;
        while (!isdigit(c)) n |= c == '-', c = getchar();
        while (isdigit(c)) t = t * 10 + c - 48, c = getchar();
        if (n) t = -t;
    }

    template<typename T, typename... Args>
    inline
    void read(T &t, Args &... args) {
        read(t);
        read(args...);
    }

    inline static
    void putchar(const char &ch) {
        if (ptr - output_buffer == MAXSIZE) {
            fwrite(output_buffer, 1, MAXSIZE, stdout);
            ptr = output_buffer;
        }
        *ptr++ = ch;
    }

    template<typename T>
    inline void write(T x) {
        if (x < 0) x = -x, putchar('-');
        if (x > 9) write(x / 10);
        putchar(x % 10 + 48);
    }

    template<typename T>
    inline static void writeln(T x) {
        write(x);
        putchar('\n');
    }

    // Execute this function after using write() on all numbers for output.
    inline
    void flush() {
        fwrite(output_buffer, 1, ptr - output_buffer, stdout);
    }
}

// Usage: freopen(); FasterIO::init(); ...; FastIO::flush();
// Notice: freopen() must be executed as the first step!
namespace FasterIO {

    static constexpr int MAXSIZE = 1024 * 1024;
    static char *input_buffer = nullptr;
    static char *ptr0;
    static char output_buffer[MAXSIZE];
    static char *ptr = output_buffer;
    int total_size;

    inline static
    void init() {
        struct stat sb; // dont initialize it in order to save time
        fstat(fileno_unlocked(stdin), &sb);
        total_size = sb.st_size;
        input_buffer = reinterpret_cast<char *>(mmap(nullptr, total_size,
                                                     PROT_READ, MAP_PRIVATE,
                                                     fileno_unlocked(stdin),
                                                     0));
        ptr0 = input_buffer;
    }

    inline static
    char getchar() {
        if (ptr0 == input_buffer + total_size || *ptr0 == EOF) return EOF;
        return *ptr0++;
    }

    template<typename T>
    inline static
    void read(T &t) {
        int n = 0;
        int c = getchar();
        t = 0;
        while (!isdigit(c)) n |= c == '-', c = getchar();
        while (isdigit(c)) t = t * 10 + c - 48, c = getchar();
        if (n) t = -t;
    }

    template<typename T, typename... Args>
    inline
    void read(T &t, Args &... args) {
        read(t);
        read(args...);
    }

    inline static
    void putchar(const char &ch) {
        if (ptr - output_buffer == MAXSIZE) {
#ifdef __linux__
            fwrite_unlocked(output_buffer, 1, MAXSIZE, stdout);
#else
            fwrite(output_buffer, 1, MAXSIZE, stdout);
#endif
            ptr = output_buffer;
        }
        *ptr++ = ch;
    }

    template<typename T>
    inline void write(T x) {
        if (x < 0) x = -x, putchar('-');
        if (x > 9) write(x / 10);
        putchar(x % 10 + 48);
    }

    template<typename T>
    inline void writeln(T x) {
        write(x);
        putchar('\n');
    }

    inline
    void flush() {
#ifdef __linux__
        fwrite_unlocked(output_buffer, 1, ptr - output_buffer, stdout);
#else
        fwrite(output_buffer, 1, ptr - output_buffer, stdout);
#endif
    }
}

inline static
void create_data(const size_t &data_size, const std::string &file_name) {

    // Initialize a random number generator.
    std::random_device dev;
    std::mt19937 random_generator(dev());
    std::uniform_int_distribution<int> dist(std::numeric_limits<int>::min(),
                                            std::numeric_limits<int>::max());

    // Create an empty file
    std::fstream file;
    file.open(file_name, std::ios::out);
    if (!file) {
        std::cerr << "Failed to create the test file!" << std::endl;
        exit(-1);
    }

    // Write into a file
    std::ofstream myFile;
    myFile.open(file_name);
    for (size_t i = 0; i != data_size; ++i) {
        myFile << dist(random_generator) << '\n';
    }
    myFile.close();
}

inline static
void read_by_fread(const size_t &data_size, const std::string &file_name) {

    // Define some variables for the test
    std::chrono::time_point<std::chrono::steady_clock> start, stop;
    std::chrono::duration<double> elapsed_in_seconds{};
    auto arr0 = std::make_unique<int[]>(data_size);

    // Use getchar read from file_name
    freopen(file_name.c_str(), "r", stdin);
    start = std::chrono::steady_clock::now();
    for (size_t i = 0; i != data_size; ++i) {
        FastIO::read<int>(arr0[i]);
    }
    stop = std::chrono::steady_clock::now();
    elapsed_in_seconds = stop - start;
    std::cout << "fread: " << elapsed_in_seconds.count() << " seconds"
              << std::endl;
}

inline static
void read_by_mmap(const size_t &data_size, const std::string &file_name) {

    // Define some variables for the test
    std::chrono::time_point<std::chrono::steady_clock> start, stop;
    std::chrono::duration<double> elapsed_in_seconds{};
    auto arr0 = std::make_unique<int[]>(data_size);

    // Use mmap read from file_name
    freopen(file_name.c_str(), "r", stdin);
    FasterIO::init();
    start = std::chrono::steady_clock::now();
    for (size_t i = 0; i != data_size; ++i) {
        FasterIO::read<int>(arr0[i]);
    }
    stop = std::chrono::steady_clock::now();
    elapsed_in_seconds = stop - start;
    std::cout << "mmap: " << elapsed_in_seconds.count() << " seconds"
              << std::endl;
}

inline static
void
read_by_getchar_unlocked(const size_t &data_size, const std::string &filename) {

    // Define some variables for the test
    std::chrono::time_point<std::chrono::steady_clock> start, stop;
    std::chrono::duration<double> elapsed_in_seconds{};
    auto arr0 = std::make_unique<int[]>(data_size);

    // Use getchar read from filename
    freopen(filename.c_str(), "r", stdin);
    start = std::chrono::steady_clock::now();
    for (size_t i = 0; i != data_size; ++i) {
        IO::read(arr0[i]);
    }
    stop = std::chrono::steady_clock::now();
    elapsed_in_seconds = stop - start;
    std::cout << "getchar unlocked: " << elapsed_in_seconds.count()
              << " seconds" << std::endl;

}

inline static
void read_by_getchar(const size_t &data_size, const std::string &file_name) {

    // Define some variables for the test
    std::chrono::time_point<std::chrono::steady_clock> start, stop;
    std::chrono::duration<double> elapsed_in_seconds{};
    auto arr0 = std::make_unique<int[]>(data_size);

    // Use getchar read from file_name
    freopen(file_name.c_str(), "r", stdin);
    start = std::chrono::steady_clock::now();
    for (size_t i = 0; i != data_size; ++i) {
        Temp::read(arr0[i]);
    }
    stop = std::chrono::steady_clock::now();
    elapsed_in_seconds = stop - start;
    std::cout << "getchar: " << elapsed_in_seconds.count() << " seconds"
              << std::endl;

}

inline static
void read_by_scanf(const size_t &data_size, const std::string &file_name) {

    // Define some variables for the test
    std::chrono::time_point<std::chrono::steady_clock> start, stop;
    std::chrono::duration<double> elapsed_in_seconds{};
    auto arr0 = std::make_unique<int[]>(data_size);

    // Use scanf read from file_name
    freopen(file_name.c_str(), "r", stdin);
    start = std::chrono::steady_clock::now();
    for (size_t i = 0; i != data_size; ++i) {
        scanf("%d", &arr0[i]);
    }
    stop = std::chrono::steady_clock::now();
    elapsed_in_seconds = stop - start;
    std::cout << "scanf: " << elapsed_in_seconds.count() << " seconds"
              << std::endl;
}

inline static
void read_by_cin_without_sync(const size_t &data_size,
                              const std::string &file_name) {

    // Define some variables for the test
    std::chrono::time_point<std::chrono::steady_clock> start, stop;
    std::chrono::duration<double> elapsed_in_seconds{};
    auto arr0 = std::make_unique<int[]>(data_size);

    // Use cin without sync read from file_name
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    freopen(file_name.c_str(), "r", stdin);
    start = std::chrono::steady_clock::now();
    for (size_t i = 0; i != data_size; ++i) {
        std::cin >> arr0[i];
    }
    stop = std::chrono::steady_clock::now();
    elapsed_in_seconds = stop - start;
    std::cout << "cin without sync: " << elapsed_in_seconds.count()
              << " seconds" << std::endl;
}

inline static
void read_by_cin(const size_t &data_size, const std::string &file_name) {

    // Define some variables for the test
    std::chrono::time_point<std::chrono::steady_clock> start, stop;
    std::chrono::duration<double> elapsed_in_seconds{};
    auto arr0 = std::make_unique<int[]>(data_size);

    // Use cin read from file_name
    freopen(file_name.c_str(), "r", stdin);
    start = std::chrono::steady_clock::now();
    for (size_t i = 0; i != data_size; ++i) {
        std::cin >> arr0[i];
    }
    stop = std::chrono::steady_clock::now();
    elapsed_in_seconds = stop - start;
    std::cout << "cin: " << elapsed_in_seconds.count() << " seconds"
              << std::endl;
}

inline static
void write_by_fwrite_unlocked
        (const size_t &data_size, const std::string &file_name) {

    // Define some variables for the test
    std::chrono::time_point<std::chrono::steady_clock> start, stop;
    std::chrono::duration<double> elapsed_in_seconds{};
    auto arr0 = std::make_unique<int[]>(data_size);

    // Fill arr0 with the data from file_name
    freopen(file_name.c_str(), "r", stdin);
    for (size_t i = 0; i != data_size; ++i) {
        scanf("%d", &arr0[i]);
    }
    fclose(stdin);

    // Create an empty file for output
    const char *output_file("testData.out");

    // Use FasterIO::write to write to output_file
    freopen(output_file, "w", stdout);
    start = std::chrono::steady_clock::now();
    for (size_t i = 0; i != data_size; ++i) {
        FasterIO::writeln(arr0[i]);
    }
    FasterIO::flush();
    stop = std::chrono::steady_clock::now();
    elapsed_in_seconds = stop - start;
    fclose(stdout);

    // Since stdout is closed, we use stderr to print the result
    std::cerr << "fwrite unlocked: " << elapsed_in_seconds.count() << " seconds"
              << std::endl;

    // Cleaning
    std::remove(output_file);
}

inline static
void write_by_fwrite(const size_t &data_size, const std::string &file_name) {

    // Define some variables for the test
    std::chrono::time_point<std::chrono::steady_clock> start, stop;
    std::chrono::duration<double> elapsed_in_seconds{};
    auto arr0 = std::make_unique<int[]>(data_size);

    // Fill arr0 with the data from file_name
    freopen(file_name.c_str(), "r", stdin);
    for (size_t i = 0; i != data_size; ++i) {
        scanf("%d", &arr0[i]);
    }
    fclose(stdin);

    // Create an empty file for output
    const char *output_file("testData.out");

    // Use FastIO::write to write to output_file
    freopen(output_file, "w", stdout);
    start = std::chrono::steady_clock::now();
    for (size_t i = 0; i != data_size; ++i) {
        FastIO::writeln(arr0[i]);
    }
    FastIO::flush();
    stop = std::chrono::steady_clock::now();
    elapsed_in_seconds = stop - start;
    fclose(stdout);

    // Since stdout is closed, we use stderr to print the result
    std::cerr << "fwrite: " << elapsed_in_seconds.count() << " seconds"
              << std::endl;

    // Cleaning
    std::remove(output_file);
}

inline static
void write_by_putchar_unlocked(const size_t &data_size,
                               const std::string &file_name) {

    // Define some variables for the test
    std::chrono::time_point<std::chrono::steady_clock> start, stop;
    std::chrono::duration<double> elapsed_in_seconds{};
    auto arr0 = std::make_unique<int[]>(data_size);

    // Fill arr0 with the data from file_name
    freopen(file_name.c_str(), "r", stdin);
    for (size_t i = 0; i != data_size; ++i) {
        scanf("%d", &arr0[i]);
    }
    fclose(stdin);

    // Create an empty file for output
    const char *output_file("testData.out");

    // Use FastIO::writeInt write to output_file
    freopen(output_file, "w", stdout);
    start = std::chrono::steady_clock::now();
    for (size_t i = 0; i != data_size; ++i) {
        IO::writeln(arr0[i]);
    }
    stop = std::chrono::steady_clock::now();
    elapsed_in_seconds = stop - start;
    fclose(stdout);

    // Since stdout is closed, we use stderr to print the result
    std::cerr << "putchar unlocked: " << elapsed_in_seconds.count()
              << " seconds" << std::endl;

    // Cleaning
    std::remove(output_file);
}

inline static
void write_by_putchar(const size_t &data_size, const std::string &file_name) {

    // Define some variables for the test
    std::chrono::time_point<std::chrono::steady_clock> start, stop;
    std::chrono::duration<double> elapsed_in_seconds{};
    auto arr0 = std::make_unique<int[]>(data_size);

    // Fill arr0 with the data from file_name
    freopen(file_name.c_str(), "r", stdin);
    for (size_t i = 0; i != data_size; ++i) {
        scanf("%d", &arr0[i]);
    }
    fclose(stdin);

    // Create an empty file for output
    const char *outputFile("testData.out");

    // Use FastIO::writeInt write to outputFile
    freopen(outputFile, "w", stdout);
    start = std::chrono::steady_clock::now();
    for (size_t i = 0; i != data_size; ++i) {
        Temp::writeln(arr0[i]);
    }
    stop = std::chrono::steady_clock::now();
    elapsed_in_seconds = stop - start;
    fclose(stdout);

    // Since stdout is closed, we use stderr to print the result
    std::cerr << "putchar: " << elapsed_in_seconds.count() << " seconds"
              << std::endl;

    // Cleaning
    std::remove(outputFile);
}

inline static
void write_by_printf(const size_t &dataSize, const std::string &fileName) {

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

    // Use printf to write to outputFile
    freopen(outputFile, "w", stdout);
    start = std::chrono::steady_clock::now();
    for (size_t i = 0; i != dataSize; ++i) {
        printf("%d\n", arr0[i]);
    }
    stop = std::chrono::steady_clock::now();
    elapsed_in_seconds = stop - start;
    fclose(stdout);

    // Since stdout is closed, we use stderr to print the result
    std::cerr << "printf: " << elapsed_in_seconds.count() << " seconds"
              << std::endl;

    // Cleaning
    std::remove(outputFile);
}

inline static
void write_by_cout_without_sync(const size_t &data_size,
                                const std::string &file_name) {

    // Define some variables for the test
    std::chrono::time_point<std::chrono::steady_clock> start, stop;
    std::chrono::duration<double> elapsed_in_seconds{};
    auto arr0 = std::make_unique<int[]>(data_size);

    // Fill arr0 with the data from file_name
    freopen(file_name.c_str(), "r", stdin);
    for (size_t i = 0; i != data_size; ++i) {
        scanf("%d", &arr0[i]);
    }
    fclose(stdin);

    // Create an empty file for output
    const char *output_file("testData.out");

    // Use cout without sync to write to output_file
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    freopen(output_file, "w", stdout);
    start = std::chrono::steady_clock::now();
    for (size_t i = 0; i != data_size; ++i) {
        std::cout << arr0[i] << '\n';
    }
    stop = std::chrono::steady_clock::now();
    elapsed_in_seconds = stop - start;
    fclose(stdout);

    // Since stdout is closed, we use stderr to print the result
    std::cerr << "cout without sync: " << elapsed_in_seconds.count()
              << " seconds" << std::endl;

    // Cleaning
    std::remove(output_file);
}

inline static
void write_by_cout(const size_t &data_size, const std::string &file_name) {

    // Define some variables for the test
    std::chrono::time_point<std::chrono::steady_clock> start, stop;
    std::chrono::duration<double> elapsed_in_seconds{};
    auto arr0 = std::make_unique<int[]>(data_size);

    // Fill arr0 with the data from fileName
    freopen(file_name.c_str(), "r", stdin);
    for (size_t i = 0; i != data_size; ++i) {
        scanf("%d", &arr0[i]);
    }
    fclose(stdin);

    // Create an empty file for output
    const char *output_file("testData.out");

    // Use cout to write to to output_file
    freopen(output_file, "w", stdout);
    start = std::chrono::steady_clock::now();
    for (size_t i = 0; i != data_size; ++i) {
        std::cout << arr0[i] << std::endl;
    }
    stop = std::chrono::steady_clock::now();
    elapsed_in_seconds = stop - start;
    fclose(stdout);

    // Since stdout is closed, we use stderr to print the result
    std::cerr << "cout: " << elapsed_in_seconds.count() << " seconds"
              << std::endl;

    // Cleaning
    std::remove(output_file);
}

inline static
void check_arguments(int argc, char **argv) {

    // Show usage if argc or argv are not correct.
    const std::string usage = "\nUsage: ./FastIO in/out 0/1/2/3/4/5 data_size\n\n"
                              "in: read input test\n"
                              " 0: mmap"
                              " 1: fread\n"
                              " 2: getchar unlocked\n"
                              " 3: scanf\n"
                              " 4: cin + sync(false) + tie(nullptr)\n"
                              " 5: cin\n"
                              " 6: getchar\n\n"
                              "out: print output test\n"
                              " 1: fwrite\n"
                              " 2: putchar unlocked\n"
                              " 3: printf\n"
                              " 4: cout + sync(false) + tie(nullptr)\n"
                              " 5: cout\n"
                              " 6: putchar\n"
                              "* data_size is the number of integers for the read input test, and it must be >= 1000 and <= 10000000\n\n";

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
    bool third_option_is_valid = false;
    for (int i = 0; i <= 6; ++i) {
        if (strcmp(argv[2], std::to_string(i).c_str()) == 0) {
            third_option_is_valid = true;
            break;
        }
    }
    if (!third_option_is_valid) {
        std::cout << usage;
        exit(-1);
    }
    // The fourth option is invalid.
    std::string data_size = argv[3];
    std::string pattern("^(-?[1-9][0-9]*|0)$");
    std::regex r(pattern);
    if (!std::regex_match(begin(data_size), end(data_size), r)) {
        // Case 1: The fourth option is not an integer.
        std::cout << usage;
        exit(-1);
    }
    auto data_size_int = static_cast<size_t>(stoi(data_size));
    if (data_size_int < 10000 || data_size_int > 10000000) {
        // Case 1: The size of data is out of valid range.
        std::cout << usage;
        exit(-1);
    }
}

int main(int argc, char *argv[]) {

    // Check arguments, exit if any argument is invalid.
    check_arguments(argc, argv);

    // Initialization
    int choice_number = stoi(std::string(argv[2]));
    const size_t data_size_int = static_cast<size_t>(stoi(
            std::string(argv[3])));
    const std::string file_name = "testData.in";

    create_data(data_size_int, file_name);
    if (strcmp(argv[1], "in") == 0) {
        switch (choice_number) {
            case 0:
                read_by_mmap(data_size_int, file_name);
                break;
            case 1:
                read_by_fread(data_size_int, file_name);
                break;
            case 2:
                read_by_getchar_unlocked(data_size_int, file_name);
                break;
            case 3:
                read_by_scanf(data_size_int, file_name);
                break;
            case 4:
                read_by_cin_without_sync(data_size_int, file_name);
                break;
            case 5:
                read_by_cin(data_size_int, file_name);
                break;
            default:
                read_by_getchar(data_size_int, file_name);
                break;
        }
    } else {
        switch (choice_number) {
            case 0:
                write_by_fwrite_unlocked(data_size_int, file_name);
                break;
            case 1:
                write_by_fwrite(data_size_int, file_name);
                break;
            case 2:
                write_by_putchar_unlocked(data_size_int, file_name);
                break;
            case 3:
                write_by_printf(data_size_int, file_name);
                break;
            case 4:
                write_by_cout_without_sync(data_size_int, file_name);
                break;
            case 5:
                write_by_cout(data_size_int, file_name);
                break;
            default:
                write_by_putchar(data_size_int, file_name);
                break;
        }
    }
    std::remove(file_name.c_str());
    return 0;
}

