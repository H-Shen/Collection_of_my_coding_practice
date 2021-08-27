func fizzBuzz(n int) []string {
    var res = make([]string, n)
    for i := 1; i <= n; i++ {
        if (i % 15 == 0) {
            res[i-1] = "FizzBuzz"
        } else if (i % 3 != 0 && i % 5 != 0) {
            res[i-1] = strconv.Itoa(i)
        } else if (i % 3 == 0) {
            res[i-1] = "Fizz"
        } else {
            res[i-1] = "Buzz"
        }
    }
    return res
}