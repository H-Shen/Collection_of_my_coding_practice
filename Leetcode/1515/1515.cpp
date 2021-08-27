namespace SA {

    constexpr double DELTA = 0.998;
    constexpr double MINIMAL_TEMP = 1e-4;
    constexpr double EPS = 1e-6;

    int sgn(double x) {
        if (x > EPS) return 1;
        if (x > -EPS) return 0;
        return -1;
    }

    int n, sumX, sumY;
    vector<int> xArr, yArr;

    // Global best result
    double resultX, resultY, minimalSoFar;

    // Generate random numbers from -1.0 to 1.0
    double getRandomNumber() {
        return 2.0 * rand() / RAND_MAX - 1.0;
    }

    double f(double x, double y) {
        double result = 0.0;
        double deltaX;
        double deltaY;
        for (int i = 0; i < n; ++i) {
            deltaX = x - xArr.at(i);
            deltaY = y - yArr.at(i);
            result += sqrt(deltaX * deltaX + deltaY * deltaY);
        }
        // Update the final answer if it is closer to the best solution
        if (result < minimalSoFar) {
            minimalSoFar = result;
            resultX = x;
            resultY = y;
        }
        return result;
    }

    inline static
    void simulateAnneal() {
        double t = 1000000.0; // Set the initial temperature
        double currentX = resultX;
        double currentY = resultY;
        double newX, newY, delta;
        while (t > MINIMAL_TEMP) {
            newX = currentX + getRandomNumber() * t;
            newY = currentY + getRandomNumber() * t;
            // delta = f(new) - f = f(newX, newY) - f(currentX, currentY)
            delta = f(newX, newY) - f(currentX, currentY);
            // Accept the new answer with a probability if it is not closer to
            // the best solution
            if (exp(-delta / t) > getRandomNumber()) {
                currentX = newX;
                currentY = newY;
            }
            // Update the temperature
            t *= DELTA;
        }
        // More iterations on the same temperature(make sure the status is steady)
        for (int i = 0; i < 1000; ++i) {
            newX = resultX + getRandomNumber() * t;
            newY = resultY + getRandomNumber() * t;
            double temp = f(newX, newY);
        }
    }

    void solve() {
        // We start from its average
        resultX = sumX * 1.0 / n;
        resultY = sumY * 1.0 / n;
        double resultXCopy(resultX);
        double resultYCopy(resultY);
        minimalSoFar = f(resultX, resultY);
        while (true) {
            simulateAnneal();
            if (sgn(resultXCopy - resultX) == 0 && sgn(resultYCopy - resultY) == 0) {
                break;
            }
            resultXCopy = resultX;
            resultYCopy = resultY;
        }
    }
}

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    double getMinDistSum(vector<vector<int>>& positions) {
        SA::n = (int)positions.size();
        SA::xArr.resize(SA::n);
        SA::yArr.resize(SA::n);
        for (int i = 0; i < SA::n; ++i) {
            SA::xArr.at(i) = positions.at(i).at(0);
            SA::yArr.at(i) = positions.at(i).at(1);
        }
        SA::sumX = accumulate(SA::xArr.begin(), SA::xArr.end(), 0.0);
        SA::sumY = accumulate(SA::yArr.begin(), SA::yArr.end(), 0.0);
        srand(time(nullptr));
        SA::solve();
        double result = 0.0;
        for (int i = 0; i < SA::n; ++i) {
            result += sqrt((SA::resultX - SA::xArr.at(i)) * (SA::resultX - SA::xArr.at(i))
                    + (SA::resultY - SA::yArr.at(i)) * (SA::resultY - SA::yArr.at(i)));
        }
        return result;
    }
};