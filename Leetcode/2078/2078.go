func maxDistance(colors []int) int {
	ans := 0
	var temp int
	for i := 0; i < len(colors)-1; i++ {
		for j := i+1; j < len(colors); j++ {
			if colors[i] != colors[j] {
				temp = j-i
				if temp > ans {
					ans = temp
				}
			}
		}
	}
	return ans
}