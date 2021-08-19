type Item struct {
	first, second int
}
type ItemSlice []Item

func threeWayComparator(i, j int) int {
	if i > j {
		return 1
	} else if i == j {
		return 0
	}
	return -1
}

func nthElement(itemSlice ItemSlice, k int, cmp func(a, b *Item) int) Item {
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

func kthSmallestPrimeFraction(arr []int, k int) []int {
	var length = (len(arr)-1)*len(arr)
	var A = make(ItemSlice, length)
	var pos = 0
	for i := 0; i < len(arr)-1; i++ {
		for j := 0; j < len(arr); j++ {
			A[pos].first = arr[i]
			A[pos].second = arr[j]
			pos++
		}
	}
	nthElement(A,k-1, func(a, b *Item) int {
		return threeWayComparator((*a).first*(*b).second,(*a).second*(*b).first)
	})
	return []int{A[k-1].first,A[k-1].second}
}