// Warning: This is a randomized algorithm. I don't guarantee that the same code will get 'AC' for the second time!
//
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

// constant factor that temperature decreases in
constexpr double DELTA = 0.997;
// The lower bound of the temperature
constexpr double MINIMAL_TEMP = 1e-4;
constexpr double EPS = 1e-6;
inline static
int sgn(double x) {
    if (x > EPS) return 1;
    if (x > -EPS) return 0;
    return -1;
}

int n;
vector<int> X;
vector<int> Y;
vector<int> W;
int sum_X = 0;
int sum_Y = 0;

// Global best result
double result_X;
double result_Y;
double minimal_so_far;

// Generate random numbers from -1.0 to 1.0
inline static
double get_random_number() {
    return 2.0 * rand() / RAND_MAX - 1.0;
}

inline static
double f(double x, double y) {
    double result = 0.0;
    double delta_x;
    double delta_y;
    for (int i = 0; i < n; ++i) {
        delta_x = x - X.at(i);
        delta_y = y - Y.at(i);
        result += sqrt(delta_x*delta_x+delta_y*delta_y) * W.at(i);
    }
    // Update the final answer if it is closer to the best solution
    if (result < minimal_so_far) {
        minimal_so_far = result;
        result_X = x;
        result_Y = y;
    }
    return result;
}

inline static
void simulate_anneal() {
    double t = 100000.0; // Set the initial temperature
    double current_x = result_X;
    double current_y = result_Y;
    double new_x, new_y, delta;
    while (t > MINIMAL_TEMP) {
        // 给new_x和new_y增加一个随机扰动 -1 <= get_random_number() < 1
        new_x = current_x + get_random_number() * t;
        new_y = current_y + get_random_number() * t;
        // delta = f(new) - f = f(new_x, new_y) - f(current_x, current_y)
        delta = f(new_x, new_y) - f(current_x, current_y);
        // Accept the new answer with a probability if it is not closer to
        // the best solution
        if (exp(-delta/t) > get_random_number()) {
            current_x = new_x;
            current_y = new_y;
        }
        // Update the temperature
        t *= DELTA;
    }
    // More iterations on the same temperature(make sure the status is steady)
    for (int i = 0; i < 1000; ++i) {
        new_x = result_X + get_random_number() * t;
        new_y = result_Y + get_random_number() * t;
        double temp = f(new_x, new_y);
    }
}

inline static
void solve() {
    // We start from its average
    result_X = sum_X * 1.0 / n;
    result_Y = sum_Y * 1.0 / n;
    double result_X_copy(result_X);
    double result_Y_copy(result_Y);
    minimal_so_far = f(result_X, result_Y);
    while (true) {
        simulate_anneal();
        if (sgn(result_X_copy - result_X) == 0 && sgn(result_Y_copy - result_Y) == 0) {
            break;
        }
        result_X_copy = result_X;
        result_Y_copy = result_Y;
    }
}

int main() {

    srand(time(nullptr));
    scanf("%d", &n);
    X.resize(n);
    Y.resize(n);
    W.resize(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d %d %d", &X.at(i), &Y.at(i), &W.at(i));
        sum_X += X.at(i);
        sum_Y += Y.at(i);
    }
    solve();
    printf("%.3lf %.3lf\n", result_X, result_Y);

    return 0;
}

