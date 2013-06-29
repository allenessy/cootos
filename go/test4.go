package main

import (
	"fmt"
)

/*
  6: 0110
 11: 1011
 ----------
 &   0010 = 2
 |   1111 = 15
 ^   1101 = 13
 &^  0100 = 4
*/

func main() {
	fmt.Println(^2)
	fmt.Println(1 ^ 2)
	fmt.Println(!true)
	fmt.Println(1 << 10)
	fmt.Println(1 << 10 << 10)
	fmt.Println(1 << 10 << 10 >> 10)
	fmt.Println(6 & 11)
	fmt.Println(6 | 11)
	fmt.Println(6 ^ 11)
	fmt.Println(6 &^ 11)
	a := 1
	if a > 0 && (10/a) > 1 {
		fmt.Println("OK")
	}
}
