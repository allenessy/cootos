package main

import (
 	"strconv"
)

func main() {
	i, err := strconv.Atoi("12345")
	if err != nil {
		panic(err)
	}
	i += 3
	println(i)

	s := strconv.Itoa(12345)
	s += "3"
	println(s)
}
