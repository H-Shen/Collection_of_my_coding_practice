func f(n int) int {
	if n & 1 != 0 {
		return (n-1)>>1
	}
	return (n>>1)-1
}
func g(n int) int {
	if n & 1 != 0 {
		return (n-1)>>1
	}
	return n>>1
}
func h(n int) int {
	if n & 1 != 0 {
		return (n+1)>>1
	}
	return n>>1
}

func canPlaceFlowers(flowerbed []int, n int) bool {
	containsOne := false
	for _, i := range flowerbed {
		if i == 1 {
			containsOne = true
			break
		}
	}
	if !containsOne {
		return h(len(flowerbed)) >= n
	}
	var sum, i, counter int
	for ; i < len(flowerbed) && flowerbed[i] != 1; i++ {
		counter++
	}
	if counter > 0 {
		sum += g(counter)
	}
	j := len(flowerbed) - 1
    counter = 0
	for ; j >= 0 && flowerbed[j] != 1; j-- {
		counter++
	}
	if counter > 0 {
		sum += g(counter)
	}
	counter = 0
	for ; i < j; i++ {
		if flowerbed[i] == 0 {
			counter++
		} else {
			if counter > 0 {
				sum += f(counter)
				counter = 0
			}
		}
	}
	if counter > 0 {
		sum += f(counter)
	}
	return sum >= n
}
