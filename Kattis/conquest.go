// https://open.kattis.com/problems/conquest

package main

import (
	"bufio"
	"container/heap"
	"fmt"
	"os"
)

// Fast IO Wrapper
var (
	reader *bufio.Reader = bufio.NewReader(os.Stdin)
	writer *bufio.Writer = bufio.NewWriter(os.Stdout)
)

func myPrintf(f string, a ...interface{}) { fmt.Fprintf(writer, f, a...) }
func myScanf(f string, a ...interface{})  { fmt.Fscanf(reader, f, a...) }

type Pair struct {
	first, second int
}
type EmptyStruct struct {

}

type PriorityQueue []Pair

func (pq *PriorityQueue) Len() int {
	return len(*pq)
}
func (pq *PriorityQueue) Less(i, j int) bool {
	if (*pq)[i].first == (*pq)[j].first {
		return (*pq)[i].second < (*pq)[j].second
	}
	return (*pq)[i].first < (*pq)[j].first
}
func (pq *PriorityQueue) Swap(i, j int) {
	(*pq)[i], (*pq)[j] = (*pq)[j], (*pq)[i]
}
func (pq *PriorityQueue) Push(x interface{}) {
	*pq = append(*pq, x.(Pair))
}
func (pq *PriorityQueue) Pop() interface{} {
	var n = len(*pq)
	var x = (*pq)[n-1]
	*pq = (*pq)[:n-1]
	return x
}
func (pq *PriorityQueue) Empty() bool {
	return (*pq).Len() == 0
}

var (
	n, m    int
	adjlist [][]int
	v, army []int
	freq map[Pair]EmptyStruct
	emptyStruct EmptyStruct
)

func main() {
	defer writer.Flush()
	myScanf("%d %d\n", &n, &m)
	freq = make(map[Pair]EmptyStruct)
	adjlist = make([][]int, n)
	v = make([]int, n)
	army = make([]int, n)
	var x, y int
	for i := 0; i < m; i++ {
		myScanf("%d %d\n", &x, &y)
		x--
		y--
		adjlist[x] = append(adjlist[x], y)
		adjlist[y] = append(adjlist[y], x)
	}
	for i := 0; i < n; i++ {
		myScanf("%d\n", &army[i])
	}
	var ans = army[0]
	v[0] = 1
	var pq PriorityQueue
	heap.Init(&pq)
	var pair Pair
	for _, i := range adjlist[0] {
		pair.first = army[i]
		pair.second = i
		_, ok := freq[pair]
		if !ok {
			heap.Push(&pq, pair)
			freq[pair] = emptyStruct
		}
	}
	for !pq.Empty() {
		var p = heap.Pop(&pq).(Pair)
		v[p.second] = 1
		if p.first >= ans {
			break
		}
		delete(freq, p)
		ans += p.first
		for _, i := range adjlist[p.second] {
			if v[i] == 0 {
				pair.first = army[i]
				pair.second = i
				_, ok := freq[pair]
				if !ok {
					heap.Push(&pq, pair)
					freq[pair] = emptyStruct
				}
			}
		}
	}
	myPrintf("%v\n", ans)
}
