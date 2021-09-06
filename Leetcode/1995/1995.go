func countQuadruplets(nums []int) int {
	ans := 0
	for i := 0; i < len(nums)-3; i++ {
		for j := i+1; j < len(nums)-2; j++ {
			for k := j+1; k < len(nums)-1; k++ {
				for n := k+1; n < len(nums); n++ {
					if nums[i]+nums[j]+nums[k] == nums[n] {
						ans++
					}
				}
			}
		}
	}
	return ans
}