#include <bits/stdc++.h>

/**
 * A template to measure the running time of a function.
 */
void testFunc() {
    int sum{0};
    for (int i = 0; i < 1000000; ++i) {
        sum += i;
    }
}

void measureRunningTime() {
    std::chrono::time_point<std::chrono::steady_clock> start, stop;
    start = std::chrono::steady_clock::now();
    testFunc();
    stop = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed_in_seconds = stop - start;
    std::cout << elapsed_in_seconds.count() << " seconds" << std::endl;     // returns the count of ticks
}

int main() {

    measureRunningTime();

    return 0;
}
