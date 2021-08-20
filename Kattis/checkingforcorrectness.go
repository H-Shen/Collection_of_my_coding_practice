// https://open.kattis.com/problems/checkingforcorrectness

package main

import (
	"bufio"
	"fmt"
	"math/big"
	"os"
)

// Fast IO Wrapper
var (
	reader *bufio.Reader = bufio.NewReader(os.Stdin)
	writer *bufio.Writer = bufio.NewWriter(os.Stdout)
)

func printf(f string, a ...interface{}) { fmt.Fprintf(writer, f, a...) }
func scanf(f string, a ...interface{})  { fmt.Fscanf(reader, f, a...) }

var M big.Int

func main() {
	defer writer.Flush()
	M.SetInt64(int64(10000))
	var a, b, c string
	var num1, num2 big.Int
	for {
		_, err := fmt.Fscanf(reader, "%s %s %s\n", &a, &b, &c)
		if err != nil {
			break
		}
		num1.SetString(a, 10)
		num2.SetString(c, 10)
		switch b {
		case "+":
			num1.Add(&num1, &num2)
			num1.Mod(&num1, &M)
		case "*":
			num1.Mul(&num1, &num2)
			num1.Mod(&num1, &M)
		default:
			num1.Exp(&num1, &num2, &M)
		}
		printf("%v\n", &num1)
	}
}
