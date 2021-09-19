func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}

func countKDifference(nums []int, k int) int {
	counter := 0
	for i := 0; i < len(nums)-1; i++ {
		for j := i+1; j < len(nums); j++ {
			if abs(nums[i]-nums[j]) == k {
				counter++
			}
		}
	}
	return counter
}