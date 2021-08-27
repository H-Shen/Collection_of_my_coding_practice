type ItemSlice []int

func threeWayComparator(i, j *int) int {
	if *i > *j {
		return 1
	} else if *i == *j {
		return 0
	}
	return -1
}

func nthElement(itemSlice ItemSlice, k int, cmp func(a, b *int) int) int {
	if k < 0 || k >= len(itemSlice) {
		panic("Invalid arguments!")
	}
	var l, r = 0, len(itemSlice) - 1
	var mid, i, j int
	for {
		if r <= l+1 {
			if r == l+1 && cmp(&itemSlice[l], &itemSlice[r]) > 0 {
				itemSlice[l], itemSlice[r] = itemSlice[r], itemSlice[l]
			}
			return itemSlice[k]
		}
		mid = l + ((r - l) >> 1)
		itemSlice[mid], itemSlice[l+1] = itemSlice[l+1], itemSlice[mid]
		if cmp(&itemSlice[l], &itemSlice[r]) > 0 {
			itemSlice[l], itemSlice[r] = itemSlice[r], itemSlice[l]
		}
		if cmp(&itemSlice[l+1], &itemSlice[r]) > 0 {
			itemSlice[l+1], itemSlice[r] = itemSlice[r], itemSlice[l+1]
		}
		if cmp(&itemSlice[l], &itemSlice[l+1]) > 0 {
			itemSlice[l], itemSlice[l+1] = itemSlice[l+1], itemSlice[l]
		}
		i = l + 1
		j = r
		var current = itemSlice[l+1]
		for {
			for i++; cmp(&itemSlice[i], &current) < 0; i++ {}
			for j--; cmp(&itemSlice[j], &current) > 0; j-- {}
			if i > j {
				break
			}
			itemSlice[i], itemSlice[j] = itemSlice[j], itemSlice[i]
		}
		itemSlice[l+1] = itemSlice[j]
		itemSlice[j] = current
		if j >= k {
			r = j - 1
		}
		if j <= k {
			l = i
		}
	}
}
func findKthLargest(nums []int, k int) int {
	nthElement(nums,k-1, func(a, b *int) int {
		return threeWayComparator(b, a)
	})
	return nums[k-1]
}