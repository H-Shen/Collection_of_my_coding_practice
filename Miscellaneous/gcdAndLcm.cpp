
// Greatest Common Divisor (with recursion)
long long gcdWithRecursion(long long a, long long b) {

    // Case 1:
    if (a < 0) {
        return gcdWithRecursion(-a, b);
    }

    // Case 2:
    if (b < 0) {
        return gcdWithRecursion(a, -b);
    }

    // Case 3:
    if (a == 0 || b == 0) {
        return 0;
    }

    // Case 4:
    return (b > 0) ? gcdWithRecursion(b, a % b) : a;
}


// Greatest Common Divisor (without recursion)
long long gcd(long long a, long long b) {

    // Case 1:
    if (a < 0) {
        return gcd(-a, b);
    }

    // Case 2:
    if (b < 0) {
        return gcd(a, -b);
    }

    // Case 3:
    if (a == 0 || b == 0) {
        return 0;
    }

    // Case 4:
    long long t;
    while (b > 0) {
        t = a % b;
        a = b;
        b = t;
    }
    return a;
}

// Least Common Multiple (may overflow)
long long lcm(long long a, long long b)  {

    // Case 1:
    if (a < 0) {
        return lcm(-a, b);
    }

    // Case 2:
    if (b < 0) {
        return lcm(a, -b);
    }

    // Case 3:
    if (a == 0 || b == 0) {
        return 0;
    }

    // Case 4:
    return a * b / gcd(a, b);
}

int main() {



    return 0;
}