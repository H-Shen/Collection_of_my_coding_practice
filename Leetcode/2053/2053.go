type Node struct {
	freq, index int
}
type Pair struct {
	s string
	index int
}
func kthDistinct(arr []string, k int) string {
	m := make(map[string]Node)
	for i := 0; i < len(arr); i++ {
		val, ok := m[arr[i]]
		if !ok {
			m[arr[i]] = Node{
				freq: 1,
				index: i,
			}
		} else {
			m[arr[i]] = Node{
				freq: val.freq+1,
				index: i,
			}
		}
	}
	var temp []Pair
	for k, v := range m {
		if v.freq == 1 {
			temp = append(temp, Pair{
				s: k,
				index: v.index,
			})
		}
	}
	if len(temp) < k {
		return ""
	}
	sort.Slice(temp, func(i, j int) bool {
		return temp[i].index < temp[j].index
	})
	return temp[k-1].s
}