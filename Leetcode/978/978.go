func maxTurbulenceSize(arr []int) int {
	dp1 := make([]int, len(arr))
	dp2 := make([]int, len(arr))
	dp1[0] = 1
	dp2[0] = 1
	for i := 1; i < len(arr); i++ {
		if (i & 1) != 0 {
			if arr[i-1] < arr[i] {
				dp1[i] = dp1[i-1] + 1
			} else {
				dp1[i] = 1
			}
		} else {
			if arr[i-1] > arr[i] {
				dp1[i] = dp1[i-1] + 1
			} else {
				dp1[i] = 1
			}
		}
	}
	for i := 1; i < len(arr); i++ {
		if (i & 1) != 0 {
			if arr[i-1] > arr[i] {
				dp2[i] = dp2[i-1] + 1
			} else {
				dp2[i] = 1
			}
		} else {
			if arr[i-1] < arr[i] {
				dp2[i] = dp2[i-1] + 1
			} else {
				dp2[i] = 1
			}
		}
	}
	ans := 0
	for i := 0; i < len(arr); i++ {
		ans = max(ans, dp1[i], dp2[i])
	}
	return ans
}

func max(a ... int) int {
	ans := math.MinInt32
	for _, i := range a {
		if i > ans {
			ans = i
		}
	}
	return ans
}