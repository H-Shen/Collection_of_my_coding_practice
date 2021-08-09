package main

import (
	"bufio"
	"fmt"
	"math/big"
	"os"
	"strconv"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	t, _ := reader.ReadString('\n')
	t = strings.TrimSuffix(t, "\n")
	t = strings.TrimSuffix(t, "\r")
	tInt, err := strconv.Atoi(t)
	if err != nil {
		fmt.Println(err)
		os.Exit(2)
	}
	a := new(big.Int)
	b := new(big.Int)
	n := new(big.Int)
	zero := new(big.Int)
	two := new(big.Int)
	three := new(big.Int)
	zero.SetInt64(0)
	two.SetInt64(2)
	three.SetInt64(3)
	for i := 0; i < tInt; i++ {
		s, _ := reader.ReadString('\n')
		a = three
		b = two
		n.SetString(s, 10)
		for {
			if new(big.Int).Mod(n, a).Cmp(zero) == 0 {
				break
			}
			b = new(big.Int).Mul(b, two)
			a = new(big.Int).Add(a, b)
		}
		fmt.Println(new(big.Int).Div(n, a).String())
	}
}