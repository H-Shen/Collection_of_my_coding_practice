// https://open.kattis.com/problems/smallestmultiple

package main

import (
	"bufio"
	"fmt"
	"io"
	"math/big"
	"os"
	"strings"
)

// Fast IO Wrapper
var (
	reader *bufio.Reader = bufio.NewReader(os.Stdin)
	writer *bufio.Writer = bufio.NewWriter(os.Stdout)
)

func printf(f string, a ...interface{}) { fmt.Fprintf(writer, f, a...) }
func scanf(f string, a ...interface{})  { fmt.Fscanf(reader, f, a...) }

func lcm(a *big.Int, b *big.Int) *big.Int {
	return new(big.Int).Div(new(big.Int).Mul(a, b), new(big.Int).GCD(nil, nil, a, b))
}

func main() {
	defer writer.Flush()
	for {
		fmt.Scan()
		s, err := bufio.NewReader(reader).ReadString('\n')
		if err == io.EOF {
			break
		}
		temp := strings.Split(s, " ")
		var result big.Int
		result.SetInt64(int64(1))
		var temp2 big.Int
		for _, i := range temp {
			temp2.SetString(i, 10)
			result.Set(lcm(&result, &temp2))
		}
		printf("%v\n", result.String())
	}
}
