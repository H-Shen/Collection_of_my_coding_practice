func maxOperations(nums []int, k int) int {
	freq := make(map[int]int)
	for i := 0; i < len(nums); i++ {
		freq[nums[i]]++
	}
	counter := 0
	for len(freq) > 0 {
		for k1, v1 := range freq {
			k2 := k - k1
			if v2, ok := freq[k2]; ok {
				if k2 == k1 {
					counter += v1 / 2
					delete(freq, k1)
				} else {
					if v1 > v2 {
						counter += v2
					} else {
						counter += v1
					}
					delete(freq, k1)
					delete(freq, k2)
				}
			} else {
				delete(freq, k1)
			}
		}
	}
	return counter
}