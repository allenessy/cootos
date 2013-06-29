package main

import (
 	"fmt"
)

func main() {
 	var a int = 65
	b := string(a)
	fmt.Println(b)
	c := "hello world"
	length := len(c)
	fmt.Println(length)
	d := 1
	var p *int = &d
	fmt.Println(p)
	fmt.Println(*p)
}
