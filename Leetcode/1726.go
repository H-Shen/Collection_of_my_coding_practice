const MIN int = 4

func tupleSameProduct(nums []int) int {
	if len(nums) < MIN {
		return 0
	} 
	var m map[int]int
	m = make(map[int]int)
	for i := 0; i < len(nums)-1; i++ {
		for j := i+1; j < len(nums); j++ {
			m[nums[i]*nums[j]]++
		}
	}
	var ans = 0
	for _, v := range m {
		if v > 1 {
			ans += (v*(v-1)) << 2
		}
	}
	return ans
}