package main

import (
	"bufio"
	"fmt"
	"math/big"
	"os"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	a, _ := reader.ReadString('\n')
	b, _ := reader.ReadString('\n')

	if a != "0" {
		a = strings.TrimPrefix(a, "0")
	}
	if b != "0" {
		b = strings.TrimPrefix(b, "0")
	}

	n1 := new(big.Int)
	_, _ = fmt.Sscan(a, n1)
	n2 := new(big.Int)
	_, _ = fmt.Sscan(b, n2)
	myMod := new(big.Int)
	myMod, _ = myMod.SetString("19260817", 10)
	n3 := new(big.Int).ModInverse(n2, myMod)
	if n3 == nil {
		fmt.Println("Angry!")
	} else {
		n2 = new(big.Int).Mul(n1, n3)
		n2 = new(big.Int).Mod(n2, myMod)
		fmt.Println(n2.String())
	}
}