package main

import (
  "fmt"
)

func main() {
	a := "Hello"
  //先把string类型转换为slice切片
	b := []byte(a)
	b[0] = 'w'
	b[1] = 'o'
	b[2] = 'r'
	b[3] = 'l'
	b[4] = 'd'
  //再把slice转换为string类型
	c := string(b)
	fmt.Println(c)
}
