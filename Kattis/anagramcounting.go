// https://open.kattis.com/problems/anagramcounting

package main

import (
	"bufio"
	"fmt"
	"io"
	"math/big"
	"os"
)

// Fast IO Wrapper
var (
	reader = bufio.NewReader(os.Stdin)
	writer = bufio.NewWriter(os.Stdout)
)

func printf(f string, a ...interface{}) { fmt.Fprintf(writer, f, a...) }
func scanf(f string, a ...interface{})  { fmt.Fscanf(reader, f, a...) }

const N int = 102

var (
	a []*big.Int
	A map[rune]int
)

func main() {
	defer writer.Flush()
	var m = new(big.Int).SetInt64(1)
	a = append(a, m)
	var index = new(big.Int)
	for i := 1; i < N; i++ {
		index.SetInt64(int64(i))
		m = new(big.Int).Mul(m, index)
		a = append(a, m)
	}
	for {
		var s string
		var res = new(big.Int)
		A = make(map[rune]int)
		_, err := fmt.Fscanf(reader, "%s\n", &s)
		if err == io.EOF {
			return
		}
		for _, i := range s {
			_, ok := A[i]
			if !ok {
				A[i] = 1
			} else {
				A[i]++
			}
		}
		res.Set(a[len(s)])
		for i := range A {
			res = new(big.Int).Div(res, a[A[i]])
		}
		printf("%v\n", res)
		A = nil
	}

}
