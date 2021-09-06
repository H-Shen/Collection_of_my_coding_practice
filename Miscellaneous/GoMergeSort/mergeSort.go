package main

import "sync"

const (
	THRESHOLD = 1024
	ROUTINE   = 1
)

func merge(s []int, mid int) {
	temp := make([]int, len(s))
	l := 0
	r := mid
	k := 0
	for l < mid && r < len(s) {
		if s[l] < s[r] {
			temp[k] = s[l]
			l++
		} else {
			temp[k] = s[r]
			r++
		}
		k++
	}
	for l < mid {
		temp[k] = s[l]
		l++
		k++
	}
	for r < len(s) {
		temp[k] = s[r]
		r++
		k++
	}
	// copy back to s
	for i := 0; i < len(s); i++ {
		s[i] = temp[i]
	}
}

func seqMergesort(s []int) {
	if len(s) <= 1 {
		return
	}
	mid := len(s) >> 1
	seqMergesort(s[:mid])
	seqMergesort(s[mid:])
	merge(s, mid)
}

func parMergesort(s []int) {
	if len(s) <= 1 {
		return
	}
	if len(s) <= THRESHOLD {
		seqMergesort(s)
	} else {
		mid := len(s) >> 1
		var wg sync.WaitGroup
		wg.Add(ROUTINE)
		go func() {
			defer wg.Done()
			parMergesort(s[:mid])
		}()
		parMergesort(s[mid:])
		wg.Wait()
		merge(s, mid)
	}
}