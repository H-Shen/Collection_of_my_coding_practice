func twoSum(nums []int, target int) []int {
	var m map[int][]int
	var res []int
	m = make(map[int][]int)
	for i, num := range nums {
		m[num] = append(m[num], i)
	}
	if target % 2 == 0 {
		val, ok := m[target/2]
		if ok && len(val) > 1 {
			res = append(res, val[0])
			res = append(res, val[1])
			return res
		}
	}
	for k, v := range m {
		val, ok := m[target - k]
		if target - k != k && ok {
			res = append(res, v[0])
			res = append(res, val[0])
			break
		}
	}
	return res
}