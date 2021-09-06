package main

import (
	"math/rand"
	"testing"
	"time"
)

const N = 1e6

func getRandomElements() []int {
	res := make([]int, N)
	rand.Seed(time.Now().UnixNano())
	for i := 0; i < len(res); i++ {
		res[i] = rand.Int()
	}
	return res
}

func BenchmarkParallelMergeSort(b *testing.B)  {
	for i := 0; i < b.N; i++ {
		parMergesort(getRandomElements())
	}
}

func BenchmarkSeqMergeSort(b *testing.B)  {
	for i := 0; i < b.N; i++ {
		seqMergesort(getRandomElements())
	}
}
