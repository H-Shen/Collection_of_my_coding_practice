func validMountainArray(arr []int) bool {
	if len(arr) < 3 {
		return false
	}
	maxValue := -1
	index := 0
	for i := 0; i < len(arr); i++ {
		if maxValue < arr[i] {
			maxValue = arr[i]
			index = i
		}
	}
	if index == 0 || index == len(arr) - 1 {
		return false
	}
	for i := index; i >= 1; i-- {
		if arr[i] <= arr[i-1] {
			return false
		}
	}
	for i := index; i < len(arr)-1; i++ {
		if arr[i] <= arr[i+1] {
			return false
		}
	}
	return true
}