var (
	father []int
	Size   []int
)

func initDsu(n int) {
	father = nil
	Size = nil
	father = make([]int, n+5)
	for i := 0; i < len(father); i++ {
		father[i] = i
	}
	Size = make([]int, n+5)
	for i := 0; i < len(Size); i++ {
		Size[i] = 1
	}
}

func find(x int) int {
	if father[x] != x {
		father[x] = find(father[x])
	}
	return father[x]
}

func merge(x, y int) {
	x = find(x)
	y = find(y)
	if x == y {
		return
	}
	if Size[x] > Size[y] {
		x, y = y, x
	}
	Size[y] += Size[x]
	father[x] = y
}

func smallestStringWithSwaps(s string, pairs [][]int) string {
	n := len(s)
	initDsu(n)
	var u, v int
	for i := 0; i < len(pairs); i++ {
		u = pairs[i][0]
		v = pairs[i][1]
		merge(u, v)
	}
    groups := make(map[int][]int)
	var groupId int
	for i := 0; i < n; i++ {
		groupId = find(i)
		groups[groupId] = append(groups[groupId], i)
	}
	result := make([]rune, n)
	for i := 0; i < n; i++ {
		result[i] = -1
	}
	for _, vList := range groups {
        sort.Slice(vList, func(i, j int) bool {
			return vList[i] < vList[j]
		})
        temp := make([]int, len(vList))
        copy(temp, vList)
		sort.Slice(temp, func(i, j int) bool {
			return s[temp[i]] < s[temp[j]]
		})
		for i := 0; i < len(vList); i++ {
			result[vList[i]] = rune(s[temp[i]])
		}
	}
	for i := 0; i < n; i++ {
		if result[i] == -1 {
			result[i] = rune(s[i])
		}
	}
	return string(result)
}