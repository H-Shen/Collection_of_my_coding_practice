// https://open.kattis.com/problems/primes2

package main

import (
	"bufio"
	"fmt"
	"math/big"
	"os"
	"strconv"
)

var reader *bufio.Reader = bufio.NewReader(os.Stdin)
var writer *bufio.Writer = bufio.NewWriter(os.Stdout)
func printf(f string, a ...interface{}) { fmt.Fprintf(writer, f, a...) }
func scanf(f string, a ...interface{}) { fmt.Fscanf(reader, f, a...) }

func gcd(a, b int) int {
	if a < 0 {
		return gcd(-a, b)
	} else if b < 0 {
		return gcd(a, -b)
	}
	for b != 0 {
		t := b
		b = a % b
		a = t
	}
	return a
}

func main() {
	defer writer.Flush()
	var t int
	var s string
	var counter, total int
	scanf("%d\n", &t)
	for t > 0 {
		counter = 0
		total = 0
		scanf("%s\n", &s)
		temp, err := strconv.ParseInt(s, 2, 64)
		if err == nil {
			if big.NewInt(temp).ProbablyPrime(20) {
				counter++
			}
			total++
		}
		temp, err = strconv.ParseInt(s, 8, 64)
		if err == nil {
			if big.NewInt(temp).ProbablyPrime(20) {
				counter++
			}
			total++
		}
		temp, err = strconv.ParseInt(s, 10, 64)
		if err == nil {
			if big.NewInt(temp).ProbablyPrime(20) {
				counter++
			}
			total++
		}
		temp, err = strconv.ParseInt(s, 16, 64)
		if err == nil {
			if big.NewInt(temp).ProbablyPrime(20) {
				counter++
			}
			total++
		}
		if counter == 0 {
			total = 1
		} else {
			tempGcd := gcd(counter, total)
			counter /= tempGcd
			total /= tempGcd
		}
		printf("%d/%d\n", counter, total)
		t--
	}
}
