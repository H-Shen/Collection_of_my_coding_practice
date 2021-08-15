// https://open.kattis.com/problems/interviewqueue

package main

import (
	"bufio"
	"fmt"
	"os"
)

// Fast IO Wrapper
var reader *bufio.Reader = bufio.NewReader(os.Stdin)
var writer *bufio.Writer = bufio.NewWriter(os.Stdout)

func myPrintf(f string, a ...interface{}) { fmt.Fprintf(writer, f, a...) }
func myScanf(f string, a ...interface{})  { fmt.Fscanf(reader, f, a...) }

type Pair struct {
	first  int
	second int
}

var (
	n          int
	L   [][]int
	ans int
	arr []int
	A     []Pair
	B          []Pair
	backIndex  int
	frontIndex int
	lastIndex  int
	elem       int
)

func main() {
	var val, freq int
	myScanf("%d\n", &n)
	for i := 0; i < n; i++ {
		myScanf("%d", &elem)
		if i == 0 {
			val = elem
			freq = 1
			continue
		}
		if val == elem {
			freq++
		} else {
			A = append(A, Pair{val, freq})
			val = elem
			freq = 1
		}
	}
    A = append(A, Pair{val, freq})
	for {
		ans = 0
		arr = nil
		B = nil
		for i := 0; i < len(A); i++ {
			backIndex = i - 1
			frontIndex = i + 1
			lastIndex = 0
			if backIndex >= 0 && A[backIndex].first > A[i].first {
				lastIndex++
			}
			if frontIndex < len(A) && A[frontIndex].first > A[i].first {
				lastIndex++
			}
			if lastIndex > A[i].second {
				lastIndex = A[i].second
			}
			for j := 0; j < lastIndex; j++ {
				arr = append(arr, A[i].first)
			}
			A[i].second -= lastIndex
			if A[i].second > 0 {
				B = append(B, A[i])
			}
			ans += lastIndex
		}
		A = nil
		for _, i := range B {
			A = append(A, i)
		}
		if ans == 0 {
			break
		}
		L = append(L, arr)
	}
	// output
	myPrintf("%v\n", len(L))
	for _, i := range L {
		for _, j := range i {
			myPrintf("%v ", j)
		}
		myPrintf("\n")
	}
	for _, i := range A {
		for j := 0; j < i.second; j++ {
			myPrintf("%v ", i.first)
		}
	}
	myPrintf("\n")
	writer.Flush()
}
