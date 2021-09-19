func max(a ... int) int {
	ans := math.MinInt32
	for _, i := range a {
		if i > ans {
			ans = i
		}
	}
	return ans
}

func min(a ... int) int {
	ans := math.MaxInt32
	for _, i := range a {
		if i < ans {
			ans = i
		}
	}
	return ans
}

func sumOfBeauties(nums []int) int {
	n := len(nums)
	maxFromLeft := make([]int, n)
	maxFromLeft[0] = nums[0]
	for i := 1; i <= n-1; i++ {
		maxFromLeft[i] = max(maxFromLeft[i-1], nums[i])
	}
	minFromRight := make([]int, n)
	minFromRight[n-1] = nums[n-1]
	for i := n-2; i >= 0; i-- {
		minFromRight[i] = min(minFromRight[i+1], nums[i])
	}
	counter := 0
	for i := 1; i <= n-2; i++ {
		if maxFromLeft[i-1] < nums[i] && nums[i] < minFromRight[i+1] {
			counter += 2
		} else if nums[i-1] < nums[i] && nums[i] < nums[i+1] {
			counter++
		}
	}
	return counter
}