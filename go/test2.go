package main

import (
  "fmt"
	"strconv"
)

func main() {
	var a int = 65
	b := strconv.Itoa(a)
	a = strconv.Atoi(b)
	fmt.Println(b)
	fmt.Println(a)
}
