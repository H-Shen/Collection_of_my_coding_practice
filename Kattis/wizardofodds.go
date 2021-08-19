// https://open.kattis.com/problems/wizardofodds

package main

import (
	"bufio"
	"fmt"
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

var (
	two big.Int
	lowerBound big.Int
)

func main() {
	defer writer.Flush()
	two.SetInt64(2)
	lowerBound.SetInt64(340)
	var nStr, kStr string
	scanf("%s %s\n", &nStr, &kStr)
	var n = new(big.Int)
	n.SetString(nStr, 10)
	var k = new(big.Int)
	k.SetString(kStr, 10)
	if k.Cmp(&lowerBound) >= 0 || new(big.Int).Exp(&two, k, nil).Cmp(n) >= 0 {
		printf("Your wish is granted!\n")
	} else {
		printf("You will become a flying monkey!\n")
	}
}
