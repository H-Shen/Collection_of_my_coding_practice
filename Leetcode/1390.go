func f(n int) int {
	sum, a, b, counter := 0, 0, 0, 0
	for i := 1; i*i <= n; i++ {
		if n % i == 0 {
			a = i
			b = n / i
			if a == b {
				counter++
				sum += a
			} else {
				counter += 2
				sum += a + b
			}
			if counter > 4 {
				sum = 0
				break
			}
		}
	}
	if counter < 4 {
		sum = 0
	}
	return sum
}
func sumFourDivisors(nums []int) int {
	ans := 0
	for _, num := range nums {
		ans += f(num)
	}
	return ans
}