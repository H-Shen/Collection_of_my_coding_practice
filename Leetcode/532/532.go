type Pair struct {
	a, b int
}

var empty = struct {
	
}{}

// (0,3) and (3,0) are the same pair here!
func findPairs(nums []int, k int) int {
	unmap := make(map[int][]int)
	for i := 0; i < len(nums); i++ {
		unmap[nums[i]] = append(unmap[nums[i]], i)
	}
	counter := 0
	if k == 0 {
		for _, value := range unmap {
			if len(value) > 1 {
				counter++
			}
		}
	} else {
		var temp int
		stats := make(map[Pair]struct{})
		for i := 0; i < len(nums); i++ {
			temp = nums[i] + k
			val, ok := unmap[temp]
			if ok && sort.Search(len(val), func(j int) bool {
				return val[j] > i
			}) != len(val) {
				if nums[i] < temp {
					stats[Pair{
						a: nums[i],
						b: temp,
					}] = empty
				} else {
					stats[Pair{
						a: temp,
						b: nums[i],
					}] = empty
				}
			}
			temp = nums[i] - k
			val, ok = unmap[temp]
			if ok && sort.Search(len(val), func(j int) bool {
				return val[j] > i
			}) != len(val) {
				if nums[i] < temp {
					stats[Pair{
						a: nums[i],
						b: temp,
					}] = empty
				} else {
					stats[Pair{
						a: temp,
						b: nums[i],
					}] = empty
				}
			}
		}
		counter = len(stats)
	}
	return counter
}