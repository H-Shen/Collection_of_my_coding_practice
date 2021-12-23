func majorityElement(nums []int) int {
	val := math.MaxInt64
	counter := 0
	for i := 0; i < len(nums); i++ {
		if val != nums[i] {
			counter--
			if counter < 0 {
				val = nums[i]
				counter = 1
			}
		} else {
			counter++
		}
	}
	return val
}
